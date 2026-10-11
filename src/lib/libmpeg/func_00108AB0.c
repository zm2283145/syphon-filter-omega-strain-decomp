typedef struct { char pad[0x110]; int x110; char p1[0x54]; int x168; char p2[0x20]; int x18C; char p3[0x40]; int x1D0; int x1D4; int x1D8; int x1DC; int x1E0; int x1E4; int x1E8; int x1EC; int x1F0; int x1F4; int x1F8; int x1FC; } Mpeg8AB0;
extern void func_001092C8(Mpeg8AB0 *, int, int);
extern void func_001093D8(Mpeg8AB0 *, int, int, int);

void func_00108AB0(Mpeg8AB0 *m, int n, int flag)
{
    if (flag) {
        if (m->x18C == 3) {
            func_001092C8(m, m->x168 == 3 ? m->x1DC : m->x1D0, n - 1);
        } else {
            int a, b;
            if (m->x168 == 3) { a = m->x1EC; b = m->x1FC; }
            else { a = m->x1E0; b = m->x1F0; }
            func_001093D8(m, a, b, n - 1);
        }
    }
    if (m->x110 == 1) m->x110 = 2;
}