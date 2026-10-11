#pragma cplusplus on
#include "types.h"
extern "C" {
#include "net_local_id.h"
}
typedef struct { char pad[0xC]; char key[0x20]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_12D0;
extern "C" {
void func_003CE810(void);
void func_0043B190(void* ctx);
int func_0043AB20(void* ctx, void* key);
void func_00439D00(void* ctx, void* key, int id);
void func_0043A420(void* ctx, void* key);
}
extern "C" void cGenerator_v06(Gen_12D0* g)
{
    char ctx[4];
    func_003CE810();
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        func_0043B190(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && func_0043AB20(ctx, g->key) == 0) {
            void* key = g->key;
            func_00439D00(ctx, key, NetLocalId());
        }
        func_0043A420(ctx, g->key);
    }
}