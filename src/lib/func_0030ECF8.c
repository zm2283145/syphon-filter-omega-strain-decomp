typedef struct { int f0; int f4; int f8; int state; char pad[0x205C]; void (*cb)(void *o, int a, int b, int c, unsigned short d, int e); } ScfConnCtx2;
typedef struct { char pad[0x58]; ScfConnCtx2 *ctx; int f5C; int f60; } ScfConn2;
extern int func_002FB3C0(void *pp);
int func_0030ECF8(ScfConn2 *o)
{
    func_002FB3C0(&o->ctx);
    o->ctx = 0;
    return 0;
}