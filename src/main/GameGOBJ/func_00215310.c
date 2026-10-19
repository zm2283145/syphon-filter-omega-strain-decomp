#pragma cplusplus on
#include "types.h"

typedef struct ElevE6Msg { void* vtbl; char pad[0x74]; char a[0x9C]; char b[0xBC]; } ElevE6Msg;

class ElevE6Child {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual void Fn(void* arg);
};

typedef struct ElevE6 {
    char pad[0x64];
    ElevE6Child* child;
    char pad2[0x2E0 - 0x68];
    char key[4];
} ElevE6;

extern "C" char g_Game[];
extern "C" char D_004DADF0[];
extern "C" char g_TargetVisMgr[];
extern "C" void SoundStopMsg_Ctor(ElevE6Msg* msg, void* key, ElevE6* self);
extern "C" void Event_Send(ElevE6Msg*, void*, int);
extern "C" void FileMan_Release(void*, int);
extern "C" void cMessage_dtor(ElevE6Msg*, int);
extern "C" void Object_Deactivate(ElevE6* self, void* arg);
extern "C" void TargetVis_Unregister(void* list, ElevE6* self);

/* cElevatorGOBJ vtable slot 16: broadcast, forward to the child, then base handling. */
extern "C" void cElevatorGOBJ_v16(ElevE6* self, void* arg)
{
    ElevE6Msg msg;
    SoundStopMsg_Ctor(&msg, self->key, self);
    Event_Send(&msg, g_Game, 1);
    msg.vtbl = D_004DADF0;
    FileMan_Release(msg.b, -1);
    FileMan_Release(msg.a, -1);
    cMessage_dtor(&msg, 0);
    if (self->child != 0) {
        self->child->Fn(arg);
    }
    Object_Deactivate(self, arg);
    TargetVis_Unregister(g_TargetVisMgr, self);
}