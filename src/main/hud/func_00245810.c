#include "types.h"
typedef struct { char pad[0x6DC]; float a; float b; } B5bObj;
extern unsigned char D_005721C8;
extern int func_0042B1A0(int);float func_00245810(B5bObj* o) {
    float t;
    if (D_005721C8) {
        t = (float)func_0042B1A0(0) / 1000.0f;
        if (o->b < 0.0f) {
            o->b = t;
            return t;
        }
    } else {
        t = o->a;
    }
    return t;
}