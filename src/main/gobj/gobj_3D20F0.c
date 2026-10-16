/*
 * main/gobj: 4 files, 003D20F0-003D24B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D20F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container/iterator helpers; original translation unit not identified yet.
 */

#include "types.h"
#include "loose04_types.h"

/* Iterator inequality. */
int func_003D20F0(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* end(): iterator at the tree header. */
void func_003D2110(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
L4Iter* func_003D2120(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

void* func_003D2140(void* self) {
    return self;
}

int func_003D2150(Word* self) {
    return self->value;
}

/* Iterator dereference. */
int* func_003D2160(L4Iter* it) {
    return &it->node->value;
}

Word* func_003D2170(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* begin() of a PtrVec. */
void func_003D2180(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D20F0 */

/* merge_units: begin func_003D2190 */
#pragma push /* merge_units */
typedef struct { char p0[0x22]; unsigned short frames; } Anim3D2190;
typedef struct { char p0[0x44]; Anim3D2190* anim; char p48[4]; int frame; char p50[0x10]; signed char f60; signed char f61; } Tex3D2190;
typedef struct { int idx; char p4[0x10]; unsigned int count; char p18[0x10]; int cur; } Ent3D2190;
typedef struct { char p0[8]; Tex3D2190** list; } Mgr3D2190;
extern int func_00379740(int, int);
extern int func_003797D0(char*);
#if 0 /* merge_units */
extern int func_003D20F0(int*, int);
#endif /* merge_units */
#define func_003D20F0(a0, a1) (func_003D20F0((L4Iter *)(a0), (L4Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2110(int*, int);
#endif /* merge_units */
#define func_003D2110(a0, a1) (func_003D2110((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2120(int*);
#endif /* merge_units */
#define func_003D2120(a0) ((void)func_003D2120((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2140(int);
#endif /* merge_units */
#define func_003D2140(a0) ((int)func_003D2140((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2150(Ent3D2190*);
#endif /* merge_units */
#define func_003D2150(a0) (func_003D2150((Word *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern Ent3D2190** func_003D2160(int*);
#endif /* merge_units */
#define func_003D2160(a0) ((Ent3D2190 * *)func_003D2160((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2170(int*, int*);
#endif /* merge_units */
#define func_003D2170(a0, a1) ((int)func_003D2170((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2180(int*, int);
#endif /* merge_units */
#define func_003D2180(a0, a1) (func_003D2180((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

extern int strcmp(int, int);
extern char D_005381F0[];
extern Mgr3D2190* D_00539248;
#pragma push
#pragma opt_common_subs off
void Global_DecTexture(int list, int name)
{
    int it[1];
    int b[1];
    int e[1];
    int a[1];
    Ent3D2190* found;
    Ent3D2190* ent;
int db;
    unsigned int n;
    Tex3D2190* t;

    found = 0;
    func_003D2180(b, list);
    func_003D2170(it, b);
    func_003D2110(a, list);
    while (func_003D20F0(it, func_003D2170(e, a)) != 0) {
        ent = *func_003D2160(it);
        db = func_003797D0(D_005381F0);
        if (strcmp(func_003D2140(func_00379740(db, func_003D2150(ent))), name) == 0) {
            found = ent;
            break;
        }
        func_003D2120(it);
        func_003D2110(a, list);
    }
    if (found != 0) {
        n = found->cur - 1;
        if (n < found->count) {
            t = D_00539248->list[found->idx];
            if (n != t->frame && n < t->anim->frames) {
                t->f60 = 0;
                t->f61 = 0;
                t->frame = n;
            }
            found->cur = n;
        }
    }
}
#pragma pop
#undef func_003D20F0 /* merge_units */
#undef func_003D2110 /* merge_units */
#undef func_003D2120 /* merge_units */
#undef func_003D2140 /* merge_units */
#undef func_003D2150 /* merge_units */
#undef func_003D2160 /* merge_units */
#undef func_003D2170 /* merge_units */
#undef func_003D2180 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2190 */

/* merge_units: begin func_003D2320 */
#pragma push /* merge_units */
typedef struct { char p0[0x22]; unsigned short frames; } Anim3D2320;
typedef struct { char p0[0x44]; Anim3D2320* anim; char p48[4]; int frame; char p50[0x10]; signed char f60; signed char f61; } Tex3D2320;
typedef struct { int idx; char p4[0x10]; unsigned int count; char p18[0x10]; int cur; } Ent3D2320;
typedef struct { char p0[8]; Tex3D2320** list; } Mgr3D2320;
#if 0 /* merge_units */
extern int func_003D20F0(int*, int);
#endif /* merge_units */
#define func_003D20F0(a0, a1) (func_003D20F0((L4Iter *)(a0), (L4Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2110(int*, int);
#endif /* merge_units */
#define func_003D2110(a0, a1) (func_003D2110((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2120(int*);
#endif /* merge_units */
#define func_003D2120(a0) ((void)func_003D2120((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2140(int);
#endif /* merge_units */
#define func_003D2140(a0) ((int)func_003D2140((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2150(Ent3D2320*);
#endif /* merge_units */
#define func_003D2150(a0) (func_003D2150((Word *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern Ent3D2320** func_003D2160(int*);
#endif /* merge_units */
#define func_003D2160(a0) ((Ent3D2320 * *)func_003D2160((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D2170(int*, int*);
#endif /* merge_units */
#define func_003D2170(a0, a1) ((int)func_003D2170((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D2180(int*, int);
#endif /* merge_units */
#define func_003D2180(a0, a1) (func_003D2180((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern Mgr3D2320* D_00539248;
#endif /* merge_units */
#define D_00539248 (*(Mgr3D2320 **)&D_00539248) /* merge_units */

#pragma push
#pragma opt_common_subs off
void Global_IncTexture(int list, int name)
{
    int it[1];
    int b[1];
    int e[1];
    int a[1];
    Ent3D2320* found;
    Ent3D2320* ent;
int db;
    unsigned int n;
    Tex3D2320* t;

    found = 0;
    func_003D2180(b, list);
    func_003D2170(it, b);
    func_003D2110(a, list);
    while (func_003D20F0(it, func_003D2170(e, a)) != 0) {
        ent = *func_003D2160(it);
        db = func_003797D0(D_005381F0);
        if (strcmp(func_003D2140(func_00379740(db, func_003D2150(ent))), name) == 0) {
            found = ent;
            break;
        }
        func_003D2120(it);
        func_003D2110(a, list);
    }
    if (found != 0) {
        n = found->cur + 1;
        if (n < found->count) {
            t = D_00539248->list[found->idx];
            if (n != t->frame && n < t->anim->frames) {
                t->f60 = 0;
                t->f61 = 0;
                t->frame = n;
            }
            found->cur = n;
        }
    }
}
#pragma pop
#undef func_003D20F0 /* merge_units */
#undef func_003D2110 /* merge_units */
#undef func_003D2120 /* merge_units */
#undef func_003D2140 /* merge_units */
#undef func_003D2150 /* merge_units */
#undef func_003D2160 /* merge_units */
#undef func_003D2170 /* merge_units */
#undef func_003D2180 /* merge_units */
#undef D_00539248 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2320 */

/* merge_units: begin func_003D24B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Base_24B0 { char pad[0x10]; };
struct Obj_24B0 : Base_24B0 { virtual void Update(float); virtual void Reset(); };
struct Raw_24B0 { int p; };
struct S_24B0 { int a, b, c; unsigned char dirty; };
extern "C" {
Raw_24B0 List_Begin(void*);
Raw_24B0 func_003D2610(void*);
void func_003D2620(char**, const Raw_24B0&);
void func_003D2600(char**, const Raw_24B0&);
}
extern "C" void ListenerList_Update(S_24B0* self, float dt) {
    char* end1;
    char* end2;
    if (self->dirty) {
        char* it;
        char* n;
        func_003D2620(&it, List_Begin(self));
        n = it;
        while ((func_003D2600(&end1, func_003D2610(self)), n != end1)) {
            F_(n, 0x8, Obj_24B0*)->Reset();
            n = F_(n, 0x4, char*);
        }
        self->dirty = 0;
    }
    {
        char* it;
        char* n;
        func_003D2620(&it, List_Begin(self));
        n = it;
        while ((func_003D2600(&end2, func_003D2610(self)), n != end2)) {
            F_(n, 0x8, Obj_24B0*)->Update(dt);
            n = F_(n, 0x4, char*);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D24B0 */
