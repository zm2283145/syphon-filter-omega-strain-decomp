#include "types.h"
typedef struct { void* x0; int x4; void* x8; } S_7110;
extern void* D_004FFD30;
extern void WeaponDb_OnModelLoaded(void* db, int a, void* b, int c);
void WeaponDb_LoadCallback(S_7110* self, int a, int flag)
{
    if (flag) {
        void* b = self->x8;
        int c = self->x4;
        b = b ? b : self->x0;
        WeaponDb_OnModelLoaded(D_004FFD30, a, b, c);
    }
}