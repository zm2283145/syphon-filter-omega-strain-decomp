typedef struct N N;
struct N { N *next; N *prev; };
typedef struct { char p[0x64]; void *f64; int f68; N *f6C; } S;
typedef struct { char p[0x10]; int f10; int f14; } R;
extern N *func_002F2FA8(N *, int);
extern int func_002F3198(N *, int);
extern N *func_002F3068(S *, R *);
extern int func_002EF748(void *, N *);
extern void *func_002D9E18(S *, int);
extern void *func_002D9DD8(S *, int, int);
extern int func_002EDD08(void *, char *, int, int);
extern int func_002D9A30(S *, int, char *, unsigned short *, int);
N *func_002DAAB0(S *s, R *r)
{
    char buf[16];
    unsigned short h[8];
    N *n;
    N *head;
    void *m;
    n = func_002F2FA8(s->f6C, r->f14);
    if (n) {
        func_002F3198(n, r->f10);
    } else {
        n = func_002F3068(s, r);
        head = s->f6C;
        if (head == 0) {
            s->f6C = n;
            head = n;
        }
        n->prev = head;
        n->next = s->f6C->next;
        head->next = n;
        n->next->prev = n;
    }
    func_002EF748(s->f64, n);
    if (r->f10 > 0) {
        m = func_002D9E18(s, r->f10);
        if (m == 0) {
            m = func_002D9DD8(s, r->f10, 3);
            h[0] = r->f10;
            func_002EDD08(m, buf, 7, 2);
            func_002D9A30(s, r->f14, buf, h, 2);
        }
        func_002EF748(m, n);
    }
    return n;
}
