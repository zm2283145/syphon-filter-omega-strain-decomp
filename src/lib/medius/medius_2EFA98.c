/*
 * lib/medius: 2 files, 002EFA98-002EFB28
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EFA98 */
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
/* merge_units: end func_002EFA98 */

/* merge_units: begin func_002EFB28 */
typedef struct { int x0; char *x4; int x8; int xC; int x10; } E2EFB28;
typedef struct { unsigned short a, b; } M2EFB28;
extern int func_002DA918(int);
extern void func_002EDD08(int, char *, int, int);
extern void func_002D9A30(int, int, char *, M2EFB28 *, int);
void func_002EFB28(char *s)
{
    char buf[16];
    M2EFB28 m;
    int i;
    E2EFB28 *e;
    if (s == 0) return;
    if (*(int *)(s + 0x58) == 0) return;
    m.a = *(unsigned short *)(s + 0xC);
    m.b = 0xFFFF;
    func_002EDD08(func_002DA918(*(int *)(s + 8)), buf, 0x12, 4);
    for (i = 0; i < *(int *)(s + 0x5C); i++) {
        e = (E2EFB28 *)(i * 0x14 + *(int *)(s + 0x60));
        if (e->x4 && e->x8 == 2)
            func_002D9A30(*(int *)(s + 8), *(int *)(e->x4 + 0x34), buf, &m, 4);
    }
}
/* merge_units: end func_002EFB28 */
