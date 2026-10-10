#include "types.h"
typedef struct {
    int unk0;
    unsigned char b4, b5, b6, b7;
    float unk8;
    float unkC;
    float unk10;
    int unk14;
    unsigned char b18, b19;
    char pad1A[2];
    int unk1C;
    int unk20;
} Settings0045A7A0;
/* Initialise settings with defaults. */
Settings0045A7A0* func_0045A7A0(Settings0045A7A0* s)
{
    s->unk0 = 1;
    s->b4 = 0;
    s->b5 = 1;
    s->b6 = 1;
    s->b7 = 0;
    s->unk8 = 0.8f;
    s->unkC = 1.0f;
    s->unk10 = 0.8f;
    s->unk14 = 0;
    s->b18 = 1;
    s->b19 = 1;
    s->unk1C = 0;
    s->unk20 = 0;
    return s;
}
