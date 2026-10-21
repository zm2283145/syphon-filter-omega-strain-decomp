typedef struct {
    int mode; unsigned char kind; char pad5; unsigned short id; char pad8[0x40];
    unsigned int size50; unsigned int size4C; int q50[6]; int q68[7];
} NcSock;
typedef struct {
    unsigned short id; short pad2; unsigned int kind; char pad8[0x70]; NcSock *sock[2];
} NcConn;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern NcConn **D_004908F4;
extern void *memcpy(void *, const void *, unsigned int);
extern int Net_AllocZeroed(void *, int);
extern void func_002FB3C0(void *);
extern int func_00301038(NcConn *, int);
extern int func_002F52A8(void *, unsigned int, int);
extern int func_00301220(unsigned int);

int NetConn_Allocate(unsigned short *out, unsigned int kind, unsigned int rx, unsigned int tx)
{
    NcConn **tab = 0;
    NcSock *s = 0;
    unsigned short i = 0;
    unsigned short n;
    int r;

    if (D_004908EC != 1) return 5;
    if (!out) return 2;
    if (kind >= 2) return 2;
    if (!rx) return 2;
    if (!tx) return 2;
    if (D_004908F0 != 0) {
        for (i = 0; i < D_004908F0; i++)
            if (D_004908F4[i] == 0) break;
    } else i = 0;
    if (i == D_004908F0) {
        n = D_004908F0 + 10;
        tab = 0;
        if (Net_AllocZeroed(&tab, n * 4)) return 8;
        if (D_004908F4) {
            memcpy(tab, D_004908F4, D_004908F0 * 4);
            func_002FB3C0(&D_004908F4);
        }
        D_004908F0 = n;
        D_004908F4 = tab;
    }
    if (Net_AllocZeroed(&tab, 0x98)) return 8;
    D_004908F4[i] = (NcConn *)tab;
    D_004908F4[i]->id = i;
    D_004908F4[i]->kind = kind;
    if ((r = func_00301038(D_004908F4[i], 0)) != 0) return r;
    if (kind == 1) {
        rx >>= 1;
        tx >>= 1;
    }
    if (rx < 0x248) rx = 0x248;
    if (tx < 0x248) tx = 0x248;
    if (kind < 2) {
        s = 0;
        if (Net_AllocZeroed(&s, 0x2D4)) return 8;
        if (!s) return 9;
        s->kind = 1;
        s->id = i;
        s->mode = 0;
        if (func_002F52A8(s->q68, rx, 0)) return 0x15;
        s->size50 = rx;
        if (func_002F52A8(s->q50, tx, 0)) return 0x15;
        s->size4C = tx;
        D_004908F4[i]->sock[0] = s;
    }
    if (kind == 1) {
        s = 0;
        if (Net_AllocZeroed(&s, 0x2D4)) return 8;
        if (!s) return 9;
        s->kind = kind;
        s->id = i;
        s->mode = kind;
        if (func_002F52A8(s->q68, rx, 0)) return 0x15;
        s->size50 = rx;
        if (func_002F52A8(s->q50, tx, 0)) return 0x15;
        s->size4C = tx;
        D_004908F4[i]->sock[1] = s;
    }
    if ((r = func_00301220(rx)) != 0) return r;
    if ((r = func_00301220(tx)) != 0) return r;
    if ((r = func_00301038(D_004908F4[i], 1)) != 0) return r;
    *out = i;
    return 0;
}

