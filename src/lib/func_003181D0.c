#include "types.h"

extern float VoiceFontVoicing(void* a0, float* a1, float* a2);
extern float VoiceFontSquash(void* a0, float* a1);
extern float VoiceFontShift(void* a0, float* a1);

void ApplyCustomVoiceFont(void* a0, float* out, float* f)
{
    float k = 8000.0f;
    register float lo asm("$f21") = 50.0f;
    float hi = 1000.0f;
    float r;

    if (*(unsigned short*)((char*)a0 + 0x2C) != 0) {
        *out = VoiceFontVoicing(a0, out, f);
        return;
    }
    if (*(unsigned short*)((char*)a0 + 0x2A) != 0) {
        *f = k / *f;
        r = VoiceFontSquash(a0, f);
    } else {
        *f = k / *f;
        r = VoiceFontShift(a0, f);
    }
    *f = r;
    if (r < lo) *f = lo;
    if (hi < *f) *f = hi;
    *f = k / *f;
}
