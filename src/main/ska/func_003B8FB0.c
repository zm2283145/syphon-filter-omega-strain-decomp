/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern void __construct_array(void* array, void* ctor, void* dtor, int elemSize, int count);
extern int func_0018A210(int, int);
extern int func_0018A870(int);

/* Copy-construct the notification table: construct seven 8-byte entries, then copy all fourteen words. */
SkaNotifyTable* NotifyTable_CopyConstruct(SkaNotifyTable* dst, SkaNotifyTable* src) {
    __construct_array(dst, (void*)func_0018A870, (void*)func_0018A210, 8, 7);
    dst->words[0] = src->words[0];
    dst->words[1] = src->words[1];
    dst->words[2] = src->words[2];
    dst->words[3] = src->words[3];
    dst->words[4] = src->words[4];
    dst->words[5] = src->words[5];
    dst->words[6] = src->words[6];
    dst->words[7] = src->words[7];
    dst->words[8] = src->words[8];
    dst->words[9] = src->words[9];
    dst->words[10] = src->words[10];
    dst->words[11] = src->words[11];
    dst->words[12] = src->words[12];
    dst->words[13] = src->words[13];
    return dst;
}
