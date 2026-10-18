/*
 * main/NIEvent: range (5 files, 00238990-00239370)
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
int Mem_Free();
int strlen(const char *);

/* merge_units: begin func_00238990 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
class A1_Item {
public:
    virtual void Fire(int arg);
    float t;
};
struct A1_Obj { int a0; unsigned char active; float time; int pad; int count; A1_Item** items; };
extern "C" bool NiEventList_Advance(A1_Obj* o, float dt) {
    bool ret = false;
    float t = o->time + dt;
    int i;
    if (o->active) {
        for (i = 0; i < o->count; i++) {
            A1_Item* it = o->items[i];
            if (it->t <= t && !(it->t <= o->time)) {
                it->Fire(o->a0);
                ret = true;
            }
        }
        o->time = t;
    }
    return ret;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238990 */

/* merge_units: begin func_00238A50 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Pop_00238A50 { int version; int size; unsigned int base; char* cur; } Pop_00238A50;
typedef struct Vec_00238A50 { int a; int b; void** data; } Vec_00238A50;
typedef struct Trk_00238A50 { int owner; unsigned char f4; char pad5[3]; unsigned int f8; Vec_00238A50 vec; } Trk_00238A50;
typedef struct Cue_00238A50 { void* vt; float f4; int type; float fC; float f10; float f14; float f18; } Cue_00238A50;
extern "C" {
void* Mem_Alloc(int heap, int size, char* file, int line);
void PtrVector_Resize(Vec_00238A50* v, int n, void** fill);
void* NiEventType4_CtorFromStream(void* p, Pop_00238A50* r, int owner);
void* NiEventSound_CtorFromStream(void* p, Pop_00238A50* r, int owner);
extern char D_004DC028[];
extern char D_004DC038[];
}
static inline float ReadF_00238A50(Pop_00238A50* r)
{
    float v = *(float*)r->cur;
    r->cur += 4;
    return v;
}
static inline void* Alloc_00238A50(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, "NIEvent.cc", line);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void NiEvent_ReadEvents(Trk_00238A50* self, int owner, Pop_00238A50* r)
{
    int n = (int)ReadF_00238A50(r);
    void* fill1 = 0;
    void* fill0 = 0;
    int i;
    PtrVector_Resize(&self->vec, 0, &fill0);
    PtrVector_Resize(&self->vec, n, &fill1);
    for (i = 0; i < n; i++) {
        int type;
        Cue_00238A50* c = 0;
        type = (int)ReadF_00238A50(r);
        switch (type) {
        case 0:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0xC, 0x6C3);
            if (p) {
                p->vt = D_004DC038;
                p->type = type;
                p->f4 = ReadF_00238A50(r);
            }
            c = p;
            }
            break;
        case 1:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1C, 0x6C7);
            if (p) {
                p->vt = D_004DC038;
                p->type = 1;
                p->f4 = ReadF_00238A50(r);
                p->vt = D_004DC028;
                p->f14 = *(float*)r->cur; r->cur += 4;
                p->f18 = *(float*)r->cur; r->cur += 4;
                p->fC = *(float*)r->cur; r->cur += 4;
                p->f10 = *(float*)r->cur; r->cur += 4;
            }
            c = p;
            }
            break;
        case 2:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1A0, 0x6CB);
            if (p)
                p = (Cue_00238A50*)NiEventSound_CtorFromStream(p, r, owner);
            c = p;
            }
            break;
        case 3:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0xC, 0x6CF);
            if (p) {
                p->vt = D_004DC038;
                p->type = type;
                p->f4 = ReadF_00238A50(r);
            }
            c = p;
            }
            break;
        case 4:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1A0, 0x6D3);
            if (p)
                p = (Cue_00238A50*)NiEventType4_CtorFromStream(p, r, owner);
            c = p;
            }
            break;
        }
        if (c)
            self->vec.data[i] = c;
    }
    self->owner = owner;
    self->f8 = 0x80000000;
    self->f4 = 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238A50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238A50 */

/* merge_units: begin func_00238F20 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004A6FA8[];
extern void** D_004F7C70;
extern int D_004F7C78;
}
extern "C" void func_00238F20(void)
{
    int i;
    for (i = 0; i < D_004F7C78; i++) {
        void* p = D_004F7C70[i];
        AllocGuard g;
        Mem_Free(0, p, D_004A6FA8, 0x69C);
    }
    void** q = D_004F7C70;
    if (q) {
        {
            AllocGuard g;
            Mem_Free(0, q, D_004A6FA8, 0x6A0);
        }
        D_004F7C70 = 0;
    }
    D_004F7C78 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238F20 */

/* merge_units: begin func_002390A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_2390A0 { int version; int size; unsigned int base; char* cur; };
extern "C" {
#if 0 /* merge_units */
extern char** D_004F7C70;
#endif /* merge_units */
#define D_004F7C70 (*(char * **)&D_004F7C70) /* merge_units */

extern int D_004F7C80;
extern int D_0048AE28;
#if 0 /* merge_units */
void* Mem_Alloc(int pool, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

int Pop_FindTag(PopReader_2390A0* r, int tag);
}
extern "C" void NiEvent_ReadSoundNames(PopReader_2390A0* r)
{
    int mis;
    D_004F7C80 = 0;
    D_0048AE28 = -1;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    if ((unsigned char)Pop_FindTag(r, 0x3A53494E)) {
        D_004F7C78 = *(int*)r->cur;
        r->cur += 4;
        if (D_004F7C78) {
            int i;
            {
                char** p;
                {
                    int sz = D_004F7C78 * 4;
                    AllocGuard g;
                    p = (char**)Mem_Alloc(0, sz, D_004A6FA8, 0x680);
                }
                D_004F7C70 = p;
            }
            for (i = 0; i < D_004F7C78; i++) {
                char* p;
                char* s = r->cur;
                while (*r->cur++)
                    ;
                mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
                if (mis)
                    r->cur += 4 - mis;
                {
                    int len = strlen(s) + 1;
                    AllocGuard g;
                    p = (char*)Mem_Alloc(0, len, D_004A6FA8, 0x686);
                }
                D_004F7C70[i] = p;
                String_Copy(D_004F7C70[i], s);
                if (r->version >= 0x43) {
                    int v = *(int*)r->cur;
                    r->cur += 4;
                    if (D_0048AE28 == -1)
                        D_0048AE28 = v;
                    if (D_0048AE28 == v)
                        D_004F7C80++;
                }
            }
        }
    }
}
#undef D_004F7C70 /* merge_units */
#undef Mem_Alloc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002390A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002390A0 */

/* merge_units: begin func_00239370 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Elem_239370 { void* vt; };
struct Vec_239370 { int cap; };
struct Obj_239370 { char pad[0xC]; Vec_239370 vec; int count; };
extern "C" {
Elem_239370** func_00239590(Vec_239370* v, int i);
void func_002394A0(Vec_239370* v, int f);
void operator_delete(void* p);
}
extern "C" Obj_239370* func_00239370(Obj_239370* o, short flag)
{
    if (o) {
        int i;
        for (i = 0; i < o->count; i++) {
            Elem_239370* e = *func_00239590(&o->vec, i);
            AllocGuard g;
            if (e)
                e->vt = D_004DC038;
            Mem_Free(0, e, D_004A6FA8, 0x667);
        }
        o->count = 0;
        Vec_239370* v = &o->vec;
        if (v)
            func_002394A0(v, -1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239370 */
