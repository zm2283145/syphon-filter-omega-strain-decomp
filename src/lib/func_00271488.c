/* RPC request-end handler with per-command completion */
typedef struct { void *pkt_addr; int rpc_id; int sema_id; unsigned int mode; } RpcHdr1488;
typedef struct { RpcHdr1488 hdr; unsigned int command; void *buff; void *gp; void (*end_function)(void *); void *end_param; void *server; int sema; int x2C; } RpcClient1488;
typedef struct { char pad[0x1C]; RpcClient1488 *client; unsigned int cid; void *server; void *buff; } RpcRend1488;
extern int iSignalSema(int);
extern void _sceRpcFreePacket_void_2(void *);
static __inline__ void *ChangeGP_1488(void *gp)
{
    void *old;
    /* $gp swap: register moves only expressible in asm */
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(gp) : "memory");
    return old;
}
void _request_end_void_2(RpcRend1488 *req)
{
    RpcClient1488 *client;
    switch (req->cid) {
    case 0x8000001A:
        client = req->client;
        if (client->end_function) {
            void *gp = ChangeGP_1488(client->gp);
            client->end_function(client->end_param);
            ChangeGP_1488(gp);
        }
        iSignalSema(client->sema);
        break;
    case 0x80000019:
        client = req->client;
        client->server = req->server;
        client->buff = req->buff;
        iSignalSema(client->sema);
        break;
    case 0x8000001C:
        break;
    case 0x8000001D:
        client = req->client;
        client->x2C = (int)req->server;
        iSignalSema(client->sema);
        break;
    }
    {
        RpcClient1488 *c = req->client;
        if (c->hdr.sema_id >= 0) iSignalSema(c->hdr.sema_id);
        _sceRpcFreePacket_void_2(c->hdr.pkt_addr);
        c->hdr.pkt_addr = 0;
    }
}
