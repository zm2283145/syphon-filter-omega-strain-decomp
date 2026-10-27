/*
 * SFOGame/Source/npc: 5 files, 0014FC00-0014FD30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014FC00 */
#pragma push /* merge_units */
#include "types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */


int cGobjController_DetermineDeathType_int(void) {
    return 0;
}

void std_list_cActiveListItemPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC00 */

/* merge_units: begin func_0014FC20 */
#pragma push /* merge_units */
typedef struct { char pad[0x120]; int priority; char pad124[0x13D - 0x124]; char kind; } Obj120;

/* Records a new kind/priority pair unless the current priority is higher. */
void cNPC_SetAimMode_eAimMode_int(Obj120* self, char kind, int priority)
{
    if (priority < self->priority)
        return;
    self->kind = kind;
    self->priority = priority;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC20 */

/* merge_units: begin func_0014FC40 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
struct CxNpcThunk { VPAD32(a) VPAD8(b) VPAD4(c) VPAD1(d)
virtual void Target(int,int);
};
extern "C" { static inline void CxNpcThunk_Call(CxNpcThunk* self,int arg) { self->Target(arg,100); } }
#pragma cplusplus off
void cNPC_SetAimMode_eAimMode(struct CxNpcThunk* self,int arg) { CxNpcThunk_Call(self,arg); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC40 */

/* merge_units: begin func_0014FC60 */
#pragma push /* merge_units */
typedef struct CxBurstActor { char pad0[0xC]; int serial; char pad10[0x3524-0x10]; void* weapons; } CxBurstActor;
typedef struct CxBurstNpc { char pad0[0x30]; CxBurstActor* actor; char pad34[0xA4-0x34]; int burst; int shots; } CxBurstNpc;
extern int cHuman_IsHoldingGun(CxBurstActor*);
extern int Libc_Rand(void);
extern int cWeapon_GetClipSize(void*,int);
void func_0014FC60(CxBurstNpc* self) {
    CxBurstActor* actor=self->actor;
    if(cHuman_IsHoldingGun(actor)) {
        void* weapons=actor->weapons;
        self->burst=(self->actor->serial&7)+3;
        if(Libc_Rand()&1)self->burst++;
        if(self->burst>cWeapon_GetClipSize(weapons,6)) {
            int n=cWeapon_GetClipSize(weapons,6)/2;
            if(n<=0)n=1;
            self->burst=n;
        }
    } else self->burst=0;
    self->shots=0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC60 */

/* merge_units: begin func_0014FD30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vc_copy.h"
struct V4 {
    __int128 q;
    V4() {}
};
struct Mat { V4 r[4]; Mat() {} };
class GObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual Mat GetMatrix();
};
struct PNode { char pad[0x7C]; int f7C; };
extern "C" PNode* cAIPathData_GetNode(int);
struct Self_S {
    char pad0[0x30]; GObj* obj; char pad34[0x3C]; float f70; float f74; char pad78[0x44];
    int bitsBC[8]; char padDC[4]; int fE0; char padE4[0x5B]; unsigned char f13F; char pad140; unsigned char u141;
    char pad142[0x6A]; V4* target; int f1B0;
};
extern "C" {
extern char g_Game[];
extern char g_NpcRouteMgr[];
void* cSystemContainer_GetSystem(void* a, void* b);
int cPathSystem_IsRequestBeingProcessed(void* svc, GObj* id);
void cPathNavigator_Request_int(int r, int node);
int cPathNavigator_GetGroupIndexForPatrolPath(int r);
unsigned char cPathSystem_RequestNodeIndexFromGroup(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void cNodePickerParameters_ctor_float_float_bool(float a, float b, void* out, int k);
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" unsigned char cNPC_MoveToAttackNode(Self_S* self) {
    char e0[0x10];
    V4 pos;
    V4 tgt;
    unsigned char r = 0;
    if (!cPathSystem_IsRequestBeingProcessed(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->obj)) {
        void* svc;
        float dist;
        GObj* o;
        cNodePickerParameters_ctor_float_float_bool(self->f70, self->f74, e0, 0);
        { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; } { V4* d = &tgt; *(__int128*)d = *(__int128*)self->target; }
        svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
        {
            V4 d;
            V4 rr;
            {
                V4* pr = &rr; V4* pa = &tgt; V4* pb = &pos;
                asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
            }
            {
                V4* dd; V4* ss; int t; __int128 x; V4* pv;
                ss = &rr; pv = &d; asm { mtc1 $zero, dist } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
                asm {
                    lqc2 vf1, 0(pv)
                    vmul.xyz vf2, vf1, vf1
                    vmulax.w ACC, vf0, vf2x
                    vmadday.w ACC, vf0, vf2y
                    vmaddz.w vf3, vf0, vf2z
                    vsqrt Q, vf3w
                    vwaitq
                    vaddq.x vf4, vf0, Q
                    qmfc2.ni t, vf4
                    mtc1 t, dist
                }
            }
        }
        { float lim = self->f74; if (dist < lim) dist = lim; }
        o = self->obj;
        r = cPathSystem_RequestNodeIndexFromGroup(15.0f + dist, svc, o, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->f1B0), 0x80, 1, -1);
        self->f13F = 4;
    }
    return r;
}
static inline void merge_flush_func_0014FD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014FD30 */
