/*
 * lib/medius: 3 files, 002FD980-002FDA18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FD980 */
extern unsigned char D_004908EC;
extern int func_002F6550(void);
extern int func_003010C8(int);
int func_002FD980(void)
{
    int r;
    if (D_004908EC != 1)
        return 5;
    r = func_003010C8(func_002F6550());
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD980 */

/* merge_units: begin func_002FD9B8 */
extern int func_002FE860(unsigned short, char **);
extern int func_002F6568(int, int);
int func_002FD9B8(unsigned short a, int b)
{
    char *p = 0;
    int r;
    if (b == 0) return 2;
    r = func_002FE860(a, &p);
    if (r) return r;
    r = func_003010C8(func_002F6568(*(int *)(*(char **)(p + 0x80) + 0x1C), b));
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002FD9B8 */

/* merge_units: begin func_002FDA18 */
typedef struct {
    unsigned short id; short pad;
    int f4;
    int f8;
    char pad2[0x84 - 0xC];
    void (*cb)(unsigned short, int, int, int, int);
} O;
#if 0 /* merge_units */
extern int func_002FE860(unsigned short, O **);
#endif /* merge_units */
#define func_002FE860(a0, a1) (func_002FE860((a0), (char * *)(a1))) /* merge_units */

extern int func_002FDAE8(O *, unsigned char);
extern int func_00301060(int);
extern int func_002FE7C0(unsigned short);
extern int func_00301038(O *, int);
int func_002FDA18(unsigned short id, unsigned char k)
{
    O *o[1];
    int r;
    o[0] = 0;
    r = func_002FE860(id, o);
    if (r) return r;
    r = func_002FDAE8(o[0], k);
    if (r != 0 && k == 1 && func_00301060(o[0]->f8) == 1) {
    if (o[0]->cb) {
        unsigned short h = o[0]->id;
        o[0]->cb(id, 0, 0, 0, 1);
        if (func_002FE7C0(h) == 0) return 0xB;
    }
    func_00301038(o[0], 0xB);
    }
    return r;
}
#undef func_002FE860 /* merge_units */
/* merge_units: end func_002FDA18 */
