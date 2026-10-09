/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int Global_RemoveArray(ScriptArray* array);
extern int func_002689F0(int arg);
extern int func_00269090(int value);
extern ScriptArray* func_002690C0(void* obj);

Word* func_00268680(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00268690(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002686A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_002686B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002686C0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002686D0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Script native: RemoveArray(args[0]). */
int Script_RemoveArray(ScriptArg* args) {
    Global_RemoveArray(func_002690C0(args[0].p));
    return 0;
}

/* Script native: CreateArray(args[0]). volatile mirrors the original stack temporary. */
int Script_CreateArray(ScriptArg* args) {
    volatile int arg = args[0].i;
    return func_00269090(func_002689F0(arg));
}
