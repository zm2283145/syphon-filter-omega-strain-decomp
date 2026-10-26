/*
 * lib/libkernl: 5 files, 0010E590-0010EA30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010E590 */
typedef struct { int x0; int x4; int x8; char *xC; } SubE590;
typedef struct { int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; SubE590 *x18; } CtxE590;
extern int kprintf(const char *, ...);
extern int sceDeci2ExRecv(int, void *, unsigned short);
extern int sceDeci2ExSend(int, void *, unsigned short);
extern void QueuePeekWriteDone(SubE590 *);
void sceTtyHandler(int cmd, int n, CtxE590 *c)
{
    int r;
    switch (cmd) {
    case 1:
    case 2:
        if (n != 0) {
            if (c->x8 + n > 0x140)
                kprintf("TTY: packet size larger than expect\n");
            {
                unsigned int off = c->x8;
                n = sceDeci2ExRecv(c->fd, c->x14 + off, n);
            }
            if (n < 0)
                kprintf("TTY: receive error");
            c->x8 += n;
        } else {
            unsigned short *h = (unsigned short *)c->x14;
            for (n = 12; n < *h; n++) {
                *c->x18->xC = c->x14[n];
                QueuePeekWriteDone(c->x18);
            }
            c->x8 = 0;
        }
        break;
    case 3:
        r = sceDeci2ExSend(c->fd, c->x10, c->x4);
        if (r < 0) {
            kprintf("TTY: send err %d\n", r);
            c->xC = 0;
        } else {
            c->x10 += r;
            c->x4 -= r;
        }
        break;
    case 4:
        if (c->x4)
            kprintf("TTY: err ti->wlen=%08x\n", c->x4);
        c->xC = 0;
        break;
    }
}
/* merge_units: end func_0010E590 */

/* merge_units: begin func_0010E728 */
typedef struct { int size; volatile int count; unsigned char *rd; unsigned char *wr; } Ring;
typedef struct { volatile int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; Ring *x18; } Ctx;
extern Ctx D_004E2950;
extern char D_004E2980[];
extern int DIntr(void);
extern int EIntr(void);
extern int sceDeci2ReqSend(int, char);
extern void sceDeci2Poll(int);
int sceTtyWrite(char *s, int n)
{
    int cnt = 0;
    int j = 0;
    int intr;
    char *p;
    char *d;
    if (D_004E2950.xC != 0)
        return -1;
    intr = DIntr();
    D_004E2950.xC = 1;
    p = (char *)((unsigned int)D_004E2980 | 0x20000000);
    D_004E2950.x10 = p;
    d = p + 12;
    while (--n != -1) {
        if (*s == '\n') {
            *d++ = '\r';
            j++;
            if (j >= 0x100)
                break;
        }
        *d = *s; j++; s++; d++;
        cnt++;
        if (j >= 0x100)
            break;
    }
    D_004E2950.x4 = j + 12;
    *(short *)p = D_004E2950.x4;
    if (sceDeci2ReqSend(D_004E2950.fd, p[7]) < 0) {
        D_004E2950.xC = 0;
        if (intr)
            EIntr();
        return -1;
    }
    while (D_004E2950.xC)
        sceDeci2Poll(D_004E2950.fd);
    if (intr)
        EIntr();
    return cnt;
}
/* merge_units: end func_0010E728 */

/* merge_units: begin func_0010E8A0 */
typedef struct { int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; Ring *x18; } Ctx_0010E8A0;
#if 0 /* merge_units */
extern Ctx_0010E8A0 D_004E2950;
#endif /* merge_units */
#define D_004E2950 (*(Ctx_0010E8A0*)&D_004E2950) /* merge_units */

extern void ByteRing_Pop(Ring *);
int sceTtyRead(char *buf, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        while (D_004E2950.x18->count == 0)
            ;
        buf[i] = *D_004E2950.x18->rd;
        ByteRing_Pop(D_004E2950.x18);
        if (buf[i] == '\n' || buf[i] == '\r')
            return i + 1;
    }
    return i;
}
#undef D_004E2950 /* merge_units */
/* merge_units: end func_0010E8A0 */

/* merge_units: begin func_0010E970 */
extern char D_004E2AC0[];
extern void FlushCache(int);
extern int sceDeci2Open(int, void *, void (*)(int, int, Ctx *));
#if 0 /* merge_units */
extern void sceTtyHandler(int, int, Ctx *);
#endif /* merge_units */
#define sceTtyHandler(a0, a1, a2) (sceTtyHandler((a0), (a1), (CtxE590 *)(a2))) /* merge_units */

extern Ring *QueueInit(int);
int sceTtyInit(void)
{
    char *b;
    FlushCache(0);
    D_004E2950.fd = sceDeci2Open(0x210, &D_004E2950, sceTtyHandler);
    if (D_004E2950.fd < 0)
        return 0;
    D_004E2950.xC = 0;
    D_004E2950.x4 = 0;
    D_004E2950.x8 = 0;
    D_004E2950.x14 = (unsigned char *)((unsigned int)D_004E2AC0 | 0x20000000);
    b = (char *)((unsigned int)D_004E2980 | 0x20000000);
    D_004E2950.x10 = b;
    *(short *)(b + 4) = 0x210;
    b[6] = 0x45;
    b[7] = 0x48;
    *(short *)(b + 2) = 0;
    *(int *)(b + 8) = 0;
    D_004E2950.x18 = QueueInit(0x100);
    return 1;
}
#undef sceTtyHandler /* merge_units */
/* merge_units: end func_0010E970 */

/* merge_units: begin func_0010EA30 */
int kputchar(int c)
{
    while (*(volatile int*)0x1000F130 & 0x8000)
        ;
    *(volatile char*)0x1000F180 = c;
    return c;
}
/* merge_units: end func_0010EA30 */
