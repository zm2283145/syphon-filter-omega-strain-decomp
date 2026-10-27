/*
 * SFOGame/Source/game: 5 files, 00133900-00133E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00133900 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cNextFrameMsg_dtor, D_004D9160, cMessage_dtor)
static inline void merge_flush_func_00133900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133900 */

/* merge_units: begin func_00133960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cArray_cGOBJPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cArray_cGOBJPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cObjList_cGOBJPtr_GetList(char* self) {
    return self + 4;
}
static inline void merge_flush_func_00133960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133960 */

/* merge_units: begin func_001339B0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x150];
    float fogNear;
    float fogFar;
    float zNear;
    float zFar;
    char pad2[0x20];
    float a180;
    char pad3[0xC];
    float a190;
    char pad4[0xC];
    float q1A0;
    float q1A4;
    float q1A8;
    float q1AC;
} F6Fog;
void XLib_UpdateFogParms(F6Fog* r)
{
    float a = 255.0f * (1.0f - r->fogNear);
    float b = 255.0f * (1.0f - r->fogFar);
    r->a180 = ((a + b) + (b - a) * (r->zFar + r->zNear) / (r->zFar - r->zNear)) / 2.0f;
    r->a190 = r->zFar * r->zNear * (a - b) / (r->zFar - r->zNear);
    {
        float n;
        float f;
        float d1;
        float d0;
        float dz;
        n = r->zNear;
        f = r->zFar;
        d0 = r->fogNear;
        d1 = r->fogFar;
        r->q1A0 = 8388608.0f + 16.0f * r->a180;
        dz = f - n;
        r->q1A4 = ((d0 + d1) + (d1 - d0) * (f + n) / dz) / 2.0f - 1.0f;
        r->q1A8 = f * n * (d0 - d1) / dz;
    }
    r->q1AC = 16.0f * r->a190;
}
static inline void merge_flush_func_001339B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001339B0 */

/* merge_units: begin func_00133AB0 */
#pragma push /* merge_units */
/* UpdateDarkness: for every active actor, relight its model at its
 * current position and store a 0..100 visibility level derived from the
 * gathered light colour (0 when below the darkness threshold or when the
 * actor's flashlight is on). */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Model {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad[0x4C];
    unsigned char dirty;
};
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Actor {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V GetPos();
    char p04[0x28];
    bool enabled, activated, removed; char p2F[0x15];
    int light; char p48[0x10]; Ctl* ctrl; char p5C[0x2E78 - 0x5C]; Model* model;
};
struct It {
    Actor** p;
    bool operator==(const It& o) const { Actor** b = o.p; return p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
};
struct Vec { int n; Actor** data; };
extern "C" {
extern Vec* g_ActorList;
extern V D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
extern V D_00537D80;
extern char g_LightMgr[];
extern int DarknessDecreaser;
extern int NpcDarknessDecreaser;
void* cObjList_cHumanPtr_GetList(Vec* v);
void cArray_cHumanPtr_Begin(It* out, void* v);
void cArray_cHumanPtr_End(It* out, void* v);
It* cArray_cHumanPtr_ConstIterator_ctor(It* d, It* s);
void cLightMan_Update(void* m, unsigned int mask, unsigned int flags, void* out);
int cHuman_FlashlightIsOn(Actor* a);
void UpdateDarkness(void);
}
/* VU0 compare / length: macro-mode VU0 ops have no C equivalent (asm). */
static inline unsigned char Eq4(V* a, V* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
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
static inline float Len(V* a) {
    int rv0; float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
static inline bool Alive(Actor* p) { bool r = 0; if (p->activated && p->enabled) r = 1; return r; }
static inline bool Live(Actor* p) { return !p->removed; }
static inline void Scale(V* r, const V& v, float k) { r->z = v.z / k; r->y = v.y / k; r->x = v.x / k; r->w = 0.0f; }
static inline bool Active(Actor* p) { bool r = 0; if (Alive(p) && Live(p)) r = 1; return r; }
static inline bool Player(Ctl* c) { bool yes = false; if (c) if (c->IsPlayer()) yes = true; return yes; }
static inline void Begin(It* o, Vec* v) { It t; cArray_cHumanPtr_Begin(&t, cObjList_cHumanPtr_GetList(v)); cArray_cHumanPtr_ConstIterator_ctor(o, &t); }
static inline void End(It* o, Vec* v) { It t; cArray_cHumanPtr_End(&t, cObjList_cHumanPtr_GetList(v)); cArray_cHumanPtr_ConstIterator_ctor(o, &t); }

void UpdateDarkness(void)
{
    Vec* list = g_ActorList;
    It end;
    It it;
    End(&end, list);
    Begin(&it, list);
    for (; it != end; it.p++) {
        Actor* a = *it.p;
        if (Active(a)) {
            V c; V s;
            V p = a->GetPos();
            if ((Eq4(&D_00535D40, &p) != 0) ^ 1) {
                D_00535D40 = p;
                D_00535D60 = 1;
                D_00535D61 = 1;
            }
            Model* m = a->model;
            if (m->dirty) m->Update();
            cLightMan_Update(g_LightMgr, 23, 3, (char*)m + 0x10);
            c = D_00537D80;
            Scale(&s, c, 128.0f);
            int lvl = (int)(100.0f * (1.0f - Len(&s)));
            int dec = !Player(a->ctrl) ? NpcDarknessDecreaser : DarknessDecreaser;
            if (lvl < dec)
                lvl = 0;
            else
                lvl = (int)(100.0f / (float)(100 - dec) * (float)(lvl - dec));
            if (cHuman_FlashlightIsOn(a)) lvl = 0;
            a->light = lvl;
        }
    }
}
static inline void merge_flush_func_00133AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133AB0 */

/* merge_units: begin func_00133E00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00133E00 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
typedef __int128 Q128;
int cSkeleton_GetBoneToWorldMatrix(...);         
int Physical_GetPositionPtr(...);                
int cVector_opAdd(...);                    
int func_00133EC0(...);                             
}
extern "C" void cHuman_GetActivationPoint(Q128 * volatile sp2C, char * arg1) {
    char * temp_s0;
    char * temp_s0_2;

    temp_s0 = (char *)(F_(arg1, 0x3310, int));
    if (temp_s0 != NULL) {
        if (F_(temp_s0, 0x10, unsigned char) != 0) {
            cVector_opAdd(sp2C, Physical_GetPositionPtr(temp_s0 + 0x2E0), temp_s0 + 0x380);
        } else {
            Q128 sp30[4]; cSkeleton_GetBoneToWorldMatrix(sp30, F_(temp_s0, 0x8, int), 0);
            cVector_opAdd(sp2C, func_00133EC0(sp30), temp_s0 + 0x380);
        }
        return;
    }
    temp_s0_2 = (char *)(F_(arg1, 0x50, int));
    if (F_(temp_s0_2, 0x50, unsigned char) != 0) {
        ((VC00133E00 *)(temp_s0_2))->v20();
    }
    { Q128* d = sp2C; V4Copy(d, &F_(temp_s0_2, 0x40, Q128)); (void)sp2C; }
}
static inline void merge_flush_func_00133E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133E00 */
