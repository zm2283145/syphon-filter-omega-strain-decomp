/*
 * SFOGame/Source/playerControls: 6 files, 00249460-00249670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00249460 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { unsigned char b0; char pad[3]; int f4; int f8; char fC; } Slot49;
typedef struct { char pad[0x13C]; void* p13C; Slot49* p140; } Owner49;
typedef struct { char pad[0x3584]; Slot49* p3584; } Ctx49;
void cPlayerControls_NetDisableManualAim(Owner49* self, Ctx49* ctx) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) self->p140->b0 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249460 */

/* merge_units: begin func_00249490 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec49;
typedef struct { unsigned char b0; char pad[15]; Vec49 v; } Slot49c;
typedef struct { char pad[0x140]; Slot49c* p140; } Owner49c;
typedef struct { char pad[0x3584]; Slot49c* p3584; } Ctx49c;
void cPlayerControls_NetSetManualTarget(Owner49c* self, Ctx49c* ctx, Vec49* v) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        Slot49c* s = self->p140;
        s->b0 = 1;
        s->v.x = v->x;
        s->v.y = v->y;
        s->v.z = v->z;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249490(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249490 */

/* merge_units: begin func_002494E0 */
#pragma push /* merge_units */
void cPlayerControls_NetSetTarget(Owner49* self, Ctx49* ctx, int a2, int* a3, char t0) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        self->p140->f4 = a2;
        self->p140->f8 = *a3;
        self->p140->fC = t0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002494E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002494E0 */

/* merge_units: begin func_00249530 */
#pragma push /* merge_units */
typedef struct { unsigned short count; } Sub49b;
typedef struct { char pad[0x13C]; Sub49b* p13C; void* p140; } Owner49b;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49b;
void cPlayerControls_NetShootWeapon(Owner49b* self, Ctx49b* ctx) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49b*)q;
    }
    if (self->p13C) self->p13C->count++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249530 */

/* merge_units: begin func_00249580 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; } Obj249580;
typedef struct { void* vtable; char base[0x1C]; unsigned char b20; char p21[3]; int f24; unsigned char b28; char p29[3]; int f2C; } Msg249580;
extern char g_ActorActionMsgClass[];
extern char D_004E01A0[];
extern char D_004E0840[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cPlayerControls_SetManualAimEyesTargetInHuman(void* self, Obj249580* o, void* target) {
    if (o) {
        Msg249580 m;
        int id = o->id;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.f24 = 0x3E;
m.b28 = 5;
m.vtable = D_004E01A0;
m.b20 = 1;
m.f2C = id;
        QueueMessage_cMessageR_cSystemP_int(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    } else {
        Msg249580 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.vtable = D_004E0840;
        m.f24 = 0x3F;
        m.b20 = 1;
        m.b28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249580 */

/* merge_units: begin func_00249670 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V operator+(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
} __attribute__((aligned(16)));

struct CamView { char pad[0x10]; V dir; char pad20[0x10]; V pos; };
struct Cam { char pad[0xDA0]; CamView view; };

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_004E0140[];
#if 0 /* merge_units */
void cPlayerControls_NetSetManualTarget(void* s, void* actor, V* v);
#endif /* merge_units */
#define cPlayerControls_NetSetManualTarget(a0, a1, a2) (cPlayerControls_NetSetManualTarget((Owner49c *)(a0), (Ctx49c *)(a1), (Vec49 *)(a2))) /* merge_units */

}

struct MsgB {
    void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3];
    MsgB() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vt = D_004E0840; cMessage_dtor(this, 0); }
    void Send(void* to) { b20 = 1; QueueMessage_cMessageR_cSystemP_int(this, to, 1); }
    void Init(int t, unsigned char k) { cMessage_ctor_cMessageNameR(this, g_ActorActionMsgClass); vt = D_004E0840; type = t; kind = k; }
};
struct MsgPt : MsgB { char p2C[4]; V pt; MsgPt(const V& v) { MsgPt* p = this; p->Init(0x39, 4); p->vt = D_004E0140; p->pt = v; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgPt() {} };

extern "C" void cPlayerControls_SetManualAimWeaponTargetInHuman(void* s, Cam* cam, void* actor)
{
    CamView* cv = &cam->view;
    V pos = cv->pos;
    V dir = cv->dir;
    float k = 100.0f;
    V pt = pos + dir * k;
    MsgPt(pt).Send(actor);
    if (g_IsMultiplayer) cPlayerControls_NetSetManualTarget(s, actor, &pt);
}
#undef cPlayerControls_NetSetManualTarget /* merge_units */
static inline void merge_flush_func_00249670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00249670 */
