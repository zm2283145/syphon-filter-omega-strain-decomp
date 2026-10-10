#include "types.h"
typedef struct { int x0; unsigned char x4; } FxEnt232120;
extern FxEnt232120 D_004F7A50[];
extern int Effect_CreateInstance(int);
static inline FxEnt232120* GetFx232120(int id) {
    if (!D_004F7A50[id].x4) return 0;
    if ((unsigned int)id < 41) return &D_004F7A50[id];
    return 0;
}
int Effect_SpawnById(signed char id) {
    return Effect_CreateInstance(GetFx232120(id)->x0);
}