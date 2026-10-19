#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
struct Msg { void* vtable; char pad[0x20]; unsigned char kind; char pad2[0xB]; char data[0x40]; };
struct Arg_AFE0 { char pad[0x78]; int id; };
struct NPC_AFE0 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Reset();
    char pad[0x2C]; void* target; char pad2[0x6C]; int a0; char pad3[0x10C]; void* path;
};
extern "C" {
extern char D_0055D4E0[];
extern char D_004D9360[];
extern unsigned char D_005721C8;
void Node_GetTranslation(Vec4* out, void* node);
void Event_Construct(Msg* m, void* type);
void* Mtx_GetIdentity(void);
void Vec4_CopyAsPoint(Vec4* out, void* v);
void Mtx_SetRotationTranslation(void* data, void* obj, Vec4* v);
void Event_Send(Msg* m, void* target, int immediate);
void cMessage_dtor(Msg* m, int flags);
void NpcPath_RelocateStuck(void* path, int id);
void NpcAi_SetMovementState(NPC_AFE0* self, int a, int b);
void NetEvent_Send(void* target, int a, int b, unsigned int c, int d, int e, int f);
}
extern "C" void cNPC_v41(NPC_AFE0* self, Arg_AFE0* node)
{
    Vec4 t;
    Msg msg;
    Vec4 p;
    Msg* m;
    void* id;
    Node_GetTranslation(&t, node);
    m = &msg;
    Event_Construct(m, D_0055D4E0);
    msg.kind = 0;
    msg.vtable = D_004D9360;
    id = Mtx_GetIdentity();
    Vec4_CopyAsPoint(&p, &t);
    {
        void* data = m->data;
        /* Preserve message-data address construction before the identity argument. */
        asm { .set reorder }
        Mtx_SetRotationTranslation(data, id, &p);
    }
    Event_Send(m, self->target, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(m, 0);
    NpcPath_RelocateStuck(self->path, node->id);
    self->Reset();
    self->a0 = 0;
    NpcAi_SetMovementState(self, 0, 0);
    if (D_005721C8)
        NetEvent_Send(self->target, 7, 4, node->id, 0, 0, 0);
}
