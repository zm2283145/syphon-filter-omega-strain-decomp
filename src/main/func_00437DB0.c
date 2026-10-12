#include "types.h"
extern int D_00497548;
extern char D_00583060[];
extern int lgAudWrite(int h, int mode, void* buf, int* len);

static inline void Copy_7DB0(void* d0, void* s0, int n0)
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
        nop
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

static inline int Samples_7DB0(int l, int b) { return l / b; }
#pragma opt_propagation off
int func_00437DB0(char* src, int count)
{
    int total = 0;
    int len = 0;
    int bps = 2;
    while (count > 0) {
        char* s;
        char* d;
        int i;
        len = count;
        if (0x400 / bps < len)
            len = 0x400 / bps;
        s = src;
        d = D_00583060;
        for (i = 0; i < len; i++) {
            Copy_7DB0(d, s, bps);
            Copy_7DB0(d + bps, s, bps);
            s += bps;
            d += bps * 2;
        }
        len = len * 2;
        lgAudWrite(D_00497548, 1, D_00583060, &len);
        if (len <= 0)
            break;
        {
            int q = Samples_7DB0(len, bps);
            src += q;
            total += q;
        }
        count -= len / bps;
    }
    return total;
}
#pragma opt_propagation reset

