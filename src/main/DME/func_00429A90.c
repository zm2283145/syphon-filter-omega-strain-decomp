#include "types.h"
typedef struct { int kind; int id; } Pk429A90;
extern unsigned char D_005723C8;
extern int D_005723F0;
extern unsigned char D_00572418[];
extern int D_00572424[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
#pragma push

void func_00429A90(Pk429A90* p) {
    unsigned char ok;
    if (!D_005723C8) D_005723C8 = 1;
    D_005723F0++;
    D_00572418[p->id] = 0;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok && p->id) D_00572424[p->id] = 0x0FFFFFFE;
    D_005723C8 = 0;
}
#pragma pop
