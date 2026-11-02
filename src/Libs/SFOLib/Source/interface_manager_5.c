/*
 * Libs/SFOLib/Source/interface_manager: 11 files, 00413800-00413EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00413800 */
#pragma push /* merge_units */
#include "types.h"
#include "interface_manager_types.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { int unk0; int count; String* data; } StringVec;

#if 0 /* merge_units */
extern void String_Dtor(String* s, int flags);
#endif /* merge_units */
void* String_Dtor(void* self, short deleteFlag); /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((void *)(a0), (short)(a1))) /* merge_units */


/* Removes the last string of the vector and destroys it. */
void StringVec_PopBack(StringVec* self)
{
    String* last = &self->data[--self->count];
    if (last)
        String_Dtor(last, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413800(void) {}
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413800 */

/* merge_units: begin func_00413850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */


/* Address of record `index`. */
IfRec12* std_vector_cString_opIndex(IfRecVec* v, int index) {
    return v->data + index;
}

/* Number of records. */
int cArray_cString_Size(IfRecVec* v) {
    return v->count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00413850 */

/* merge_units: begin func_00413880 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int std_basic_string_char_char_traits_char_ctor_charP();                      
#if 0 /* merge_units */
int String_Dtor();
#endif /* merge_units */
                            
int std_vector_imp_cString_insert();               

#pragma opt_common_subs off
void func_00413880(char * arg0) {
    int sp20[4];
    char * temp_a0;

    if (F_(arg0, 0x1E4, int) != NULL) {
        std_basic_string_char_char_traits_char_ctor_charP(sp20);
        temp_a0 = (char *)(F_(arg0, 0x1E4, int));
        std_vector_imp_cString_insert(temp_a0, F_(temp_a0, 0x8, int) + (F_(temp_a0, 0x4, int) * 0xC), 1, sp20);
        String_Dtor(sp20, 0);
    }
}
static inline void merge_flush_func_00413880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413880 */

/* merge_units: begin func_004138F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */


/* Setter for unk1E0. */
void cInterfaceManager_SetHogList(IfManager* mgr, int value) {
    mgr->unk1E0 = value;
}
static inline void merge_flush_func_004138F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004138F0 */

/* merge_units: begin func_00413900 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on

struct Str413900 { int a; int b; int c; };
struct Arc413900 { char pad[0x14C]; unsigned char ready; };
struct Self413900 { char pad[0x1E0]; int h1E0; int p1E4; Arc413900* arc; };

extern "C" {
int cInterfaceManager_FindHogFile(Self413900* self, Str413900* out, int name, int flags);
#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str413900* s);
#endif /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(void*); /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */

Arc413900* cHogList_Open(int h, char* name, int a, int b);
#if 0 /* merge_units */
void String_Dtor(Str413900* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((void *)(a0), (short)(a1))) /* merge_units */

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
            self->arc = cHogList_Open(self->h1E0, std_basic_string_char_char_traits_char_c_str(&s), 1, 0);
            if (self->arc->ready) ok = true;
        }
        String_Dtor(&s, 0);
    }
    if (!ok) self->arc = 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413900(void) {}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef String_Dtor /* merge_units */
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
int std_basic_string_char_char_traits_char_c_str(Item_4139C0* it);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) ((int)std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */


void cInterface_dtor(void* p, int f);
void cHogList_Close(int a, int b);
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
            cHogList_Close(self->h1E0, e->handle);
            { void* o = e->obj; AllocGuard g; cInterface_dtor(o, -1); cMemMan_Deallocate(0, o, D_004BEF30, 0x47); }
            e->active = 0;
            e->obj = 0;
        }
    }
    if (self->p1EC) {
        int n = self->p1EC->count;
        int j;
        for (j = 0; j < n; j++) cHogList_Close(self->h1E0, std_basic_string_char_char_traits_char_c_str(&self->p1EC->data[j]));
        { List_4139C0* p = self->p1EC; AllocGuard g; D1_4139C0(p); cMemMan_Deallocate(0, p, D_004BEF30, 0x53); }
        self->p1EC = 0;
    }
    {
        List_4139C0* p = self->p1E4;
        if (p) {
            { AllocGuard g; D1_4139C0(p); cMemMan_Deallocate(0, p, D_004BEF30, 0x5A); }
            self->p1E4 = 0;
        }
    }
    if (self->h1E8) cHogList_Close(self->h1E0, self->h1E8);
    self->h1E0 = 0;
    self->h1E8 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004139C0(void) {}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004139C0 */

/* merge_units: begin func_00413C70 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Rec413C70 { int a; int b; int c; unsigned char owned; };
struct Ent413C70 { char pad[0xC]; void* obj; int active; int handle; };
struct Self413C70 { Ent413C70 ents[20]; int h1E0; Rec413C70* p1E4; int h1E8; Rec413C70* p1EC; };

extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
Rec413C70* func_00413E10(Rec413C70* r);
#endif /* merge_units */
Rel* func_00413E10(Rel* r); /* merge_units */
#define func_00413E10(a0) ((Rec413C70 *)func_00413E10((Rel *)(a0))) /* merge_units */

}

static inline Rec413C70* New413C70(int line)
{
    Rec413C70* p;
    {
        AllocGuard g;
        p = (Rec413C70*)cMemMan_Allocate(0, 0x10, D_004BEF30, line);
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
#undef func_00413E10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413C70 */

/* merge_units: begin func_00413E10 */
#pragma push /* merge_units */
/* Zero-initialise a three-word record. */
Rel* func_00413E10(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00413E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413E10 */

/* merge_units: begin interface_manager_413E30 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { 
#if 0 /* merge_units */
void cInterfaceManager_Reset(void* self);
#endif /* merge_units */
#define cInterfaceManager_Reset(a0) (cInterfaceManager_Reset((Self_4139C0 *)(a0))) /* merge_units */
#if 0 /* merge_units */
void cInterfaceManager_Entry_dtor(void);
#endif /* merge_units */
void* cInterfaceManager_Entry_dtor(void* self, short deleteFlag); /* merge_units */
void __destroy_array(void* p, void* dtor, int size, int n); void operator_delete(void* p); }
extern "C" void* cInterfaceManager_dtor(void* self, short deleteFlag)
{
    if (self) {
        cInterfaceManager_Reset(self);
        __destroy_array(self, (void*)cInterfaceManager_Entry_dtor, 0x18, 0x14);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef cInterfaceManager_Reset /* merge_units */
static inline void merge_flush_interface_manager_413E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end interface_manager_413E30 */

/* merge_units: begin func_00413EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cInterfaceManager_Entry_dtor, String_Dtor)
static inline void merge_flush_func_00413EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413EA0 */

/* merge_units: begin func_00413F00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* cInterfaceManager_Entry_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00413F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413F00 */
