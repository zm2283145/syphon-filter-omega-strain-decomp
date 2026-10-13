#include "types.h"
extern void InvalidDCache(int*, char*);
extern int sceCdSync(int);
extern int snd_FlushSoundCommands(void);
extern int snd_SendIOPCommandAndWait(int, int, void*);
extern int D_0053DC00;
extern int D_0053DC18;
extern int D_00542800;
extern int D_00542878;
extern char D_0054283F;
static inline unsigned char Done3A7200(void) { return !D_00542800; }
static inline int Poll3A7200(char* k) {
    int t;
    InvalidDCache(&D_00542800, k);
    t = Done3A7200();
    D_0053DC18 = t;
    return t;
}
static inline int Sync3A7200(int wait)
{
    char* k;
    int t;
    if (D_0053DC00 == 0) return sceCdSync(wait);
    k = &D_0054283F;
    t = Poll3A7200(k);
    if (t == 1) return 0;
    if (wait == 1) return 1;
    while (t == 0) {
        snd_FlushSoundCommands();
        t = Poll3A7200(k);
    }
    return 0;
}
#pragma push
#pragma bool off
void func_003A7200(void)
{
    if (D_0053DC00) {
        if (D_00542878) {
            while (snd_FlushSoundCommands()) { }
        }
        Sync3A7200(0);
        snd_SendIOPCommandAndWait(0x35, 0, 0);
        D_0053DC00 = 0;
    }
}
#pragma pop
