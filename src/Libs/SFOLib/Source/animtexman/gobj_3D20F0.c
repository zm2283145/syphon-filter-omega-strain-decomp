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
int opNe_cConstLListIteratorR_cConstLListIteratorR_5(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* end(): iterator at the tree header. */
void cLList_cAnimTexturePtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Iterator increment. */
L4Iter* cConstLListIterator_cAnimTexturePtr_opInc(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

void* cTexture_GetName(void* self) {
    return self;
}

int cAnimTexture_GetTextureId(Word* self) {
    return self->value;
}

/* Iterator dereference. */
int* cConstLListIterator_cAnimTexturePtr_opMul(L4Iter* it) {
    return &it->node->value;
}

Word* cConstLListIterator_cAnimTexturePtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* begin() of a PtrVec. */
void cLList_cAnimTexturePtr_Begin(Iter* out, PtrVec* v) {
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
extern int cTexMan_GetTexture(int, int);
extern int XLib_GetTexMan(char*);
#if 0 /* merge_units */
extern int opNe_cConstLListIteratorR_cConstLListIteratorR_5(int*, int);
#endif /* merge_units */
#define opNe_cConstLListIteratorR_cConstLListIteratorR_5(a0, a1) (opNe_cConstLListIteratorR_cConstLListIteratorR_5((L4Iter *)(a0), (L4Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLList_cAnimTexturePtr_End(int*, int);
#endif /* merge_units */
#define cLList_cAnimTexturePtr_End(a0, a1) (cLList_cAnimTexturePtr_End((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cConstLListIterator_cAnimTexturePtr_opInc(int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_opInc(a0) ((void)cConstLListIterator_cAnimTexturePtr_opInc((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cTexture_GetName(int);
#endif /* merge_units */
#define cTexture_GetName(a0) ((int)cTexture_GetName((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cAnimTexture_GetTextureId(Ent3D2190*);
#endif /* merge_units */
#define cAnimTexture_GetTextureId(a0) (cAnimTexture_GetTextureId((Word *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern Ent3D2190** cConstLListIterator_cAnimTexturePtr_opMul(int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_opMul(a0) ((Ent3D2190 * *)cConstLListIterator_cAnimTexturePtr_opMul((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cConstLListIterator_cAnimTexturePtr_ctor(int*, int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_ctor(a0, a1) ((int)cConstLListIterator_cAnimTexturePtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLList_cAnimTexturePtr_Begin(int*, int);
#endif /* merge_units */
#define cLList_cAnimTexturePtr_Begin(a0, a1) (cLList_cAnimTexturePtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

extern int strcmp(int, int);
extern char g_Video[];
extern Mgr3D2190* g_TextureMgr;
#pragma push
#pragma opt_common_subs off
void cAnimTexMan_DecTextureFrame(int list, int name)
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
    cLList_cAnimTexturePtr_Begin(b, list);
    cConstLListIterator_cAnimTexturePtr_ctor(it, b);
    cLList_cAnimTexturePtr_End(a, list);
    while (opNe_cConstLListIteratorR_cConstLListIteratorR_5(it, cConstLListIterator_cAnimTexturePtr_ctor(e, a)) != 0) {
        ent = *cConstLListIterator_cAnimTexturePtr_opMul(it);
        db = XLib_GetTexMan(g_Video);
        if (strcmp(cTexture_GetName(cTexMan_GetTexture(db, cAnimTexture_GetTextureId(ent))), name) == 0) {
            found = ent;
            break;
        }
        cConstLListIterator_cAnimTexturePtr_opInc(it);
        cLList_cAnimTexturePtr_End(a, list);
    }
    if (found != 0) {
        n = found->cur - 1;
        if (n < found->count) {
            t = g_TextureMgr->list[found->idx];
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
#undef opNe_cConstLListIteratorR_cConstLListIteratorR_5 /* merge_units */
#undef cLList_cAnimTexturePtr_End /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_opInc /* merge_units */
#undef cTexture_GetName /* merge_units */
#undef cAnimTexture_GetTextureId /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_opMul /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_ctor /* merge_units */
#undef cLList_cAnimTexturePtr_Begin /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2190 */

/* merge_units: begin func_003D2320 */
#pragma push /* merge_units */
typedef struct { char p0[0x22]; unsigned short frames; } Anim3D2320;
typedef struct { char p0[0x44]; Anim3D2320* anim; char p48[4]; int frame; char p50[0x10]; signed char f60; signed char f61; } Tex3D2320;
typedef struct { int idx; char p4[0x10]; unsigned int count; char p18[0x10]; int cur; } Ent3D2320;
typedef struct { char p0[8]; Tex3D2320** list; } Mgr3D2320;
#if 0 /* merge_units */
extern int opNe_cConstLListIteratorR_cConstLListIteratorR_5(int*, int);
#endif /* merge_units */
#define opNe_cConstLListIteratorR_cConstLListIteratorR_5(a0, a1) (opNe_cConstLListIteratorR_cConstLListIteratorR_5((L4Iter *)(a0), (L4Iter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLList_cAnimTexturePtr_End(int*, int);
#endif /* merge_units */
#define cLList_cAnimTexturePtr_End(a0, a1) (cLList_cAnimTexturePtr_End((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cConstLListIterator_cAnimTexturePtr_opInc(int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_opInc(a0) ((void)cConstLListIterator_cAnimTexturePtr_opInc((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cTexture_GetName(int);
#endif /* merge_units */
#define cTexture_GetName(a0) ((int)cTexture_GetName((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cAnimTexture_GetTextureId(Ent3D2320*);
#endif /* merge_units */
#define cAnimTexture_GetTextureId(a0) (cAnimTexture_GetTextureId((Word *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern Ent3D2320** cConstLListIterator_cAnimTexturePtr_opMul(int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_opMul(a0) ((Ent3D2320 * *)cConstLListIterator_cAnimTexturePtr_opMul((L4Iter *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cConstLListIterator_cAnimTexturePtr_ctor(int*, int*);
#endif /* merge_units */
#define cConstLListIterator_cAnimTexturePtr_ctor(a0, a1) ((int)cConstLListIterator_cAnimTexturePtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLList_cAnimTexturePtr_Begin(int*, int);
#endif /* merge_units */
#define cLList_cAnimTexturePtr_Begin(a0, a1) (cLList_cAnimTexturePtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern Mgr3D2320* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(Mgr3D2320 **)&g_TextureMgr) /* merge_units */

#pragma push
#pragma opt_common_subs off
void cAnimTexMan_IncTextureFrame(int list, int name)
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
    cLList_cAnimTexturePtr_Begin(b, list);
    cConstLListIterator_cAnimTexturePtr_ctor(it, b);
    cLList_cAnimTexturePtr_End(a, list);
    while (opNe_cConstLListIteratorR_cConstLListIteratorR_5(it, cConstLListIterator_cAnimTexturePtr_ctor(e, a)) != 0) {
        ent = *cConstLListIterator_cAnimTexturePtr_opMul(it);
        db = XLib_GetTexMan(g_Video);
        if (strcmp(cTexture_GetName(cTexMan_GetTexture(db, cAnimTexture_GetTextureId(ent))), name) == 0) {
            found = ent;
            break;
        }
        cConstLListIterator_cAnimTexturePtr_opInc(it);
        cLList_cAnimTexturePtr_End(a, list);
    }
    if (found != 0) {
        n = found->cur + 1;
        if (n < found->count) {
            t = g_TextureMgr->list[found->idx];
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
#undef opNe_cConstLListIteratorR_cConstLListIteratorR_5 /* merge_units */
#undef cLList_cAnimTexturePtr_End /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_opInc /* merge_units */
#undef cTexture_GetName /* merge_units */
#undef cAnimTexture_GetTextureId /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_opMul /* merge_units */
#undef cConstLListIterator_cAnimTexturePtr_ctor /* merge_units */
#undef cLList_cAnimTexturePtr_Begin /* merge_units */
#undef g_TextureMgr /* merge_units */
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
Raw_24B0 std_list_deleter_voidPtr_begin_void(void*);
Raw_24B0 std_list_cAnimTexturePtr_end(void*);
void std_list_cAnimTexturePtr_generic_iterator_ctor(char**, const Raw_24B0&);
void cLListIterator_cAnimTexturePtr_ctor_listR(char**, const Raw_24B0&);
}
extern "C" void cAnimTexMan_NextFrame(S_24B0* self, float dt) {
    char* end1;
    char* end2;
    if (self->dirty) {
        char* it;
        char* n;
        std_list_cAnimTexturePtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self));
        n = it;
        while ((cLListIterator_cAnimTexturePtr_ctor_listR(&end1, std_list_cAnimTexturePtr_end(self)), n != end1)) {
            F_(n, 0x8, Obj_24B0*)->Reset();
            n = F_(n, 0x4, char*);
        }
        self->dirty = 0;
    }
    {
        char* it;
        char* n;
        std_list_cAnimTexturePtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self));
        n = it;
        while ((cLListIterator_cAnimTexturePtr_ctor_listR(&end2, std_list_cAnimTexturePtr_end(self)), n != end2)) {
            F_(n, 0x8, Obj_24B0*)->Update(dt);
            n = F_(n, 0x4, char*);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D24B0 */
