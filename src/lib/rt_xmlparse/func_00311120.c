extern void printf(const char *a, const char *b, int line, const char *c);
extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F28[];
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
