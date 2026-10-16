/*
 * main/man: 6 files, 00392380-00392670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00392380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and retail's hand-written quad memclear as asm; the unused xx locals keep retail's dead addius.
   The member arrays' empty ctor loops are explicit do/while walks (placement-new of Arr added a null check);
   each loop starts from the previous end pointer so retail's register reuse is kept. */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V mn; V mx; Box() : mn(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f), mx(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f) {} };
struct E40 { char p[0x40]; E40() {} };
struct E50 { char p[0x50]; E50() {} };
static inline __int128 Hi(long long v) { __int128 r; asm { pcpyld r, v, zero } return r; }
static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
struct Arr {
    E40 a480[0x69];
    char pad1EC0[0x2460 - 0x1EC0];
    E50 a2460[10];
    V a2780[2];
    V a27A0[2];
    E40 a27C0[0x10];
};
struct Man {
    Box box;
    char name[0x460];
    Arr arr;
    char pad2BC0[0x1B];
    unsigned char x2BDB;
    unsigned char x2BDC;
    char pad2BDD[0xF];
    short x2BEC;
    char pad2BEE[0x16];
    int x2C04;
    char pad2C08[6];
    signed char x2C0E;
    signed char x2C0F;
    char pad2C10[0x160];
    int x2D70;
    int x2D74;
    char pad2D78[0x1C];
    short x2D94;
    char pad2D96[2];
    short x2D98;
};
extern "C" {
extern __int128 D_00493A70;
extern __int128 D_00493A80;
extern __int128 D_00493A90;
extern __int128 D_00493AA0;
extern char D_004BC428[];
void String_Copy(char* d, const char* s);
}
#pragma push
#pragma opt_unroll_loops off
extern "C" Man* ManModel_ClearAttachPoints(Man* self)
{
    self->box.mn.x = 3.4028235e38f; self->box.mn.y = 3.4028235e38f; self->box.mn.z = 3.4028235e38f; self->box.mn.w = 1.0f;
    self->box.mx.x = -3.4028235e38f; self->box.mx.y = -3.4028235e38f; self->box.mx.z = -3.4028235e38f; self->box.mx.w = 1.0f;
    { E40* p = self->arr.a480; do { p++; } while (p != self->arr.a480 + 0x69); }
    { E50* p = self->arr.a2460; E50* pe = (E50*)self->arr.a2780; do { p++; } while (p != pe);
      V* p3 = (V*)pe; V* pe3 = self->arr.a27A0; do { p3++; } while (p3 != pe3);
      V* p4 = pe3; V* pe4 = (V*)self->arr.a27C0; do { p4++; } while (p4 != pe4);
      E40* p5 = (E40*)pe4; E40* pe5 = self->arr.a27C0 + 0x10; do { p5++; } while (p5 != pe5); }
    self->x2D74 = -2;
    self->x2D70 = 0;
    {
        int keep = self->x2C04;
        QZero(self, 0x2DF);
        self->x2C04 = keep;
    }
    self->x2D94 = -1;
    self->x2D98 = 300;
    self->x2BEC = 0x80;
    self->x2C0E = -1;
    self->x2C0F = -1;
    self->x2BDB = 1;
    self->x2BDC = 1;
    String_Copy(self->name, D_004BC428);
    D_00493A70 = 0x300000000000000000000000000000;
    D_00493A80 = 0x310000000000000000000000000000;
    D_00493A90 = 0x320000000000000000000000000000;
    D_00493AA0 = 0x330000000000000000000000000000;
    self->box.mn = V(-3.5f, -3.5f, -0.5f, 1.0f);
    self->box.mx = V(3.5f, 3.5f, 7.0f, 1.0f);
    return self;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00392380 */

/* merge_units: begin func_003925C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_003925C0(void) {
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003925C0 */

/* merge_units: begin func_003925D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cPARTICLE_GOBJ: only the slots used here are named (vtable offset in comments). */
struct cPARTICLE_GOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20();
    virtual void ScaleBBox(float value); /* +0x8C */
};

/* Script native: cPARTICLE_GOBJ::ScaleBBox((float)args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cPARTICLE_GOBJ_ScaleBBox(ScriptArg* args)
{
    int part[1];
    cPARTICLE_GOBJ* obj;
    part[0] = args[1].i;
    obj = (cPARTICLE_GOBJ*)args[0].p;
    obj->ScaleBBox(*(float*)part);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003925D0 */

/* merge_units: begin func_00392610 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00392610 { int i; float f; void* p; unsigned char b; } ScriptArg_00392610;

struct cPARTICLE_GOBJ_00392610 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cPARTICLE_GOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cPARTICLE_GOBJ_Disable(ScriptArg_00392610* args)
{
    cPARTICLE_GOBJ_00392610* obj = (cPARTICLE_GOBJ_00392610*)args[0].p;
    obj->Disable(-1);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00392610 */

/* merge_units: begin func_00392640 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00392640 { int i; float f; void* p; } ScriptArg_00392640;

/* Virtual-call view of cPARTICLE_GOBJ: only the slots used here are named (vtable offset in comments). */
struct cPARTICLE_GOBJ_00392640 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int mode); /* +0x64 */
};

/* Script native: cPARTICLE_GOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cPARTICLE_GOBJ_Enable(ScriptArg_00392640* args)
{
    cPARTICLE_GOBJ_00392640* obj = (cPARTICLE_GOBJ_00392640*)args[0].p;
    obj->Enable(-1);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00392640 */

/* merge_units: begin func_00392670 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration for cPARTICLE_GOBJ (code follows the man.cc range).
 */

#include "loose03_types.h"

extern int D_0053B500;
extern int D_0053B508;          /* cPARTICLE_GOBJ script type */
extern char D_00555070[];       /* script filter context */
extern int ScriptFilter_Dispatch(void* ctx, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parent);

void ScriptType_cPARTICLE_GOBJ_Init(void) {
    ScriptType_SetParent(D_0053B508, *cGOBJ_GetScriptTypeKeyPtr());
}

int func_003926A0(void) {
    return D_0053B500;
}

int func_003926B0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00392670 */
