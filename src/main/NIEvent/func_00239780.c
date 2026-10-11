#include "types.h"
typedef struct {
    void* vtable;
    char pad04[0x1C];
    char b20;
    char pad21[0x57];
    char memberA[0x9C];
    char memberB[0xAC];
} Msg00239780;
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void SoundEvent_CtorFromPreset(Msg00239780* m, void* preset, void* a);
extern void Event_Send(Msg00239780* m, void* target, int a);
extern void func_0036E220(void* member, int flags);
extern void cMessage_dtor(Msg00239780* m, int flags);
void func_00239780(char* self, void* a)
{
    Msg00239780 m;
    SoundEvent_CtorFromPreset(&m, self + 0x10, a);
    m.b20 = 1;
    Event_Send(&m, D_004FFB50, 1);
    m.vtable = D_004DAE30;
    func_0036E220(m.memberB, -1);
    func_0036E220(m.memberA, -1);
    cMessage_dtor(&m, 0);
}