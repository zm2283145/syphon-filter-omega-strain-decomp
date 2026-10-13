#pragma opt_strength_reduction off
typedef struct { char pad[0x416]; signed char v; } T_45D710;
typedef struct {
    char pad0[0xF0];
    unsigned char type;
    char padF1[0x11C - 0xF1];
    T_45D710* alt;
    char pad120[0x13C - 0x120];
    T_45D710* main;
} W_45D710;
typedef struct {
    char pad0[0x74];
    int n;
    int* ids;
    char pad7C[0x88 - 0x7C];
    int* vals;
    char pad8C[0xD8 - 0x8C];
    T_45D710* def;
} O_45D710;
extern void* D_004FFD30;
W_45D710* WeaponDb_Get(void* db, int id);

static inline T_45D710* W_Get(W_45D710* w)
{
    if (w->type == 7 && w->alt != 0) return w->alt;
    return w->main;
}

void func_0045D710(O_45D710* o)
{
    int i;
    for (i = 0; i < o->n; i++) {
        if (o->ids[i] == -2) {
            o->def->v = -1;
        } else {
            W_45D710* w = WeaponDb_Get(D_004FFD30, o->ids[i]);
            if (w) {
                T_45D710* t = W_Get(w);
                if (t) t->v = o->vals[i];
            }
        }
    }
}
