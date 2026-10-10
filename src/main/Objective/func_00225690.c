#include "types.h"

typedef struct ObjectiveM {
    char pad00[0x27];
    unsigned char multiType;  /* 0x27 */
    unsigned char multiCount; /* 0x28 */
} ObjectiveM;

typedef struct MultiArgs {
    void* obj;
    unsigned char type;
    char pad5[3];
    int count;
} MultiArgs;

extern ObjectiveM* Objective_ResolveReceiver(void* obj);

/* Script native: cObjective.SetMultiType(type, count). */
int Script_cObjective_SetMultiType(MultiArgs* args) {
    volatile int countSlot;
    int count;
    unsigned char type;
    ObjectiveM* obj;

    countSlot = args->count;
    type = args->type;
    count = countSlot;
    obj = Objective_ResolveReceiver(args->obj);
    obj->multiType = type;
    obj->multiCount = count;
    return 0;
}
