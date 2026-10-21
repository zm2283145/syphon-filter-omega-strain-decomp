/* FireEffectObj_Update (c211nm). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
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
void* Mem_Alloc(int a, int size, char* file, int line);
void Mem_Free(int a, void* p, char* file, int line);
void FireEffectObj_RecordMatrix(Self5F60* self, int i, M4* m);
int ParticleLib_FindId(char* lib, int id);
Obj5F60* Tracer_Create(void* p, int id, M4* m, float rate);
void ParticleInst_Kill(Obj5F60* o, int a);
void ParticleInst_Update(Obj5F60* o, float dt, M4* m, V* vel);
void ParticleEmitter_SetRate(Obj5F60* o, float r);
void FireEffectObj_Update(Self5F60* self, float dt);
}

static inline float Max5F60(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }

extern "C" void FireEffectObj_Update(Self5F60* self, float dt)
{
    int i;
    float total = 0.0f;
    float acc = total;
    for (i = 0; i < self->x84; i++) {
        V vel;
        M4 m;
        Def5F60* def = &self->x78[i];
        Ent5F60* e = self->x7C[i];
        FireEffectObj_RecordMatrix(self, i, &m);
        if (!e->obj) {
            Obj5F60* p;
            {
                AllocGuard g;
                p = (Obj5F60*)Mem_Alloc(0, 0x70, D_004A6E38, 0x1E6);
            }
            if (p) p = Tracer_Create(p, ParticleLib_FindId(D_0053B540, def->id), &m, def->rate);
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
                    ParticleInst_Kill(o, -1);
                    Mem_Free(0, o, D_004A6E38, 0x1F9);
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
            ParticleInst_Update(e->obj, dt, &m, &vel);
            ParticleEmitter_SetRate(e->obj, def->scaleRate ? e->life * def->rate : def->rate);
            e->obj->f5C = Max5F60(def->minv, e->life);
            acc += e->life * def->rate;
        }
        total += def->rate;
        e->pos = m.t;
    }
    self->x80 = total ? acc / total : 0.0f;
}



