typedef struct Ctx {
    char pad0[0x14];
    int x14;
    char *x18;
    char pad1C[0x120 - 0x1C];
    __int128 regs[14];
    __int128 fp;
    char pad210[0x220 - 0x210];
    unsigned int x220;
    unsigned int x224;
    int x228;
    int x22C;
    int x230;
    unsigned int x234;
    char pad238[0x288 - 0x238];
    int iregs[16];
} Ctx;

typedef struct Info {
    int x0;
    signed char *p;
} Info;

int func_001025D0(Ctx *ctx, Info *info)
{
    unsigned long off;
    int flag;
    unsigned long cfa;
    unsigned long n;
    __int128 *sp;
    int i;
    unsigned long m;
    int *ip;
    int ret;

    cfa = ctx->x220;
    off = ctx->x224;
    flag = info->p[0] & 0x40;
    n = ctx->x228;
    if (flag) {
        m = ctx->x234;
        ip = (int *)(ctx->x18 + off + ((m * sizeof(int) + 15) & ~15));
        sp = (__int128 *)((unsigned long)ip + n * sizeof(__int128));
    } else {
        sp = (__int128 *)(ctx->x18 + off + n * sizeof(__int128));
    }
    if (ctx->x230)
        sp++;
    ret = *(int *)sp;
    if (ctx->x230) {
        sp--;
        ctx->fp = *sp;
    } else if (n == 9) {
        sp--;
        n--;
        ctx->fp = *sp;
    }
    sp -= n;
    for (i = 0; i < n; i++)
        ctx->regs[i] = *sp++;
    ctx->x14 = (int)(ctx->x18 + cfa);
    if (flag) {
        ip -= m;
        for (i = 0; i < m; i++)
            ctx->iregs[i] = *ip++;
    }
    return ret;
}







