typedef struct { int v[256]; unsigned int cur; } Tab80D0;
typedef struct { unsigned char state, b1, active, slot, flag, ready; char pad[10]; int x10; int x14; char pad2[0x14]; char x2C[1]; } Ent80D0;
typedef struct { unsigned char id; } Src80D0;
typedef void (*Cb80D0)(int, unsigned int);
extern Cb80D0 D_00598398[];
extern int D_00590318[];
extern int D_0048C450;
extern int func_002DD9F8(unsigned int, Ent80D0 **);
extern int func_002E51B8(int, Tab80D0 **);
extern int func_002DDB30(unsigned int *, int);
extern int func_002DD328(void *);
extern int func_002F5348(void *);
int func_002E80D0(int a0, int a1, int a2, Src80D0 *src)
{
    Ent80D0 *p = 0;
    Tab80D0 *tab = 0;
    unsigned int n = 0x100;
    Cb80D0 cb;
    if (src == 0) return -1;
    if (func_002DD9F8(src->id, &p) == 0 && p != 0 && p->state == 2) {
        cb = D_00598398[p->slot];
        if (cb != 0) cb(a2, src->id);
        if (func_002E51B8(D_0048C450, &tab) == 0 && tab != 0) {
            func_002DDB30(&n, a0);
            if (tab->cur == n && p->ready != 0 && D_00590318[p->slot] != 0) {
                p->flag = 1;
            } else {
                p->state = 1;
                if (p->active != 0) {
                    func_002DD328(&p->x10);
                    func_002F5348(p->x2C);
                    p->x10 = 0;
                    p->x14 = 0;
                }
            }
        }
    }
    return 1;
}


