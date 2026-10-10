#pragma cplusplus on
#include "types.h"
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct KillActor_e8 {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34) V4(v38)
    virtual void v3C(); virtual void v3D();
    virtual void Damage(KillActor_e8*, int, int, int, int, int, float); /* 0x100 */
    virtual void v3F();
    virtual unsigned char GetState(); /* 0x108 */
    char pad4[0x3C];
    float health; /* 0x40 */
    char pad44[0x33A5 - 0x44];
    unsigned char flag33A5;
};
struct KillNPC_e8 { char pad[0x30]; KillActor_e8* actor; };
extern "C" void cNPC_Kill(KillNPC_e8* self)
{
    KillActor_e8* a = self->actor;
    if (a->GetState() != 3 || a->flag33A5) {
        KillActor_e8* b = self->actor;
        b->Damage(b, 2, 10, 0, 0, 0, (float)(int)a->health);
    }
}