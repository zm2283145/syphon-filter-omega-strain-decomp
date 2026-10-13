typedef struct { short a; short b; } P_403940;
typedef struct {
    char pad0[0xD0];
    unsigned int count;
    char padD4[0x810 - 0xD4];
    short t[(0x1410 - 0x810) / 2];
    P_403940 p[(0xBC10 - 0x1410) / 4];
    __int128 k[1];
} S_403940;
extern int D_00539248;
extern __int128 D_005716E0;
extern void func_003813A0(int a, int b, int c);
void func_00403940(S_403940* s, unsigned int i)
{
    if (s->t[i] != 0) {
        s->t[i]--;
        if (s->t[i] <= 0 && i >= s->count) {
            if (s->p[i].a != s->p[i].b)
                func_003813A0(D_00539248, s->p[i].b, 0);
            func_003813A0(D_00539248, s->p[i].a, 0);
            s->p[i].a = 0;
            s->p[i].b = 0;
            s->k[i] = D_005716E0;
        }
    }
}

