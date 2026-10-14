/*
 * lib/medius: 3 files, 00300918-00300A58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00300918 */
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern void func_00301AB8(unsigned char *src, unsigned int *out);
extern void *memcpy(void *d, const void *s, unsigned int n);
int func_00300918(int a, int b, int c, unsigned char *buf, unsigned int len)
{
    unsigned int h[2];
    int st = D_004908EC;
    if (st != 1) return 5;
    if (func_002FE720() != st) return 2;
    if (buf == 0) return 2;
    if (len < 9) return 0;
    func_00301AB8(buf, &h[0]);
    func_00301AB8(buf + 4, &h[1]);
    if (h[1] != len - 8) return 0;
    memcpy((void *)h[0], buf + 8, h[1]);
    return 0;
}
/* merge_units: end func_00300918 */

/* merge_units: begin func_003009C8 */
typedef struct { unsigned char type; char pad; unsigned short val; } Pfx09C8;
extern int func_003018E0(unsigned char *dst, unsigned char v);
extern int func_00301988(unsigned char *dst, unsigned short v);
int NetPacket_WritePrefix(unsigned char *dst, Pfx09C8 *p, unsigned short *len)
{
    if (dst == 0) return 2;
    if (p == 0) return 2;
    if (len == 0) return 2;
    *len = 0;
    if (func_003018E0(dst, p->type) != 0) return 7;
    (*len)++;
    if (func_00301988(dst + 1, p->val) != 0) return 7;
    *len += 2;
    return 0;
}
/* merge_units: end func_003009C8 */

/* merge_units: begin func_00300A58 */
typedef struct { unsigned char type; char pad; unsigned short val; } Pfx0A58;
extern int func_00301900(unsigned char *dst, Pfx0A58 *p);
extern int func_003019B0(unsigned char *dst, unsigned short *v);
int func_00300A58(unsigned char *dst, Pfx0A58 *p, unsigned short *len)
{
    if (dst == 0) return 2;
    if (p == 0) return 2;
    if (len == 0) return 2;
    *len = 0;
    if (func_00301900(dst, p) != 0) return 7;
    (*len)++;
    if (func_003019B0(dst + 1, &p->val) != 0) return 7;
    *len += 2;
    return 0;
}
/* merge_units: end func_00300A58 */
