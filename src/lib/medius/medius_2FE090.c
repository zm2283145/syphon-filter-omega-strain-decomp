/*
 * lib/medius: 2 files, 002FE090-002FE168
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FE090 */
typedef struct { char p[5]; unsigned char f5; unsigned short f6; } B;
extern unsigned char D_004908EC;
extern int func_002FE720(void);
extern int func_002FE8B0(B *);
extern int func_00300D68(B *);
extern int func_002FF308(unsigned short *, B *);
int func_002FE090(unsigned short *a, B *b, unsigned char c)
{
    int r;
    if (D_004908EC != 1) return 5;
    if (func_002FE720() != 1) return 2;
    if (func_002FE8B0(b) != 1) return 2;
    if (b->f5 != 1) return 2;
    if (*a != b->f6) return 2;
    r = func_00300D68(b);
    if (r) return r;
    if (c == 1) {
        r = func_002FF308(a, b);
        if (r) return r;
    }
    return 0;
}
/* merge_units: end func_002FE090 */

/* merge_units: begin func_002FE168 */
typedef struct { unsigned char flag; char pad[3]; int x4; void (*cb)(char *, unsigned short); } S2FE168;
extern S2FE168 D_005297E0;
extern int func_002F6268(int, unsigned char *, char *, unsigned short *);
extern int func_003010C8(int);
int func_002FE168(void)
{
    char buf[16];
    unsigned char y;
    unsigned short x;
    int r;
    unsigned char st;
    x = 0;
    y = 0;
    st = D_004908EC;
    if (st != 1) return 5;
    if (D_005297E0.flag != st) return 5;
    do {
        r = func_003010C8(func_002F6268(D_005297E0.x4, &y, buf, &x));
        if (r) return r;
        if (y != 1) break;
        if (D_005297E0.cb) D_005297E0.cb(buf, x);
    } while (y == 1);
    return 0;
}
/* merge_units: end func_002FE168 */
