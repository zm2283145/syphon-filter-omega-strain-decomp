#include "types.h"
#include "scriptUtils_types.h"

extern float Global_RandomInt(float lo, float hi);

/* Script native: RandomInt(lo, hi); the float result is returned as raw bits. */
int Script_RandomInt_2(ScriptArg* args) {
    volatile float result;
    volatile int hi = args[1].i;
    volatile int lo = args[0].i;
    result = Global_RandomInt(*(float*)&lo, *(float*)&hi);
    return *(int*)&result;
}
