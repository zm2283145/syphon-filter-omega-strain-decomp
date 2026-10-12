#include "types.h"
typedef struct { char name[16]; } P_Name;
typedef struct { float x, y, z, w; } P_Sc;
typedef struct { unsigned int count; P_Name e[24]; P_Sc* sc[1]; } P_Tbl;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } P_Skl;
typedef struct { char pad0[0xA0]; char name[0x2BC4]; P_Skl* skel; } P_App;
typedef struct { char pad0[0x70]; P_App* app; } P_Obj;
extern P_Tbl D_00571300;
extern int strcmp(const char*, const char*);
extern void* memcpy(void*, const void*, unsigned int);
extern float* func_0028D5F0(void*, int);
extern void* SkelNodes_GetAt(void*, int);
extern void func_0028D580(void*, float);
extern void func_0028D530(void*, float);
extern void func_0028D4E0(void*, float);

void func_0028D300(P_Obj* o) {
    unsigned int preset;
    int i;
    for (preset = 0; preset < D_00571300.count; preset++) {
        if (!strcmp(o->app->name, D_00571300.e[preset].name)) break;
    }
    preset++;
    if (preset >= D_00571300.count) preset = 0;
    memcpy(o->app->name, D_00571300.e[preset].name, 0xF);
    for (i = 0; i < 0x15; i++) {
        P_Skl* k;
        float v;
        v = D_00571300.sc[preset][i].x; k = o->app->skel;
        func_0028D5F0(k->bones, i)[0] = v;
        if (k->hasMorph) func_0028D580(SkelNodes_GetAt(k->morph, i), v);
        v = D_00571300.sc[preset][i].y; k = o->app->skel;
        func_0028D5F0(k->bones, i)[1] = v;
        if (k->hasMorph) func_0028D530(SkelNodes_GetAt(k->morph, i), v);
        v = D_00571300.sc[preset][i].z; k = o->app->skel;
        func_0028D5F0(k->bones, i)[2] = v;
        if (k->hasMorph) func_0028D4E0(SkelNodes_GetAt(k->morph, i), v);
    }
}

