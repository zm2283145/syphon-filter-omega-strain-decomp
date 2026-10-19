#include "types.h"
typedef struct CxRequest { char pad[0xC]; unsigned char kind; } CxRequest;
typedef struct CxQueueNode { char pad[8]; CxRequest* request; } CxQueueNode;
typedef struct CxRouter { char pad[0x20]; int count; int unk24; CxQueueNode* first; } CxRouter;
extern int* Event_GetType(void*);
extern int Receiver_HandleEventBase(CxRouter*, void*);
extern void NpcRoute_Update(CxRouter*);
extern void NpcRoute_HandleRouteLosResult(CxRequest*, void*);
extern void NpcRoute_HandleLosResult(CxRequest*, void*);
extern int D_004ED9B8;
extern unsigned char D_004ED9D0;
extern int g_LosResultMsgClass;
extern int D_005436B0;

unsigned char NpcRouteMgr_HandleMessage(CxRouter* self, char* event) {
    unsigned char handled=1;
    int type=*Event_GetType(event);
    if(type==D_005436B0) {
        NpcRoute_Update(self);
    } else {
        type=*Event_GetType(event);
        if(type!=D_004ED9B8) {
            type=*Event_GetType(event);
            if(type==g_LosResultMsgClass) {
                if(D_004ED9D0==2) {
                    D_004ED9D0=0;
                } else if(self->count>0) {
                    CxRequest* request=self->first->request;
                    D_004ED9D0=0;
                    if(request->kind==1) NpcRoute_HandleRouteLosResult(request,event+0x30);
                    else NpcRoute_HandleLosResult(request,event+0x30);
                }
            } else handled=Receiver_HandleEventBase(self,event);
        }
    }
    return handled;
}
