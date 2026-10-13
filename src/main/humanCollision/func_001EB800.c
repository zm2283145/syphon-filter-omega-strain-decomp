#include "types.h"
#include "humanCollision_types.h"

extern void HumanColBufA_Init(HumanColVec* v);
extern void HumanColBufA_Reserve(HumanColVec* v, int capacity); /* vector reserve (buffer A) */

/* Constructor for buffer A: empty vector, reserve *capacity, store the flag byte; returns v. */
HumanColVec* HumanColBufA_Ctor(HumanColVec* v, int* capacity, char flag)
{
    HumanColBufA_Init(v);
    HumanColBufA_Reserve(v, *capacity);
    v->flag0C = flag;
    return v;
}
