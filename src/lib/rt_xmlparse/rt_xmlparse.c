/*
 * lib/rt_xmlparse: 4 files, 00311018-00311120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00311018 */
extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
extern void printf(const char* a, const char* b, int line, const char* c);
int func_00311018(char* ctx, int v)
{
    if (ctx == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x148, D_004B0F28);
        return 3;
    }
    *(int*)(ctx + 0x8C18) = v;
    return 0;
}
/* merge_units: end func_00311018 */

/* merge_units: begin func_00311070 */
int func_00311070(char* ctx, int v)
{
    if (ctx == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x157, D_004B0F28);
        return 3;
    }
    *(int*)(ctx + 0x8C20) = v;
    return 0;
}
/* merge_units: end func_00311070 */

/* merge_units: begin func_003110C8 */
int func_003110C8(char* ctx, int v)
{
    if (ctx == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x166, D_004B0F28);
        return 3;
    }
    *(int*)(ctx + 0x8C24) = v;
    return 0;
}
/* merge_units: end func_003110C8 */

/* merge_units: begin func_00311120 */
typedef struct {
    char pad0[0x8C1C];
    unsigned char flag;
    char pad1[0x8C28 - 0x8C1D];
    int value;
} Ctx;
/* Stores a flag byte and value into the parser context; logs and returns 3 on NULL. */
int func_00311120(Ctx *raw, unsigned char flag, int value)
{
    register Ctx *ctx asm("$3");
    if (raw == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x176, D_004B0F28);
        return 3;
    }
    ctx = raw;
    ctx->flag = flag;
    ctx->value = value;
    return 0;
}
/* merge_units: end func_00311120 */
