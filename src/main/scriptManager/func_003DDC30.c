#include "types.h"
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; int pad8; int count; KeyRef** args; } ScrEntry;
typedef struct { int x0; int count; void** data; } PtrList;
extern PtrList* D_00554F30;
extern PtrList* D_00554F28;
extern PtrList* D_00554F18;
extern PtrList* D_00554F20;
extern int strlen(const char* s);
extern char* String_Copy(char* dst, const char* src);
extern void func_003D6580(Writer* w, int size);
extern int func_003D6570(Writer* w, int size);
extern void func_003D63C0(Writer* w, int words);
extern char* func_003D7510(void* key);
extern void func_003D6730(void*, Writer*);
extern void func_003D6B40(void*, Writer*);
extern void func_003D68B0(void*, Writer*);
extern void func_003D62D0(void*, Writer*);
static inline void* At(PtrList* l, unsigned int i) { return l->data[i]; }
static inline void Writer_PutInt(Writer* w, int v)
{
    func_003D63C0(w, 1);
    *w->cursor++ = v;
}
static inline void Writer_PutString(Writer* w, char* s)
{
    int size = strlen(s) + 1;
    int words;
    func_003D6580(w, size);
    words = func_003D6570(w, size);
    func_003D63C0(w, words);
    String_Copy((char*)w->cursor, s);
    w->cursor += words;
}
void func_003DDC30(void* self, Writer* w)
{
    int n;
    int i;
    n = D_00554F30->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        func_003D6730(At(D_00554F30, i), w);
    n = D_00554F28->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        func_003D6B40(At(D_00554F28, i), w);
    for (i = 0; i < n; i++)
        func_003D68B0(At(D_00554F28, i), w);
    n = D_00554F18->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        func_003D62D0(At(D_00554F18, i), w);
    n = D_00554F20->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++) {
        ScrEntry* e; int na; int j;
        e = (ScrEntry*)At(D_00554F20, i);
        Writer_PutString(w, e->name);
        na = e->count;
        Writer_PutString(w, func_003D7510(e->ref->key));
        Writer_PutInt(w, na);
        for (j = 0; j < na; j++)
            Writer_PutString(w, func_003D7510(e->args[(unsigned int)j]->key));
    }
}



