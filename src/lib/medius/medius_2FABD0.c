/*
 * lib/medius: 2 files, 002FABD0-002FAC20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002FABD0 */
extern int rt_list_buf_is_valid(char *);
int rt_list_buf_get_head(char *o, int *out)
{
    if (rt_list_buf_is_valid(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    return 0;
}
/* merge_units: end func_002FABD0 */

/* merge_units: begin func_002FAC20 */
extern int rt_list_buf_get_next(int);
int rt_list_buf_get_tail(char *o, int *out)
{
    int v;
    if (rt_list_buf_is_valid(o) == 0) return 2;
    *out = *(int *)(o + 0x14);
    while ((v = rt_list_buf_get_next(*out)) != 0) *out = rt_list_buf_get_next(*out);
    return 0;
}
/* merge_units: end func_002FAC20 */
