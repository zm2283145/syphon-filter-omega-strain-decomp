#include "types.h"
extern void SyncDCache(int*, char*);
extern void InvalidDCache(int*, char*);
extern int sceCdSync(int);
extern int sceCdRead(int, int, int);
extern int snd_SendIOPCommandNoWait(int, int, int*, int, int);
extern int D_0053DC00;
extern int D_0053DC10;
extern int D_0053DC18;
extern int D_00542800;
extern int D_00542810;
extern char D_0054283F;
static inline unsigned char Done3A7060(void) { return !D_00542800; }
static inline int Poll3A7060(char* k) {
    int t;
    InvalidDCache(&D_00542800, k);
    t = Done3A7060();
    D_0053DC18 = t;
    return t;
}
static inline int Check3A7060(int w) {
    if (D_0053DC00 == 0) return sceCdSync(w);
    if (Poll3A7060(&D_0054283F) == 1) return 0;
    return 1;
}
#pragma push
#pragma bool off
int snd_StreamSafeCdRead(int a, int b, int c)
{
    int buf[3];
    if (D_0053DC00 == 0) return sceCdRead(a, b, c);
    if (Check3A7060(1) == 1) return 0;
    D_00542800 = 1;
    D_00542810 = 0;
    SyncDCache(&D_00542800, &D_0054283F);
    D_0053DC10 = 1;
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    D_0053DC18 = 0;
    snd_SendIOPCommandNoWait(0x38, 0xC, buf, 0, 0);
    return 1;
}
#pragma pop
