typedef struct S2DAFB8 {
    char p0[0x8C];
    int x8C;
} S2DAFB8;
extern void func_00307928(int h, int key);
extern void func_00308380(int h, int key);
extern void func_002DAF00(S2DAFB8 *s, int flag);
void func_002DAFB8(int a, int key, unsigned int kind, int flag, S2DAFB8 *s)
{
    if (s == 0) return;
    switch (kind) {
    case 0:
    case 1:
        return;
    case 2:
        func_00308380(s->x8C, key);
        return;
    case 3:
        func_00307928(s->x8C, key);
        return;
    case 4:
        func_00307928(s->x8C, key);
        return;
    case 5:
        func_002DAF00(s, flag);
        return;
    case 6:
        func_00307928(s->x8C, key);
        return;
    case 7:
        func_00307928(s->x8C, key);
        return;
    case 8:
        func_00307928(s->x8C, key);
        return;
    }
}

