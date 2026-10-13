/*
 * main/989snd: 3 files, 003A7EC0-003A8040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A7EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int snd_SendIOPCommandNoWait(int, int, int, int, int);

void func_003A7EC0(int a0, int a1, int a2, int a3) {
    int loc[4];
    int t0, v0;

    t0 = 0;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 34;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 16;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    a3 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F00(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    int loc[8];
    int v0;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 33;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 24;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    *(int*)((char*)loc + 16) = t0;
    a3 = t2;
    *(int*)((char*)loc + 20) = t1;
    t0 = t3;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F50(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 97;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F80(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 23;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7FB0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 22;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

int func_003A7FE0(void) {
    return snd_SendIOPCommandNoWait(24, 0, 0, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003A7EC0 */

/* merge_units: begin func_003A8000 */
#pragma push /* merge_units */
typedef struct { int a; int c; long long b; __int128 d; int e; char pad[0xC]; } P3A8000;
#if 0 /* merge_units */
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, int y);
#endif /* merge_units */
#define snd_SendIOPCommandNoWait(a0, a1, a2, a3, a4) (snd_SendIOPCommandNoWait((a0), (a1), (int)(a2), (a3), (a4))) /* merge_units */

int func_003A8000(int a, long long b, int c, __int128 d, int e, int x, int y)
{
    P3A8000 p;
    p.a = a;
    p.b = b;
    p.c = c;
    p.d = d;
    p.e = e;
    return snd_SendIOPCommandNoWait(0x56, 0x30, &p, x, y);
}
#undef snd_SendIOPCommandNoWait /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8000 */

/* merge_units: begin func_003A8040 */
#pragma push /* merge_units */
void func_003A8040(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 21;
    t0 = 0;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A8040 */
