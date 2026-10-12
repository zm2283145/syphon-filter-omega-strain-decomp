#include "types.h"
typedef struct {
    int a;
    int id;
    int ammo;
    int extra;
} Slot_142170;
typedef struct {
    int pad0;
    Slot_142170 slots[6];
    char pad64[0x24];
    int actor;
} Inv_142170;
typedef struct {
    char pad0[0x70];
    int clip;
    int f74;
    char pad78[0x78];
    unsigned char fF0;
} Wpn_142170;
extern int D_004FFD30;
extern float MaxNpcAmmoPct;
extern float D_00489C20;
Wpn_142170* WeaponDb_Get(int, int);
int WeaponInv_ClipsForActor(int, int);
int Random_Next(void);
static inline float frand(void) { return Random_Next() / 2147483648.0f; }

void WeaponInv_RandomizeDroppedAmmo(Inv_142170* inv)
{
    int i;
    for (i = 0; i < 6; i++) {
        Slot_142170* s = &inv->slots[i];
        if (s->id != -1) {
            Wpn_142170* w = WeaponDb_Get(D_004FFD30, s->id);
            int total = w->clip * WeaponInv_ClipsForActor(inv->actor, w->f74);
            float pct;
            int n;
            pct = frand();
            pct *= D_00489C20 - MaxNpcAmmoPct;
            pct += MaxNpcAmmoPct;
            if (total < 10) pct *= 2.0f;
            n = (int)(total * pct);
            if (w->fF0 == 1) {
                s->extra = n;
                s->ammo = 0;
            } else {
                if (w->clip < n) {
                    s->extra = n - w->clip;
                    n -= s->extra;
                } else {
                    s->extra = 0;
                }
                s->ammo = n;
                if (s->extra > 0) {
                    int r = (int)(w->clip * (frand()));
                    s->ammo -= r;
                    s->extra += r;
                }
            }
        }
    }
}



