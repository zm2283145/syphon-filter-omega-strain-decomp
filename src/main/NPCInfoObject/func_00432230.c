#pragma cplusplus on
#include "types.h"
extern "C" {
#include "net_local_id.h"
}
#pragma inline_depth(10)
struct C_432230 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual int v15();
};
typedef struct { char pad[0x58]; C_432230* f58; } Obj_432230;
typedef struct { int id; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; unsigned char b8; unsigned char b9; char padA[6]; } T_432230;
typedef struct { int f0; int f4; char pad8[0x14]; T_432230* f1C; } P_432230;
typedef struct { int x; } L_432230;
extern "C" {
extern int D_005827F8;
extern unsigned char D_00582778;
extern int D_00582A68;
extern int D_00582A78; extern int D_00582A80; extern int D_00582A88; extern int D_00582A90; extern int D_00582A98;
extern unsigned char D_005827A0; extern unsigned char D_005827A8; extern unsigned char D_005827B0; extern unsigned char D_005827B8; extern unsigned char D_005827C0;
int func_002EB650(P_432230** out, int key);
void func_004355D0(L_432230* l);
void func_00432B10(L_432230* l, T_432230* t);
void func_00432F50(L_432230* l, T_432230* t, int key);
void func_00432910(L_432230* l, T_432230* t, int key);
void func_00432750(L_432230* l, T_432230* t, int key);
void func_00432D00(L_432230* l, T_432230* t, int key);
void func_00432510(L_432230* l, T_432230* t, int key);
Obj_432230* Object_LookupById(int* id);
T_432230* func_004361C0(int* id, int f);
void func_00432230(int unused, int key, int code);
}

void func_00432230(int unused, int key, int code)
{
    P_432230* p = 0;
    int r = func_002EB650(&p, key);
    if (D_005827F8 && p && !r) {
        T_432230* t = p->f1C;
        if (code == -2 && p->f4 == NetLocalId()) {
            L_432230 lk;
            int i;
            if (!D_00582778) func_004355D0(&lk);
            D_00582A68++;
            func_00432B10(&lk, t);
            func_00432F50(&lk, t, key);
            func_00432910(&lk, t, key);
            func_00432750(&lk, t, key);
            func_00432D00(&lk, t, key);
            func_00432510(&lk, t, key);
            for (i = 0; i < 29; i++, t++) {
                int id2;
                int id;
                if (t->id != -1 && t->b4 == NetLocalId()) {
                    id = t->id;
                    Obj_432230* o = Object_LookupById(&id);
                    if (o && o->f58 && !o->f58->v15()) {
                        id2 = t->id;
                        T_432230* e = func_004361C0(&id2, 0);
                        if (e) {
                            e->id = -1;
                            e->b4 = 0xFF;
                            e->b6 = 0;
                            e->b7 = 0;
                            e->b8 = 0;
                            e->b9 = 0;
                        }
                    }
                }
            }
            if (key == D_00582A78) D_005827A0 = 1;
            if (key == D_00582A80) D_005827A8 = 1;
            if (key == D_00582A88) D_005827B0 = 1;
            if (key == D_00582A90) D_005827B8 = 1;
            if (key == D_00582A98) D_005827C0 = 1;
            D_00582A68--;
        }
    }
}