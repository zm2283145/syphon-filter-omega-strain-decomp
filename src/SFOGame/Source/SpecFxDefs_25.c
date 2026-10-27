/*
 * SFOGame/Source/SpecFxDefs: 4 files, 00235D70-00236380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00235D70 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cElementPtr_dtor_void_2)
static inline void merge_flush_func_00235D70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00235D70 */

/* merge_units: begin func_00235DF0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int x0; int x4; int x8; } L_35DF0;
typedef struct { int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70; L_35DF0 list; unsigned char f80; char p81[0xA0 - 0x81]; int fA0; float fA4; float fA8; float fAC; float fB0; float fB4; } S_35DF0;
extern char D_004DF860[];
extern char D_004DBC70[];
int nGobjManager_GetNextId(int*, int);
int cGOBJ_ctor(S_35DF0*, int*, int, int*);
void std_list_deleter_voidPtr_ctor_void(L_35DF0*);
#if 0 /* merge_units */
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, L_35DF0* l, int* first, int** last);
#endif /* merge_units */
#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter(a0, a1, a2, a3) (std_list_deleter_voidPtr_erase_listdeleter_listdeleter((ObjListNode * *)(a0), (ObjList *)(a1), (ObjListNode * *)(a2), (ObjListNode * *)(a3))) /* merge_units */

float Libc_Asinf(float);
S_35DF0* cCameraAtmosphericEffect_ctor(S_35DF0* self, unsigned char kind, float a, float b, float c, float d)
{
    int id;
    int z;
    int r;
    int first;
    int* last;
    nGobjManager_GetNextId(&id, 0xE7);
    z = 0;
    cGOBJ_ctor(self, &id, 4, &z);
    self->f0 = (int)D_004DF860;
    self->f60 = -1;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 0x3F800000;
    self->f2F = 1;
    self->f0 = (int)D_004DBC70;
    std_list_deleter_voidPtr_ctor_void(&self->list);
    last = &self->list.x4;
    first = self->list.x8;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, &self->list, &first, &last);
    self->f80 = kind;
    self->fA8 = a;
    self->fAC = b + a;
    self->fB0 = c + self->fA8;
    self->fB4 = d;
    self->fA4 = 2.0f * Libc_Asinf(a / (2.0f * c));
    self->fA0 = (int)(0.5f + 1.5707964f / self->fA4);
    return self;
}
#undef std_list_deleter_voidPtr_erase_listdeleter_listdeleter /* merge_units */
static inline void merge_flush_func_00235DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00235DF0 */

/* merge_units: begin func_00235F60 */
#pragma push /* merge_units */
/* cHumanParticleGroup_NextFrame (c211nm). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "alloc_guard.h"
#include "vslot_pad.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const { V r; const V* bp = &b; V* rp = &r; const V* tp = this; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(bp), "r"(tp) : "memory"); return r; }
} __attribute__((aligned(16)));
struct M4 { float r[12]; V t; };

struct Def5F60 {
    int id;
    char p4[8];
    float rate;
    float minv;
    float k;
    unsigned char scaleRate;
    unsigned char vel;
    char p1A[2];
};
struct Obj5F60 { char p0[0x5C]; float f5C; char p60[0xA]; unsigned char b6A; };
struct Ent5F60 { Obj5F60* obj; float life; char p8[8]; V pos; };
struct Sub5F60 { VPAD32(a) VPAD32(b) virtual unsigned char f108(); char p4[0x3200]; int x3204; char p3208[0x346D - 0x3208]; unsigned char b346D; };
struct Self5F60 {
    char p0[0x74];
    Sub5F60* x74;
    Def5F60* x78;
    Ent5F60** x7C;
    float x80;
    int x84;
};

extern "C" {
extern char D_004A6E38[];
extern char D_0053B540[];
void* cMemMan_Allocate(int a, int size, char* file, int line);
void cMemMan_Deallocate(int a, void* p, char* file, int line);
void cHumanParticleGroup_SetMatrix(Self5F60* self, int i, M4* m);
int cParticleSystem_GetEffectID(char* lib, int id);
Obj5F60* cParticle_ctor(void* p, int id, M4* m, float rate);
void cParticle_dtor(Obj5F60* o, int a);
void cParticle_NextFrame(Obj5F60* o, float dt, M4* m, V* vel);
void cParticle_SetScale(Obj5F60* o, float r);
void cHumanParticleGroup_NextFrame(Self5F60* self, float dt);
}

static inline float Max5F60(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }

extern "C" void cHumanParticleGroup_NextFrame(Self5F60* self, float dt)
{
    int i;
    float total = 0.0f;
    float acc = total;
    for (i = 0; i < self->x84; i++) {
        V vel;
        M4 m;
        Def5F60* def = &self->x78[i];
        Ent5F60* e = self->x7C[i];
        cHumanParticleGroup_SetMatrix(self, i, &m);
        if (!e->obj) {
            Obj5F60* p;
            {
                AllocGuard g;
                p = (Obj5F60*)cMemMan_Allocate(0, 0x70, D_004A6E38, 0x1E6);
            }
            if (p) p = cParticle_ctor(p, cParticleSystem_GetEffectID(D_0053B540, def->id), &m, def->rate);
            e->obj = p;
            { const V* s = &m.t; e->pos = *s; }
        }
        if (e->obj) {
            Sub5F60* s = self->x74;
            float k;
            if ((s->x3204 >> 5) & 1 || s->b346D) k = 0.2f;
            else if (s->f108() == 3) k = def->k;
            else k = 3.0f * -def->k;
            e->life = e->life - k * dt;
            if (e->life < 0.0f) {
                Obj5F60* o = e->obj;
                {
                    AllocGuard g;
                    cParticle_dtor(o, -1);
                    cMemMan_Deallocate(0, o, D_004A6E38, 0x1F9);
                }
                e->obj = 0;
            } else if (e->life < 0.2f) {
                Obj5F60* o = e->obj; o->b6A = 1;
            } else if (!(e->life <= 1.0f)) {
                e->life = 1.0f;
            }
        }
        if (def->vel) {
            vel = e->pos - m.t;
        } else {
            vel.x = vel.y = vel.z = 0.0f;
        }
        if (e->obj) {
            cParticle_NextFrame(e->obj, dt, &m, &vel);
            cParticle_SetScale(e->obj, def->scaleRate ? e->life * def->rate : def->rate);
            e->obj->f5C = Max5F60(def->minv, e->life);
            acc += e->life * def->rate;
        }
        total += def->rate;
        e->pos = m.t;
    }
    self->x80 = total ? acc / total : 0.0f;
}
static inline void merge_flush_func_00235F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00235F60 */

/* merge_units: begin func_00236380 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { V4* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); return *this; }
};
struct M4_00236380 { V4 r[3]; V4 t; };
struct Ent236380 { void* obj; char p4[0xC]; V4 pos; };
struct Sub236380 { char p0[0x38]; int x38; };
struct Self236380 {
    char p0[0x74];
    Sub236380* x74;
    char p78[4];
    Ent236380** x7C;
    char p80[4];
    int x84;
};
extern "C" {
void cParticle_Render(void* obj, int a, M4_00236380* m);
void cHumanParticleGroup_Render(Self236380* self);
}
static inline void UM(void* m) { void* p = m; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
extern "C" void cHumanParticleGroup_Render(Self236380* self) {
    int i;
    for (i = 0; i < self->x84; i++) {
        if (self->x7C[i]->obj) {
            M4_00236380 m;
            UM(&m);
            m.t = self->x7C[i]->pos;
            { Sub236380* s = self->x74; cParticle_Render(self->x7C[i]->obj, s->x38, &m); }
        }
    }
}
static inline void merge_flush_func_00236380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236380 */
