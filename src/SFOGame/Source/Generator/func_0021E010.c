#include "types.h"
int cNetObj_AddSystem(int, int, void*);
int NetGetMyClientIndex(int*, int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
typedef struct { char pad[0xC]; int idC; int id10; } Gen_E010;
void cGenerator_InitNetwork(Gen_E010* self)
{
    int ok;
    self->id10 = self->idC;
    ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        int t = self->id10;
        int id;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
        cNetObj_AddSystem(t, id, self);
    }
}