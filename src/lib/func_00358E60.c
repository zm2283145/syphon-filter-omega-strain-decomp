typedef struct N8E60 { struct N8E60 *next; int x4; int x8; int xC; int x10; int port; } N8E60;
typedef struct { unsigned char len; unsigned char family; unsigned short port; } Addr8E60;
extern void *func_003581E0(int);
extern N8E60 *func_00358480(int);
extern int func_003583A0(void *, int);
extern int func_00358530(int);
extern N8E60 *D_00492CD8;

int func_00358E60(int s, Addr8E60 *a, int len)
{
    void *lk = func_003581E0(0);
    N8E60 *n, *p;
    int port;
    if (!lk) return -1;
    n = func_00358480(s);
    if (!n) return func_003583A0(lk, 9);
    if (len != 16) return func_003583A0(lk, 0x16);
    if (a->family != 2) return func_003583A0(lk, 0x6A);
    port = func_00358530(a->port);
    for (p = D_00492CD8; p; p = p->next) {
        if (port == p->port) return func_003583A0(lk, 0x70);
    }
    n->port = port;
    return func_003583A0(lk, 0);
}