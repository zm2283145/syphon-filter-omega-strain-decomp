extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EA8[];
extern char D_004B11D0[];
extern char D_004B11E8[];
extern char D_004B0F38[];
extern int func_00127358(const char *, ...);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { char pad[0x10C]; void **arr; int n; } Obj312910;
/* same-unit callee stubs: weak, in a section the link discards; restore retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) func_003111E0(void *c, void **pp, unsigned int size) { return 0; }
int __attribute__((weak, section(".dtors_drop"))) func_00311320(void *c, void *pp) { return 0; }
int func_00312910(void *c, Obj312910 *o, void *item)
{
    void **arr = 0;
    int r;
    if (c == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x3D6, D_004B0EA8);
        return 3;
    }
    if (o == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x3D7, D_004B11D0);
        return 3;
    }
    if (item == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x3D8, D_004B11E8);
        return 3;
    }
    r = func_003111E0(c, (void **)&arr, o->n * 4 + 4);
    if (r) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x3DD, D_004B0F38);
        return r;
    }
    memcpy(arr, o->arr, o->n * 4);
    arr[o->n] = item;
    o->n++;
    if (func_00311320(c, &o->arr))
        func_00127358(D_004B0DE0, D_004B0E18, 0x3E8, D_004B0F38);
    o->arr = arr;
    return 0;
}