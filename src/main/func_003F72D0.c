#include "types.h"
typedef unsigned long u_long64;
typedef unsigned int u_int;
typedef __int128 u_long128;
typedef struct { u_long128 q; } GTag;
typedef struct { u_long128* cur; int a; int b; int c; } VifPk;
extern int D_0053820C;
extern int D_00538210;
extern unsigned char D_0055C740;
extern GTag D_004939F0;
extern GTag D_00493A00;
extern void func_00104430(VifPk* pk, u_int base);
extern void func_00104440(VifPk* pk);
extern void func_001044A8(VifPk* pk, int a, int b, int c);
extern void func_001045B8(VifPk* pk, int a, int b, int c);
extern void func_00104648(VifPk* pk, u_long128 tag);
extern void func_00104708(VifPk* pk, int reg, u_long64 data);
extern void func_00104660(VifPk* pk);
extern u_long64* func_00104630(VifPk* pk, int n);
extern void func_00104520(VifPk* pk, u_int addr, int size, int a, int b, int c);
extern void func_00104450(VifPk* pk);
u_long128* func_003F72D0(void* buf, u_long128* tex, int skip, int w, int h)
{
    GTag tagA;
    GTag tagB;
    VifPk pk;
    int tw;
    int th;
    u_long128* ret;
    int x1, y1, x0, y0, dx, dy;
    tw = D_0053820C;
    th = D_00538210;
    tagA = D_004939F0;
    tagB = D_00493A00;
    func_00104430(&pk, ((u_int)buf & 0x0FFFFFFF) | 0x20000000);
    func_00104440(&pk);
    if (!skip) {
        int i, j;
        int nx, ny;
        func_001044A8(&pk, 0, 0, 0);
        func_00104648(&pk, tagA.q);
        func_00104708(&pk, 0x50, ((u_long64)(((tw + 63) & ~63) * ((th + 31) & ~31) * sizeof(short) / 64) << 32) | ((u_long64)12 << 48));
        func_00104708(&pk, 0x52, (u_long64)16 | ((u_long64)16 << 32));
        func_00104660(&pk);
        nx = w >> 4;
        ny = h >> 4;
        for (i = 0; i < nx; i++) {
            for (j = 0; j < ny; j++) {
                u_long64* p;
                func_001044A8(&pk, 0, 0, 0);
                func_00104648(&pk, tagA.q);
                func_00104708(&pk, 0x51, ((u_long64)(u_int)(i * 16) << 32) | ((u_long64)(u_int)(j * 16) << 48));
                func_00104708(&pk, 0x53, 0);
                func_00104660(&pk);
                p = func_00104630(&pk, 4);
                p[0] = 0x40 | ((u_long64)2 << 58);
                p[1] = 0;
                func_00104520(&pk, (u_int)tex & 0x0FFFFFFF, 0x40, 0, 0, 0);
                tex += 0x40;
            }
        }
    }
    y1 = h << 4;
    x1 = w << 4;
    if (D_0055C740) {
        x0 = 0x6C00; y0 = 0x7100; dx = 0x2800; dy = 0x1E00;
    } else {
        x0 = 0x6C00; y0 = 0x7880; dx = 0x2800; dy = 0xF00;
    }
    func_001045B8(&pk, 0, 0, 0);
    ret = pk.cur - 1;
    func_00104648(&pk, tagB.q);
    func_00104708(&pk, 0x3F, 0);
    func_00104708(&pk, 0x14, 0x60);
    func_00104708(&pk, 0x06, (u_long64)(((tw + 63) & ~63) * ((th + 31) & ~31) * sizeof(short) / 64) | ((u_long64)12 << 14) | ((u_long64)10 << 26) | ((u_long64)10 << 30) | ((u_long64)1 << 35));
    func_00104708(&pk, 0x00, 0x116);
    func_00104708(&pk, 0x03, 0x80008);
    func_00104708(&pk, 0x05, (u_long64)x0 | ((u_long64)y0 << 16));
    func_00104708(&pk, 0x03, (u_long64)(x1 + 8) | ((u_long64)(y1 + 8) << 16));
    func_00104708(&pk, 0x05, (u_long64)(x0 + dx) | ((u_long64)(y0 + dy) << 16));
    func_00104660(&pk);
    func_00104450(&pk);
    return ret;
}



