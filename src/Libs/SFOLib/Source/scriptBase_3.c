/*
 * Libs/SFOLib/Source/scriptBase: 3 files, 003D6030-003D6190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D6030 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Allocate(...);                      
int std_vector_intPtr_ctor(...);                            
int memcpy(...);                            
int strlen(...);                                    
extern char D_004BD3B0;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * FuncDef_ctor_charP_intPintPint_bool(char * arg0, int arg1, int arg2, signed char arg3) {
    int temp_v1;
    int var_v0;
    int var_s1;
    char * temp_s0;
    int temp_s0_2;

    temp_s0 = arg0 + 8;
    std_vector_intPtr_ctor(temp_s0);
    var_s1 = 0;
    F_(temp_s0, 0xC, signed char) = 1;
    if (arg1 != 0) {
        temp_v1 = strlen(arg1) + 1; temp_s0_2 = (temp_v1 + 0x1F) / 32 * 32;
        {
            AllocGuard g;
        var_s1 = cMemMan_Allocate(0, temp_s0_2, &D_004BD3B0, 0x130);
        }
        memcpy(var_s1, arg1, temp_s0_2);
    }
    F_(arg0, 0x0, int) = var_s1;
    F_(arg0, 0x18, int) = 0;
    F_(arg0, 0x1C, int) = arg2;
    F_(arg0, 0x20, int) = 0;
    F_(arg0, 0x34, signed char) = 1;
    F_(arg0, 0x28, int) = -1;
    F_(arg0, 0x2C, int) = 0;
    F_(arg0, 0x24, int) = 0;
    F_(arg0, 0x30, int) = 0;
    F_(arg0, 0x35, signed char) = arg3;
    F_(arg0, 0x38, int) = 0;
    F_(arg0, 0x40, signed char) = 0;
    F_(arg0, 0x41, signed char) = 0;
    return arg0;
}
static inline void merge_flush_func_003D6030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D6030 */

/* merge_units: begin func_003D6190 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern char D_004BD3B0[];
#endif /* merge_units */
#define D_004BD3B0 ((char*)&D_004BD3B0) /* merge_units */

#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
#endif /* merge_units */

#if 0 /* merge_units */
int strlen(const char* s);
#endif /* merge_units */

#if 0 /* merge_units */
void* memcpy(void* d, const void* s, unsigned int n);
#endif /* merge_units */

}
struct S6190 {
    char* name;
    int a;
    unsigned char has;
    int b;
    int c10;
    int c14;
    unsigned char b18;
    unsigned char b19;
};
static inline char* Alloc6190(int n) {
    AllocGuard g;
    return (char*)cMemMan_Allocate(0, n, D_004BD3B0, 0x130);
}
static inline int Round6190(int n) { return (n + 31) / 32 * 32; }
extern "C" S6190* VarDef_ctor(S6190* s, const char* name, int a, int b, unsigned char f)
{
    char* p = 0;
    if (name) {
        int n = Round6190(strlen(name) + 1);
        p = Alloc6190(n);
        memcpy(p, name, n);
    }
    s->name = p;
    s->a = a;
    s->has = b != 0;
    s->b = b;
    s->c10 = 0;
    s->c14 = 0;
    s->b18 = 0;
    s->b19 = f;
    return s;
}
#undef D_004BD3B0 /* merge_units */
static inline void merge_flush_func_003D6190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D6190 */

/* merge_units: begin func_003D62D0 */
#pragma push /* merge_units */
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; } NamedRef;
#if 0 /* merge_units */
extern int strlen(const char* s); /* strlen */
#endif /* merge_units */

extern char* Libc_Strcpy(char* dst, const char* src);
extern void ScriptFileBuff_put(Writer* w, int size);
extern int ScriptFileBuff_charsToInts(Writer* w, int size);
extern void ScriptFileBuff_expand(Writer* w, int words);
extern char* cScriptBase_getClassName(void* key);
static inline void Writer_PutString(Writer* w, char* s)
{
    int size = strlen(s) + 1;
    int words;
    ScriptFileBuff_put(w, size);
    words = ScriptFileBuff_charsToInts(w, size);
    ScriptFileBuff_expand(w, words);
    Libc_Strcpy((char*)w->cursor, s);
    w->cursor += words;
}
/* Serialises the name and the key's name as padded strings. */
void VarDef_exportData(NamedRef* r, Writer* w)
{
    Writer_PutString(w, r->name);
    Writer_PutString(w, cScriptBase_getClassName(r->ref->key));
}
static inline void merge_flush_func_003D62D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D62D0 */
