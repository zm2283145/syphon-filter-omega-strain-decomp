#include "types.h"
typedef struct { char pad[0x3314]; void* p3314; char pad2[0x352C - 0x3318]; float f352C; } A1_S;
extern float D_0048A208;
extern void func_001CA7D0(void*);
void func_001B3400(A1_S* s, float dt) {
    s->f352C += dt;
    if (s->f352C > D_0048A208) s->f352C = D_0048A208;
    if (s->p3314) func_001CA7D0(s->p3314);
}