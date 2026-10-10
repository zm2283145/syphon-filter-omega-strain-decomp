#include "types.h"

typedef struct Obj3A39 {
    char pad00[0x10];
    int target;            /* 0x10 */
    int unk14;             /* 0x14 */
    char pad18[4];
    unsigned char unk1C;   /* 0x1C */
} Obj3A39;

extern int D_0053B560, D_0053B564, D_0053B570, D_0053B574;
extern int D_0053B580, D_0053B584, D_0053B590, D_0053B594;
extern unsigned long long D_0053B680, D_0053B688, D_0053B690, D_0053B698;

/* Resets the object and the four global register slots (GS register tags 0x44/0x68/0x48/0x46). */
void func_003A3910(Obj3A39* obj, int target) {
    obj->target = target;
    obj->unk14 = 0;
    obj->unk1C = 0;
    D_0053B564 = 0;
    D_0053B560 = 0;
    D_0053B680 = 0x44 | ((unsigned long long)0x80 << 32);
    D_0053B574 = 0;
    D_0053B688 = 0x68 | ((unsigned long long)0x80 << 32);
    D_0053B570 = 0;
    D_0053B690 = 0x48 | ((unsigned long long)0x80 << 32);
    D_0053B584 = 0;
    D_0053B698 = 0x46 | ((unsigned long long)0x80 << 32);
    D_0053B580 = 0;
    D_0053B594 = 0;
    D_0053B590 = 0;
}
