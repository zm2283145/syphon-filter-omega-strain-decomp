/*
 * lib/medius: 2 files, 002ED448-002ED4D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ED448 */
extern int D_0048C458;
extern unsigned int D_0058DF78;
extern int D_00590318[];
extern int D_00598358[];
extern int D_00598398[];
int func_002ED448(int *out, int a, int b, int c)
{
    int i;
    if (D_0048C458 == 0) return 0x11;
    if (D_0058DF78 >= 0x10) return 0x16;
    if (out == 0) return 0x17;
    *out = -1;
    i = D_0058DF78;
    *out = i;
    D_00598358[i] = a;
D_00598398[i] = b;
D_00590318[i] = c;
    D_0058DF78++;
    return 0;
}
/* merge_units: end func_002ED448 */

/* merge_units: begin func_002ED4D0 */
extern int D_0058DF74;
extern int D_00590218[];
int func_002ED4D0(int *out, int v)
{
    int idx;
    if (D_0048C458 == 0) return 0x11;
    if (out == 0) return 0x17;
    idx = D_0058DF74;
    *out = idx;
    D_00590218[idx] = v;
    D_0058DF74++;
    return 0;
}
/* merge_units: end func_002ED4D0 */
