#include "types.h"
typedef struct G1Ev G1Ev;
typedef struct {
    char pad[0x50]; char state; char prevState; char pad2[0xE8 - 0x52]; void* anim;
    char pad3[0x1C4 - 0xEC]; unsigned char f1C4; unsigned char f1C5; unsigned char f1C6;
} G1Ob;
extern int* cMessage_Name(G1Ev*);
extern int cSystemContainer_HandleMessage(G1Ob*, G1Ev*);
extern int cGameSystem_NextFrame(G1Ob*);
extern void cGameSystem_SendAgentData(G1Ob*, int, int);
extern void cScreenFader_StartFade(void*, int, float);
extern int D_005436B0;
extern int D_004F5398;
extern unsigned char g_IsMultiplayer;
int cGameSystem_HandleMessage(G1Ob* o, G1Ev* e)
{
    int t;
    int handled = (unsigned char)cSystemContainer_HandleMessage(o, e);
    t = *cMessage_Name(e);
    if (t == D_005436B0) {
        return cGameSystem_NextFrame(o) != 0 || handled != 0;
    }
    t = *cMessage_Name(e);
    if (t == D_004F5398) {
        if ((unsigned char)o->state != 0x13 && (unsigned char)o->state != 0x14) {
            if (g_IsMultiplayer) cGameSystem_SendAgentData(o, 0, 1);
            if (o->f1C4 && o->f1C5 && o->f1C6) {
                o->prevState = o->state;
                o->state = 0x14;
            } else {
                o->prevState = o->state;
                o->state = 0x13;
                cScreenFader_StartFade(o->anim, 2, 1.0f);
            }
            return 1;
        }
    }
    return handled;
}