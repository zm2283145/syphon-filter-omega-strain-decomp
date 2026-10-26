/*
 * lib/medius: 4 files, 002FAF48-002FB000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FAF48 */
typedef struct { int x0; int x4; int x8; int xC; char *x10; int *x14; } SAF48;
int rt_list_buf_place_list_head(SAF48 *s)
{
    int *p = (int *)(s->x10 + s->x4);
    int a, c;
    p[0] = 0;
    p[1] = 0;
    a = s->x4;
    c = s->xC;
    __asm__("" : "+r"(p) : "r"(a), "r"(c)); /* scheduling barrier (emits no code) */
    s->x14 = p;
    s->x4 = a + 8;
    s->xC = c + 8;
    return 0;
}
/* merge_units: end func_002FAF48 */

/* merge_units: begin func_002FAF80 */
int rt_list_buf_calc_free_space(int *o, int *out)
{
    int d;
    if (out == 0) return 2;
    d = o[2] - o[3];
    if (d < 0) d = 0;
    *out = d;
    return 0;
}
/* merge_units: end func_002FAF80 */

/* merge_units: begin func_002FAFB0 */
int rt_list_buf_calc_free_contiguous_space(unsigned int *o, unsigned int *out)
{
    if (out == 0) return 2;
    if (o[0] < o[1]) *out = o[2] - o[1];
    else if (o[1] < o[0]) *out = o[0] - o[1];
    else *out = 0;
    return 0;
}
/* merge_units: end func_002FAFB0 */

/* merge_units: begin func_002FB000 */
int rt_list_buf_calc_free_non_contiguous_space(unsigned int *o, unsigned int *out)
{
    if (out == 0) return 2;
    if (o[0] < o[1]) *out = o[2] - o[1] + o[0];
    else if (o[1] < o[0]) *out = o[0] - o[1];
    else *out = 0;
    return 0;
}
/* merge_units: end func_002FB000 */
