typedef struct N0960 { char pad[0x14]; struct N0960 *next; } N0960;
typedef struct { char pad[0x28]; struct N0960 *head; } L0960;
extern L0960 D_004E4780;
extern int func_001161A0(void);
extern int func_001161F8(void);

N0960 *func_00110960(N0960 *it)
{
    N0960 *p, *n;
    func_001161A0();
    p = D_004E4780.head;
    if (p == it) {
        D_004E4780.head = p->next;
    } else if (p) {
        while (p->next != it) {
            p = p->next;
            if (!p) goto out;
        }
        p->next = it->next;
    }
out:
    func_001161F8();
    return p;
}