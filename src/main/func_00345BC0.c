#include "types.h"

typedef struct Shape345 {
    int unk00;
    float a, b, c, d, e;   /* 0x04 - 0x14 */
    char part18[0x18];     /* 0x18 */
    char part30[8];        /* 0x30 */
    unsigned char flag;    /* 0x38 */
} Shape345;

extern void func_001BED80(void* dst, void* src);
extern float func_001BED70(void* src);
extern void func_001BED50(void* dst, void* ref, float value);

/* Copy-assigns a shape; returns dst. */
Shape345* func_00345BC0(Shape345* dst, Shape345* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    func_001BED80(dst->part18, src->part18);
    func_001BED50(dst->part30, dst->part18, func_001BED70(src->part30));
    dst->flag = src->flag;
    return dst;
}
