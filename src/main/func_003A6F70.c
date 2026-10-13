#include "types.h"
extern void InvalidDCache(int*, char*);
extern int sceCdSync(void);
extern void func_003A85E0(void);
extern int D_0053DC00;
extern int D_0053DC18;
extern int D_00542800;
extern char D_0054283F;
static inline unsigned char Done3A6F70(void) { return !D_00542800; }
static inline int Poll3A6F70(char* k) {
    int t;
    InvalidDCache(&D_00542800, k);
    t = Done3A6F70();
    D_0053DC18 = t;
    return t;
}
#pragma push
#pragma bool off
int func_003A6F70(int wait)
{
    char* k;
    if (D_0053DC00 == 0) return sceCdSync();
    k = &D_0054283F;
    if (Poll3A6F70(k) == 1) return 0;
    if (wait == 1) return 1;
    while (D_0053DC18 == 0) {
        func_003A85E0();
        Poll3A6F70(k);
    }
    return 0;
}
#pragma pop
