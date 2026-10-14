typedef struct L2F2F30 { struct L2F2F30 *prev; struct L2F2F30 *next; } L2F2F30;
extern L2F2F30 *func_002F2FA8(L2F2F30 *, int);
extern void func_002F30E0(L2F2F30 *);
void func_002F2F30(L2F2F30 **head, int key)
{
    L2F2F30 *n = func_002F2FA8(*head, key);
    L2F2F30 *nx;
    if (n == 0) return;
    if (n == *head) {
        nx = n->next;
        if (n == nx) nx = 0;
        *head = nx;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    func_002F30E0(n);
}
