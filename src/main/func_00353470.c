#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiAchievementScreen" yields null. */
int func_00353470(void) {
    return strcmp("GuiAchievementScreen") == 0;
}
