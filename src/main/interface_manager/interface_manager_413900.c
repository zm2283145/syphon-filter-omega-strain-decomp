/*
 * main/interface_manager: range (3 files, 00413900-00413C70)
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
int Mem_Free();

/* merge_units: begin func_00413900 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Str413900 { int a; int b; int c; };
struct Arc413900 { char pad[0x14C]; unsigned char ready; };
struct Self413900 { char pad[0x1E0]; int h1E0; int p1E4; Arc413900* arc; };

extern "C" {
int cInterfaceManager_FindHogFile(Self413900* self, Str413900* out, int name, int flags);
char* String_CStr(Str413900* s);
Arc413900* Archive_Open(int h, char* name, int a, int b);
void String_Dtor(Str413900* s, int flags);
}

#pragma push
#pragma opt_propagation off
extern "C" void cInterfaceManager_OpenHogOfHog(Self413900* self, int name)
{
    bool ok = false;
    if (self->p1E4 && self->h1E0) {
        Str413900 s;
        Str413900* ps = &s;
        ps->a = 0; ps->b = 0; ps->c = 0;
        if (cInterfaceManager_FindHogFile(self, ps, name, 0)) {
            self->arc = Archive_Open(self->h1E0, String_CStr(&s), 1, 0);
            if (self->arc->ready) ok = true;
        }
        String_Dtor(&s, 0);
    }
    if (!ok) self->arc = 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00413900 */

/* merge_units: begin func_004139C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

typedef struct { char pad[0xC]; } Item_4139C0;
typedef struct { int pad0; int count; Item_4139C0* data; } List_4139C0;
typedef struct { char pad[0xC]; void* obj; int active; int handle; } Ent_4139C0;
typedef struct {
    Ent_4139C0 ents[20]; int h1E0; List_4139C0* p1E4; int h1E8; List_4139C0* p1EC;
} Self_4139C0;
extern "C" {
extern char D_004BEF30[];
#if 0 /* merge_units */
int String_CStr(Item_4139C0* it);
#endif /* merge_units */
#define String_CStr(a0) ((int)String_CStr((Str413900 *)(a0))) /* merge_units */

void Interface_Dtor(void* p, int f);
void ArchiveList_CloseNamed(int a, int b);
void std_vector_deleter_cString_dtor(void* p, int f);
}
static inline void D3_4139C0(void* p) { if (p) std_vector_deleter_cString_dtor(p, 0); }
static inline void D2_4139C0(void* p) { if (p) D3_4139C0(p); }
static inline void D1_4139C0(void* p) { if (p) D2_4139C0(p); }

#pragma opt_strength_reduction off
extern "C" void cInterfaceManager_Reset(Self_4139C0* self)
{
    int i;
    Ent_4139C0* e = self->ents;
    for (i = 0; i < 20; i++, e++) {
        if (e->active && e->obj) {
            ArchiveList_CloseNamed(self->h1E0, e->handle);
            { void* o = e->obj; AllocGuard g; Interface_Dtor(o, -1); Mem_Free(0, o, D_004BEF30, 0x47); }
            e->active = 0;
            e->obj = 0;
        }
    }
    if (self->p1EC) {
        int n = self->p1EC->count;
        int j;
        for (j = 0; j < n; j++) ArchiveList_CloseNamed(self->h1E0, String_CStr(&self->p1EC->data[j]));
        { List_4139C0* p = self->p1EC; AllocGuard g; D1_4139C0(p); Mem_Free(0, p, D_004BEF30, 0x53); }
        self->p1EC = 0;
    }
    {
        List_4139C0* p = self->p1E4;
        if (p) {
            { AllocGuard g; D1_4139C0(p); Mem_Free(0, p, D_004BEF30, 0x5A); }
            self->p1E4 = 0;
        }
    }
    if (self->h1E8) ArchiveList_CloseNamed(self->h1E0, self->h1E8);
    self->h1E0 = 0;
    self->h1E8 = 0;
}
#undef String_CStr /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004139C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004139C0 */

/* merge_units: begin func_00413C70 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Rec413C70 { int a; int b; int c; unsigned char owned; };
struct Ent413C70 { char pad[0xC]; void* obj; int active; int handle; };
struct Self413C70 { Ent413C70 ents[20]; int h1E0; Rec413C70* p1E4; int h1E8; Rec413C70* p1EC; };

extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
Rec413C70* func_00413E10(Rec413C70* r);
}

static inline Rec413C70* New413C70(int line)
{
    Rec413C70* p;
    {
        AllocGuard g;
        p = (Rec413C70*)Mem_Alloc(0, 0x10, D_004BEF30, line);
    }
    if (p) {
        func_00413E10(p);
        p->owned = 1;
    }
    return p;
}

extern "C" void cInterfaceManager_Init(Self413C70* self)
{
    int i;
    self->h1E0 = 0;
    if (!self->p1E4) self->p1E4 = New413C70(0x31);
    if (!self->p1EC) self->p1EC = New413C70(0x35);
    for (i = 0; i < 20; i++) {
        self->ents[i].obj = 0;
        self->ents[i].active = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00413C70 */
