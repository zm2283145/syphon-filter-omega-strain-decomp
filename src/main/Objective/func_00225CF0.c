#include "types.h"
typedef struct { char p[0xAC]; unsigned char bAC; } Man225CF0;
typedef struct { char p[0x2C]; unsigned char kind; char p2D[3]; int stage; int id; } Ev225CF0;
extern int D_005436B0;
extern int D_0051F0B0;
int* Event_GetType(void* ev);
void func_00226200(Man225CF0* m, int f);
void ObjMan_StartStage(Man225CF0* m, int stage, int f);
void** NetMap_Lookup(int id);
void func_00227450(Man225CF0* m, void* o, int f);
unsigned char cObjectiveMan_v01(Man225CF0* self, Ev225CF0* ev)
{
    unsigned char r = 0;
    int t = *Event_GetType(ev);
    if (t == D_005436B0) {
        if (self->bAC) func_00226200(self, 0);
        r = 1;
    } else {
        t = *Event_GetType(ev);
        if (t == D_0051F0B0) {
        switch (ev->kind) {
        case 4:
            ObjMan_StartStage(self, ev->stage, 1);
            r = 1;
            break;
        case 5: {
            void** o = NetMap_Lookup(ev->id);
            if (o) func_00227450(self, *o, 1);
            r = 1;
            break;
        }
        }
        }
    }
    return r;
}
