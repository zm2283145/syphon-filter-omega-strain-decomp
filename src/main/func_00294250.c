#include "types.h"
typedef struct { char pad[0x1C]; int id; } T294250;
typedef struct { char pad[0x20]; T294250* t; } G294250;
typedef struct {
    char pad0[0x1D4];
    unsigned char idx;
    char pad1[3];
    int ids[62];
    T294250* objs[6];
    unsigned char flag;
} S294250;
extern G294250* func_004147A0(void);
extern T294250* func_0041D8C0(S294250* s);
T294250* func_00294250(S294250* s)
{
    int id;
    T294250* o = s->objs[s->idx];
    if (o && o->id == s->ids[s->idx]) {
        if (s->flag || (func_004147A0()->t && (id = func_004147A0()->t->id, id != s->ids[s->idx]))) {
            s->flag = 0;
            return s->objs[s->idx];
        }
    }
    return func_0041D8C0(s);
}