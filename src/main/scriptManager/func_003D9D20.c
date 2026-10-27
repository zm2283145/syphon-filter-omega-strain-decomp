/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern ScriptManager D_00555070;
extern int strlen(void* obj);
extern int cScriptVars_extend(ScriptBound* self, int binding);
extern int cScriptInterpreter_FindScriptObj(ScriptManager* manager, void* obj, int* key, int* out);

/* Address of slot i in a word table. */
int* cScriptVars_getExtVar(int** table, int i) {
    return *table + i;
}

/* Looks up obj's script binding in the script manager (D_00555070) and hands it to cScriptVars_extend. */
void cScriptVars_initScriptlet(ScriptBound* self, void* obj) {
    int binding;

    if (obj != 0 && strlen(obj) != 0) {
        binding = 0;
        cScriptInterpreter_FindScriptObj(&D_00555070, obj, &self->key, &binding);
        cScriptVars_extend(self, binding);
    }
}
