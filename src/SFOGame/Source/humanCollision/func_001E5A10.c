#pragma cplusplus on
#include "types.h"

/* gcc-style asm on purpose: retail keeps bool temporaries as move/daddiu pairs (docs/HANDOFF.md) */
static inline void Cp(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }

static inline void Cp2(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); }
#include "v4_asm_copy.h"
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { V4Copy(this, &o); return *this; }
} __attribute__((aligned(16)));

static inline void Cp3(void* d, const void* s) { void* dd = d; const void* ss = s; __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(ss), "r"(dd) : "memory"); }
struct Phys {
    char pad[0xA0];
    V4 vel;
};

struct Body {
    char pad[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2[0x54 - 0x2F];
    Phys* phys;
};

struct Contact {
    unsigned char active;
    char pad[0x1F];
    V4 normal;
    char pad2[0x64 - 0x30];
    Body** bodies;
};

struct Actor {
    char pad[0xC];
    char* world;
    char pad2[0x1F0 - 0x10];
    Body* ignore[3];
    char pad3[0x310 - 0x1FC];
    V4 ref;
};

struct cGameEventMsg;

extern "C" {
extern char D_004A03C8[];
extern char D_004DAD20[];
extern char D_004F82F0[];
void* RootCollection_FindByKey(void* coll, void* key, void* obj);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* root);
void* cQuatVec_Translation(void* xf);
void cMessage_ctor_cMessageNameR(cGameEventMsg* m, void* name);
void QueueMessage_cMessageR_cSystemP_int(cGameEventMsg* m, void* target, int immediate);
void cMessage_dtor(cGameEventMsg* m, int flags);
void cHumanCollisionRoutine_HandleAnyLethalCollisions(Actor* self, void* target, Contact* c);
}

struct cGameEventMsg {
    void* vtable;
    char base[0x20];
    unsigned char kind;
    char pad[3];
    Body* body;
    char pad2[4];
};

static inline bool Body_IsSolid(Body* b)
{
    bool r = false;
    if (b->f2D && b->f2C) {
        r = true;
    }
    return r;
}

static inline bool Body_IsFree(Body* b) { return !b->f2E; }

static inline bool Body_IsActive(Body* b)
{
    bool r = false;
    if (Body_IsSolid(b) && Body_IsFree(b)) {
        r = true;
    }
    return r;
}

static inline unsigned char V4_IsZero(V4* v)
{
    int k, f;
    int r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}

static inline void V4_Sub(V4* out, V4* a, V4* b)
{
    V4 l0;
    V4* pb = b; V4* q1 = &l0; V4* pa = a;
    asm volatile {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    { V4* pd = out; const V4* ps = &l0; __int128 t; asm { lq t, 0(ps); sq t, 0(pd) } }
}

static inline float V4_Dot3(V4* a, V4* b)
{
    int t;
    V4* pb = b; V4* pa = a;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}

#pragma opt_common_subs off
void cHumanCollisionRoutine_HandleAnyLethalCollisions(Actor* self, void* target, Contact* c)
{
    V4 vel;
    V4 d;
    cGameEventMsg msg1;
    cGameEventMsg msg2;
    cGameEventMsg* m;
    Body* body;
    bool sent;
    bool found;
    Phys* phys;
    unsigned int i;
    float eps;

    if (!c->active) {
        return;
    }
    body = *c->bodies;
    phys = body->phys;
    if (phys == 0) {
        return;
    }
    if (!Body_IsActive(body)) {
        return;
    }
    Cp2(&vel, &phys->vel);
    if (V4_IsZero(&vel)) {
        return;
    }
    sent = false;
    if (!sent) {
        char* w = self->world;
        eps = 0.01f;
        cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(w + 0xB0, D_004A03C8, phys)));
        if (vel.z < -eps && c->normal.z < -0.9397f) {
            found = false;
            for (i = 0; i < 3; i++) {
                if (body == self->ignore[i]) {
                    found = true;
                }
            }
            if (!found) {
                m = &msg1;
                cMessage_ctor_cMessageNameR(m, D_004F82F0);
                m->vtable = D_004DAD20;
                m->kind = 2;
                m->body = body;
                QueueMessage_cMessageR_cSystemP_int(m, target, 1);
                msg1.vtable = D_004DAD20;
                cMessage_dtor(m, 0);
                sent = true;
            }
        }
    }
    if (!sent) {
        V4* pb; V4* pa;
        V4_Sub(&d, &vel, &self->ref);
        pb = &c->normal; pa = &d;
        float lim = 30.0f;
        if (!(V4_Dot3(pa, pb) <= lim)) {
            m = &msg2;
            cMessage_ctor_cMessageNameR(m, D_004F82F0);
            m->vtable = D_004DAD20;
            int one = 1;
            m->kind = one;
            m->body = body;
            QueueMessage_cMessageR_cSystemP_int(m, target, one);
            msg2.vtable = D_004DAD20;
            cMessage_dtor(m, 0);
        }
    }
}
