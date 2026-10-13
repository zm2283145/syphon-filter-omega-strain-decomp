typedef struct {
    long a;
    long b;
    int pos;
    int len;
} Req;

typedef struct {
    char pad0[0x40];
    int lock;
    char pad44[0xC];
    Req* reqs;
    int cap;
    int count;
    int head;
} ReqQueue;

extern void WaitSema(int);
extern void SignalSema(int);
extern int func_003F48B0(ReqQueue* q, Req* r);

int func_003F4770(ReqQueue* q, Req* r)
{
    int ret = 0;
    WaitSema(q->lock);
    if (q->count < q->cap) {
        func_003F48B0(q, r);
        if (r->a >= 0 || r->b >= 0) {
            q->reqs[q->head].a = r->a;
            q->reqs[q->head].b = r->b;
            q->reqs[q->head].pos = r->pos;
            q->reqs[q->head].len = r->len;
            q->count++;
            q->head = (q->head + 1) % q->cap;
        }
        ret = 1;
    }
    SignalSema(q->lock);
    return ret;
}
