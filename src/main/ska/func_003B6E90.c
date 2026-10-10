#include "types.h"

/* Retail loads the byte fields before storing them (copy propagation off). */
#pragma opt_propagation off

typedef struct { char data[0x50]; } Part50;
typedef struct {
    Part50 a;               /* +0x00 */
    Part50 b;               /* +0x50 */
    unsigned char c[3];     /* +0xA0 */
    char padA3[0xB0 - 0xA3];
    int value;              /* +0xB0 */
    char sub[0xC];          /* +0xB4 */
    unsigned char flag;     /* +0xC0 */
} RecC0;
extern void func_003B6F10(Part50* dst, Part50* src);
extern void func_001C50A0(void* dst, void* src);

/* Copy: both parts, three bytes, a word, the sub-object and the flag; returns dst. */
RecC0* func_003B6E90(RecC0* dst, RecC0* src)
{
    unsigned char c0, c1, c2;
    func_003B6F10(&dst->a, &src->a);
    func_003B6F10(&dst->b, &src->b);
    c0 = src->c[0];
    c1 = src->c[1];
    c2 = src->c[2];
    dst->c[0] = c0;
    dst->c[1] = c1;
    dst->c[2] = c2;
    dst->value = src->value;
    func_001C50A0(dst->sub, src->sub);
    dst->flag = src->flag;
    return dst;
}
