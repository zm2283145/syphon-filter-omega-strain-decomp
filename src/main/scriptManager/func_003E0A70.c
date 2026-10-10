#include "types.h"

typedef struct LevelInfo {
    char pad[0x8C];
    int level;
} LevelInfo;

typedef struct LevelOwner {
    char pad[0x20];
    LevelInfo* info;
} LevelOwner;

extern int func_003D6C90(void* arg);

/* Returns func_003D6C90(arg) as a byte when the owner's level is at least 8, else 0. */
int func_003E0A70(void* self, LevelOwner* owner, void* arg) {
    int result = 0;
    LevelInfo* info = owner->info;
    if (info && info->level > 7) {
        result = (unsigned char)func_003D6C90(arg);
    }
    return result;
}
