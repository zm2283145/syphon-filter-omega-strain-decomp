/*
 * lib/medius: 2 files, 002FD0A8-002FD180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD0A8 */
typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FD0A8;
extern unsigned char D_004908EC;
extern unsigned short D_004908F0;
extern S2FD0A8 D_005297E0;
extern int func_002FE7C0(unsigned short);
extern int func_002FDA18(unsigned short, unsigned char);
extern int func_002FE168(void);
int func_002FD0A8(unsigned char k)
{
    unsigned int i = 0;
    int r;
    if (D_004908EC != 1) return 5;
    for (; i < D_004908F0; i++) {
        if (func_002FE7C0(i) == 1) {
            r = func_002FDA18(i, k);
            if (r) return r;
        }
    }
    if (D_005297E0.flag == 1 && k == D_005297E0.flag) {
        r = func_002FE168();
        if (r) return r;
    }
    return 0;
}
/* merge_units: end func_002FD0A8 */

/* merge_units: begin func_002FD180 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))

extern int func_002FE860(int, void **);
extern int NetConn_BufferMessage(void *, int, int, int, int, int);
int func_002FD180(unsigned short a0, unsigned short id, int flags, int data, unsigned short len)
{
    void *c = 0;
    unsigned char st = D_004908EC;
    int r;
    void *dst;
    void *alt;
    int type;
    if (st != 1) return 5;
    if (data == 0) return 2;
    if (len > 0x200) return 2;
    r = func_002FE860(a0, &c);
    if (r != 0) return r;
    if (F(c, int, 8) != 8) return 0x17;
    dst = F(c, void *, 0x80);
    if (F(c, int, 4) == 1) {
        alt = F(c, void *, 0x7C);
        if (alt != 0 && F(alt, unsigned char, 5) == F(c, int, 4) && (flags & 0x50) == 0)
            dst = alt;
    }
    if (id == 0xFFFE) type = 2;
    else if (id == 0xFFFF) type = 0xB;
    else type = 3;
    return NetConn_BufferMessage(dst, type, id, data, len, (flags >> 7) & 1);
}
/* merge_units: end func_002FD180 */
