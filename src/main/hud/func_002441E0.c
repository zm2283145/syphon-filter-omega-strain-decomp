#include "types.h"
typedef struct { char pad[0x6C]; void* widget; } H_2441E0;
extern void func_003F44E0(void* w, float v);
void func_002441E0(H_2441E0* h, int cur, int max) {
    if (h->widget != 0) {
        func_003F44E0(h->widget, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}