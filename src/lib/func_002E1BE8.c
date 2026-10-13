typedef struct { unsigned int v[100]; unsigned int cnt; int pos; char lock[4]; } Q;
typedef struct { char pad[0x444]; int n; } S;
extern int D_0048C450;
extern int func_002E51B8(int, S **);
extern int func_002E50C8(int, Q **);
extern int func_002DDB30(int *, int);
int __attribute__((weak, section(".dtors_drop"))) func_002DDB08(int *p0) { return 0; }
extern int func_002DCE20(int *, int);
extern int func_002DD2D8(char *);
extern int func_003060D8(void *);

void func_002E1BE8(int err, void *msg, unsigned int len, char *data, int sess, int idx)
{
    S *s = 0;
    Q *q;
    int t;
    int a;
    int b;
    int n;
    int h;

    if (func_002E51B8(sess, &s) != 0) return;
    if (s == 0) return;
    if (sess != D_0048C450) return;
    if (idx >= s->n) return;
    if (err != 0) return;
    t = 0x100;
    q = 0;
    func_002E50C8(idx, &q);
    h = len >> 1;
    if (q == 0) return;
    n = q->pos;
    q->v[n++] = h;
    if (q->cnt < 100) q->cnt++;
    func_002DDB30(&t, sess);
    if (sess == D_0048C450 && idx == t && data != 0) {
        func_002DDB08(&a);
        func_002DCE20(&b, idx);
        if (b >= h) func_002DD2D8(data + h);
    }
    if (n >= 100) n = 0;
    q->pos = n;
    func_003060D8(q->lock);
}




