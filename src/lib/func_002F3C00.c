typedef struct S {
    void *h;
    int max;
    int cnt;
    char pad0C[0x14];
    int busy;
    char pad24[0x8];
    void *cur;
} S;
extern int func_002DC288(void *p);
extern void func_002DC1F0(void *p);
extern void *func_002DBD58(void *h, int id, int n);
extern int func_002DC230(void *p);
void *func_002F3C00(S *s, int id, int lim)
{
    void *p;
    if (s->busy) return 0;
    if (s->cnt >= s->max && s->max + 1 < lim) return 0;
    if (s->cur && func_002DC288(s->cur) != id) {
        func_002DC1F0(s->cur);
        s->cur = 0;
    }
    if (s->cur == 0) {
        s->cur = func_002DBD58(s->h, id, 1);
    }
    p = s->cur;
    if (p) {
        func_002DC230(p);
        s->busy = 1;
    }
    return p;
}
