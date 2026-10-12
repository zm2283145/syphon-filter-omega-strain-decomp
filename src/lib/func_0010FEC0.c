/* SIF RPC request-end handler */
typedef struct { void *pkt_addr; int rpc_id; int sema_id; unsigned int mode; } RpcHdrFEC0;
typedef struct { RpcHdrFEC0 hdr; unsigned int command; void *buff; void *gp; void (*end_function)(void *); void *end_param; void *server; } RpcClientFEC0;
typedef struct { char pad[0x1C]; RpcClientFEC0 *client; unsigned int cid; void *server; void *buff; } RpcRendFEC0;
extern int func_0010D190(int);
extern void func_0010FE30(void *);
static __inline__ void *ChangeGP_FEC0(void *gp)
{
    void *old;
    /* $gp swap: register moves only expressible in asm */
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(gp) : "memory");
    return old;
}
void func_0010FEC0(RpcRendFEC0 *req)
{
    RpcClientFEC0 *client;
    switch (req->cid) {
    case 0x8000000A:
        client = req->client;
        if (client->end_function) {
            void *gp = ChangeGP_FEC0(client->gp);
            client->end_function(client->end_param);
            ChangeGP_FEC0(gp);
        }
        break;
    case 0x8000000C:
        break;
    case 0x80000009:
        client = req->client;
        client->server = req->server;
        client->buff = req->buff;
        break;
    }
    {
        RpcClientFEC0 *c = req->client;
        if (c->hdr.sema_id >= 0) func_0010D190(c->hdr.sema_id);
        func_0010FE30(c->hdr.pkt_addr);
        c->hdr.pkt_addr = 0;
    }
}
