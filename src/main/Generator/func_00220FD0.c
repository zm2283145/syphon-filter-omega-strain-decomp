#pragma cplusplus on
#include "types.h"
extern "C" {
#include "net_local_id.h"
}
typedef struct { char pad[0xC]; unsigned int h; } Own_0FD0;
typedef struct { char pad[0xC]; char key[4]; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_0FD0;
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[3]; int f24; } Msg_0FD0;
extern "C" {
extern char D_004E0880[];
extern char g_cEnableMsgClass[];
void func_0043B190(void* ctx);
void func_00439D00(void* ctx, void* key, int id);
void func_0043A420(void* ctx, void* key);
Own_0FD0* Object_ClosestPlayerDistSq(Gen_0FD0* g, int i);
void Event_Construct(Msg_0FD0* m, void* type);
void func_003FF930(Msg_0FD0* m, int id);
void cMessage_dtor(Msg_0FD0* m, int flags);
}
static inline int Owner_0FD0(Own_0FD0* o) { return ((o->h & 0x7F000000) >> 24) - 1; }
extern "C" void cGenerator_v17(Gen_0FD0* g, int who)
{
    char ctx[4];
    char ctx2[4];
    Msg_0FD0 msg;
    g->b2C = 1;
    if (D_005721C8) {
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        if (ok) {
            func_0043B190(ctx);
            if (who < 0) {
                Own_0FD0* o = Object_ClosestPlayerDistSq(g, 0);
                func_00439D00(ctx, g->key, o ? Owner_0FD0(o) : NetLocalId());
            } else {
                if (who == NetLocalId() && g->maskCC == 0) {
                    void* key = g->key;
                    func_00439D00(ctx, key, NetLocalId());
                }
            }
            func_0043A420(ctx, g->key);
        } else if (who < 0) {
            int own = -1;
            Own_0FD0* o = Object_ClosestPlayerDistSq(g, 0);
            if (o) own = Owner_0FD0(o);
            if (own != NetLocalId()) {
                func_0043B190(ctx2);
                func_00439D00(ctx2, g->key, own);
            }
        }
        if (who >= 0) g->maskCC |= 1 << who; else g->maskCC = 0xFF;
        Event_Construct(&msg, g_cEnableMsgClass);
        msg.f24 = who;
        msg.vt = D_004E0880;
        msg.f1C = 0x40;
        msg.f20 = 4;
        func_003FF930(&msg, g->id10);
        msg.vt = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
}