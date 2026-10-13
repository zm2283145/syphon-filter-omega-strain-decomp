#include "types.h"
typedef struct Ctx3DC7 { char pad0[0x8]; int* defs; } Ctx3DC7;
extern char D_00555070[];
extern int Script_ResolveType(Ctx3DC7* ctx, int type);
extern int func_003DD790(void* tab, int a, int type, int b, int c, Ctx3DC7* ctx, int d);
void func_003DC7F0(Ctx3DC7* ctx, int a, int type, int b, int c, int d, int idx)
{
    int r;
    int t = Script_ResolveType(ctx, type);
    r = 0;
    if (t >= 0) {
        r = func_003DD790(D_00555070, a, t, b, c, ctx, d);
    }
    ctx->defs[idx] = r;
}
