typedef struct I2F33 { char pad[0x34]; int key; } I2F33;
typedef struct N2F33 { int unk0; struct N2F33* next; I2F33* item; } N2F33;
typedef struct L2F33 { int unk0; N2F33* head; } L2F33;N2F33* func_002F3388(L2F33* l, int key)
{
    N2F33* n = l->head;
    N2F33* first;
    if (n != 0) {
        first = n;
        do {
            if (n->item->key == key) return n;
            n = n->next;
            if (n == first) n = 0;
        } while (n != 0);
    }
    return 0;
}