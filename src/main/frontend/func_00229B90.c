#include "types.h"
#pragma opt_common_subs off
extern char D_004A62C8[];
extern char D_004A62D8[];
extern char D_004A62E8[];
extern char D_0048B2F8[];
extern char D_004A62F0[];
extern char D_0053BB70[];
extern int sprintf(char* buf, const char* fmt, ...);
extern int func_003F96B0(void* a, char* path, int b);
extern int Skel_Load(int* out, void* skel, char* name, int hog);
void func_00229B90(void* self, void* fs) {
    char path[128];
    char* names[3] = { D_004A62C8, D_004A62D8, D_004A62E8 };
    int out;
    int hog;
    char** p;
    sprintf(path, D_004A62F0, D_0048B2F8);
    hog = func_003F96B0(fs, path, 0);
    for (p = names; **p != 0; p++) {
        Skel_Load(&out, D_0053BB70, *p, hog);
    }
}