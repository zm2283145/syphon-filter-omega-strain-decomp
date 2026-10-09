/*
 * Matched functions (byte-identical with the retail executable).
 * Script evaluation stack (ScriptManager+0x4E70, grows downwards).
 */

#include "types.h"
#include "scriptManager_types.h"

extern void ScriptStack_Push(ScriptManager* self, int value);
extern int ScriptStack_Pop(ScriptManager* self);

/* Pops a float. volatile mirrors the original stack temporary. */
float ScriptStack_PopFloat(ScriptManager* self) {
    volatile int bits = ScriptStack_Pop(self);
    return *(float*)&bits;
}

/* Pops an int word. */
int ScriptStack_Pop(ScriptManager* self) {
    return *self->sp++;
}

/* Pushes a float. volatile mirrors the original stack temporary. */
void ScriptStack_PushFloat(ScriptManager* self, float value) {
    volatile float bits = value;
    ScriptStack_Push(self, *(int*)&bits);
}

void ScriptStack_Push(ScriptManager* self, int value) {
    self->sp = self->sp - 1;
    *self->sp = value;
}
