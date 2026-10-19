/*
 * lib/usbkb: 3 files, 00223F10-00223FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00223F10 */
typedef struct { unsigned char key; char pad; unsigned short val; } K223F10;
extern K223F10 D_004A5A50[2][21];
unsigned int func_00223F10(int set, unsigned char k)
{
    unsigned int c = k;
    unsigned int i;
    int t = set & 1;
    for (i = 0; i < 21; i++) {
        if (k == D_004A5A50[t][i].key) {
            c = D_004A5A50[t][i].val | 0x4000;
            break;
        }
    }
    return c;
}
/* merge_units: end func_00223F10 */

/* merge_units: begin func_00223F80 */
typedef struct { int f0; int f4; int f8; int mode; int f10; int f14; int f18; int f1c; unsigned short s20; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } E223F80;
typedef struct { int count; E223F80* tbl; int f8; int fc; int f10; } G223F80;
extern G223F80 D_004F5780;
int func_00223F80(int i, unsigned int mode)
{
    E223F80* e; int off;
    if (i >= D_004F5780.count) return -11;
    if (mode >= 2) return -12;
    off = i * sizeof(E223F80);
    e = (E223F80*)(off + (int)D_004F5780.tbl);
    if (mode != e->mode) {
        e->f14 = 0;
        e->wr = 0;
        e->rd = 0;
        D_004F5780.f10 = 0;
        e->s20 = 0;
    }
    e->mode = mode;
    return 0;
}
/* merge_units: end func_00223F80 */

/* merge_units: begin func_00223FF0 */
typedef struct { int f0; int f4; int f8; int mode; int f10; int f14; int f18; int f1c; unsigned short s20; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } E223FF0;
typedef struct { unsigned int count; E223FF0* tbl; } G223FF0;
#if 0 /* merge_units */
extern G223FF0 D_004F5780;
#endif /* merge_units */
#define D_004F5780 (*(G223FF0*)&D_004F5780) /* merge_units */

extern int D_0048AB18;
extern unsigned char D_004F5880[];
extern char D_004F5820[];
extern char D_004F58C0[];
extern char D_004A4D80[];
extern void func_00223400(void* p);
extern void WaitSema(int s);
extern int sceSifCallRpc(void* cd, int fno, int mode, void* send, int ssize, void* recv, int rsize, void (*end)(void*), void* param);
extern int scePrintf(char* fmt, ...);
int func_00223FF0(unsigned int port)
{
    E223FF0* e;
    int r;
    if (D_0048AB18 == -1) return -1;
    if (port >= D_004F5780.count) return -11;
    D_004F5880[0] = port;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 6, 1, D_004F5880, 0x10, D_004F58C0, 0, func_00223400, 0);
    if (r != 0) {
        scePrintf(D_004A4D80, r);
        return -2;
    }
    e = &D_004F5780.tbl[port];
    e->f10 = 0;
    e->f14 = 0;
    e->s20 = 0;
    e->wr = 0;
    e->rd = 0;
    e->count = 0;
    return 0;
}
#undef D_004F5780 /* merge_units */
/* merge_units: end func_00223FF0 */
