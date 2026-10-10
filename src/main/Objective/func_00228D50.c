#include "types.h"

typedef struct Objective {
    char pad[0x24];
    unsigned char completed;
    char pad2[0x78 - 0x25];
    int outcome;
} Objective;

extern int ObjMan_GetService(Objective* obj);
extern void ObjMan_Notify(int owner, int outcome);

/* Marks the objective completed and reports its outcome to the owner. */
void Objective_SetCompleted(Objective* obj) {
    obj->completed = 1;
    ObjMan_Notify(ObjMan_GetService(obj), obj->outcome);
}
