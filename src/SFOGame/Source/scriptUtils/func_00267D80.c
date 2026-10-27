#pragma cplusplus on
#include "types.h"
#include "vc_copy.h"
struct V4 {
    __int128 q;
    V4() {}
};
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
    virtual V4 GetPos();
};
struct Holder {
    char pad[0x30];
    GObj* obj;
};
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" float nScriptUtils_Distance_cPlayerP_cNPCP(Holder* h, Holder* o) {
    GObj* g = h->obj; V4 a = g->GetPos();
    V4 b = o->obj->GetPos();
    V4 d;
    V4 r;
    float ret;
    {
        V4* pr = &r; V4* pa = &a; V4* pb = &b;
        asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    }
    {
V4* dd; V4* ss; int t; __int128 x; V4* pv;
ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
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
            mtc1 t, ret
        }
    }
    return ret;
}










