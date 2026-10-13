#pragma opt_propagation off
typedef struct {
    char pad0[0x4C];
    int x4C;
    char pad50[0x54 - 0x50];
    int x54;
    char pad58[0x8C - 0x58];
    void* x8C;
} S;
extern void func_0043BC70(void* a, int b, int c, int d, int e);

void func_00423500(S* s)
{
    if (s->x8C != 0) {
        S* t = s;
        func_0043BC70(t->x8C, 0, t->x54, 0, t->x4C - 1);
    }
}
