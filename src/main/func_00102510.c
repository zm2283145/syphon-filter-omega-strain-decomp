typedef struct ThrowCtx {
    char pad0[0x14];
    int x14;
    int x18;
    char pad1C[0x200 - 0x1C];
    __int128 fp;
    char pad210[0x220 - 0x210];
    unsigned int x220;
    unsigned int x224;
    int x228;
    int x22C;
    int x230;
    unsigned int x234;
} ThrowCtx;

typedef struct ActionInfo {
    int x0;
    signed char *p;
} ActionInfo;

extern unsigned char *func_00100BC0(unsigned char *p, unsigned int *out);

void func_00102510(ThrowCtx *ctx, ActionInfo *info)
{
    signed char *p = info->p;
    int f = p[0] & 0x40;
    unsigned char *q;
    ctx->x230 = p[0] & 0x20;
    ctx->x22C = p[0] & 0x10;
    ctx->x228 = p[0] & 0xF;
    q = func_00100BC0((unsigned char *)p + 1, &ctx->x220);
    q = func_00100BC0(q, &ctx->x224);
    if (ctx->x230)
        ctx->x18 = (int)ctx->fp;
    else
        ctx->x18 = ctx->x14;
    if (f)
        func_00100BC0(q, &ctx->x234);
    else
        ctx->x234 = 0;
}
