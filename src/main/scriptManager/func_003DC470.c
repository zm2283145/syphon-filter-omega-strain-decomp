/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern PtrVec* D_00554F30;  /* global enum table (ScriptEnum* entries, ids start at 10) */
extern ScriptEnum** func_003DC4C0(PtrVec* v, int i);
extern int Script_RemapEnumId(Script* script, int localId);

/* First word of member 'index' of the script-local enum 'localId'. */
int func_003DC470(Script* script, int localId, int index) {
    int id = Script_RemapEnumId(script, localId);
    ScriptEnum* e = *func_003DC4C0(D_00554F30, id - 10);
    return e->members[index].unk0;
}
