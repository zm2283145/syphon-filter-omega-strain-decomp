#pragma cplusplus on
#include "types.h"
typedef struct { char* base; char* y; int pad8; int padC; int count; } MovieBufs;
typedef struct { int a; int b; int stopped; char pad[0xA8 - 0xC]; int state; } MovieCtx;
typedef struct { int y; int uv; } Frame;
extern "C" {
int func_0010B378(MovieCtx*);
void func_0010B398(MovieCtx*);
void func_0010B250(MovieCtx*, int, int);
void func_00127358(char*);
int func_003F5F20(MovieBufs*);
void func_003F5F70(MovieBufs*);
int func_003F72D0(char*, char*, int, int, int);
void func_003F7FD0(int, int);
void func_003F7FF0(void);
void func_004117A0(char*, int, int, int, int);
void func_004118E0(char*);
void func_00412220(char*);
}
extern char D_004BE1C0[];
extern MovieBufs D_0055C460;
extern int D_0055C5A8;
extern char D_00571CF0[];

extern "C" int Movie_DecodeThread(MovieCtx* self)
{
    int ret = 1;
    Frame f[2];
    while (!func_0010B378(self)) {
        int buf;
        if (self->state == 1) {
            ret = -1;
            func_00127358(D_004BE1C0);
            break;
        }
        while (!(buf = func_003F5F20(&D_0055C460)))
            func_003F7FF0();
        func_0010B250(self, buf, 0x654);
        if (self->stopped == 0) {
            int a = self->a;
            int b = self->b;
            int i;
            for (i = 0; i < D_0055C460.count; i++) {
                f[i].y = func_003F72D0(D_0055C460.y + i * 0x4CE40 + 0x40, D_0055C460.base + i * 0x195000, 0, a, b);
                f[i].uv = func_003F72D0(D_0055C460.y + i * 0x4CE40 + 0x26740, D_0055C460.base + i * 0x195000, 1, a, b);
            }
            func_003F7FD0(a, b);
            D_0055C5A8 = 0;
            func_004117A0(D_00571CF0, f[0].y, f[0].uv, f[1].y, f[1].uv);
            func_00412220(D_00571CF0);
        }
        func_004118E0(D_00571CF0);
        func_003F5F70(&D_0055C460);
        func_003F7FF0();
    }
    func_0010B398(self);
    return ret;
}



