typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char retried; } ScfConnCtx;
typedef struct { char pad[0x58]; ScfConnCtx *ctx; } ScfConn;
void func_0030DB38(ScfConn *o, int err)
{
    if (o == 0) return;
    if (err == 0) o->ctx->state = 2;
    else o->ctx->state = 8;
}