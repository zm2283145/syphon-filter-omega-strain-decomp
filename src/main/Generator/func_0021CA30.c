#include "types.h"
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
} E7Msg;
typedef struct { char pad[0xB8]; float minDistSq; } E7Gen;
extern unsigned char D_005721C8;
extern char D_004A4A78[];
extern char D_004DB5E0[];
extern void Event_Construct(E7Msg* msg, void* name);
extern void Event_Send(E7Msg* msg, void* target, int flags);
extern void cMessage_dtor(E7Msg* msg, int flags);
int Script_cGenerator_SetMinSpawnDistance(int* args)
{
    volatile int iv = args[1];
    float d = *(float*)&iv;
    E7Gen* gen = (E7Gen*)args[0];
    gen->minDistSq = d * d;
    if (D_005721C8) {
        float v = gen->minDistSq;
        E7Msg msg;
        Event_Construct(&msg, D_004A4A78);
        msg.vtable = D_004DB5E0;
        msg.b28 = 1;
        msg.b20 = 4;
        msg.value = (int)v;
        Event_Send(&msg, gen, 0);
        msg.vtable = D_004DB5E0;
        cMessage_dtor(&msg, 0);
    }
    return 0;
}