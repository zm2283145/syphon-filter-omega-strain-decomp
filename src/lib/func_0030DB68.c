typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char retried; } ScfConnCtx;
typedef struct { char pad[0x58]; ScfConnCtx *ctx; } ScfConn;
void func_0030DB68(ScfConn *o, int err, int flags)
{
    if (o == 0) return;
    if (err == 0) {
        if (flags & 0x1000) { o->ctx->state = 3; return; }
        if (flags & 0x800) { o->ctx->retried = 1; o->ctx->state = 3; return; }
    }
    o->ctx->state = 8;
}