/*
 * main/FileHalPS2: 2 files, 003698B0-00369920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003698B0 */
#pragma push /* merge_units */
#include "types.h"
long long SoftFloat_FloatToDouble(float f);
int func_0011C200(int a, long long b);
long long SoftFloat_DoubleMultiply(long long a, long long b);
int func_0011C7A0(int v);
long long func_0011C858(int v);
extern int D_00572538;

/* Soft-float double helper chain on D_00572538 (constant 0x3FB0000000000000 = 0.0625). */
long long Time_GetMilliseconds(void) {
    int v = D_00572538;
    int n = func_0011C7A0(v);
    return (long long)(func_0011C858(func_0011C200(n, SoftFloat_DoubleMultiply((long long)0x3FB00000 << 0x20, SoftFloat_FloatToDouble((float)v)))) << 0x20) >> 0x20;
}
#pragma pop /* merge_units */
/* merge_units: end func_003698B0 */

/* merge_units: begin func_00369920 */
#pragma push /* merge_units */
typedef struct Dev100 {
    char pad000[0x100];
    void* port; /* 0x100 */
} Dev100;

extern void func_0026BB28(void* port, int count, unsigned char* cmd, int len, unsigned char* data);

/* Sends command 3 with two data bytes built from the flags. */
void Pad_SetVibration(Dev100* dev, int on, int mode) {
    unsigned char data[3];
    unsigned char cmd;
    cmd = 3;
    data[0] = (on != 0) + ((mode << 1) & 0xFE);
    data[1] = (mode & 0x80) != 0;
    func_0026BB28(dev->port, 1, &cmd, 2, data);
}
#pragma pop /* merge_units */
/* merge_units: end func_00369920 */
