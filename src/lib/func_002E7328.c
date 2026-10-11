typedef struct { int busy; unsigned int n; int a; int len; char p[0x10]; int tm; unsigned char *map; char *data; } T2E7328;
typedef struct { unsigned char type, sub; unsigned short len; unsigned short x; unsigned short idx; char p[8]; int off; char payload[4]; } H2E7328;
extern int func_002E8F08(int, int, H2E7328 *, T2E7328 **);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_00306018(int *);
extern void NetMsg_GetCallback(unsigned char, unsigned char, void (**)(int, int, int, char *));
extern void func_002DD328(void *);
int func_002E7328(int a, int b, int c, H2E7328 *h)
{
    T2E7328 *t = 0;
    void (*cb)(int, int, int, char *);
    int done = 1;
    unsigned int i;
    if (h == 0) return -1;
    if (func_002E8F08(a, c, h, &t) != 0) return h->len + 0x14;
    if (t == 0) return h->len + 0x14;
    memcpy(t->data + h->off, h->payload, h->len);
    t->len += h->len;
    func_00306018(&t->tm);
    t->map[h->idx] = 1;
    for (i = 0; i < t->n; i++) {
        if (t->map[i] == 0) {
            done = 0;
            break;
        }
    }
    if (done) {
        cb = 0;
        NetMsg_GetCallback(h->type, h->sub, &cb);
        if (cb) cb(a, b, c, t->data);
        if (t->data) {
            func_002DD328(&t->data);
            t->data = 0;
        }
        if (t->map) {
            func_002DD328(&t->map);
            t->map = 0;
        }
        t->busy = 0;
    }
    return h->len + 0x14;
}