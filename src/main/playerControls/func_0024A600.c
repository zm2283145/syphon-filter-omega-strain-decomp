#include "types.h"
typedef struct { char pad0[0x4C]; int type; } CzZone;
extern int D_0049D010;
extern int PlayerInput_TryStand(void* p, CzZone* z);
static inline CzZone* Cz(CzZone* z) { return (z && z->type == D_0049D010) ? z : 0; } int func_0024A600(void* p, CzZone* z) { CzZone* c = Cz(z); if (c) return PlayerInput_TryStand(p, c); return 0; }
