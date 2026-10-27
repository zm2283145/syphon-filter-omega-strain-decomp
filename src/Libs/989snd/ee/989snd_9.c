/*
 * Libs/989snd/ee/989snd: 1 file, 003A8A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A8A90 */
#pragma push /* merge_units */
#include "types.h"

extern int* D_004934E0;
extern int* D_004934E4;
extern int D_004934E8;
extern int D_004934EC;
extern int* D_004934F0;
extern int* D_004934F4;
extern int* D_004934F8;
extern int* D_004934FC;
extern char D_004BCCC0[];
extern char D_004BCCE8[];
extern int D_0053DBC0[];
extern int D_0053DBE4;
extern int D_0053DF80[];
extern int D_0053EF80[];
extern int D_0053FF80[];
extern int D_00540F80[];
extern int D_00541F80[];
extern int D_005423C0[];
extern int D_00542800[];
extern int D_00542810;
extern int D_00542850[];
extern int D_00542874;
extern int D_00542878;
extern int D_00542880;
extern long long D_00542888;
extern int D_005428C0;
extern int D_00542990;
void func_0010FBC0(int);
int printf(const char*, ...);
int sceSifBindRpc(void*, unsigned int, int);
void snd_SendIOPCommandAndWait(int, int, void*);

void snd_StartSoundSystemEx(unsigned int flags)
{
    int* args[2];

    D_004934E0 = D_0053DF80;
    D_004934E4 = D_0053EF80;
    D_004934F8 = D_00541F80;
    D_004934FC = D_005423C0;
    D_004934F0 = D_0053FF80;
    D_004934F4 = D_00540F80;
    if ((unsigned long long)flags & 2)
        D_00542990 = 1;
    else
        D_00542990 = 0;
    func_0010FBC0(0);
    for (;;) {
        if (sceSifBindRpc(D_0053DBC0, 0x123456, 0) < 0) {
            printf(D_004BCCC0, D_004BCCE8, 0xB5);
            for (;;) ;
        }
        if (D_0053DBE4)
            break;
    }
    D_00542878 = 0;
    D_00542880 = 0;
    D_00542888 = 0;
    D_005428C0 = 0;
    for (;;) {
        if (sceSifBindRpc(D_00542850, 0x123457, 0) < 0) {
            printf(D_004BCCC0, D_004BCCE8, 0xCA);
            for (;;) ;
        }
        if (D_00542874)
            break;
    }
    D_00542800[0] = 0;
    D_00542810 = 0;
    D_0053DF80[0] = 0;
    D_0053EF80[0] = 0;
    D_004934E8 = 0xFFC;
    D_004934EC = 0xFFC;
    args[0] = D_00542800;
    args[1] = (int*)flags;
    snd_SendIOPCommandAndWait(0, 8, args);
}
static inline void merge_flush_func_003A8A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8A90 */
