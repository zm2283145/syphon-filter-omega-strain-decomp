/*
 * SFOGame/Source/fire: 11 files, 00261BD0-002624A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00261BD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Empty / constant virtual methods.
 */

#include "types.h"

void cFireObj_Init(void) {
}

void cFireObj_Load(void) {
}

void cFireObj_Render(void) {
}
static inline void merge_flush_func_00261BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261BD0 */

/* merge_units: begin func_00261C00 */
#pragma push /* merge_units */
#include "event_toggle_send.h"

/* Post the "on" event and set the state flag. */
DEFINE_EVENT_TOGGLE_SEND(cFireObj_Enable, g_cEnableMsgClass, D_004E0880, cEnableMsg_SendEnabled, 1)
static inline void merge_flush_func_00261C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261C00 */

/* merge_units: begin func_00261C90 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int target; char pad3[8]; } Msg_261C90;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_261C90;
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_261C90* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((ToggleEventMsg *)(a0), (a1))) /* merge_units */



extern void cDisableMsg_SendDisabled(Msg_261C90* m, int id, int x);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg_261C90* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ToggleEventMsg *)(a0), (a1))) /* merge_units */



void cFireObj_Disable(S_261C90* s)
{
    Msg_261C90 msg;
    cMessage_ctor_cMessageNameR(&msg, g_cDisableMsgClass);
    msg.vtable = D_004E0860;
    msg.target = -1;
    msg.flags = 0x40;
    cDisableMsg_SendDisabled(&msg, s->id, -1);
    s->state = 0;
    msg.vtable = D_004E0860;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261C90(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261C90 */

/* merge_units: begin func_00261D10 */
#pragma push /* merge_units */
#include "fireObj_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj on/off virtuals.
 */


void cFireObj_NetEnable(cFireObj* self) {
    self->lit = 1;
}

void cFireObj_NetDisable(cFireObj* self) {
    self->lit = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D10 */

/* merge_units: begin func_00261D30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cFireObj_00261D30 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cFireObj::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cFireObj_Disable(ScriptArg* args)
{
    cFireObj_00261D30* obj = (cFireObj_00261D30*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D30 */

/* merge_units: begin func_00261D60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00261D60 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00261D60;

/* Virtual-call view of cFireObj: only the slots used here are named (vtable offset in comments). */
struct cFireObj_00261D60 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cFireObj::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cFireObj_Enable(ScriptArg_00261D60* args)
{
    cFireObj_00261D60* obj = (cFireObj_00261D60*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D60 */

/* merge_units: begin func_00261D90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj script type registration and class helpers.
 */


extern int D_004F8310;   /* cFireObj class type id */
extern int D_004F8318;   /* cFireObj script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cFireObj script type under its parent type. */
void cFireObj_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004F8318, *parent);
}

int cFireObj_getSOBJClassId(void) {
    return D_004F8310;
}

int cFireObj_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00261D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00261D90 */

/* merge_units: begin func_00261DF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    cVector& operator=(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } return *this; }
} __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
static inline void AddV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
// .set noreorder: retail has no assembler-inserted nop between mfc1 and qmtc2 (same idiom as func_003E4720.c)
static inline void ScaleV(cVector* r, const cVector* a, float s) {
    int t; const cVector* pa = a; cVector* pr = r;
    asm volatile { .set noreorder; lqc2 vf1, 0x0(pa); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(pr); .set reorder }
}
static inline cVector ScaleR(const cVector& a, float s) { cVector r; cVector* p = &r; const cVector* q = &a; ScaleV(p, q, s); return r; }
static inline cVector operator*(const cVector& a, float s) { return ScaleR(a, s); }
static inline cVector operator+(const cVector& a, const cVector& b) { cVector r; AddV(&r, &a, &b); return r; }
static inline cVector& operator-=(cVector& a, const cVector& b) { SubV(&a, &a, &b); return a; }

static inline float Abs_FO(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Max_FO(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Min_FO(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

struct cSubclassId { int id; bool operator==(const cSubclassId& o) const { int k = o.id; return id == k; } };

struct cGobjController {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7();
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual bool IsDangerAware();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void NearFire(float pct, void* src);
};

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

struct cGOBJ {
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6();
    virtual cVector GetPosition();
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5();
    virtual void Damage(void* src, int a, int b, int c, int d, int e, float amt);
    virtual void i0();
    virtual unsigned char GetState();
    char pad4[8];
    int mSerial;
    char pad10[4];
    unsigned char mVisible;
    char pad15[0x2C - 0x15];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char pad2F[0x4C - 0x2F];
    cSubclassId mSubclassId;
    char pad50[8];
    cGobjController* mController;
    cGOBJ* m_AllAboard;
    bool IsNotStreaming() const { return !(bool)mStreamingFlag; }
    bool IsActive() const {
        bool r = false;
        bool a = false;
        if (mActiveFlag && mEnabled) a = true;
        if (a && IsNotStreaming()) r = true;
        return r;
    }
};

struct cHuman : cGOBJ {
    char pad60[0x33A5 - 0x60];
    unsigned char mFlag33A5;
};

struct cSafePtr {
    cGOBJ* mPtr;
    int mSerial;
    bool SerialOK() const { return mPtr->mSerial == mSerial; }
    bool IsValid() const { return !(bool)mPtr || SerialOK(); }
    cGOBJ* Get() const { return IsValid() ? mPtr : 0; }
};

struct cLListNode {
    cLListNode* prev;
    cLListNode* next;
    cSafePtr data;
};

struct cConstLListIterator {
    cLListNode* n;
    cConstLListIterator() {}
    cConstLListIterator(cLListNode* p) : n(p) {}
    const cSafePtr& operator*() const { return n->data; }
    bool operator!=(const cConstLListIterator& o) const { return n != o.n; }
    cConstLListIterator PostInc() { cConstLListIterator t = *this; n = n->next; return t; }
    cConstLListIterator operator++(int) { cConstLListIterator r = PostInc(); return r; }
};

extern "C" cLListNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void*);

struct cLList {
    char pad0[4];
    char mImpl[4];
    cConstLListIterator begin() { cConstLListIterator it(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(mImpl)->next); return it; }
    cConstLListIterator end() { cConstLListIterator it(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(mImpl)); return it; }
};

struct cFireObj_00261DF0 : cGOBJ {
    int mDamagePerSecond;
    char pad64[0xC];
    cVector mCenter;
    cVector mRad;
    cSafePtr mOwner;
};

extern "C" {
extern float D_0048B0E8;
extern cSubclassId g_HumanActorClassKey;
extern cLList D_004F78DC;
}

static inline const cSubclassId& HumanKey() { return g_HumanActorClassKey; }
extern "C" void cFireObj_NextFrame(cFireObj_00261DF0* self, float timeStep)
{
    if (self->mEnabled) {
        if (self->mOwner.Get() && !self->mOwner.Get()->IsActive()) return;
        if (self->mOwner.Get()) {
            self->mCenter = self->mOwner.Get()->GetPosition();
            self->mCenter.z += 2.0f;
        }
        cLList& targets = D_004F78DC;
        cConstLListIterator targ = targets.begin();
        cConstLListIterator end = targets.end();
        cVector halfRad = self->mRad * 0.5f;
        cVector dangerRad = self->mRad + cVector(D_0048B0E8, D_0048B0E8, D_0048B0E8, 0.0f);
        for (; targ != end; targ++) {
            cGOBJ* gobj = (*targ).Get();
            if (!gobj) continue;
            if (!gobj->IsActive()) continue;
            if (gobj == self->mOwner.Get()) continue;
            if (!gobj->mVisible) continue;
            if (gobj->mSubclassId == HumanKey()) {
                cHuman* human = (cHuman*)gobj;
                if (human->GetState() == 3 && !human->mFlag33A5) continue;
            }
            cVector loc = gobj->GetPosition();
            loc -= self->mCenter;
            float pct = 1.0f;
            loc.x = Abs_FO(loc.x);
            loc.y = Abs_FO(loc.y);
            loc.z = Abs_FO(loc.z);
            if (loc.x < self->mRad.x && loc.y < self->mRad.y && loc.z < self->mRad.z) {
                int dmg = pct * ((float)self->mDamagePerSecond * timeStep);
                gobj->Damage(self, 3, 4, 0, 0, 0, dmg);
                if (gobj->mController) gobj->mController->NearFire(pct, self);
            } else if (gobj->mVisible) {
                bool aware = false;
                if (gobj->mController && gobj->mController->IsDangerAware()) aware = true;
                if (aware && loc.x < dangerRad.x && loc.y < dangerRad.y && loc.z < dangerRad.z) {
                    loc -= self->mRad;
                    float val = Max_FO(loc.x, loc.y);
                    val = Max_FO(val, loc.z);
                    val = Min_FO(val, D_0048B0E8);
                    float pct = (D_0048B0E8 - val) / D_0048B0E8;
                    gobj->mController->NearFire(pct, self);
                }
            }
        }
    }
}
static inline void merge_flush_func_00261DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261DF0 */

/* merge_units: begin func_00262460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Empty / constant virtual methods.
 */


int cFireObj_HandleMessage(void) {
    return 0;
}
static inline void merge_flush_func_00262460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00262460 */

/* merge_units: begin func_00262470 */
#pragma push /* merge_units */
const float D_0048B0E0[2] = { 1.4013e-42f, 0.0f };
typedef struct { char pad[0x60]; int v; } T262470;
void cFireObj_SetIntensity(T262470* p, float f) {
    p->v = (int)((float)(*(int*)D_0048B0E0) * f / 100.0f);
}
static inline void merge_flush_func_00262470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00262470 */

/* merge_units: begin func_002624A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VF24 { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void f5C(int); };
typedef struct { char pad[0xC]; int id; } Own24;
typedef struct Fire24 {
    void** vt; char pad4[0x5C]; int x60; char pad64[0x1C]; float x80, x84, x88; char pad8C[4];
    Own24* owner; int ownerId;
} Fire24;
extern "C" {
extern void* D_004DC970[];
extern int D_004F8308[];
#if 0 /* merge_units */
extern int D_0048B0E0;
#endif /* merge_units */
#define D_0048B0E0 (*(int*)&D_0048B0E0) /* merge_units */

void nGobjManager_GetNextId(int* out, int kind);
void cGOBJ_ctor(void* p, int* id, int a, int* b);
void nGobjManager_AddGOBJ(Fire24* p);
}
extern "C" Fire24* cFireObj_ctor_cGOBJP_float_float(Fire24* s, Own24* o, float r, float t)
{
    int id;
    nGobjManager_GetNextId(&id, 0xF8);
    cGOBJ_ctor(s, &id, 0x12, D_004F8308);
    s->vt = D_004DC970;
    s->ownerId = -2;
    s->owner = 0;
    s->owner = o;
    {
        int tmp;
        s->ownerId = *(o ? &o->id : (tmp = -1, &tmp));
    }
    s->x88 = r;
    s->x84 = r;
    s->x80 = r;
    s->x60 = (int)((float)D_0048B0E0 * t / 100.0f);
    nGobjManager_AddGOBJ(s);
    ((VF24*)s)->f5C(1);
    return s;
}
#undef D_0048B0E0 /* merge_units */
static inline void merge_flush_func_002624A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002624A0 */
