#include "types.h"

typedef struct { char b[0x18]; } Part18;
typedef struct { char b[8]; } Part8;
typedef struct { int unk0; float f[5]; Part18 a; Part8 b; unsigned char flag; } Obj366;
extern void func_001BED80(Part18* dst, Part18* src);
extern float func_001BED70(Part8* p);
extern void func_001BED50(Part8* dst, Part18* a, float v);

/* Copies src into dst field by field; returns dst. */
Obj366* func_00366890(Obj366* dst, Obj366* src)
{
    dst->f[0] = src->f[0];
    dst->f[1] = src->f[1];
    dst->f[2] = src->f[2];
    dst->f[3] = src->f[3];
    dst->f[4] = src->f[4];
    func_001BED80(&dst->a, &src->a);
    func_001BED50(&dst->b, &dst->a, func_001BED70(&src->b));
    dst->flag = src->flag;
    return dst;
}
