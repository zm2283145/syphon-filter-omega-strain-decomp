typedef struct { int state; int x4; int x8; int xC; int id; int x14; int x18; unsigned char b1C; unsigned char b1D; char pad1E[2]; int x20; void *p24; void *p28; } E2E8F08;
typedef struct { unsigned char b0; unsigned char b1; char pad2[2]; unsigned short x4; char pad6[2]; unsigned char b8; char pad9[3]; int xC; } M2E8F08;
extern E2E8F08 D_005227F0[];
extern void *func_002DD2E8(int);
extern void func_002DD328(void *);

int func_002E8F08(int id, int x, M2E8F08 *m, E2E8F08 **out)
{
    E2E8F08 *e;
    unsigned int i;
    int slot = -1;

    if (!out) return 23;
    *out = 0;
    if (!m) return 23;
    if (id < 0 || (id >= 4 && id != 0xFFFF)) return 23;
    if ((x < -1 || x > 255) && x != 0xFFFF) return 23;
    for (i = 0; i < 256; i++) {
        switch (D_005227F0[i].state) {
        case 2:
            if (id == D_005227F0[i].id && x == D_005227F0[i].x14 && m->x4 == D_005227F0[i].x4 &&
                m->xC == D_005227F0[i].x8 && m->b8 == (unsigned char)D_005227F0[i].x18 &&
                m->b0 == D_005227F0[i].b1C && m->b1 == D_005227F0[i].b1D)
                *out = &D_005227F0[i];
            break;
        case 0:
            if (slot == -1) slot = i;
            break;
        default:
            if (D_005227F0[i].p28) { func_002DD328(&D_005227F0[i].p28); D_005227F0[i].p28 = 0; }
            if (D_005227F0[i].p24) { func_002DD328(&D_005227F0[i].p24); D_005227F0[i].p24 = 0; }
            D_005227F0[i].state = 0;
            if (slot == -1) slot = i;
            break;
        }
    }
    if (*out) goto ok;
    if (slot != -1) {
        e = &D_005227F0[slot];
        e->state = 2;
        e->x4 = m->x4;
        e->x8 = m->xC;
        e->id = id;
        e->xC = 0;
        e->x14 = x;
        e->x18 = m->b8;
        e->b1C = m->b0;
        e->b1D = m->b1;
        e->p28 = func_002DD2E8(m->xC);
        e->p24 = func_002DD2E8(m->x4);
        if (!e->p28 || !e->p24) {
            if (e->p28) { func_002DD328(&e->p28); e->p28 = 0; }
            if (e->p24) { func_002DD328(&e->p24); e->p24 = 0; }
            e->state = 0;
            return 22;
        }
        *out = e;
    } else
        return 25;
ok:
    return 0;
}
