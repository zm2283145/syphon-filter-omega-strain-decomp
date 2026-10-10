#include "types.h"

typedef struct ScriptArgs2 {
    int group;
    int name;
} ScriptArgs2;

extern int Group_FromHandle(int handle);
extern int func_003CB1C0(int str);
extern int func_003D9C80(int group, int key);

/* Script native: cGroup.Find(name). */
int Script_cGroup_Find(ScriptArgs2* args) {
    int group = Group_FromHandle(args->group);
    volatile int found = func_003D9C80(group, func_003CB1C0(args->name));
    return found;
}
