/*
 * main/scriptManager: range (3 files, 003DD790-003DDC30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strlen(const char *);

/* merge_units: begin func_003DD790 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Var3DD790 {
    int pad0[2];
    unsigned char active;
    int* ptr;
    int refs;
    int v14;
    unsigned char b18;
    int v1C;
};

struct Mgr3DD790 {
    char pad[0x28];
    int count;
    int arr[5000];
};

extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
Var3DD790* cScriptInterpreter_findVar(Mgr3DD790*, char*, int);
void cScriptBase_sm_printf(char*, char*);
Var3DD790* VarDef_ctor(void*, char*, int*, int*, int);
void std_vector_VarDefPtr_push_back(int, Var3DD790**);
extern char D_004BD4C0[];
extern char D_004BD4F0[];
extern int D_00554F18;
}

extern "C" Var3DD790* cScriptInterpreter_considerVar(Mgr3DD790* m, char* name, int id, int* out, int t0, int t1, int t2)
{
    Var3DD790* r;
    Var3DD790* p;
    bool has;

    r = cScriptInterpreter_findVar(m, name, id);
    has = out != 0;
    if (r) {
        if (r->active && has && !t2)
            cScriptBase_sm_printf(D_004BD4F0, name);
        if (!r->active || (t2 && has)) {
            r->b18 = has && t0 != 0;
            if (r->active && t2 && has) {
                r->b18 = 0;
                *out = *r->ptr;
            }
            r->active = has;
            r->ptr = out;
            r->v14 = t0;
        }
    } else {
        if (has)
            *out = 0;
        {
            AllocGuard g;
            p = (Var3DD790*)cMemMan_Allocate(0, 0x20, D_004BD4C0, 0xAB3);
        }
        if (p) {
            if ((unsigned int)m->count < 5000) {
                m->arr[m->count] = id;
                m->count++;
            }
            p = (Var3DD790*)VarDef_ctor(p, name, (int*)&m->count + m->count, out, 1);
        }
        r = p;
        p->v14 = t0;
        r->b18 = t0 != 0;
        std_vector_VarDefPtr_push_back(D_00554F18, &r);
    }
    if (has)
        r->v1C = t1;
    r->refs++;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DD790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DD790 */

/* merge_units: begin func_003DD9F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Al3DD { int x; };
struct Scr3DD {
    char* name;
    char m4[0x10];
    char m14[0x10];
    char m24[0x10];
    int x34;
    int x38;
    unsigned char x3C;
    char pad3d[3];
    int x40;
    unsigned char x44;
    unsigned char x45;
    char pad46[2];
    int x48;
    unsigned char x4C;
};
struct Info3DD { char pad0[8]; int x8; char padc[0x38 - 0xC]; int id; unsigned char on; };
struct Mgr3DD { int pad0; int count; };
extern "C" {
extern Mgr3DD* D_00554F28;
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

char* cScriptBase_myStrdup(char*);
Al3DD* cArrayCapacity_ctor(Al3DD*, int);
void cArray_FieldDefPtr_ctor(void*, Al3DD*, int);
void cArray_MemberFuncPtr_ctor(void*, Al3DD*, int);
void cArray_int_ctor(void*);
void std_vector_ClassDefPtr_push_back(Mgr3DD*, Scr3DD**);
void ClassDef_init(Scr3DD*, int, int, int, int, int);
Info3DD* cScriptInterpreter_findCls(int, char*);
}
static inline int Data3DD(Info3DD* i) { return i->on ? i->x8 : 0; }
extern "C" Scr3DD* cScriptInterpreter_considerClass(int ctx, char* name, int noInit, char* parent, int a, int b, int c)
{
    Scr3DD* s = (Scr3DD*)cScriptInterpreter_findCls(ctx, name);
    Info3DD* p = parent ? cScriptInterpreter_findCls(ctx, parent) : 0;
    int id = p ? p->id : -1;
    int d = (p && p->on) ? p->x8 : 0;
    if (!s) {
        Scr3DD* n;
        {
            AllocGuard g;
            n = (Scr3DD*)cMemMan_Allocate(0, 0x50, D_004BD4C0, 0xA84);
        }
        if (n) {
            char* nm = cScriptBase_myStrdup(name);
            Al3DD t1;
            cArray_FieldDefPtr_ctor(n->m4, cArrayCapacity_ctor(&t1, 5), 1);
            Al3DD t2;
            cArray_MemberFuncPtr_ctor(n->m14, cArrayCapacity_ctor(&t2, 5), 1);
            cArray_int_ctor(n->m24);
            n->name = nm;
            n->x34 = 0;
            n->x3C = 0;
            n->x40 = -1;
            n->x44 = 0;
            n->x45 = 0;
            n->x48 = 0;
            n->x4C = 1;
        }
        s = n;
        if (!noInit)
            ClassDef_init(s, a, b, c, id, d);
        s->x38 = D_00554F28->count + 100;
        std_vector_ClassDefPtr_push_back(D_00554F28, &s);
    } else if (!noInit) {
        ClassDef_init(s, a, b, c, id, d);
    }
    return s;
}
#undef cMemMan_Allocate /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DD9F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DD9F0 */

/* merge_units: begin func_003DDC30 */
#pragma push /* merge_units */
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; int pad8; int count; KeyRef** args; } ScrEntry;
typedef struct { int x0; int count; void** data; } PtrList;
extern PtrList* D_00554F30;
#if 0 /* merge_units */
extern PtrList* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(PtrList **)&D_00554F28) /* merge_units */

#if 0 /* merge_units */
extern PtrList* D_00554F18;
#endif /* merge_units */
#define D_00554F18 (*(PtrList **)&D_00554F18) /* merge_units */

extern PtrList* D_00554F20;
extern void ScriptFileBuff_put(Writer* w, int size);
extern int ScriptFileBuff_charsToInts(Writer* w, int size);
extern void ScriptFileBuff_expand(Writer* w, int words);
extern char* cScriptBase_getClassName(void* key);
extern void EnumDef_exportData(void*, Writer*);
extern void ClassDef_exportNames(void*, Writer*);
extern void ClassDef_exportFields(void*, Writer*);
extern void VarDef_exportData(void*, Writer*);
static inline void* At(PtrList* l, unsigned int i) { return l->data[i]; }
static inline void Writer_PutInt(Writer* w, int v)
{
    ScriptFileBuff_expand(w, 1);
    *w->cursor++ = v;
}
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
void cScriptInterpreter_exportData(void* self, Writer* w)
{
    int n;
    int i;
    n = D_00554F30->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        EnumDef_exportData(At(D_00554F30, i), w);
    n = D_00554F28->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        ClassDef_exportNames(At(D_00554F28, i), w);
    for (i = 0; i < n; i++)
        ClassDef_exportFields(At(D_00554F28, i), w);
    n = D_00554F18->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        VarDef_exportData(At(D_00554F18, i), w);
    n = D_00554F20->count;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++) {
        ScrEntry* e; int na; int j;
        e = (ScrEntry*)At(D_00554F20, i);
        Writer_PutString(w, e->name);
        na = e->count;
        Writer_PutString(w, cScriptBase_getClassName(e->ref->key));
        Writer_PutInt(w, na);
        for (j = 0; j < na; j++)
            Writer_PutString(w, cScriptBase_getClassName(e->args[(unsigned int)j]->key));
    }
}
#undef D_00554F28 /* merge_units */
#undef D_00554F18 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DDC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DDC30 */
