#include "types.h"
typedef struct { char pad[0x70]; int id; } cObjective;
extern void* ObjMan_GetService(cObjective* o);
extern void ObjMan_Notify(void* list, int id);
/* Registers the objective with its owner list. */
void cObjective_Add(cObjective* o) { ObjMan_Notify(ObjMan_GetService(o), o->id); }
