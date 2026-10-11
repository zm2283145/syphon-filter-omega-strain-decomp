
#include "types.h"
/* Skel_ApplyScalePreset */
typedef struct { char name[16]; } Pt2_PresetName;
typedef struct { unsigned int count; Pt2_PresetName e[24]; } Pt2_PresetTbl;
typedef struct { float x, y, z, w; } Pt2_Sc;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } Pt2_Skl;
typedef struct { char pad0[0x40]; char name[0x2BC4]; Pt2_Skl* skel; char pad2C08[8]; unsigned char preset; } Pt2_App;
extern Pt2_PresetTbl D_00571300;
extern Pt2_Sc* D_00571484[];
extern char D_004BC410[];
extern int strcmp(const char*, const char*);
extern void* memcpy(void*, const void*, unsigned int);
extern float* func_0028D5F0(void*, int);
extern void* func_001AF330(void*, int);
extern void func_0028D580(void*, float);
extern void func_0028D530(void*, float);
extern void func_0028D4E0(void*, float);

int Skel_ApplyScalePreset(Pt2_App* a, int preset) {
    Pt2_Sc* s;
    int i;
    if (preset < 0) {
        for (preset = 0; (unsigned int)preset < D_00571300.count; preset++) {
            if (!strcmp(a->name, D_00571300.e[preset].name)) break;
        }
        if ((unsigned int)preset >= D_00571300.count) {
            strcmp(a->name, D_004BC410);
            return 0;
        }
    }
    if ((unsigned int)preset >= D_00571300.count) return 0;
    memcpy(a->name, D_00571300.e[preset].name, 0xF);
    s = D_00571484[preset];
    for (i = 0; i < 0x15; i++, s++) {
        Pt2_Skl* k;
        float v;
        k = a->skel; v = s->x;
        func_0028D5F0(k->bones, i)[0] = v;
        if (k->hasMorph) func_0028D580(func_001AF330(k->morph, i), v);
        k = a->skel; v = s->y;
        func_0028D5F0(k->bones, i)[1] = v;
        if (k->hasMorph) func_0028D530(func_001AF330(k->morph, i), v);
        k = a->skel; v = s->z;
        func_0028D5F0(k->bones, i)[2] = v;
        if (k->hasMorph) func_0028D4E0(func_001AF330(k->morph, i), v);
    }
    a->preset = preset;
    return preset;
}