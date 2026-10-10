#include "types.h"
typedef struct F1Ctx3DC { char pad0[0x18]; int* defs; } F1Ctx3DC;
typedef struct F1Def3DC { int pad0; int type; int count; char pad0C[0x10]; int args[23]; int linked; } F1Def3DC;
extern char D_00555070[];
extern int Script_ResolveType(F1Ctx3DC* ctx, int type);
extern int Script_LinkDefinition(void* tab, F1Def3DC* def, F1Ctx3DC* ctx);
int func_003DC720(F1Ctx3DC* ctx, F1Def3DC* def, int idx)
{
    int i;
    int r;
    def->type = Script_ResolveType(ctx, def->type);
    for (i = 0; i < def->count; i++) {
        def->args[i] = Script_ResolveType(ctx, def->args[i]);
    }
    r = 0;
    if (def->type >= 0) {
        r = Script_LinkDefinition(D_00555070, def, def->linked ? ctx : 0);
    }
    ctx->defs[idx] = r;
    return r;
}