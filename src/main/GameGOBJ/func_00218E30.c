#include "types.h"

typedef struct Src40 {
    char pad[0x10];
    float m[12];
} Src40;

extern void Mtx44_Set(void*, float, float, float, float, float, float, float, float,
                          float, float, float, float, float, float, float, float);

/* Forwards a 3x4 transform from src (+0x10) to Mtx44_Set with (0, 0, 0, 1) appended. */
void func_00218E30(void* self, Src40* src) {
    Mtx44_Set(self, src->m[0], src->m[1], src->m[2], src->m[3], src->m[4], src->m[5], src->m[6], src->m[7],
                  src->m[8], src->m[9], src->m[10], src->m[11], 0.0f, 0.0f, 0.0f, 1.0f);
}
