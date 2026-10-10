#include "types.h"
typedef struct { char pad[0x14]; int x14; char x18[1]; } Los13AB50;
extern void func_0013AC60(void*, int, int, int*);
extern void func_0013ABC0(int*, int, int*);
void LosProvider_ClearExclusions(Los13AB50* p, unsigned int n) {
    int a[1];
    int b[1];
    a[0] = 0;
    if (n < 3) {
        func_0013AC60(p->x18, p->x14, n - 1, a);
        p->x14 = n;
    } else {
        b[0] = 0;
        func_0013ABC0(&p->x14, 2, b);
    }
}