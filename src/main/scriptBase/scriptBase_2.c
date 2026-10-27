/*
 * main/scriptBase: 2 files, 003D6190-003D62D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D6190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD3B0[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
int strlen(const char* s);
void* memcpy(void* d, const void* s, unsigned int n);
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
#pragma pop /* merge_units */
/* merge_units: end func_003D6190 */

/* merge_units: begin func_003D62D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; } NamedRef;
extern int strlen(const char* s); /* strlen */
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
#pragma pop /* merge_units */
/* merge_units: end func_003D62D0 */
