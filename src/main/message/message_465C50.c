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
extern void EffectMsg_WrapRequest(Msg00239780* m, void* a, void* b);
extern void Event_Send(Msg00239780* m, void* target, int a);
extern void FileMan_Release(void* member, int flags);
extern void cMessage_dtor(Msg00239780* m, int flags);
int GuiSound_Play(char* self, void* a, void* b)
{
    Msg00239780 m;
    EffectMsg_WrapRequest(&m, a, b);
    m.b20 = 1;
    Event_Send(&m, D_004FFB50, 1);
    m.vtable = D_004DAE30;
    FileMan_Release(m.memberB, -1);
    FileMan_Release(m.memberA, -1);
    cMessage_dtor(&m, 0);
    return 1;
}