typedef struct { char pad[0x154]; int x154; char pad2[0x34]; int x18C; int x190; int x194; int x198; int x19C; int x1A0; int a[3]; int b[3]; } Mpeg8858;
extern int func_00107ED8(Mpeg8858 *, int);

void func_00108858(Mpeg8858 *m)
{
    int n, i;
    if (m->x154) {
        if (m->x19C) n = m->x190 ? 3 : 2;
        else n = 1;
    } else {
        if (m->x18C != 3) n = 1;
        else n = m->x19C ? 3 : 2;
    }
    for (i = 0; i < n; i++) {
        m->a[i] = func_00107ED8(m, 16);
        func_00107ED8(m, 1);
        m->b[i] = func_00107ED8(m, 16);
        func_00107ED8(m, 1);
    }
}