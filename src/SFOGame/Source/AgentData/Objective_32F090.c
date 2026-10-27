/*
 * main/Objective: 2 files, 0032F090-0032F0D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032F090 */
#pragma push /* merge_units */
#include "types.h"

/* Sets bit n in the objective mask (ignores negative n). */
void cAgentData_SetBit(void* self, unsigned int* mask, int n)
{
    if (n > -1)
        mask[n / 32] |= 1 << (n & 31);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032F090 */

/* merge_units: begin func_0032F0D0 */
#pragma push /* merge_units */
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x18]; } ObjRow_32F0D0;
extern int D_00532BC0;
extern char D_005329F0[];
extern void* cAgentData_Record_ctor_charP_int_int(ObjRow_32F0D0* r, int a, int b, int id);
extern void cArray_Record_PushBackActual(void* registry, void* item);
int Objective_Register(ScriptArg* args)
{
    ObjRow_32F0D0 r;
    int p0[1];
    int p1[1];
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    cArray_Record_PushBackActual(D_005329F0, cAgentData_Record_ctor_charP_int_int(&r, *(int*)p0, *(int*)p1, D_00532BC0++));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032F0D0 */
