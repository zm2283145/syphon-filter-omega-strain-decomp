#pragma opt_strength_reduction off
typedef struct {
    char pad0[8];
    unsigned char idx;
    char pad9[7];
    int need;
    int arg;
} E_3351E0;
typedef struct {
    char pad0[8];
    int v[(0xB00 - 8) / 4];
    unsigned char* flags;
} O_3351E0;
extern int D_00532AD4;
extern E_3351E0* D_00532AD8;
void func_003352C0(O_3351E0* o, int arg);

void func_003351E0(O_3351E0* o, int force)
{
    int i;
    for (i = 0; i < D_00532AD4; i++) {
        E_3351E0* e = &D_00532AD8[i];
        if (o->v[e->idx] >= e->need) {
            if (force) {
                o->flags[i] = 2;
            } else if (o->flags[i] == 0) {
                o->flags[i] = 1;
            }
            func_003352C0(o, e->arg);
        }
    }
}

