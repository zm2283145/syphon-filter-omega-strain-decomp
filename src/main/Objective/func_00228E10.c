#include "types.h"
typedef struct { char pad[0x2C]; unsigned char kind; char p1[3]; int arg; int id; char name[4]; } Ev228E10;
extern int D_0051F0B0;
extern int* Event_GetType(Ev228E10*);
extern void Objective_SetFailed(void*);
extern void Objective_SetCompleted(void*);
extern void Objective_FormatStatusText(void*);
extern void func_00228BE0(void*, int);
extern void* Object_LookupById(int*);
extern void cObjective_SetMapObject(void*, void*, char*, int);
extern void cObjective_ClearMapObject(void*, int);
extern void cObjective_SetNameLabel(void*, char*, int);
extern void cObjective_SetMenuLabel(void*, char*, int);
extern void cObjective_SetMapLabel(void*, char*, int);
extern void cObjective_SetAddLabel(void*, char*, int);
extern void cObjective_SetCompleteLabel(void*, char*, int);
extern void cObjective_SetFailLabel(void*, char*, int);
extern void cObjective_SetSingleLabel(void*, char*, int);
extern void cObjective_SetPluralLabel(void*, char*, int);
unsigned char Objective_ConsumeEvent(void* o, Ev228E10* e) {
    unsigned char r = 0;
    int* t = Event_GetType(e);
    if (*t == D_0051F0B0) {
        switch (e->kind) {
        case 0: Objective_SetFailed(o); r = 1; break;
        case 1: Objective_SetCompleted(o); r = 1; break;
        case 2: Objective_FormatStatusText(o); r = 1; break;
        case 3: func_00228BE0(o, e->arg); r = 1; break;
        case 6: {
            int id = e->id;
            void* p = Object_LookupById(&id);
            if (p) cObjective_SetMapObject(o, p, e->name, 1);
            r = 1;
            break;
        }
        case 7: cObjective_ClearMapObject(o, 1); r = 1; break;
        case 8: cObjective_SetNameLabel(o, e->name, 1); break;
        case 9: cObjective_SetMenuLabel(o, e->name, 1); break;
        case 10: cObjective_SetMapLabel(o, e->name, 1); break;
        case 11: cObjective_SetAddLabel(o, e->name, 1); break;
        case 12: cObjective_SetCompleteLabel(o, e->name, 1); break;
        case 13: cObjective_SetFailLabel(o, e->name, 1); break;
        case 14: cObjective_SetSingleLabel(o, e->name, 1); break;
        case 15: cObjective_SetPluralLabel(o, e->name, 1); break;
        }
    }
    return r;
}