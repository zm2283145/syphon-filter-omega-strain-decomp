#include "types.h"
typedef struct CxRequest { char pad[0xC]; unsigned char kind; } CxRequest;
typedef struct CxQueueNode { char pad[8]; CxRequest* request; } CxQueueNode;
typedef struct CxRouter { char pad[0x20]; int count; int unk24; CxQueueNode* first; } CxRouter;
extern int* cMessage_Name(void*);
extern int cSystem_HandleMessage(CxRouter*, void*);
extern void cPathSystem_NextFrame(CxRouter*);
extern void cPathRequest_UpdateLOSResult(CxRequest*, void*);
extern void cNodeRequest_UpdateLOSResult(CxRequest*, void*);
extern int D_004ED9B8;
extern unsigned char D_004ED9D0;
extern int g_LosResultMsgClass;
extern int D_005436B0;

unsigned char cPathSystem_HandleMessage(CxRouter* self, char* event) {
    unsigned char handled=1;
    int type=*cMessage_Name(event);
    if(type==D_005436B0) {
        cPathSystem_NextFrame(self);
    } else {
        type=*cMessage_Name(event);
        if(type!=D_004ED9B8) {
            type=*cMessage_Name(event);
            if(type==g_LosResultMsgClass) {
                if(D_004ED9D0==2) {
                    D_004ED9D0=0;
                } else if(self->count>0) {
                    CxRequest* request=self->first->request;
                    D_004ED9D0=0;
                    if(request->kind==1) cPathRequest_UpdateLOSResult(request,event+0x30);
                    else cNodeRequest_UpdateLOSResult(request,event+0x30);
                }
            } else handled=cSystem_HandleMessage(self,event);
        }
    }
    return handled;
}
