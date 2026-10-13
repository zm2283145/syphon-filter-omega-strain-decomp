typedef struct {
    long a;
    long b;
    int pos;
    int len;
} Req;

typedef struct {
    char pad0[8];
    int sectors;
    char padC[0x44];
    Req* reqs;
    int cap;
    int count;
    int head;
} ReqQueue;

int func_003F48B0(ReqQueue* q, Req* r)
{
    int i;
    int size;
    int more;
    more = 1;
    i = (q->cap + (q->head - q->count)) % q->cap;
    size = q->sectors << 11;
    if (q->count > 0) {
        do {
            Req* e = &q->reqs[i];
            if (e->len == 0)
                break;
            if (r->len == 0)
                break;
            if ((int)((e->pos + size - r->pos) % size < r->len) != 0) {
                int n = r->pos + r->len - e->pos;
                n = n < e->len ? n : e->len;
                e->pos = (e->pos + n) % size;
                e->len -= n;
                if (e->len == 0) {
                    if (e->a >= 0) {
                        e->a = -1;
                        e->b = -1;
                        e->pos = 0;
                        e->len = 0;
                    }
                    {
                        int c = q->count - 1;
                        q->count = c > 0 ? c : 0;
                    }
                }
            } else {
                more = 0;
            }
            i = (i + 1) % q->cap;
        } while (more);
    }
    return 0;
}


