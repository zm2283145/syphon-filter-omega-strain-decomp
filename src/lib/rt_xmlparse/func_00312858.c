extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EA8[];
extern char D_004B11B0[];
extern int printf(const char *, ...);
typedef struct { char pad[0x800C]; void *stack[0x100]; unsigned int sp; } Ctx3127;int func_00312858(Ctx3127 *c, void **out)
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