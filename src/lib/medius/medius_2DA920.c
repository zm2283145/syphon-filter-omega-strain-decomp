/*
 * lib/medius: 3 files, 002DA920-002DAA50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DA920 */
typedef struct { char b[32]; } B2DA920;
extern int func_002D9E88(char *, int);
int func_002DA920(char *s, int b, B2DA920 *out)
{
    if (!func_002D9E88(s, b)) return -1;
    *out = *(B2DA920 *)(*(char **)(s + 0x68) + 0x20);
    return 0;
}
/* merge_units: end func_002DA920 */

/* merge_units: begin func_002DA9A8 */
#if 0 /* merge_units */
extern char *func_002D9E88(char *, int);
#endif /* merge_units */
#define func_002D9E88(a0, a1) ((char *)func_002D9E88((a0), (a1))) /* merge_units */

extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(char *, int, char *, int *, int);
int func_002DA9A8(char *s, int id, int v)
{
    char buf[16];
    int w;
    char *p;
    if (id == 0xFFFF || id == *(int *)(s + 0x78)) return -1;
    p = func_002D9E88(s, id);
    if (p == 0) return -1;
    *(int *)(p + 0x38) = v;
    w = v;
    func_002EDD08(*(int *)(s + 0x64), buf, 0x11, 4);
    func_002D9A30(s, id, buf, &w, 4);
    return 0;
}
#undef func_002D9E88 /* merge_units */
/* merge_units: end func_002DA9A8 */

/* merge_units: begin func_002DAA50 */
extern int func_002D9E18(char *, int);
extern void func_002EFB28(int);
int func_002DAA50(char *o, int v)
{
    if (*(int *)(o + 0x74) && v == 0) {
        int n = *(int *)(o + 0x98);
        if (n > 0) func_002EFB28(func_002D9E18(o, n));
    }
    *(int *)(o + 0x74) = v;
    return 0;
}
/* merge_units: end func_002DAA50 */
