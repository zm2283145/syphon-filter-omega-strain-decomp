#pragma cplusplus on
#include "types.h"
struct Cam_249B10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void GetMatrix(void* m, int a, int b); };
struct Hit_249B10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual unsigned char Kind(); };
typedef struct {
    int a0; void* mat; int a8; unsigned char ac; int b0; float range; int b8; int bc; unsigned char c0;
    int c4; float c8; unsigned char cc; unsigned char cd; int kind; int d4; Hit_249B10* hit; char padDC[0x14];
} Probe_249B10;
typedef struct { float m[16]; } Mat_249B10;
typedef struct { char pad[0xF4]; float beam; } Wpn_249B10;
typedef struct { char pad[0x58]; Cam_249B10* cam; char pad5C[0x3524 - 0x5C]; Wpn_249B10* wpn; } Pl_249B10;
typedef struct { char pad[0xC]; int id; } HitData_249B10;
extern "C" {
extern char* D_004FFC2C;
extern char D_004A75B8[];
float Weapon_GetHeldRange(Wpn_249B10* w);
float Flashlight_BeamProbe(Pl_249B10* p, Probe_249B10* pr, int n);
int TeamTable_AreEnemies(Pl_249B10* p, Hit_249B10* h);
void func_002449D0(char* h);
void func_002449A0(char* h);
void func_00244960(char* h, float f);
int Loc_LookupText(char* key);
void func_00242FA0(char* a0, int* a1, float f0, float f1, int text, int a3, signed char c0, signed char c1);
}
static inline bool IsKind23(Hit_249B10* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
extern "C" Hit_249B10* func_00249B10(int a0, int a1, Pl_249B10* p)
{
    Probe_249B10 pr;
    Mat_249B10 m;
    float r;
    bool show;
    char* h;
    pr.c0 = 0;
    pr.bc = 0;
    pr.ac = 0;
    pr.b0 = -1;
    pr.cc = 1;
    pr.a8 = 0;
    pr.c4 = 0;
    pr.cd = 1;
    p->cam->GetMatrix(&m, 0, 1);
    pr.mat = &m;
    pr.c8 = 0.2f;
    pr.range = Weapon_GetHeldRange(p->wpn);
    r = Flashlight_BeamProbe(p, &pr, 0x10);
    if (pr.hit && !TeamTable_AreEnemies(p, pr.hit)) {
        pr.kind = 0;
        func_002449D0(D_004FFC2C);
    } else {
        func_002449A0(D_004FFC2C);
    }
    show = pr.kind == 2 && !IsKind23(pr.hit);
    h = D_004FFC2C;
    if (pr.kind == 0)
        func_00244960(h, 1.0f);
    else
        func_00244960(h, 0.0f);
    if (show) {
        int* idp = &((HitData_249B10*)pr.hit)->id;
        func_00242FA0(h, idp, 0.1f, 1.0f, Loc_LookupText(D_004A75B8), 0, 0, 0);
    }
    p->wpn->beam = r;
    return pr.hit;
}




