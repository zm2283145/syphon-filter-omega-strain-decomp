/*
 * lib/usbkb: 3 files, 00223360-00223410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00223360 */
extern int D_0048AB18;
extern char D_004F5820[];
extern void WaitSema(int);
extern void SignalSema(int);
extern int func_00223410(void);
extern int sceSifCheckStatRpc(void *);
int func_00223360(int mode, int *out)
{
    if (D_0048AB18 == -1) return -1;
    switch (mode) {
    case 0:
        WaitSema(D_0048AB18);
        *out = func_00223410();
        SignalSema(D_0048AB18);
        return 0;
    case 1:
        if (sceSifCheckStatRpc(D_004F5820) == 0) {
            *out = func_00223410();
            return 0;
        }
        return 1;
    }
    return -11;
}
/* merge_units: end func_00223360 */

/* merge_units: begin func_00223400 */
#include "types.h"

void iSignalSema(int);

void func_00223400(void)
{
    iSignalSema(D_0048AB18);
}
/* merge_units: end func_00223400 */

/* merge_units: begin func_00223410 */
typedef int (*Fn223410)(void);
typedef struct { char pad[0x90]; int mode; int f94; int f98; } G223410;
extern G223410 D_004F5780;
extern void func_00223478();
extern void func_002234D0();
extern void func_00223A48();
extern void func_00223A98();
extern void func_00223AB8();
static void * const dat_0048AB00[6] = { (void*)0x0, (void*)func_00223478, (void*)func_002234D0, (void*)func_00223A48, (void*)func_00223A98, (void*)func_00223AB8 };
int func_00223410(void)
{
    int r = 0;
    int m = D_004F5780.mode;
    if (m >= 1 && m <= 5) r = ((Fn223410*)dat_0048AB00)[m]();
    D_004F5780.mode = 0;
    D_004F5780.f98 = 0;
    return r;
}
/* merge_units: end func_00223410 */
