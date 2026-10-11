#pragma cplusplus on
#include "types.h"
struct M_00154660 { char pad[0x30]; char v[0x10]; M_00154660() {} char* Pos() { return v; } };
struct Brain_00154660 { char pad[0x5C]; int f5C; };
struct Ctl_00154660 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer(); virtual int IsAi();
    char pad4[0x1B0 - 4]; Brain_00154660* p1B0;
};
struct Act_00154660 {
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
    virtual void v55(); virtual M_00154660 GetA(); virtual void v57(); virtual void v58(); virtual M_00154660 GetB();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char GetState();
    char pad4[0x58 - 4]; Ctl_00154660* ctl;
};
struct Bits_00154660 { unsigned char lo : 6; unsigned char b6 : 1; unsigned char b7 : 1; };
struct Self_00154660 {
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
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual float GetF(int a); virtual void v81(); virtual void v82(); virtual void v83(); virtual void Reset();
    char pad4[0x2C]; int f30; char pad34[0x2C]; float f60; int f64; char pad68[0x80];
    int fE8; char padEC[8]; int fF4; char padF8[0x40]; int f138; char pad13C[5]; Bits_00154660 bits141;
    char pad142[0x1B0 - 0x142]; Brain_00154660* p1B0;
};
struct Ev_00154660 { char pad[0x24]; unsigned char b24; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern char D_004FFB50[];
extern char D_004ED9B0[];
extern int D_004ED9C0[];
int* Event_GetType(Ev_00154660* ev);
void* Service_Lookup(void* a, void* b);
void func_00163C50(void* svc, int a);
void func_0015FB20(Brain_00154660* b, int a);
Act_00154660* Object_LookupById(int* id);
int func_003CC950(Act_00154660* a);
int func_0015D790(void* v, int z);
void func_0015FA70(Brain_00154660* b, void* v, int z);
}
extern "C" unsigned char func_00154660(Self_00154660* self, Ev_00154660* ev)
{
    unsigned char handled = 0;
    int t = *Event_GetType(ev);
    if (t == D_004EE550) {
        if (ev->b24 == 0) {
            float f;
            func_00163C50(Service_Lookup(D_004FFB50, D_004ED9B0), self->f30);
            if (self->f138 >= 0) {
                func_0015FB20(self->p1B0, self->f138);
            } else if (self->fF4 != -1) {
                int id[1];
                Act_00154660* a;
                id[0] = self->fF4;
                a = Object_LookupById(id);
                if (a && (unsigned char)a->GetState() == 3) {
                    int z;
                    unsigned char r = 0;
                    Ctl_00154660* c = a->ctl;
                    if (c && c->IsPlayer())
                        r = 1;
                    if (r) {
                        z = D_004ED9C0[func_003CC950(a)];
                    } else if (a->ctl && a->ctl->IsAi()) {
                        z = a->ctl->p1B0->f5C;
                    } else {
                        z = self->p1B0->f5C;
                        z = func_0015D790(a->GetA().Pos(), z);
                    }
                    func_0015FA70(self->p1B0, a->GetB().Pos(), z);
                    self->fE8 = -1;
                }
            }
            f = self->GetF(2);
            if (self->f64 < 11) {
                self->f60 = f;
                self->f64 = 10;
                self->bits141.b6 = 0;
            }
            handled = 1;
        } else if (ev->b24 == 1) {
            if (self->f64 < 11)
                self->f64 = 10;
            handled = 1;
        }
    } else {
        int t2 = *Event_GetType(ev);
        if (t2 == D_004ED9B8) {
        if (ev->b24 == 2)
            self->Reset();
        }
    }
    return handled;
}