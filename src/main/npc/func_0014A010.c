/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D();
    virtual void DeactivateForAllPlayers(); /* +0xC0 */
    char pad04[0x141 - 4];
    unsigned char flags141 : 7;
    unsigned char busy : 1; /* +0x141 bit 7 */
};

/* Script native: cNPC::DeactivateForAllPlayers() unless the +0x141 top bit is set; returns 0. */
extern "C" int Script_cNPC_DeactivateForAllPlayers(ScriptArg* args)
{
    cNPC* npc = (cNPC*)args[0].p;
    if (!npc->busy)
        npc->DeactivateForAllPlayers();
    return 0;
}
