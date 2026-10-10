#include "types.h"
typedef struct { char pad[0x2C]; signed char type; char pad2d[3]; int id; int value; char name[0x10]; } ObjEvt_e1;
typedef struct { char pad[8]; signed char type; char pad9[3]; int id; int value; char name[0x10]; } ObjPkt_e1;
extern int D_0051F0B8;
extern int Event_PackHeader(ObjEvt_e1*, int, int*, int, int, unsigned int, char*);
extern char* strncpy(char*, const char*, unsigned int);
int ObjectiveEvent_Serialize(ObjEvt_e1* self, int recv, int* outSize, int a3, int a4, unsigned int cap, char* buf)
{
    int ret = -1;
    ObjPkt_e1* p;
    if (cap >= 0x24 && buf != 0) {
        p = (ObjPkt_e1*)buf;
        Event_PackHeader(self, recv, outSize, a3, a4, cap, buf);
        p->id = self->id;
        p->type = self->type;
        p->value = self->value;
        strncpy(p->name, self->name, 0x10);
        if (outSize != 0) {
            ret = 0x24;
            *outSize = D_0051F0B8;
        }
    }
    return ret;
}