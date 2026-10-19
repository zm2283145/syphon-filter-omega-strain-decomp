#pragma cplusplus on
#include "types.h"
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
extern "C" PNode* NpcPath_GetNode(int);
struct Self_S {
    char pad0[0x30]; GObj* obj; char pad34[0x3C]; float f70; float f74; char pad78[0x44];
    int bitsBC[8]; char padDC[4]; int fE0; char padE4[0x5B]; unsigned char f13F; char pad140; unsigned char u141;
    char pad142[0x6A]; V4* target; int f1B0;
};
extern "C" {
extern char g_Game[];
extern char g_NpcRouteMgr[];
void* Service_Lookup(void* a, void* b);
int NpcRoute_IsHeadPending(void* svc, GObj* id);
void NpcRoute_RequestToNode(int r, int node);
int NpcRoute_StartRegion(int r);
unsigned char NpcRoute_NodeSearch(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void NpcNodeSearch_SetQuery(float a, float b, void* out, int k);
}

static inline bool Visited(Self_S* self, int i)
{
    bool r = 1;
    if (i >= 0)
        { int b = NpcPath_GetNode(i)->f7C; r = (self->bitsBC[b / 32] >> (b & 31)) & 1; }
    return r;
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" unsigned char NpcAi_FiringPositionSearch(Self_S* self) {
    char e0[0x10];
    V4 pos;
    V4 tgt;
    unsigned char r = 0;
    int node = self->fE0;
    if (node >= 0 && Visited(self, node)) {
        int n = self->fE0;
        if (!NpcRoute_IsHeadPending(Service_Lookup(g_Game, g_NpcRouteMgr), self->obj)) {
            if (Visited(self, n)) NpcRoute_RequestToNode(self->f1B0, n);
        }
        r = 1; self->u141 = (self->u141 & ~1) | r;
        self->f13F = 3;
    } else if (!NpcRoute_IsHeadPending(Service_Lookup(g_Game, g_NpcRouteMgr), self->obj)) {
        void* svc;
        float dist;
        GObj* o;
        NpcNodeSearch_SetQuery(self->f70, self->f74, e0, 1);
        { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; } { V4* d = &tgt; *(__int128*)d = *(__int128*)self->target; }
        svc = Service_Lookup(g_Game, g_NpcRouteMgr);
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
        r = NpcRoute_NodeSearch(15.0f + dist, svc, o, e0, &pos, &tgt, NpcRoute_StartRegion(self->f1B0), 0x40, 1, -1);
        self->f13F = 3;
    }
    return r;
}
