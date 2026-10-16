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
    float unk1C;
    int unk20;
} Settings0045A700;
extern Settings0045A700* func_0045A7A0(Settings0045A700* s);
/* Initialise with defaults, then override three fields. */
void func_0045A700(Settings0045A700* s)
{
    Settings0045A700 def;
    func_0045A7A0(&def);
    s->unk0 = def.unk0;
    s->b4 = def.b4;
    s->b5 = def.b5;
    s->b6 = def.b6;
    s->b7 = def.b7;
    s->unk8 = def.unk8;
    s->unkC = def.unkC;
    s->unk10 = def.unk10;
    s->unk14 = def.unk14;
    s->b18 = def.b18;
    s->b19 = def.b19;
    s->unk1C = def.unk1C;
    s->unk20 = def.unk20;
    s->b5 = 1;
    s->b4 = 0;
    s->unk20 = 0;
}
