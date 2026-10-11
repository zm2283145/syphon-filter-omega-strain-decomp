typedef struct N0760 { int x0, x4, x8, xC, x10; struct N0760 *next; } N0760;
typedef struct { char pad[0x28]; N0760 *head; } L0760;
extern L0760 D_004E4780;
extern int func_001161A0(void);
extern void func_001161F8(void);

void func_00110760(N0760 *n, int x)
{
    N0760 *p;
    func_001161A0();
    n->x0 = x;
    n->x4 = 0;
    n->x8 = 0;
    n->xC = 0;
    n->x10 = 0;
    n->next = 0;
    if (D_004E4780.head == 0) {
        D_004E4780.head = n;
    } else {
        p = D_004E4780.head;
        while (p->next) p = p->next;
        p->next = n;
    }
    func_001161F8();
}