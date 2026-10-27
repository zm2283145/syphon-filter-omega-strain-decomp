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
extern void cSkaAnimAnchor_TreeNodeData_tData_opAssign(Part50* dst, Part50* src);
extern void std_vector_pod_int_opAssign(void* dst, void* src);

/* Copy: both parts, three bytes, a word, the sub-object and the flag; returns dst. */
RecC0* cTreeNode_cSkaAnimAnchor_TreeNodeData_opAssign(RecC0* dst, RecC0* src)
{
    unsigned char c0, c1, c2;
    cSkaAnimAnchor_TreeNodeData_tData_opAssign(&dst->a, &src->a);
    cSkaAnimAnchor_TreeNodeData_tData_opAssign(&dst->b, &src->b);
    c0 = src->c[0];
    c1 = src->c[1];
    c2 = src->c[2];
    dst->c[0] = c0;
    dst->c[1] = c1;
    dst->c[2] = c2;
    dst->value = src->value;
    std_vector_pod_int_opAssign(dst->sub, src->sub);
    dst->flag = src->flag;
    return dst;
}
