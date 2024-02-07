#include"Anex86.h"



namespace { // unnamed, for Anex86
BYTE JIS_tableH[0x80] = {
  0x00,0x81,0x81,0x82,0x82,0x83,0x83,0x84,
  0x84,0x85,0x85,0x86,0x86,0x87,0x87,0x88,
  0x88,0x89,0x89,0x8a,0x8a,0x8b,0x8b,0x8c,
  0x8c,0x8d,0x8d,0x8e,0x8e,0x8f,0x8f,0x90,
  0x90,0x91,0x91,0x92,0x92,0x93,0x93,0x94,
  0x94,0x95,0x95,0x96,0x96,0x97,0x97,0x98,
  0x98,0x99,0x99,0x9a,0x9a,0x9b,0x9b,0x9c,
  0x9c,0x9d,0x9d,0x9e,0x9e,0xdf,0xdf,0xe0,
  0xe0,0xe1,0xe1,0xe2,0xe2,0xe3,0xe3,0xe4,
  0xe4,0xe5,0xe5,0xe6,0xe6,0xe7,0xe7,0xe8,
  0xe8,0xe9,0xe9,0xea,0xea,0xeb,0xeb,0xec,
  0xec,0xed,0xed,0xee,0xee,0xef,0xef,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

BYTE JIS_tableL[0x80] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x40,0x41,0x42,0x43,0x44,0x45,0x46,
  0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,
  0x4f,0x50,0x51,0x52,0x53,0x54,0x55,0x56,
  0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,
  0x5f,0x60,0x61,0x62,0x63,0x64,0x65,0x66,
  0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,
  0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x76,
  0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,
  0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
  0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
  0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,
  0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x00,
};

void SpecialHookAnex86(hook_stack* stack,  HookParam*, uintptr_t *data, uintptr_t *split, size_t *len)
{
  auto ecx=stack->ecx;
  if(*(BYTE*)(ecx+0xe)!=0)return;
  auto lb=*(BYTE*)(ecx+0xc);
  auto hb=*(BYTE*)(ecx+0xd);
  if(hb==0){
    *data=lb;
    *len=1;
  }
  else{
    if(hb<=0x7e&&lb<=0x7e){

      *len=2;
      BYTE low;
      if ((hb & 1)== 0)
          low = lb + 0x7E;
      else
          low = JIS_tableL[lb];
      auto chr=low|(JIS_tableH[hb]<<8);
      *data=_byteswap_ushort(chr);
    }
  }
}
} // unnamed namespace
bool InsertAnex86Hook()
{
    const BYTE bytes[] = {
        0x8a, XX, 0x0c, // mov ??,[ecx+0C]
        0x8a, XX, 0x0d  // mov ??,[ecx+0D]
    };
    bool found = false;
    for (auto addr : Util::SearchMemory(bytes, sizeof(bytes), PAGE_EXECUTE, processStartAddress, processStopAddress)) {
  //const DWORD dwords[] = {0x618ac033,0x0d418a0c}; // jichi 12/25/2013: Remove static keyword
  //for (DWORD i = processStartAddress + 0x1000; i < processStopAddress - 8; i++)
    //if (*(DWORD *)i == dwords[0])
      //if (*(DWORD *)(i + 4) == dwords[1]) {
        HookParam hp;
        if (*(BYTE*)(addr - 2) == 0x33 || *(BYTE*)(addr - 2) == 0x31) addr = addr - 2;
        hp.address = addr;
        hp.offset=get_reg(regs::ecx);
        hp.type=USING_CHAR;
        hp.text_fun = SpecialHookAnex86;
        //hp.type = EXTERN_HOOK;
        ConsoleOutput("INSERT Anex86");
        
        found |=NewHook(hp, "Anex86");
      }
    if (found) return true;
  ConsoleOutput("Anex86: failed");
  return false;
}

bool Anex86::attach_function() {  
    
    return InsertAnex86Hook();
} 