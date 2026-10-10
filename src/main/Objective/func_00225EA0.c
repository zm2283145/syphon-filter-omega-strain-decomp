#include "types.h"
typedef struct { void* vt; } ObjEv225EA0;
extern char D_004DE4F0[];
extern void cMessage_dtor(void*, int);
extern void operator_delete(void*);
ObjEv225EA0* ObjectiveEvent_Dtor(ObjEv225EA0* self, short flag) {
    if (self) {
        self->vt = D_004DE4F0;
        cMessage_dtor(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}