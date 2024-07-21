#pragma once

// texthook/const.h
// 8/23/2013 jichi
// Branch: ITH/common.h, rev 128

enum
{
  STRING = 12,
  MESSAGE_SIZE = 500,
  PIPE_BUFFER_SIZE = 50000,
  SHIFT_JIS = 932,
  MAX_MODULE_SIZE = 120,
  PATTERN_SIZE = 30,
  HOOK_NAME_SIZE = 60,
  FIXED_SPLIT_VALUE = 0x10001,
  HOOKCODE_LEN = 500
};
enum WildcardByte
{
  XX = 0x11
};

enum HostCommandType
{
  HOST_COMMAND_NEW_HOOK,
  HOST_COMMAND_REMOVE_HOOK,
  HOST_COMMAND_FIND_HOOK,
  HOST_COMMAND_MODIFY_HOOK,
  HOST_COMMAND_HIJACK_PROCESS,
  HOST_COMMAND_DETACH
};

enum HostNotificationType
{
  HOST_NOTIFICATION_TEXT,
  HOST_NOTIFICATION_NEWHOOK,
  HOST_NOTIFICATION_FOUND_HOOK,
  HOST_NOTIFICATION_RMVHOOK,
  HOST_NOTIFICATION_INSERTING_HOOK,
  HOST_SETTEXTTHREADTYPE
};
#define NEXT_MASK(x)            \
  DUMMY1_##x,                   \
      x = (1U << (DUMMY1_##x)), \
      DUMMY2_##x = DUMMY1_##x
#define DECLARE_VALUE(x, v) \
  DUMMY1_##x,               \
      x = v,                \
      DUMMY2_##x = DUMMY1_##x - 1

enum HookParamType : uint64_t
{
  // 默认为CODEC_ANSI_LE&USING_CHAR
  // 若使用了text_fun|hook_before，会改为默认USING_STRING，这时若其实是USING_CHAR，需标明USING_STRING
  DECLARE_VALUE(CODEC_ANSI_LE, 0),
  NEXT_MASK(CODEC_ANSI_BE),
  NEXT_MASK(CODEC_UTF8),
  NEXT_MASK(CODEC_UTF16),
  NEXT_MASK(CODEC_UTF32),

  NEXT_MASK(USING_CHAR), // text_fun!=nullptr && (CODE_ANSI_BE||CODE_UTF16)
  NEXT_MASK(USING_STRING),
  NEXT_MASK(SPECIAL_JIT_STRING),

  NEXT_MASK(FULL_STRING),

  NEXT_MASK(DATA_INDIRECT),
  NEXT_MASK(USING_SPLIT), // use ctx2 or not
  NEXT_MASK(SPLIT_INDIRECT),
  NEXT_MASK(FIXING_SPLIT),
  NEXT_MASK(NO_CONTEXT),

  NEXT_MASK(MODULE_OFFSET),   // address is relative to module
  NEXT_MASK(FUNCTION_OFFSET), // address is relative to function

  NEXT_MASK(KNOWN_UNSTABLE),

  NEXT_MASK(EMBED_ABLE),
  NEXT_MASK(EMBED_DYNA_SJIS),
  NEXT_MASK(EMBED_BEFORE_SIMPLE),
  NEXT_MASK(EMBED_AFTER_NEW),
  NEXT_MASK(EMBED_AFTER_OVERWRITE),
  NEXT_MASK(EMBED_CODEC_UTF16),

  DECLARE_VALUE(NORMAL_INLINEHOOK, 0),
  NEXT_MASK(BREAK_POINT),
  NEXT_MASK(DIRECT_READ), // /R read code instead of classic /H hook code

  NEXT_MASK(HOOK_RETURN),
  NEXT_MASK(HOOK_EMPTY),
};

enum HookFontType : unsigned
{
  DECLARE_VALUE(NOT_HOOK_FONT, 0),
  NEXT_MASK(F_CreateFontA),
  NEXT_MASK(F_CreateFontW),
  NEXT_MASK(F_CreateFontIndirectA),
  NEXT_MASK(F_CreateFontIndirectW),
  NEXT_MASK(F_GetGlyphOutlineA),
  NEXT_MASK(F_GetGlyphOutlineW),
  NEXT_MASK(F_GetTextExtentPoint32A),
  NEXT_MASK(F_GetTextExtentPoint32W),
  NEXT_MASK(F_GetTextExtentExPointA),
  NEXT_MASK(F_GetTextExtentExPointW),
  // F_GetCharABCWidthsA=0x
  // F_GetCharABCWidthsW=0x
  NEXT_MASK(F_TextOutA),
  NEXT_MASK(F_TextOutW),
  NEXT_MASK(F_ExtTextOutA),
  NEXT_MASK(F_ExtTextOutW),
  NEXT_MASK(F_DrawTextA),
  NEXT_MASK(F_DrawTextW),
  NEXT_MASK(F_DrawTextExA),
  NEXT_MASK(F_DrawTextExW),
  NEXT_MASK(F_CharNextA),
  // F_CharNextW=0x
  // F_CharNextExA=0x
  // F_CharNextExW=0x
  NEXT_MASK(F_CharPrevA),
  // F_CharPrevW=0x
  NEXT_MASK(F_MultiByteToWideChar),
  NEXT_MASK(F_WideCharToMultiByte),
};