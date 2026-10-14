#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
typedef struct { int f0; int f4; } P_437F90;
typedef struct { int f0; char* buf; int f8; int len; } Pkt_437F90;
extern unsigned char D_00582B88;
extern unsigned char D_00497540;
extern int D_00582CF8;
extern void* D_00583870;
extern unsigned char D_00583860;
extern int D_00582D48;
extern int D_00582D40;
extern int D_00582D38;
extern char D_00582D50[];
extern char D_00582E90[];
extern int D_00497548;
void func_002EB650(P_437F90** out, void* s);
int func_0042B1A0(int v);
int lgAudRead(int h, int mode, void* buf, int* len);
int func_0042BFD0(char* in, char* out, char* flag);

static inline int LocalIdX_7F90(void)
{
    int r = 0;
    int a = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
        r = D_00494178;
    } else { asm { .set reorder } } /* scheduling barrier: keeps the empty else block (b + nop) */
    return r;
}
static inline void Copy_7F90(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

static inline int Owner_437F90(void)
{
    P_437F90* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}


void func_00437F90(Pkt_437F90* pkt)
{
    char flag;
    int len;
    int t0 = func_0042B1A0(1);
    if (pkt && D_00582B88 && D_00497540) {
        char* dst;
        unsigned char t;
        pkt->len = 0;
        pkt->f0 = D_00582CF8;
        t = Owner_437F90() == LocalIdX_7F90();
        if (!t) t = D_00583860;
        if (!t) {
            D_00582D48 = 0;
            D_00582D40 = 0;
            return;
        }
        dst = pkt->buf;
        do {
            if (D_00582D48 < 0x140) {
                int n;
                char* b;
                len = 0;
                n = 0x140 - D_00582D48;
                b = D_00582D50 + D_00582D48;
                if (n > 0 && b) {
                    int r;
                    len = n;
                    r = lgAudRead(D_00497548, 1, b, (int*)&len);
                    if (r) {
                        len = 0;
                        if (r == 0x80000006) D_00582B88 = 0;
                    }
                }
                D_00582D48 = D_00582D48 + (int)len;
            }
            if (D_00582D48 < 0x140) {
                D_00582D38 = func_0042B1A0(1) - t0;
                return;
            }
            {
                int k = func_0042BFD0(D_00582D50, D_00582E90 + D_00582D40, &flag);
                D_00582D48 = 0;
                D_00582D40 += k;
            }
        } while (D_00582D40 < 0xC0);
        Copy_7F90(dst, D_00582E90, 0xC0);
        pkt->len = D_00582D40;
        D_00582D40 = 0;
    }
    D_00582D38 = func_0042B1A0(1) - t0;
}




