/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_List: 6 files, 0044F700-0044FA00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044F700 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_MemFree(int);                               
int SFOLobby_MemAlloc(int);                             
int memcpy(int, int, int);                            
extern int D_00585E58;

typedef struct { int f0; int f4; int f8; char pC[4]; int f10; int f14; } PS0_0044F700;
void SFOLobbyList_CompactList(PS0_0044F700 *arg0) {
    int temp_v0;
    int var_s1;
    int temp_s0;

    if (arg0->f14 != 0) {
        var_s1 = arg0->f4;
        temp_v0 = arg0->f8;
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
        if (var_s1 <= 0) {
            var_s1 = 1;
        }
        temp_s0 = SFOLobby_MemAlloc(var_s1 * arg0->f10);
        D_00585E58 += var_s1 * arg0->f10;
        if (temp_s0 != 0) {
            memcpy(temp_s0, arg0->f14, arg0->f4 * arg0->f10);
            SFOLobby_MemFree(arg0->f14);
            D_00585E58 -= arg0->f0 * arg0->f10;
            arg0->f0 = var_s1;
            arg0->f14 = temp_s0;
        }
    }
}
static inline void merge_flush_func_0044F700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F700 */

/* merge_units: begin func_0044F7E0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
void SFOLobbyList_ClearList(int arg0) {
    if (F_(arg0, 0x14, int) != 0) {
        if (F_(arg0, 0x4, int) != 0) {
            F_(arg0, 0x18, signed char) = 1;
        }
        F_(arg0, 0x4, int) = 0;
    }
}
static inline void merge_flush_func_0044F7E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F7E0 */

/* merge_units: begin func_0044F810 */
#pragma push /* merge_units */
#pragma opt_common_subs off
void SFOLobbyList_FreeList(int arg0) {
    int temp_a0;

    temp_a0 = F_(arg0, 0x14, int);
    if (temp_a0 != 0) {
        SFOLobby_MemFree(temp_a0);
        D_00585E58 -= F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
    }
    F_(arg0, 0x0, int) = 0;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x14, int) = 0;
    F_(arg0, 0x18, signed char) = 1;
}
static inline void merge_flush_func_0044F810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F810 */

/* merge_units: begin func_0044F880 */
#pragma push /* merge_units */
#pragma opt_common_subs off
void SFOLobbyList_AllocList(int arg0, int arg1, int arg2, int arg3) {
    int temp_a0;

    temp_a0 = F_(arg0, 0x14, int);
    if (temp_a0 != 0) {
        SFOLobby_MemFree(temp_a0);
        D_00585E58 -= F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
    }
    F_(arg0, 0x0, int) = 0;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x14, int) = 0;
    F_(arg0, 0x18, signed char) = 1;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x0, int) = arg1;
    F_(arg0, 0xC, int) = arg2;
    F_(arg0, 0x10, int) = arg3;
    if (F_(arg0, 0x0, int) < 5) {
        F_(arg0, 0x0, int) = 5;
    }
    F_(arg0, 0x8, int) = F_(arg0, 0x0, int);
    F_(arg0, 0x18, signed char) = 1;
    F_(arg0, 0x14, int) = SFOLobby_MemAlloc(F_(arg0, 0x0, int) * F_(arg0, 0x10, int));
    D_00585E58 += F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
}
static inline void merge_flush_func_0044F880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F880 */

/* merge_units: begin func_0044F970 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                               
int operator_delete(char * );

typedef struct { int f0; int f4; char p8[8]; int f10; int f14; signed char f18; } PS0_0044F970;
char * SFOLobbyList_dtor(PS0_0044F970 *arg0, long long arg1) {
    int temp_a0;

    if (arg0 != NULL) {
        temp_a0 = arg0->f14;
        if (temp_a0 != 0) {
            SFOLobby_MemFree(temp_a0);
            D_00585E58 -= arg0->f0 * arg0->f10;
        }
        arg0->f0 = 0;
        arg0->f4 = 0;
        arg0->f14 = 0;
        arg0->f18 = 1;
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
static inline void merge_flush_func_0044F970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F970 */

/* merge_units: begin func_0044FA00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc (starts 0x0044FA70).
 */

#include "loose05_types.h"

extern int D_00585FA8;

/* Constructor: clears the record; dirty defaults to 1. */
LobbyRecord1C* SFOLobbyList_ctor(LobbyRecord1C* self) {
    self->elemSize = 0;
    self->grow = 0;
    self->initialCapacity = 0;
    self->count = 0;
    self->capacity = 0;
    self->data = 0;
    self->dirty = 1;
    self->refreshing = 0;
    self->unique = 0;
    self->dirty = 1;
    return self;
}

/* True when D_00585FA8 is set and the object's flag at +0x17C is clear. */
int func_0044FA40(Lobby17C* self) {
    int ret;

    ret = 0 < (unsigned int)D_00585FA8;
    if (ret != 0) {
        ret = (0 < (unsigned int)self->unk17C) ^ 1;
    }
    return ret;
}
static inline void merge_flush_func_0044FA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044FA00 */
