typedef enum { S0 } TyDDA0;
typedef struct { int f0; int f4; int f8; TyDDA0 state; char pad[0x205C]; void (*cb)(void *o, int a, int b, int c, unsigned short d, int e); } ScfConnCtx2;
typedef struct { char pad[0x58]; ScfConnCtx2 *ctx; int f5C; int f60; } ScfConn2;
void func_0030DDA0(ScfConn2 *o, int a, int b, unsigned short port)
{
    ScfConnCtx2 *c;
    if (o == 0) return;
    c = o->ctx;
    c->state = 0;
    { int e = o->f60; int f = c->f8; c->cb(o, a, f, b, port, e); }
    o->ctx->cb = 0;
    o->f60 = 0;
}