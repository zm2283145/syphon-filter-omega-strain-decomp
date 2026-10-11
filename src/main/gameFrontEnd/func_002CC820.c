#include "types.h"
typedef struct { char name[0x40]; char desc[0x80]; int text; int index; unsigned char a; unsigned char b; } LevelC820;
extern char* D_0048C160[];
extern int D_004ACB60[];
extern unsigned char D_004ACBB0[];
extern unsigned char D_004ACBD0[];
extern int D_00494198;
extern void String_Copy(char* dst, const char* src);
void func_002CC820(LevelC820* o, int i)
{
    if (i >= 0 && i < 0x12) {
        String_Copy(o->name, D_0048C160[i]);
        o->text = D_004ACB60[i];
        o->index = i;
        o->a = D_004ACBB0[i];
        o->b = D_004ACBD0[i];
        D_00494198 = i;
    } else {
        o->name[0] = 0;
        o->desc[0] = 0;
        o->text = -1;
        o->index = -1;
        o->a = 0;
    }
}