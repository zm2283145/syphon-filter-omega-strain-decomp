#include "types.h"

typedef struct Obj291 {
    int unk0;
    float values[5];
    char sub18[0x18];
    char sub30[8];
    unsigned char flag;
} Obj291;

extern void func_001BED80(void* dst, void* src);
extern float func_001BED70(void* src);
extern void func_001BED50(void* dst, void* ref, float value);

/* Copy-assigns src into dst (all fields but the first word); returns dst. */
Obj291* func_00291670(Obj291* dst, Obj291* src) {
    dst->values[0] = src->values[0];
    dst->values[1] = src->values[1];
    dst->values[2] = src->values[2];
    dst->values[3] = src->values[3];
    dst->values[4] = src->values[4];
    func_001BED80(dst->sub18, src->sub18);
    func_001BED50(dst->sub30, dst->sub18, func_001BED70(src->sub30));
    dst->flag = src->flag;
    return dst;
}
