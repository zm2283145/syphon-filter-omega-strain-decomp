/*
 * lib/medius: 2 files, 002F6430-002F64A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F6430 */
extern int func_002F6770(int, char **);
extern int func_002F7CA0(int, int);
int func_002F6430(int a, int b)
{
    char *p = 0;
    int r, t;
    if (b == 0) return 2;
    r = func_002F6770(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    t = *(int *)(p + 8);
    if (t != 0 && t != 2) return 0xC;
    r = func_002F7CA0(*(int *)(p + 4), b);
    __asm__ __volatile__("");
    return r;
}
/* merge_units: end func_002F6430 */

/* merge_units: begin func_002F64A0 */
typedef struct { char b[0x38]; } B2F64A0;
extern B2F64A0 D_00525508;
extern int func_002F68F0(void);
int func_002F64A0(B2F64A0 *out)
{
    int r;
    if (out == 0) return 2;
    r = func_002F68F0();
    if (r) return r;
    *out = D_00525508;
    return r;
}
/* merge_units: end func_002F64A0 */
