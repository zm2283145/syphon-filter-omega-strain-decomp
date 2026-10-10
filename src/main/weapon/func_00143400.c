#include "types.h"
typedef struct {
    unsigned char pad[0xA0]; unsigned char busy; unsigned char pa1[8]; unsigned char idx; unsigned char paa[2];
    float level[4]; int ptr[4]; float cc[4];
} Unit_b6;
extern int func_00143940(Unit_b6*, int);
int func_00143400(Unit_b6* s, int b)
{
    return !s->busy && s->level[s->idx] <= 0.0f && func_00143940(s, 6) > 0 && (b || !s->ptr[s->idx]) && !s->cc[s->idx];
}