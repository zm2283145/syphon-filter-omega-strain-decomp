#include "types.h"
typedef struct CxRequest { char pad[0xC]; unsigned char kind; } CxRequest;
typedef struct CxQueueNode { char pad[8]; CxRequest* request; } CxQueueNode;
typedef struct CxRouter { char pad[0x20]; int count; int unk24; CxQueueNode* first; } CxRouter;
extern int* Event_GetType(void*);
extern int Receiver_HandleEventBase(CxRouter*, void*);
extern void NpcRoute_Update(CxRouter*);
extern void func_00163580(CxRequest*, void*);
extern void func_00161DB0(CxRequest*, void*);
extern int D_004ED9B8;
extern unsigned char D_004ED9D0;
extern int D_005435A8;
extern int D_005436B0;

unsigned char func_00164180(CxRouter* self, char* event) {
    unsigned char handled=1;
    int type=*Event_GetType(event);
    if(type==D_005436B0) {
        NpcRoute_Update(self);
    } else {
        type=*Event_GetType(event);
        if(type!=D_004ED9B8) {
            type=*Event_GetType(event);
            if(type==D_005435A8) {
                if(D_004ED9D0==2) {
                    D_004ED9D0=0;
                } else if(self->count>0) {
                    CxRequest* request=self->first->request;
                    D_004ED9D0=0;
                    if(request->kind==1) func_00163580(request,event+0x30);
                    else func_00161DB0(request,event+0x30);
                }
            } else handled=Receiver_HandleEventBase(self,event);
        }
    }
    return handled;
}
