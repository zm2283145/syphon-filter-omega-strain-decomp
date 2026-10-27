#include "types.h"
#pragma cplusplus on
typedef struct { void* vtable; char base[0x20]; unsigned char kind; char pad25[3]; int node; } AiMsg_f3;
typedef struct { char pad[0x3204]; int flags; } AiOwner_f3;
class AiChar_f3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void SetAnim(int a, int b);
    char pad4[0x2C]; AiOwner_f3* owner;
    char pad34[0xA0 - 0x34]; int prio;
    char padA4[0x13C - 0xA4]; unsigned char state; unsigned char b13D;
    char pad13E[0x1C0 - 0x13E]; float f1C0; int f1C4;
};
extern "C" {
extern char D_004EE550[];
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cAIMessage_dtor();
extern "C" void cAIMessage_Clone();
void * const D_004D9340[8] = { (void*)0x0, (void*)0x0, (void*)cAIMessage_dtor, (void*)cAIMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern void cMessage_ctor_cMessageNameR(AiMsg_f3* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(AiMsg_f3* m, void* target, int immediate);
extern void cMessage_dtor(AiMsg_f3* m, int flags);
extern void cNPC_DoAction(AiChar_f3* c, int a, int b, float f);
void cNPC_SetMoveMode(AiChar_f3* c, unsigned char state, int prio);
}
void cNPC_SetMoveMode(AiChar_f3* c, unsigned char state, int prio)
{
    AiMsg_f3 msg;
    if (prio < c->prio) {
        return;
    }
    c->prio = prio;
    if (state != c->state) {
        c->state = state;
        if (state == 0) {
            cMessage_ctor_cMessageNameR(&msg, D_004EE550);
            msg.vtable = ((char*)D_004D9340);
            msg.kind = 5;
            msg.node = -1;
            QueueMessage_cMessageR_cSystemP_int(&msg, c, 0);
            msg.vtable = ((char*)D_004D9340);
            cMessage_dtor(&msg, 0);
            if (!c->b13D) {
                c->SetAnim(1, 0x14);
            }
        } else {
            if ((c->owner->flags >> 3) & 1) {
                cNPC_DoAction(c, 9, 0, 0.0f);
            }
            c->f1C0 = 999999.0f;
            c->f1C4 = 0;
        }
    }
}