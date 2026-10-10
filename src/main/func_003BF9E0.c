#include "types.h"
typedef struct { char pad[3]; unsigned char type; char pad2[0x14]; int f18; } B4Track;
typedef struct { int f0; B4Track** tracks; } B4Anim;
typedef struct { char pad[0x60]; int idx; B4Anim* anim; } B4Obj5;
extern char* func_00183B20(B4Track*, int*);
float func_003BF9E0(B4Obj5* p) {
    int idx = p->idx;
    B4Track* t = p->anim->tracks[0];
    float* v;
    if (t->type < 4) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(func_00183B20(t, k) + idx * 64);
    } else if (t->type < 5) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(func_00183B20(t, k) + idx * 32);
    } else {
        int k[1];
        k[0] = t->f18;
        v = (float*)(func_00183B20(t, k) + idx * 16);
    }
    if (*v > 0.0f) return 1.0f;
    return -1.0f;
}