#include "types.h"

typedef struct Shape139 {
    Q rows[4];               /* 0x00 */
    char part40[0x10];       /* 0x40 (bytes 0x40, 0x42 cleared first) */
    unsigned char flag50;    /* 0x50 */
    unsigned char flag51;    /* 0x51 */
    unsigned char flag52;    /* 0x52 */
    char pad53[0xD];
    int part60[2];           /* 0x60 */
} Shape139;

extern void Vec4_Copy(Q* dst, Q* src);
extern void func_00139BB0(void* dst, void* src);
extern void func_00139BA0(void* dst, void* src);

/* Copy-assigns a shape; returns dst. */
Shape139* func_00139B00(Shape139* dst, Shape139* src) {
    dst->part40[0] = 0;
    dst->part40[2] = 0;
    dst->part60[0] = 0;
    dst->part60[1] = 0;
    Vec4_Copy(&dst->rows[0], &src->rows[0]);
    Vec4_Copy(&dst->rows[1], &src->rows[1]);
    Vec4_Copy(&dst->rows[2], &src->rows[2]);
    Vec4_Copy(&dst->rows[3], &src->rows[3]);
    dst->flag50 = src->flag50;
    func_00139BB0(dst->part40, src->part40);
    func_00139BA0(dst->part60, src->part60);
    dst->flag51 = src->flag51;
    dst->flag52 = src->flag52;
    return dst;
}
