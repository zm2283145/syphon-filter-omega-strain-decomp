typedef struct N08C8 { char pad[0x38]; struct N08C8 *next; } N08C8;
typedef struct { char pad[0x8]; struct N08C8 *head; } L08C8;
extern int func_001161A0(void);
extern int func_001161F8(void);

N08C8 *func_001108C8(N08C8 *it, L08C8 *l)
{
    N08C8 *p, *n;
    func_001161A0();
    p = l->head;
    if (p == it) {
        l->head = p->next;
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