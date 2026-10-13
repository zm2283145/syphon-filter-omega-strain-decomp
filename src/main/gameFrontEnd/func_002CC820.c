#include "types.h"
typedef struct { char name[0x40]; char desc[0x80]; int text; int index; unsigned char a; unsigned char b; } LevelC820;
extern char* D_0048C160[];
static const unsigned int dat_004ACB60[20] = { 0x0, 0x1, 0x2, 0xFFFFFFFF, 0x3, 0x4, 0xFFFFFFFF, 0xFFFFFFFF, 0x5, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x6, 0x7, 0xFFFFFFFF, 0xFFFFFFFF, 0x8, 0xFFFFFFFF, 0x0, 0x0 };
static const unsigned int dat_004ACBB0[8] = { 0x1000000, 0x10000, 0x10000, 0x1000000, 0x0, 0x0, 0x0, 0x0 };
static const unsigned int dat_004ACBD0[6] = { 0x1000000, 0x10000, 0x10000, 0x1000000, 0x0, 0x0 };
extern int D_00494198;
extern void String_Copy(char* dst, const char* src);
void LevelSelect_SetLevel(LevelC820* o, int i)
{
    if (i >= 0 && i < 0x12) {
        String_Copy(o->name, D_0048C160[i]);
        o->text = ((int*)dat_004ACB60)[i];
        o->index = i;
        o->a = ((unsigned char*)dat_004ACBB0)[i];
        o->b = ((unsigned char*)dat_004ACBD0)[i];
        D_00494198 = i;
    } else {
        o->name[0] = 0;
        o->desc[0] = 0;
        o->text = -1;
        o->index = -1;
        o->a = 0;
    }
}