typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } Sema;
typedef struct { int x0[4]; int rec_id; int pkt_addr; int rpc_id; int client; int rpc_number; int send_size; int receive; int recv_size; int rmode; int server; } CallPkt;
typedef struct { int pkt_addr; int rpc_id; int sema_id; int mode; int command; int buff; int gp; int end_function; void *end_param; int server; } Client;
extern char D_004E4780[];
extern CallPkt *func_0010FD88(void *);
extern void func_0010FB10(void *, int);
extern void func_0010FE30(void *);
extern int func_0010F948(unsigned int, void *, int, void *, void *, int);
extern int CreateSema(Sema *);
extern int DeleteSema(int);
extern int WaitSema(int);
int sceSifCallRpc(Client *cd, int rpc_number, int mode, void *sendbuf, int ssize, void *recvbuf, int rsize, void *endfunc, void *efarg)
{
    Sema sema;
    CallPkt *call;
    void *gp;

    call = func_0010FD88(D_004E4780);
    if (!call)
        return -1;
    cd->end_param = efarg;
    cd->rpc_id = call->rpc_id;
    cd->pkt_addr = (int)call;
    cd->end_function = (int)endfunc;
    __asm__ volatile("move %0, $gp" : "=r"(gp));
    cd->gp = (int)gp;
    call->rpc_number = rpc_number;
    call->send_size = ssize;
    call->receive = (int)recvbuf;
    call->recv_size = rsize;
    call->pkt_addr = (int)call;
    { int s = cd->server; call->client = (int)cd; call->server = s; }

    if (!(mode & 2)) {
        if (sendbuf == recvbuf) {
            func_0010FB10(sendbuf, ssize < rsize ? rsize : ssize);
        } else {
            if (ssize > 0)
                func_0010FB10(sendbuf, ssize);
            if (rsize > 0)
                func_0010FB10(recvbuf, rsize);
        }
    }

    if (mode & 1) {
        if (!endfunc)
            call->rmode = 0;
        else
            call->rmode = 1;
        cd->sema_id = -1;
        if (func_0010F948(0x8000000A, call, 0x40, sendbuf, (void *)cd->buff, ssize))
            return 0;
        func_0010FE30(call);
        return -2;
    }

    sema.init_count = 0;
    sema.max_count = 1;
    cd->sema_id = CreateSema(&sema);
    if (cd->sema_id < 0) {
        func_0010FE30(call);
        return -3;
    }
    call->rmode = 1;
    if (!func_0010F948(0x8000000A, call, 0x40, sendbuf, (void *)cd->buff, ssize)) {
        DeleteSema(cd->sema_id);
        func_0010FE30(call);
        return -2;
    }
    WaitSema(cd->sema_id);
    DeleteSema(cd->sema_id);
    return 0;
}




