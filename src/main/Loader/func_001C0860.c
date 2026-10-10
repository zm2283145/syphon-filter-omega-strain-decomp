#include "types.h"
#pragma opt_common_subs off
typedef struct { char* n[3]; } SkNames_c7;
extern SkNames_c7 D_0048A310;
extern char D_0048B2F8[];
extern char D_0049EEC0[];
extern char D_0053BB70[];
extern int sprintf(char* buf, const char* fmt, ...);
extern int func_003F96B0(void* a, char* path, int b);
extern int Skel_Load(int* out, void* skel, char* name, int hog);
void Skel_LoadCommonModels(void* self, void* fs) {
    char path[128];
    SkNames_c7 names;
    int out;
    int hog;
    char** p;
    names = D_0048A310;
    sprintf(path, D_0049EEC0, D_0048B2F8);
    hog = func_003F96B0(fs, path, 0);
    for (p = names.n; **p != 0; p++) {
        Skel_Load(&out, D_0053BB70, *p, hog);
    }
}