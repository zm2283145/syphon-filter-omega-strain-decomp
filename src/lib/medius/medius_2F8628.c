/*
 * lib/medius: 3 files, 002F8628-002F8908
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F8628 */
typedef struct { char b[64]; } B64;
typedef struct { char pad[0xC]; B64 *p; } X;
extern void *func_002F7D68(int, int);
extern X *func_002F7ED8(void *, int);
extern int func_002F7CE8(B64 *);
extern void *memset(void *, int, unsigned int);
int func_002F8628(int a, int b, B64 *out)
{
    void *s;
    X *x;
    int r;    s = func_002F7D68(a, b);
    if (s != 0) {
        x = func_002F7ED8(s, b);
        if (x != 0) {
            r = func_002F7CE8(x->p);
            if (r == 0) {
                *out = *x->p;
                return r;
            }
        }
    }
    if (out) memset(out, 0, 64);
    return -1;
}
/* merge_units: end func_002F8628 */

/* merge_units: begin func_002F8730 */
typedef struct { char pad[0x1C]; B64 *k0; B64 *k1; } S8730;
#if 0 /* merge_units */
extern S8730 *func_002F7D68(int, B64 *);
#endif /* merge_units */
#define func_002F7D68(a0, a1) ((S8730 *)func_002F7D68((a0), (int)(a1))) /* merge_units */

extern void func_002FB2D8(void *, int);
int func_002F8730(int a, B64 *k)
{
    S8730 *s;
    int r = -1;
    s = func_002F7D68(a, k);
    if (s != 0) {
        if (func_002F7CE8(&k[0]) != 0 || func_002F7CE8(&k[1]) != 0) {
            if (s->k0) memset(s->k0, 0, 64);
            if (s->k1) memset(s->k1, 0, 64);
        } else {
            if (s->k0 == 0) func_002FB2D8(&s->k0, 64);
            if (s->k1 == 0) func_002FB2D8(&s->k1, 64);
            *s->k0 = k[0];
            *s->k1 = k[1];
        }
        r = 0;
    }
    return r;
}
#undef func_002F7D68 /* merge_units */
/* merge_units: end func_002F8730 */

/* merge_units: begin func_002F8908 */
extern B64 D_00529640[];
extern B64 D_005296C0[];
extern B64 D_00529740[];
/* Copies the 64-byte key selected by id into out; -3 (and a zeroed out) if the key is unset. */
int func_002F8908(int id, B64 *out)
{
    B64 *k;
    register int r asm("$17");
    register B64 *kk asm("$18");

    if (id == (int)0x80000000) { r = 0; k = D_00529640; }
    else if (id == -1) { r = 0; k = D_00529740; }
    else { r = 0; k = D_005296C0; }
    kk = k; if (func_002F7CE8(kk) != 0) r = -3;
    if (out != 0) {
        *out = *kk;
        if (r != 0) memset(out, 0, 64);
    }
    return r;
}
/* merge_units: end func_002F8908 */
