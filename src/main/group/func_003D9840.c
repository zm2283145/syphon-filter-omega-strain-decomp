#include "types.h"
#include "scriptUtils_types.h"

extern void* Group_FromHandle(int handle);
extern void func_003D9AC0(void* group);

/* Script native: cGroup.RemoveAll(group = args[0]). */
int Script_cGroup_RemoveAll(ScriptArg* args) {
    func_003D9AC0(Group_FromHandle(args[0].i));
    return 0;
}
