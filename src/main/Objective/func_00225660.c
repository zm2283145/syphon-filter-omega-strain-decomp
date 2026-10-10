#include "types.h"

typedef struct ObjectiveN {
    char pad00[0x54];
    unsigned char notifyType; /* 0x54 */
} ObjectiveN;

typedef struct ObjArgs {
    void* obj;
    unsigned char type;
} ObjArgs;

extern ObjectiveN* Objective_ResolveReceiver(void* obj);

/* Script native: cObjective.SetNotifyType(type). */
int Script_cObjective_SetNotifyType(ObjArgs* args) {
    unsigned char type = args->type;
    Objective_ResolveReceiver(args->obj)->notifyType = type;
    return 0;
}
