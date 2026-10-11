typedef struct N2FA8 { int pad; struct N2FA8 *next; char pad2[0x2C]; int id; } N2FA8;
N2FA8 *func_002F2FA8(N2FA8 *head, int id)
{
    N2FA8 *n = head;
    while (n && n->id != id) {
        n = n->next;
        if (n == head) n = 0;
    }
    return n;
}