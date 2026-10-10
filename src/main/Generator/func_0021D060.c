#pragma cplusplus on
#include "types.h"

class NpcE6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool IsDead();
};

typedef struct GenE6 {
    char pad[0x58];
    NpcE6* npc;
} GenE6;

typedef struct GenMsgE6 {
    char pad[0x24];
    GenE6* gen;
} GenMsgE6;

extern "C" int func_0014A670(NpcE6* npc);

/* Script native: the NPC spawned by a generator message (null if dead). */
static inline bool GenE6_NpcDead(GenE6* g)
{
    bool dead = false;
    if (g->npc != 0 && g->npc->IsDead()) {
        dead = true;
    }
    return dead;
}

extern "C" int Script_cGeneratorMessageBase_GetNPC(GenMsgE6** args)
{
    GenMsgE6* msg = args[0];
    NpcE6* npc;
    if (msg->gen != 0 && !GenE6_NpcDead(msg->gen) && msg->gen->npc != 0) {
        npc = msg->gen->npc;
    } else {
        npc = 0;
    }
    return func_0014A670(npc);
}