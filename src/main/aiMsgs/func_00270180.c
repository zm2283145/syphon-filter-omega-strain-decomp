#include "types.h"
typedef struct { int pad[3]; int id; } AIDeadSrc;
typedef struct { int pad[7]; int size; int pad2; AIDeadSrc* src; } AIDeadMsg;
extern void Event_PackHeader(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);
extern int D_004FF0F0;
int cAIDeadMsg_v02(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    int r = -1;
    if (len >= 0x10 && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        buf[2] = self->src->id;
        self->size = 0x40;
        if (type != 0) {
            r = 0x10;
            *type = D_004FF0F0;
        }
    }
    return r;
}