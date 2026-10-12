#include "types.h"
typedef struct { char pad[0x3314]; void* p3314; char pad2[0x352C - 0x3318]; float f352C; } A1_S;
extern float D_0048A208;
extern void SecondaryAim_RequestRecoil(void*);
void Actor_AddShotShake(A1_S* s, float dt) {
    s->f352C += dt;
    if (s->f352C > D_0048A208) s->f352C = D_0048A208;
    if (s->p3314) SecondaryAim_RequestRecoil(s->p3314);
}