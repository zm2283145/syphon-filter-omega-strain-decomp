typedef struct { int key; int a, b, c, d; } G7E20;
typedef struct { char pad[0x5C]; int count; G7E20* arr; } G7T20;
G7E20* func_002EF440(G7T20* t, int key)
{
    int i;
    G7E20* e;
    for (i = 0; i < t->count; i++) {
        e = &t->arr[i];
        if (e->key == key) return e;
    }
    return 0;
}