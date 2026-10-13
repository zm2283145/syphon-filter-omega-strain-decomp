#pragma cplusplus on
#include "types.h"
extern "C" {
typedef struct { char p0[0x2409]; unsigned char busy; } O2C84B0;
extern volatile int D_00533870;
extern long D_00533878;
extern int D_00533888;
extern int D_0048C348;
extern unsigned char D_00587B38;
extern unsigned char D_0051EE90;
extern unsigned char D_00572528;
extern unsigned char D_005723C8;
extern void SleepThread(void);
extern void func_0010D0D0(int);
extern void func_0010D0F0(int);
extern void func_002CC260(int, int);
extern O2C84B0* DME_GetLobby(void);
extern void func_004536B0(O2C84B0* o);
}
#pragma define_section REENT_DTOR ".dtors_drop" far_absolute RX
struct Reent_84B0 { Reent_84B0(unsigned char b) { if (!b) D_005723C8 = 1; } __declspec(weak) __declspec(REENT_DTOR) ~Reent_84B0() { D_005723C8 = 0; } };

static inline int DivTime(void)
{
    int bit;
    long d;
    int q;
    int i;
    long n;
    int sh;
    int c = (int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f);
    n = D_00533878;
    n += c;
    sh = 30;
    d = 100;
    bit = 1 << sh;
    d <<= sh;
    q = 0;
    sh++;
    #pragma opt_rotateloops off
    for (i = 0; i < sh; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}

static inline void SpSave(void* dst)
{
    int n = 0x400;
    void* s = (void*)0x70000000;
    void* d = dst;
    asm {
        .set noreorder
    loop:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $a0, -0x10(d)
        .set reorder
    }
}

static inline void SpLoad(void* src)
{
    int n = 0x400;
    void* s = src;
    void* d = (void*)0x70000000;
    asm {
        .set noreorder
    loop:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $a0, -0x10(d)
        .set reorder
    }
}

#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_rotateloops off
extern "C" void func_002C84B0(int arg)
{
    char buf[0x4000];
    int last;
    void (*fp)(int, int);
    if (arg) {
        last = 0;
        for (;;) {
            D_00533878 += (int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f);
            *(volatile int*)0x10000800 = 0;
            *(volatile int*)0x10000810 = 0x82;
            D_00533870 = 0;
            if (DivTime() - last >= 10 && !D_00533888) {
                func_0010D0D0(D_0048C348);
                SpSave(buf);
                fp = func_002CC260;
                D_0051EE90 = D_00587B38 = 1;
                fp(0, 0x3039);
                unsigned char b;
                if (!D_00572528 && !(b = D_005723C8)) {
                    O2C84B0* o;
                    { Reent_84B0 r(b); }
                    o = DME_GetLobby();
                    if (o) {
                        if (!o->busy) {
                            o->busy = 1;
                            func_004536B0(o);
                            o->busy = 0;
                        } else {
                            func_004536B0(o);
                        }
                    }
                }
                D_00587B38 = 0;
                D_0051EE90 = 0;
                SpLoad(buf);
                func_0010D0F0(D_0048C348);
                last = DivTime();
            }
            SleepThread();
        }
    }
}
