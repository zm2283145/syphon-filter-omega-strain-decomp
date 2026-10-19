/*
 * main/gameobj: range (3 files, 003941A0-003943A0)
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

/* merge_units: begin func_003941A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int ParticleInst_Kill(...);                            
int Object_Deactivate(...);                         
extern unsigned char g_ProfileLockEnabled;
}
#pragma opt_common_subs off
extern "C" void ParticleGob_OnAbsent(char * arg0, int arg1) {
    int temp_s2;

    temp_s2 = F_(arg0, 0x64, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        ParticleInst_Kill(temp_s2, -1);
        Mem_Free(0, temp_s2, "gameobj.cc", 0x286);
        }
        F_(arg0, 0x64, int) = 0;
    }
    Object_Deactivate(arg0, arg1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003941A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003941A0 */

/* merge_units: begin func_00394270 */
#pragma push /* merge_units */
#pragma cplusplus on

class Owner394270 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};

struct OwnerData394270 {
    void* vt;
    char p4[0xC];
    char pos[0x40];
    unsigned char dirty;
};

struct Tracer394270 {
    char p[0x50];
    float width;
};

struct Self394270 {
    char p0[0x50];
    OwnerData394270* owner;
    char p54[0xC];
    int id;
    Tracer394270* tracer;
    char p68[4];
    float width;
};

extern "C" {
extern char D_004BC430[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Tracer394270* Tracer_Create(void* p, int id, void* pos, float scale);
void Object_Activate(Self394270* self, int arg);
}

extern "C" void ParticleGob_OnPresent(Self394270* self, int arg)
{
    if (self->id != -1 && self->tracer == 0) {
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0x70, D_004BC430, 0x273);
        }
        if (p) {
            OwnerData394270* o = self->owner;
            if (o->dirty) ((Owner394270*)o)->Update();
            p = Tracer_Create(p, self->id, o->pos, 1.0f);
        }
        self->tracer = (Tracer394270*)p;
        if (self->tracer) self->tracer->width = self->width;
    }
    Object_Activate(self, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394270 */

/* merge_units: begin func_003943A0 */
#pragma push /* merge_units */
static inline void Q43(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4_003943A0;
typedef struct {
    Vec4_003943A0 min;
    Vec4_003943A0 max;
} Box;
typedef struct {
    char pad[0x64];
    void *mdl;
    char pad68[8];
    float scale;
} Obj;
extern Box *ParticleInst_ComputeBounds(void *);
extern signed char D_0053B4C0;
extern Box D_0053B4D0;
Box *ParticleGob_GetBounds(Obj *o)
{
    if (o->mdl != 0) {
    if (o->scale == 1.0f) return ParticleInst_ComputeBounds(o->mdl);
    if (!D_0053B4C0) {
        D_0053B4D0.min.x = 3.4028235e38f;
        D_0053B4D0.min.y = 3.4028235e38f;
        D_0053B4D0.min.z = 3.4028235e38f;
        D_0053B4D0.min.w = 1.0f;
        D_0053B4D0.max.x = -3.4028235e38f;
        D_0053B4D0.max.y = -3.4028235e38f;
        D_0053B4D0.max.z = -3.4028235e38f;
        D_0053B4D0.max.w = 1.0f;
        D_0053B4C0 = 1;
    }
    Q43(&D_0053B4D0.min, &ParticleInst_ComputeBounds(o->mdl)->min);
    D_0053B4D0.min.x = o->scale * ParticleInst_ComputeBounds(o->mdl)->min.x;
    D_0053B4D0.min.y = o->scale * ParticleInst_ComputeBounds(o->mdl)->min.y;
    Q43(&D_0053B4D0.max, &ParticleInst_ComputeBounds(o->mdl)->max); { void* xx = &D_0053B4D0.max; /* dead on purpose: retail keeps this addiu */ }
    D_0053B4D0.max.x = o->scale * ParticleInst_ComputeBounds(o->mdl)->max.x;
    D_0053B4D0.max.y = o->scale * ParticleInst_ComputeBounds(o->mdl)->max.y;
    return &D_0053B4D0;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003943A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003943A0 */
