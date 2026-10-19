/*
 * lib/rt_xmlparse: 2 files, 003127A8-00312858
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003127A8 */
extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EA8[];
extern char D_004B11C0[];
extern int printf(const char *, ...);
typedef struct { char pad[0x800C]; void *stack[0x100]; unsigned int sp; } Ctx3127;int func_003127A8(Ctx3127 *c, void *item)
{
    unsigned int n;
    if (c == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x3AB, D_004B0EA8);
        return 3;
    }
    if (item == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x3AC, "NULL != p_node");
        return 3;
    }
    n = c->sp;
    if (n < 0x100) {
        c->stack[n] = item;
        c->sp = n + 1;
        return 0;
    }
    return 5;
}
/* merge_units: end func_003127A8 */

/* merge_units: begin func_00312858 */
extern char D_004B11B0[];int func_00312858(Ctx3127 *c, void **out)
{
    if (out == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x3C0, "NULL != pp_node");
        return 3;
    }
    *out = 0;
    if (c == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x3C2, D_004B0EA8);
        return 3;
    }
    if (c->sp) {
        c->sp--;
        *out = c->stack[c->sp];
        c->stack[c->sp] = 0;
    }
    return 0;
}
/* merge_units: end func_00312858 */
