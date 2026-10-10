#include "types.h"
typedef struct { char data[0x18]; } Sub002C3280;
typedef struct { int unk0; float f[5]; Sub002C3280 sub; char sub30[8]; unsigned char flag; } Obj002C3280;
extern void func_001BED80(Sub002C3280* dst, Sub002C3280* src);
extern float func_001BED70(void* src);
extern void func_001BED50(void* dst, Sub002C3280* sub, float value);
/* Copy-assign. */
Obj002C3280* func_001BECC0(Obj002C3280* dst, Obj002C3280* src)
{
    dst->f[0] = src->f[0];
    dst->f[1] = src->f[1];
    dst->f[2] = src->f[2];
    dst->f[3] = src->f[3];
    dst->f[4] = src->f[4];
    func_001BED80(&dst->sub, &src->sub);
    func_001BED50(dst->sub30, &dst->sub, func_001BED70(src->sub30));
    dst->flag = src->flag;
    return dst;
}
