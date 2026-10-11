typedef struct { char pad[0x34]; int id; } D2EFA98;
typedef struct N2EFA98 { struct N2EFA98 *prev; struct N2EFA98 *next; D2EFA98 *data; int arr[4]; } N2EFA98;
void func_002EFA98(char *s, int key, int id)
{
    N2EFA98 *n = *(N2EFA98 **)(s + 0x54);
    N2EFA98 *head = n;
    int i, slot;
    while (n && n->data->id != id) {
        n = n->next;
        if (n == head) n = 0;
    }
    if (n == 0) return;
    slot = -1;
    for (i = 0; i < 4; i++) {
        if (n->arr[i] == key) n->arr[i] = 0xFFFF;
        if (n->arr[i] == 0xFFFF && slot < 0) {
            n->arr[i] = key;
            slot = i;
        }
    }
}
