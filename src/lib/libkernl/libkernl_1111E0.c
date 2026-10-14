/*
 * lib/libkernl: 3 files, 001111E0-00111298
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001111E0 */
#include "types.h"
extern int D_00486244;
extern void SignalSema(int);

void func_001111E0(void)
{
    SignalSema(D_00486244);
}
/* merge_units: end func_001111E0 */

/* merge_units: begin func_001111F0 */
typedef struct { int x0; int x4; } P11F0;
extern P11F0 D_004E5F80;
extern volatile int D_004E5FC0;
int D_0048623C = 0;
extern void func_001111B0(int);
extern void func_001112E0(void);
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_001111E0(void);
register int gp __asm__("$28");
int func_001111F0(int a, int b)
{
    P11F0 *p = &D_004E5F80;
    int s, old;
    func_001111B0(0x1B);
    if (D_0048623C == 0) func_001112E0();
    s = func_001161A0();
    old = D_004E5F80.x0;
    p->x4 = b;
    D_004E5F80.x0 = a;
    D_004E5FC0 = gp;
    if (s) func_001161F8();
    func_001111E0();
    return old;
}
/* merge_units: end func_001111F0 */

/* merge_units: begin func_00111298 */
typedef struct { void (*func)(void *); void *arg; } Cb11298;
#if 0 /* merge_units */
extern void *D_004E5FC0;
#endif /* merge_units */
#define D_004E5FC0 (*(void **)&D_004E5FC0) /* merge_units */

void func_00111298(int a, Cb11298 *cb)
{
    void (*f)(void *) = cb->func;
    if (f != 0) {
        void *save;
        /* $gp swap: save and load $gp, only expressible in asm */
        __asm__ volatile("move %0, $gp\n\tlw $gp, %1" : "=&r"(save) : "m"(D_004E5FC0));
        f(cb->arg);
        __asm__ volatile("move $gp, %0" : : "r"(save));
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}
#undef D_004E5FC0 /* merge_units */
/* merge_units: end func_00111298 */
