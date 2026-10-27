/*
 * SFOGame/Source/WaterFx: 2 files, 002B1CB0-002B1D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B1CB0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x40]; char splash[0x30]; char ripples[0x10]; } WaterFx;
typedef struct { char pad[0x400]; WaterFx* fx[20]; } WaterFxMgr;
extern void cSplash_Render(void*);
extern void cWake_Render(void*);
void cWaterFx_Render(WaterFxMgr* m)
{
    int i;
    WaterFxMgr* q = m;
    for (i = 0; i < 20; i++, q = (WaterFxMgr*)((char*)q + 4)) {
        WaterFx* p = q->fx[0];
        if (p) {
            cSplash_Render(p->splash);
            cWake_Render(p->ripples);
        }
    }
}
static inline void merge_flush_func_002B1CB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1CB0 */

/* merge_units: begin func_002B1D20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cWaterFx_NextFrame (cWaterFx::NextFrame): for every tracked body, follow its object while it is
   valid (ripples while it sits at or below the water line, plain splash/wake ageing otherwise),
   and free the record once the object is gone and both splash and wake have expired. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { Q16(this, &o); }
    cVector& operator=(const cVector& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
/* VU0 macro-mode vector op (COP2), not expressible in C */
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
/* max.s: no C equivalent */
static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct cMatrix { cVector r[4]; };
struct cBox { cVector mn; cVector mx; };
struct cXform { VPAD16(a) VPAD4(b) virtual void UpdateTreeNode() const; int pad4[3]; cMatrix localToWorldMatrix; unsigned char needsUpdate;
    const cMatrix& GetMatrix() const { if (needsUpdate) UpdateTreeNode(); return localToWorldMatrix; } };
struct cGOBJ {
    VPAD32(a) virtual const cBox* GetBBox() const;
    int pad4[2];
    int id;                 /* 0x0C */
    char pad10[0x40];
    cXform* mXform;         /* 0x50 */
};
static inline bool IsNullNV(void* p) { return !(p != 0); }
static inline int SameNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
static inline int SameRef(const int& a, const int& b) { return (unsigned)(a ^ b) < 1; }
struct cSafePtr {
    cGOBJ* ptr; int id;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(ptr) && !SameRef(ptr->id, id)) ok = 0; return ok; }
    cGOBJ* Get() { return IsValid() ? ptr : 0; }
    int operator==(const cGOBJ* p) { return SameNV((int)Get(), (int)p); }
};
struct cSplash { float life; char pad4[0xC]; cVector pos; float nodeMinSize; float nodeSizeRange; int frothTID; char pad2C[4];
    void NextFrame(float dt) { life = MaxF(0.0f, life - dt); } };
struct cWake { float spawnTimer; char nodes[0xC]; float nodeMinSize; float nodeSizeRange; float worldZ; int rippleTID; int numRippleFrames; };
struct tBody { cSafePtr gobj; float size; char pad0C[4]; cVector position; cVector velocity; float waterZ; char pad34[0xC]; cSplash splash; cWake wake; char pad94[0xC]; };
struct cWaterFx { char pad0[0x400]; tBody* bodies[20]; int numBodies; int numGobjBodies;
    void RemoveBody(int b);
};
extern "C" {
extern char D_004ABFE0[];
int cSplash_Expired(cSplash* s);
int cWake_Expired(cWake* w);
void cWake_NextFrame_float_cMatrixR_cVectorR(cWake* w, float dt, const cMatrix& m, const cVector& vel);
void cWake_NextFrame_float(cWake* w, float dt);
void opDelete_tBodyP_int_bool_charP_etc(tBody* p, int a, int b, char* file, int line);
void cWaterFx_NextFrame(cWaterFx* self, float dtime);
}
static inline bool Done(tBody& body) { return cSplash_Expired(&body.splash) && cWake_Expired(&body.wake); }
inline void cWaterFx::RemoveBody(int b) { if (b >= 0 && b < 20) { opDelete_tBodyP_int_bool_charP_etc(bodies[b], 0, 1, D_004ABFE0, 438); bodies[b] = 0; numBodies--; } }

void cWaterFx_NextFrame(cWaterFx* self, float dtime)
{
    int b;
    for (b = 0; b < 20; b++) {
        if (self->bodies[b]) {
            tBody& body = *self->bodies[b];
            if (body.gobj.Get()) {
                const cMatrix& newMat = body.gobj.Get()->mXform->GetMatrix();
                cVector newPos; { const cVector* s = &newMat.r[3]; cVector* d = &newPos; Q16(d, s); }
                float bodyMinZ = newPos.z + body.gobj.Get()->GetBBox()->mn.z;
                if (bodyMinZ <= body.waterZ) {
                    cVector newVel = newPos - body.position;
                    { float vy = newVel.y; float vx = newVel.x; body.velocity = cVector(vx, vy, 0.0f, 0.0f); }
                    body.position = newPos;
                    body.splash.NextFrame(dtime);
                    cWake_NextFrame_float_cMatrixR_cVectorR(&body.wake, dtime, newMat, newVel);
                } else {
                    body.splash.NextFrame(dtime);
                    cWake_NextFrame_float(&body.wake, dtime);
                }
            } else {
                body.splash.NextFrame(dtime);
                cWake_NextFrame_float(&body.wake, dtime);
            }
            if (body.gobj == 0) {
                if (Done(body)) self->RemoveBody(b);
            }
        }
    }
}
static inline void merge_flush_func_002B1D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1D20 */
