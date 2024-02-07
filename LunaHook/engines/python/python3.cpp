#include"types.h"
#include"main.h"
namespace {
    #ifdef Py_TRACE_REFS
/* Define pointers to support a doubly-linked list of all live heap objects. */
#define _PyObject_HEAD_EXTRA            \
    struct _object *_ob_next;           \
    struct _object *_ob_prev;

#define _PyObject_EXTRA_INIT 0, 0,

#else
#define _PyObject_HEAD_EXTRA
#define _PyObject_EXTRA_INIT
#endif
    typedef size_t         Py_ssize_t;
        typedef struct _object {
        _PyObject_HEAD_EXTRA
        Py_ssize_t ob_refcnt;
        struct _typeobject *ob_type;
    } PyObject;
#define PyObject_HEAD                   PyObject ob_base;
typedef Py_ssize_t Py_hash_t;
typedef struct { 
    PyObject_HEAD
    Py_ssize_t length;          /* Number of code points in the string */
    Py_hash_t hash;             /* Hash value; -1 if not set */
    struct { 
        unsigned int interned:2;
        unsigned int kind:3;
        unsigned int compact:1;
        unsigned int ascii:1;
        unsigned int ready:1;
        unsigned int :24;
    } state;
    wchar_t *wstr;              /* wchar_t representation (null-terminated) */
} PyASCIIObject;
typedef struct {
    PyASCIIObject _base;
    Py_ssize_t utf8_length;     /* Number of bytes in utf8, excluding the
                                 * terminating \0. */
    char *utf8;                 /* UTF-8 representation (null-terminated) */
    Py_ssize_t wstr_length;     /* Number of code points in wstr, possible
                                 * surrogates count as two code points. */
} PyCompactUnicodeObject;
/* Return one of the PyUnicode_*_KIND values defined above. */
#define PyUnicode_KIND(op) \
    (assert(PyUnicode_Check(op)), \
     assert(PyUnicode_IS_READY(op)),            \
     ((PyASCIIObject *)(op))->state.kind)

typedef uint32_t Py_UCS4;
typedef uint16_t Py_UCS2;
typedef uint8_t Py_UCS1;
typedef struct {
    PyCompactUnicodeObject _base;
    union {
        void *any;
        Py_UCS1 *latin1;
        Py_UCS2 *ucs2;
        Py_UCS4 *ucs4;
    } data;                     /* Canonical, smallest-form Unicode buffer */
} PyUnicodeObject;
#define PyUnicode_IS_COMPACT(op) \
    (((PyASCIIObject*)(op))->state.compact)
#define PyUnicode_IS_ASCII(op)                   \
    (assert(PyUnicode_Check(op)),                \
     assert(PyUnicode_IS_READY(op)),             \
     ((PyASCIIObject*)op)->state.ascii)
#define _PyUnicode_COMPACT_DATA(op)                     \
    (PyUnicode_IS_ASCII(op) ?                   \
     ((void*)((PyASCIIObject*)(op) + 1)) :              \
     ((void*)((PyCompactUnicodeObject*)(op) + 1)))

#define _PyUnicode_NONCOMPACT_DATA(op)                  \
    (assert(((PyUnicodeObject*)(op))->data.any),        \
     ((((PyUnicodeObject *)(op))->data.any)))

#define PyUnicode_DATA(op) \
    (assert(PyUnicode_Check(op)), \
     PyUnicode_IS_COMPACT(op) ? _PyUnicode_COMPACT_DATA(op) :   \
     _PyUnicode_NONCOMPACT_DATA(op))
#define PyUnicode_GET_LENGTH(op)                \
    (assert(PyUnicode_Check(op)),               \
     assert(PyUnicode_IS_READY(op)),            \
     ((PyASCIIObject *)(op))->length)
enum PyUnicode_Kind {
/* String contains only wstr byte characters.  This is only possible
   when the string was created with a legacy API and _PyUnicode_Ready()
   has not been called yet.  */
    PyUnicode_WCHAR_KIND = 0,
/* Return values of the PyUnicode_KIND() macro: */
    PyUnicode_1BYTE_KIND = 1,
    PyUnicode_2BYTE_KIND = 2,
    PyUnicode_4BYTE_KIND = 4
};
#define PyUnicode_READ(kind, data, index) \
    ((Py_UCS4) \
    ((kind) == PyUnicode_1BYTE_KIND ? \
        ((const Py_UCS1 *)(data))[(index)] : \
        ((kind) == PyUnicode_2BYTE_KIND ? \
            ((const Py_UCS2 *)(data))[(index)] : \
            ((const Py_UCS4 *)(data))[(index)] \
        ) \
    ))

  
}
 #ifdef _WIN64
                
bool InsertRenpy3Hook()
{
    wchar_t pythonf[] = L"python3%d.dll", libpython[] = L"libpython3.%d.dll";
    wchar_t python[64] = { 0 };
    for (wchar_t* pythonff : { python, libpython })
    {
        for (int pythonMinorVersion = 0; pythonMinorVersion <= 20; ++pythonMinorVersion)
        {
            wsprintf(python, pythonff, pythonMinorVersion);
            if (HMODULE module = GetModuleHandleW(python))
            {
                auto succ=false;
                uintptr_t addr = (uintptr_t)GetProcAddress(module, "PyUnicode_Format");
                if (addr) {
                    HookParam hp;
                    hp.address = addr;
                    hp.text_fun = [](hook_stack* stack, HookParam* hp, uintptr_t* data, uintptr_t* split, size_t* len)
                    {
                        auto format=(PyObject *)stack->rcx;
                        if (format == NULL ) 
                            return ;
                            
                        auto fmtstr=format;
                        auto fmtdata = PyUnicode_DATA(fmtstr);
                        auto fmtkind = PyUnicode_KIND(fmtstr);
                        auto fmtcnt = PyUnicode_GET_LENGTH(fmtstr);
                        
                        for(auto i=0;i<fmtcnt;i++){ 
                            if(PyUnicode_READ(fmtkind,fmtdata,i)=='%')
                                return;
                        }

                        *data=(uintptr_t)fmtdata;
                        switch (fmtkind)
                        {
                        case PyUnicode_WCHAR_KIND:
                        case PyUnicode_2BYTE_KIND:
                            hp->type=CODEC_UTF16|USING_STRING|NO_CONTEXT;
                            *len=fmtcnt*sizeof(Py_UCS2);
                            break;
                        case PyUnicode_1BYTE_KIND:
                            hp->type=CODEC_UTF8|USING_STRING|NO_CONTEXT;
                            *len=fmtcnt*sizeof(Py_UCS1);
                            break;
                        case PyUnicode_4BYTE_KIND://Py_UCS4,utf32
                            hp->type=CODEC_UTF32|USING_STRING|NO_CONTEXT;
                            *len=fmtcnt*sizeof(Py_UCS4);
                        }
                    };
                    succ|=NewHook(hp, "python3");
                }
#if 0
                addr = (uintptr_t)GetProcAddress(module, "PyUnicode_FromWideChar");
                if (addr) {
                    HookParam hp;
                    hp.address = addr;
                    hp.offset=get_reg(regs::rcx);
                    hp.type = USING_STRING | CODEC_UTF16 | NO_CONTEXT;
                    succ|=NewHook(hp, "python3");
                }
                addr = (uintptr_t)GetProcAddress(module, "PyUnicode_FromFormatV"); //ansi
                if (addr) {
                    HookParam hp;
                    hp.address = addr;
                    hp.offset=get_reg(regs::rcx);
                    hp.type = USING_STRING  | NO_CONTEXT;
                    succ|=NewHook(hp, "python3");
                }
                addr = (uintptr_t)GetProcAddress(module, "PyUnicode_FromFormat");
                if (addr) {
                    HookParam hp;
                    hp.address = addr;
                    hp.offset=get_reg(regs::rcx);
                    hp.type = USING_STRING  | NO_CONTEXT;
                    succ|=NewHook(hp, "python3");
                }
#endif
                return succ;
            }
        }
    }
    return false;
}

#endif