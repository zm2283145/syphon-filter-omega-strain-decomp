#include "types.h"

typedef struct LevelInfo {
    char pad[0x8C];
    int level;
} LevelInfo;

typedef struct LevelOwner {
    char pad[0x20];
    LevelInfo* info;
} LevelOwner;

extern int ScriptType_DerivesFromName(void* arg);

/* Returns ScriptType_DerivesFromName(arg) as a byte when the owner's level is at least 8, else 0. */
int ScriptFilter_ArgIsId(void* self, LevelOwner* owner, void* arg) {
    int result = 0;
    LevelInfo* info = owner->info;
    if (info && info->level > 7) {
        result = (unsigned char)ScriptType_DerivesFromName(arg);
    }
    return result;
}
