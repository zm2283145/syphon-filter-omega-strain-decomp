#include "types.h"
extern unsigned char AnimPriority_Helper3(void* bits, int index);
extern void AnimPriority_Helper2(void* p, int index, int v);
extern void AnimPriority_Helper1(void* p);
extern void AnimPriority_Helper0(void* p, int index, unsigned char on);
extern float D_004A03E0;
typedef struct {
    char pad[0x374];
    float f374;
    char pad378[0x9C0 - 0x378];
    unsigned char b9C0;
} Sub3310;
typedef struct {
    char pad[0x320C];
    char prio[0x3310 - 0x320C];
    Sub3310* s3310;
} Act;
static inline void Prio_(char* p, signed char k) {
    unsigned char on;
    char* q = p;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, 0);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
void func_00189590(Act* a, signed char k) {
    switch (k) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        Prio_(a->prio, 5);
        if (a->s3310) {
            a->s3310->b9C0 = 0;
            a->s3310->f374 = D_004A03E0;
        }
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 21:
    case 22:
    case 27:
    case 28:
        break;
    case 29:
    case 30:
        Prio_(a->prio, k);
        break;
    case 31:
        break;
    }
}





