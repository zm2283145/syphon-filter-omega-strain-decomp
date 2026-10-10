#include "types.h"
typedef struct { int a; char pad[0x52]; unsigned char b56; } B8S_27A830;
extern void func_003E79C0(int);
extern void func_0027AEA0(B8S_27A830*);
extern float D_00504048;
void func_0027A830(B8S_27A830* p, float dt) {
    func_003E79C0(p->a);
    if (p->b56 == 0) {
        D_00504048 += dt;
        if (D_00504048 > 5.0f) {
            func_0027AEA0(p);
            D_00504048 = 0.0f;
        }
    }
}