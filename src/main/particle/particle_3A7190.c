/*
 * main/particle: 3 files, 003A7190-003A7310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A7190 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; int b; int c; int d; int e; int f; int g; int h; } P3A7190;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, long long y);
int snd_PlayVAGStream(int a, int b, unsigned short c, unsigned short d, int ch, int dh, int e, int f, int g, int h, int x, long long y)
{
    P3A7190 p;
    p.a = a;
    p.b = b;
    p.c = (ch << 16) | c;
    p.d = (dh << 16) | d;
    p.e = e;
    p.f = f;
    p.g = g;
    p.h = h;
    return snd_SendIOPCommandNoWait(0x2C, 0x20, &p, x, y);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A7190 */

/* merge_units: begin func_003A7200 */
#pragma push /* merge_units */
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
void snd_CloseVAGStreaming(void)
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
#pragma pop /* merge_units */
/* merge_units: end func_003A7200 */

/* merge_units: begin func_003A7310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * IOP sound command wrappers (989snd library interface).
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int cmd, int size, int* args, int a3, int t0);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (void *)(a2), (a3), (long long)(a4))) /* merge_units */


int snd_FreeVAGStreamChannels(void) {
    return snd_SendIOPCommandNoWait(52, 0, 0, 0, 0);
}

void snd_SetVAGStreamChannelRange(int a0, int a1, int a2) {
    int args[4];

    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    snd_SendIOPCommandNoWait(98, 12, args, 0, 0);
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A7310 */
