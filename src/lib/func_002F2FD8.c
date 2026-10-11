typedef struct N2FD8 { int pad; struct N2FD8 *next; } N2FD8;
int func_002F2FD8(N2FD8 *head)
{
    N2FD8 *n;
    int c = 0;
    for (n = head; n; c++) {
        n = n->next;
        if (n == head) n = 0;
    }
    return c;
}