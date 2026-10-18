/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern ScriptManager D_00555070;
extern int strlen(void* obj);
extern int ScriptSlot_ResizeBuffer(ScriptBound* self, int binding);
extern int ScriptMgr_LookupResource(ScriptManager* manager, void* obj, int* key, int* out);

/* Address of slot i in a word table. */
int* func_003D9D20(int** table, int i) {
    return *table + i;
}

/* Looks up obj's script binding in the script manager (D_00555070) and hands it to ScriptSlot_ResizeBuffer. */
void Script_LookupResource(ScriptBound* self, void* obj) {
    int binding;

    if (obj != 0 && strlen(obj) != 0) {
        binding = 0;
        ScriptMgr_LookupResource(&D_00555070, obj, &self->key, &binding);
        ScriptSlot_ResizeBuffer(self, binding);
    }
}
