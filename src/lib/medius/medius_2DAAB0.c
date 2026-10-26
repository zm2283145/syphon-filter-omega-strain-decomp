typedef struct N N;
struct N { N *next; N *prev; };
typedef struct { char p[0x64]; void *f64; int f68; N *f6C; } S;
typedef struct { char p[0x10]; int f10; int f14; } R;
extern N *GetPlayerFromGroup(N *, int);
extern int SetPlayerCurChannel(N *, int);
extern N *CreatePlayerSpecific(S *, R *);
extern int GridAddPlayer(void *, N *);
extern void *GetGrid(S *, int);
extern void *AddGrid(S *, int, int);
extern int GridSetPackHeader(void *, char *, int, int);
extern int SendPackage(S *, int, char *, unsigned short *, int);
N *AddPlayer(S *s, R *r)
{
    char buf[16];
    unsigned short h[8];
    N *n;
    N *head;
    void *m;
    n = GetPlayerFromGroup(s->f6C, r->f14);
    if (n) {
        SetPlayerCurChannel(n, r->f10);
    } else {
        n = CreatePlayerSpecific(s, r);
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
    GridAddPlayer(s->f64, n);
    if (r->f10 > 0) {
        m = GetGrid(s, r->f10);
        if (m == 0) {
            m = AddGrid(s, r->f10, 3);
            h[0] = r->f10;
            GridSetPackHeader(m, buf, 7, 2);
            SendPackage(s, r->f14, buf, h, 2);
        }
        GridAddPlayer(m, n);
    }
    return n;
}
