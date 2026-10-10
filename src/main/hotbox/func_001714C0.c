#include "types.h"
#pragma cplusplus on
class IObj_f4;

class IObj_f4 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void Interact(void*); char pad4[0x8C]; int kind; };
typedef struct { void* vt; char base[0x1C]; unsigned char mode; char pad21[3]; int action; int kind; int zero; void* actor; char pad34[4]; } IMsg_f4;
struct Act_f4 { char pad[0x20]; void* actor; float timer; };
extern "C" unsigned char D_005721C8;
extern "C" char D_004EE698[];
extern "C" char D_004D9940[];
extern "C" IObj_f4* func_00171260(Act_f4*, int);
extern "C" void Event_Construct(void*, void*);
extern "C" void Event_Send(void*, void*, int);
extern "C" void cMessage_dtor(void*, int);
extern "C" int Actor_TryObjectInteraction(Act_f4* self, void* who, int setTimer, int id)
{
    IObj_f4* obj = func_00171260(self, id);
    if (obj) {
        if (D_005721C8) {
            void* actor;
            int kind = obj->kind;
            if (kind == 12) {
                actor = self->actor;
                IMsg_f4 msg;
                Event_Construct(&msg, D_004EE698);
                msg.vt = D_004D9940;
                msg.kind = kind;
                msg.action = 3;
                msg.actor = actor;
                msg.mode = 2;
                msg.zero = 0;
                Event_Send(&msg, obj, 0);
                msg.vt = D_004D9940;
                cMessage_dtor(&msg, 0);
            } else {
                obj->Interact(who);
            }
        } else {
            obj->Interact(who);
        }
        if (setTimer) {
            self->timer = 10.0f;
        }
    }
    return obj != 0;
}