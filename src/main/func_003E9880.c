#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_E98 { __int128 q; V_E98() {} V_E98& operator=(const V_E98& o) { V_E98* pd = this; const V_E98* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } return *this; } };
struct Obj_E98 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V_E98 GetNodePos(int node);
};
struct T_E98 { int a; float y; };
struct S_E98 {
    char pad[0x60];
    T_E98* x60;
    unsigned char x64;
    char pad65[3];
    int x68;
    char pad6C[4];
    V_E98 x70;
    int x80;
    unsigned char x84;
};
extern "C" {
Obj_E98* Object_LookupById(int* id);
void Object_Unregister(S_E98* s);
void Object_DeleteLater(S_E98* s, float t);
void func_003E9880(S_E98* s);
}
void func_003E9880(S_E98* s)
{
    if (s->x64) {
        Obj_E98* o = Object_LookupById(&s->x68);
        if (o) {
            s->x70 = o->GetNodePos(s->x80);
        } else {
            s->x64 = 0;
        }
    }
    if (s->x84 && s->x60->y < 0.5f) {
        Object_Unregister(s);
        Object_DeleteLater(s, 0.1f);
        s->x84 = 0;
    }
}

