#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int a, b, c, d, e; } E2EF938;
typedef struct N2EF938 { int a; struct N2EF938 *next; void *obj; } N2EF938;
extern void GetLocalID(int, int *);
extern int GridExpandConnections(void *);
extern void AudioSetConnection(int, E2EF938 *, int, int);
void GridConnectAll(void *s)
{
    int me = 0xFFFF;
    int i = 0;
    int h;
    N2EF938 *n, *head;
    E2EF938 *arr;
    int id;
    if (s == 0) return;
    if (F(s, int, 0x58) != 0) return;
    h = F(s, int, 8);
    GetLocalID(h, &me);
    n = F(s, N2EF938 *, 0x54);
    arr = F(s, E2EF938 *, 0x60);
    head = n;
    if (n == 0) return;
    do {
        id = F(n->obj, int, 0x34);
        if (id != me) {
            if (i >= F(s, int, 0x5C)) {
                GridExpandConnections(s);
                arr = F(s, E2EF938 *, 0x60) + i;
            }
            i++;
            AudioSetConnection(h, arr, 2, id);
            arr++;
        }
        n = n->next;
        if (n == head) n = 0;
    } while (n);
}