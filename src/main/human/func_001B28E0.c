#include "types.h"
typedef struct { float x, y, z, w; } B8V_1B28E0;
typedef struct { char pad[0x40]; float s; float inv; } B8S_1B28E0;
extern void Vec4_Scale(B8V_1B28E0* out, B8V_1B28E0* in, float s);
extern void func_001B29A0(B8S_1B28E0* p, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d);
void func_001B28E0(void* pv, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d) {
    B8V_1B28E0 v1;
    B8V_1B28E0 v2;
    float s;
    float inv;
    B8S_1B28E0* p = (B8S_1B28E0*)pv;
    if (p) {
        s = ((B8S_1B28E0*)pv)->s;
        Vec4_Scale(&v1, b, s);
        Vec4_Scale(&v2, d, s);
        func_001B29A0(p, a, &v1, c, &v2);
        p->s = s;
        inv = (s != 0.0f) ? 1.0f / s : 0.0f;
        p->inv = inv;
    }
}