/*
 * main/gameobj: range (3 files, 00395530-00395950)
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
int cMemMan_Deallocate();

/* merge_units: begin func_00395530 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
#pragma opt_propagation off
static inline void K_395530(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4_395530 {
    float x, y, z, w;
    V4_395530() {}
    /* split lq / sq: retail schedules the dest addiu and the next block between them */
    V4_395530(const V4_395530& o) {
        V4_395530* d = this; const V4_395530* s = &o; __int128 t;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory");
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory");
    }
} __attribute__((aligned(16)));
extern "C" {
extern char D_004BC430[];
extern char D_004BC530[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void* cVU1Model_ctor(void* p);
void* cFileMan_ctor_void(void* p);
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline const V4_395530& IdentR_395530(void) { V4_395530 l0; V4_395530* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
struct Coll_395530 {
    int i0;
    unsigned char b4;
    char pad5[0xB];
    float f10;
    char pad14[0xC];
    V4_395530 v20;
    Coll_395530() { i0 = 0; b4 = 1; Init(IdentR_395530()); }
    void Init(V4_395530 o) { f10 = 0.0f; void* xx = &v20; /* dead on purpose */ V4_395530* d = &v20; V4_395530* s = &o; K_395530(d, s); }
};
struct S_395530 {
    char pad0[0x60];
    int i60;
    void* i64;
    void* p68;
    char pad6c[4];
    Coll_395530* p70;
    char pad74[0x1E0 - 0x74];
    void* p1E0;
    void* p1E4;
    void* p1E8;
    void* p1EC;
};
static inline void* NewA_395530(int line)
{
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x9C, D_004BC430, line);
    }
    if (p) p = cFileMan_ctor_void(p);
    return p;
}
extern "C" void cVUM_GOBJ_CreateModelData(S_395530* self_, S_395530* other_)
{
    S_395530* self = self_;
    S_395530* other = other_;
    void* p;
    self_->i60 = 0;
    self_->i64 = other;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x30, D_004BC430, 0x99);
    }
    if (p) p = cVU1Model_ctor(p);
    self->p68 = p;
    if (self->p70 == 0) {
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0x30, D_004BC530, 0x4FD);
        }
        p = new (p) Coll_395530;
        self->p70 = (Coll_395530*)p;
    }
    self->p1E4 = NewA_395530(0x9C);
    self->p1E8 = NewA_395530(0x9D);
    self->p1EC = NewA_395530(0x9E);
    if (other == 0) {
        self->p1E0 = NewA_395530(0xA3);
    } else {
        self->p1E0 = other->p1E0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00395530 */

/* merge_units: begin func_00395910 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
struct S00395910 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual int Set(void* a, int b); /* +0x90 */
    char p04[0x64];
    int f68;
    int p6C;
    int f70;
    char p74[0x1E0 - 0x74];
    int f1E0;
    int f1E4;
    int f1E8;
    int f1EC;
    char p1F0[2];
    unsigned char f1F2;
    unsigned char f1F3;
};
extern "C" char g_IdentityMatrix[];
extern "C" int cVUM_GOBJ_Init(S00395910* p) {
    p->f68 = 0;
    p->f70 = 0;
    p->f1E0 = 0;
    p->f1E8 = 0;
    p->f1E4 = 0;
    p->f1EC = 0;
    p->f1F2 = 0;
    p->f1F3 = 0;
    return p->Set(g_IdentityMatrix, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00395910 */

/* merge_units: begin func_00395950 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004DF970[];
void cGOBJ_dtor(void* self, int flag);
void cHogFile_dtor(void* p, int flag);
void cFileMan_dtor(void* p, int flag);
void cVU1Model_dtor(void* p, int flag);
void cCollisionModelMaster_UnLoad(void* p);
void operator_delete(void* p);
}
static inline void DelA_00395950(void* p, int line) { AllocGuard g; cFileMan_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BC430, line); }
static inline void DelB_00395950(void* p, int line) { AllocGuard g; cVU1Model_dtor(p, -1); cMemMan_Deallocate(0, p, D_004BC430, line); }
struct S_00395950 {
    void* vt; char pad4[0x5C]; int i60; int i64; void* p68; char pad6c[4]; void* p70; char m74[0x1E0 - 0x74];
    void* p1E0; void* p1E4; void* p1E8; void* p1EC; char pad1f0[2]; unsigned char b1F2;
};
extern "C" S_00395950* cVUM_GOBJ_dtor(S_00395950* self, short flag)
{
    if (self) {
        self->vt = D_004DF970;
        if (self->i64 == 0 && self->b1F2) {
            DelA_00395950(self->p1E0, 0x3B);
            self->p1E0 = 0;
        } else if (self->i64) {
            self->p1E0 = 0;
        }
        if (self->i60 == 0) {
            DelB_00395950(self->p68, 0x44);
            { void* q = self->p70; if (q) { { AllocGuard g; if (q) cCollisionModelMaster_UnLoad(q); cMemMan_Deallocate(0, q, "collision.hh", 0x506); } self->p70 = 0; } }
            if (self->p1E0) DelA_00395950(self->p1E0, 0x49);
            DelA_00395950(self->p1E8, 0x4B);
            DelA_00395950(self->p1E4, 0x4C);
            DelA_00395950(self->p1EC, 0x4D);
        }
        self->p68 = 0;
        self->p1E0 = 0;
        self->p1E8 = 0;
        self->p1E4 = 0;
        self->p1EC = 0;
        cHogFile_dtor(self->m74, -1);
        {
            void** h = (void**)((char*)self + 0x6C);
            if (h) { if (self->p70) cCollisionModelMaster_UnLoad(self->p70); }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00395950 */
