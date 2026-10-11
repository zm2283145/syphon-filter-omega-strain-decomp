typedef struct { int next; int used; int size; int avail; int pad[11]; int busy; } NetBlk_458;
int func_0034A458(NetBlk_458 *p, unsigned int size, int *out)
{
    int total = 0;
    int n;
    if (out == 0) return 2;
    *out = 0;
    if (p == 0) return 2;
    while (size >= 0x40) {
        if (p->next != 0) break;
        if (p->busy != 0) break;
        n = p->size + 0x40;
        size -= n;
        total += n;
        p = (NetBlk_458 *)((char *)p + n);
    }
    *out = total;
    return 0;
}