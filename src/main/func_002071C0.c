/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_002071B0(Word*);
extern void func_00207200(void);

/* Tests bit 0 of the word. */
int func_002071C0(Word* self) {
    return (func_002071B0(self)->value & 1) != 0;
}

void String_Length(void) {
    func_00207200();
}
