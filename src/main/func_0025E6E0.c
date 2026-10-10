#include "types.h"
typedef struct { float a; float b; float dir; char flag; } F25E6E0_t;
void func_0025E6E0(F25E6E0_t* p, unsigned char mode, float t) {
    if (t > 0.0f) {
        p->flag = 0;
        switch (mode) {
        case 2:
            p->dir = 1.0f;
            p->a = 0.0f;
            break;
        case 1:
            p->dir = -1.0f;
            p->a = t;
            break;
        }
        p->b = t;
    }
}