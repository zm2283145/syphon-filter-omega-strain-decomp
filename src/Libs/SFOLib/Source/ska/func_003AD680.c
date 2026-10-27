#include "types.h"
typedef struct { int i0; int id; } F6Req;
typedef struct { char pad[4]; unsigned char busy; char pad2[0x2B]; char a30[0x14]; } F6Ctl2;
extern void std_deque_deleter_cSkaSystem_Request_push_back(void* arr, void* item);
extern void cSkaRequestStream_SignalInterruptionOfCurrentlyPlayingItems(F6Ctl2*);
extern void cSkaRequestStream_ClearQueue(F6Ctl2*);
extern void cSkaRequestStream_StartPlayingItem(float w, F6Ctl2* c, F6Req* r, int stop);
extern F6Req* cSkaRequestStream_GetLatestRequest(F6Ctl2*);
extern void cSkaRequestStream_ClearCurrentlyPlayingItems(F6Ctl2*);
void AnimCtl_Install(F6Ctl2* c, F6Req* r, unsigned char mode)
{
    if (c->busy) {
        return;
    }
    switch (mode) {
    case 0:
        std_deque_deleter_cSkaSystem_Request_push_back(c->a30, r);
        break;
    case 1:
        cSkaRequestStream_SignalInterruptionOfCurrentlyPlayingItems(c);
        cSkaRequestStream_ClearQueue(c);
        cSkaRequestStream_StartPlayingItem(0.0f, c, r, 1);
        break;
    case 2:
        {
        F6Req* sel = cSkaRequestStream_GetLatestRequest(c);
        if (r->id != sel->id) {
            cSkaRequestStream_SignalInterruptionOfCurrentlyPlayingItems(c);
            cSkaRequestStream_ClearQueue(c);
            cSkaRequestStream_StartPlayingItem(0.0f, c, r, 1);
        }
        }
        break;
    case 3:
        cSkaRequestStream_ClearCurrentlyPlayingItems(c);
        cSkaRequestStream_ClearQueue(c);
        cSkaRequestStream_StartPlayingItem(1.0f, c, r, 1);
        break;
    }
}