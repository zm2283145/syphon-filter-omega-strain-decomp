/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_List: 13 files, 0044F160-0044F700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044F160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Games.cc and SFOLobby_Lobby.cc; LobbyRecord1C accessors.
 */

#include "loose05_types.h"

void SFOLobbyList_SetBusy(LobbyRecord1C* self, char value) {
    self->refreshing = value;
}

unsigned char SFOLobbyList_IsBusy(LobbyRecord1C* self) {
    return self->refreshing;
}
static inline void merge_flush_func_0044F160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F160 */

/* merge_units: begin func_0044F180 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#include "types.h"
typedef struct {
    int cap;
    int count;
    int f8;
    int grow;
    int size;
    int data;
    signed char dirty;
    char pad19;
    unsigned char unique;
} Arr;
void SFOLobbyList_Append(Arr *a, int elem);
static inline int Arr_At(Arr *a, int i) {
    int d = a->data;
    if (d == 0) return 0;
    if (i < 0 || i >= a->count) return 0;
    return d + i * a->size;
}
void SFOLobbyList_CopyListFrom(Arr *dst, Arr *src) {
    int i;
    if (dst == 0 || src == 0) return;
    if (dst->size != src->size) return;
    if (dst->data != 0) {
        if (dst->count != 0) dst->dirty = 1;
        dst->count = 0;
    }
    for (i = 0; i < src->count; i++) {
        SFOLobbyList_Append(dst, Arr_At(src, i));
    }
}
static inline void merge_flush_func_0044F180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F180 */

/* merge_units: begin func_0044F280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after SFOLobby_Games.cc (ends 0x0044E960),
 * before SFOLobby_Lobby.cc (starts 0x0044FA70).
 */


void SFOLobbyList_SetUpdateFlag(char* self, char value) {
    self[24] = value;
}
static inline void merge_flush_func_0044F280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F280 */

/* merge_units: begin func_0044F290 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SFOLobbyList_GetSlot(int arg0, int arg1) {
    int temp_v1;

    temp_v1 = F_(arg0, 0x14, int);
    if (temp_v1 == 0) {
        return 0;
    }
    if ((arg1 < 0) || (arg1 >= F_(arg0, 0x4, int))) {
        return 0;
    }
    return temp_v1 + (arg1 * F_(arg0, 0x10, int));
}
static inline void merge_flush_func_0044F290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F290 */

/* merge_units: begin func_0044F2E0 */
#pragma push /* merge_units */
int memcpy(int, int, int);
int Libc_Memcmp(int, int, int);

static inline int Arr_At_0044F2E0(Arr *a, int i) {
    if (a->data == 0) return 0;
    if (i < 0 || i >= a->count) return 0;
    return a->data + i * a->size;
}

static inline void Arr_Set(Arr *a, int i, int elem) {
    int p;
    if (elem != 0) {
        p = Arr_At_0044F2E0(a, i);
        if (p != 0) {
            if (Libc_Memcmp(p, elem, a->size) != 0) {
                a->dirty = 1;
            }
            memcpy(p, elem, a->size);
        }
    }
}

void SFOLobbyList_DeleteSlot(Arr *a, int idx) {
    int i;
    if (Arr_At_0044F2E0(a, idx) != 0) {
        for (i = idx; i < a->count - 1; i++) {
            Arr_Set(a, i, Arr_At_0044F2E0(a, i + 1));
        }
        a->count--;
    }
}
static inline void merge_flush_func_0044F2E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F2E0 */

/* merge_units: begin func_0044F470 */
#pragma push /* merge_units */
int SFOLobby_MemFree(int);
int SFOLobby_MemAlloc(int);
#if 0 /* merge_units */
void SFOLobbyList_DeleteSlot(void *, int);
#endif /* merge_units */
#define SFOLobbyList_DeleteSlot(a0, a1) (SFOLobbyList_DeleteSlot((Arr *)(a0), (a1))) /* merge_units */


extern int D_00585E58;

static inline int Arr_At_0044F470(Arr *a, int i) {
    if (a->data == 0) return 0;
    if (i < 0 || i >= a->count) return 0;
    return a->data + i * a->size;
}

static inline void Arr_Set_0044F470(Arr *a, int i, int elem) {
    int p;
    if (elem != 0) {
        p = Arr_At_0044F470(a, i);
        if (p != 0) {
            if (Libc_Memcmp(p, elem, a->size) != 0) {
                a->dirty = 1;
            }
            memcpy(p, elem, a->size);
        }
    }
}

void SFOLobbyList_Append(Arr *a, int elem) {
    int i;
    int newcap;
    int p;

    if (a->data == 0) return;
    if (elem == 0) return;
    if (a->unique) {
        for (i = 0; i < a->count; i++) {
            p = Arr_At_0044F470(a, i);
            if (p != 0 && Libc_Memcmp(p, elem, a->size) == 0) return;
        }
    }
    if (a->cap < a->count + 1) {
        if (a->grow <= 0) {
            SFOLobbyList_DeleteSlot(a, 0);
        } else {
            newcap = a->cap + a->grow;
            p = SFOLobby_MemAlloc(newcap * a->size);
            D_00585E58 += newcap * a->size;
            if (p == 0) return;
            memcpy(p, a->data, a->cap * a->size);
            SFOLobby_MemFree(a->data);
            D_00585E58 -= a->cap * a->size;
            a->cap = newcap;
            a->data = p;
        }
    }
    a->count++;
    Arr_Set_0044F470(a, a->count - 1, elem);
    a->dirty = 1;
}
#undef SFOLobbyList_DeleteSlot /* merge_units */
static inline void merge_flush_func_0044F470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F470 */

/* merge_units: begin func_0044F6B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
int SFOLobbyList_CompactList();
#endif /* merge_units */
void SFOLobbyList_CompactList(); /* merge_units */
                                  

#pragma opt_common_subs off
void SFOLobbyList_ClearAndCompactList(int arg0) {
    int temp_v1;

    temp_v1 = F_(arg0, 0x14, int);
    if (temp_v1 != 0) {
        if (temp_v1 != 0) {
            if (F_(arg0, 0x4, int) != 0) {
                F_(arg0, 0x18, signed char) = 1;
            }
            F_(arg0, 0x4, int) = 0;
        }
        SFOLobbyList_CompactList();
    }
}
static inline void merge_flush_func_0044F6B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F6B0 */

/* merge_units: begin func_0044F700 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on


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
