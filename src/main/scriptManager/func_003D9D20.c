/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern ScriptManager D_00555070;
extern int strlen(void* obj);
extern int func_003D9DA0(ScriptBound* self, int binding);
extern int func_003E15B0(ScriptManager* manager, void* obj, int* key, int* out);

/* Address of slot i in a word table. */
int* func_003D9D20(int** table, int i) {
    return *table + i;
}

/* Looks up obj's script binding in the script manager (D_00555070) and hands it to func_003D9DA0. */
void func_003D9D30(ScriptBound* self, void* obj) {
    int binding;

    if (obj != 0 && strlen(obj) != 0) {
        binding = 0;
        func_003E15B0(&D_00555070, obj, &self->key, &binding);
        func_003D9DA0(self, binding);
    }
}
