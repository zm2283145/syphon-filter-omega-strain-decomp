#include "types.h"
typedef struct { int pad[3]; int id; } AIDeadSrc;
typedef struct { int pad[7]; int size; int pad2; AIDeadSrc* src; } AIDeadMsg;
extern void Event_PackHeader(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);
extern int D_0052ACF0;
int cNetRemoveHudObjectiveMsg_Pack(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    int r = -1;
    if (len >= 0xC && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        buf[2] = (int)self->src;
        self->size = 0x40;
        if (type != 0) {
            r = 0xC;
            *type = D_0052ACF0;
        }
    }
    return r;
}