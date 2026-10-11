typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char retried; } ScfConnCtx;
typedef struct { char pad[0x58]; ScfConnCtx *ctx; } ScfConn;

#define SCF_CONN_RESULT(name, okstate) void name(ScfConn *o, int err) { ScfConnCtx *c; if (o == 0) return; c = o->ctx; if (err == 0) { c->state = okstate; return; } if (c->retried == 0) { c->retried = 1; o->ctx->state = 3; return; } c->state = 8; }
SCF_CONN_RESULT(func_0030DC98, 6)
