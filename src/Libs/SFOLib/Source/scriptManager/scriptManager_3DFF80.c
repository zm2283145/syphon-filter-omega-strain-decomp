/*
 * main/scriptManager: range (2 files, 003DFF80-003DFFB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003DFF80 */
#pragma push /* merge_units */
/* Script native placeholder for invalid argument lists; does nothing. */
void cScriptInterpreter_error(int a, int b, ...)
{
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFF80 */

/* merge_units: begin func_003DFFB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script evaluation stack (ScriptManager+0x4E70, grows downwards).
 */


extern void cScriptInterpreter_pushInt(ScriptManager* self, int value);
extern int cScriptInterpreter_popInt(ScriptManager* self);

/* Pops a float. volatile mirrors the original stack temporary. */
float cScriptInterpreter_popFloat(ScriptManager* self) {
    volatile int bits = cScriptInterpreter_popInt(self);
    return *(float*)&bits;
}

/* Pops an int word. */
int cScriptInterpreter_popInt(ScriptManager* self) {
    return *self->sp++;
}

/* Pushes a float. volatile mirrors the original stack temporary. */
void cScriptInterpreter_pushFloat(ScriptManager* self, float value) {
    volatile float bits = value;
    cScriptInterpreter_pushInt(self, *(int*)&bits);
}

void cScriptInterpreter_pushInt(ScriptManager* self, int value) {
    self->sp = self->sp - 1;
    *self->sp = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFFB0 */
