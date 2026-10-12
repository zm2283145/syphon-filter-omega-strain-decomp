typedef struct Srv Srv;
typedef struct { int tid; int active; int x8; int start; int end; } Queue;
struct Srv { int x0; int x4; int x8; int s0C; int x10; int x14; int x18; int s1C; int s20; int s24; int s28; int s2C; int s30; int s34; int x38; Srv *link; Queue *base; };
typedef struct { int x0; int x4; int x8; int xC; int r10; int r14; int x18; int r1C; int r20; int r24; int r28; int r2C; int r30; Srv *server; } CallPkt;
extern void func_0010E010(int);
void func_00110498(CallPkt *req, void *data)
{
    Srv *server = req->server;
    Queue *base = server->base;
    if (!base->start)
        base->start = (int)server;
    else
        ((Srv *)base->end)->link = server;
    base->end = (int)server;
    { int a = req->r14; int b = req->r1C; server->s20 = a; server->s1C = b; }
    server->s24 = req->r20;
    server->s0C = req->r24;
    server->s28 = req->r28;
    server->s2C = req->r2C;
    server->s30 = req->r30;
    server->s34 = req->r10;
    if (base->tid >= 0 && base->active == 0)
        func_0010E010(base->tid);
}



