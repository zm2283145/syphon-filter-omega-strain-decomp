#pragma cplusplus on
#include "types.h"

struct V458 { float x, y, z, w; } __attribute__((aligned(16)));
struct Surf58 { unsigned char a, b, c, d; int pad[3]; };
struct IPair58 { int a, b; };
struct Tri58 {
    V458 v[3];
    char n[0x10];
    Surf58 s;
    unsigned char f50, f51, f52;
    char pad53[0xD];
    IPair58 p;
    int pad68[2];
    Tri58* Init() { Tri58* t = this; V458* q = t->v; do { q++; } while (q != t->v + 3); t->s.a = 0; t->s.c = 0; t->p.a = 0; t->p.b = 0; return t; }
};
struct TriVec58 { int cap; int count; Tri58* data; Tri58& back() { return *(data + count - 1); } };
struct Ctx58 { TriVec58* vec; int mesh; unsigned char mask; };
struct Owner58 { char pad0[3]; unsigned char kind; char pad4[0x28]; int key; };
struct TriDesc58 { float f0; unsigned short v[3]; unsigned char fa; };
struct Flags58 { unsigned char a; unsigned char b[3]; };

extern "C" {
extern signed char D_004E9F98;
extern Surf58 D_004E9FA0;
extern unsigned char D_004E9FA2;
extern int D_00542CB8;
void cCollisionModel_FaceProperties_dtor(void);
void __register_global_object(void*, void*, void*);
char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(Owner58* owner, int* key);
int std_vector_cCollisionFace_capacity(TriVec58* v);
void Vector_Reserve_139920(TriVec58* v, int n);
void std_vector_imp_cCollisionFace_resize(TriVec58* v, int n, Tri58* t);
void* cCollisionModel_GetVertex(int m, unsigned short i);
float* cVector_W(char* p);
int cCollisionModel_GetXform(int m);
void* Transform_GetUpdated(int x);
void Mtx_Multiply4(void* d, void* m);
void Vec4_Copy(void* d, void* s);
void cCollisionModel_FaceProperties_opAssign(void* d, void* s);
signed char cCollisionModel_Face_IsCamPassThru(TriDesc58* d);
signed char cCollisionModel_Face_IsReceiveShadow(TriDesc58* d);
signed char cCollisionModel_Face_IsReceiveReflection(TriDesc58* d);
void cCollisionModel_FaceLocator_Set(void* d, int a, int b);
}

static inline Surf58* GetSurf(Owner58* owner, int index)
{
    int key;
    if (owner->kind < 3) {
        if (D_004E9F98 == 0) {
            D_004E9FA0.a = 0;
            D_004E9FA2 = 0;
            __register_global_object(&D_004E9FA0, cCollisionModel_FaceProperties_dtor, &D_00542CB8);
            D_004E9F98 = 1;
        }
        return &D_004E9FA0;
    }
    key = owner->key;
    return (Surf58*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(owner, &key) + index * 16);
}

static inline unsigned char Blocked58()
{
    Flags58 buf;
    buf.a = 0;
    { unsigned char* q = buf.b; do { *q = 0; q++; } while (q != buf.b + 3); }
    return buf.a;
}
static inline unsigned char TestMask58(Surf58* s, unsigned char m) { m = s->a & m; return m; }

static inline void Fill58(Tri58* e, TriDesc58* d, int a3, Surf58* s, int m)
{
    void* mt;
    float f;
    void* x;
    Vec4_Copy(&e->v[0], cCollisionModel_GetVertex(m, d->v[0]));
    Vec4_Copy(&e->v[1], cCollisionModel_GetVertex(m, d->v[1]));
    Vec4_Copy(&e->v[2], cCollisionModel_GetVertex(m, d->v[2]));
    f = d->f0;
    *cVector_W(e->n) = f;
    x = (void*)cCollisionModel_GetXform(m);
    if (x) {
        mt = Transform_GetUpdated((int)x);
        Mtx_Multiply4(&e->v[0], mt);
        Mtx_Multiply4(&e->v[1], mt);
        Mtx_Multiply4(&e->v[2], mt);
    }
    cCollisionModel_FaceProperties_opAssign(&e->s, s);
    e->f50 = cCollisionModel_Face_IsCamPassThru(d);
    e->f51 = cCollisionModel_Face_IsReceiveShadow(d);
    e->f52 = cCollisionModel_Face_IsReceiveReflection(d);
    cCollisionModel_FaceLocator_Set(&e->p, a3, m);
}

extern "C" void cCollisionFaceCollector_AddFace(Ctx58* self, Owner58* owner, TriDesc58* d, int arg3)
{
    int idx = (unsigned char)(d->fa >> 1);
    Surf58* s = GetSurf(owner, idx);
    if (Blocked58())
        return;
    if (TestMask58(s, self->mask))
        return;
    {
        TriVec58* v = self->vec;
        if (v->count >= v->cap)
            Vector_Reserve_139920(self->vec, std_vector_cCollisionFace_capacity(self->vec) * 3 / 2);
    }
    {
        Tri58 t;
        t.Init();
        std_vector_imp_cCollisionFace_resize(self->vec, self->vec->count + 1, &t);
    }
    Fill58(&self->vec->back(), d, arg3, s, self->mesh);
}
