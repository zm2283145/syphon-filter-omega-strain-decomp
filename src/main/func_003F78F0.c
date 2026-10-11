#include "types.h"
typedef struct { unsigned char active; char pad1[3]; int f4; int pad8; void* handle; int pad10; char sub[4]; } S78F0;
extern void func_00114558(void* h);
extern void func_0036DEC0(void* p);
int func_003F78F0(S78F0* s) {
    if (s->active) {
        if (s->f4 && s->handle) {
            func_00114558(s->handle);
            s->handle = 0;
        }
        func_0036DEC0(s->sub);
    }
    return 1;
}