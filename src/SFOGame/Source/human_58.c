/*
 * SFOGame/Source/human: 7 files, 00198E70-00199190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00198E70 */
#pragma push /* merge_units */
#include "types.h"
#include "human_types.h"

typedef struct { unsigned int capacity; int unk4; unsigned int start; int* data; } Ring00198EF0;
int* RingBuffer_At(Ring00198EF0* ring, unsigned int index); /* gsynth: defined below */
#if 0 /* merge_units */
void* func_00198F20(void* self); /* gsynth: defined below */
#endif /* merge_units */
void * func_00198F20(); /* merge_units */

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Deque of 248-byte elements, 8 per block: map at +0x00, start +0x10, size +0x14. */
#if 0 /* merge_units */
extern int** RingBuffer_At(void* map, unsigned int block);
#endif /* merge_units */
#define RingBuffer_At(a0, a1) ((int * *)RingBuffer_At((Ring00198EF0 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void* func_00198F20(void*);
#endif /* merge_units */
void * func_00198F20(); /* merge_units */



/* Construct an iterator holding value (goes through a stack temporary). */
int std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(int a0, int a1) {
    int loc[1];
    int v0, v1;

    v0 = a0;
    *(int*)(char*)loc = a1;
    v1 = *(int*)(char*)loc;
    *(int*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}

/* back(): address of the last element. */
char* Deque_Back(char* deque) {
    int last;
    int** slot;

    last = *(int*)(deque + 16) + *(int*)(deque + 20) - 1;
    slot = RingBuffer_At(func_00198F20(deque), (unsigned int)last >> 3);
    return (char*)*slot + (last & 7) * 248;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198E70(void) {}
#undef RingBuffer_At /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198E70 */

/* merge_units: begin func_00198EF0 */
#pragma push /* merge_units */
/* Address of element `index` (relative to start) in a circular buffer. */
int* RingBuffer_At(Ring00198EF0* ring, unsigned int index)
{
    return &ring->data[(ring->start + index) % ring->capacity];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198EF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198EF0 */

/* merge_units: begin func_00198F20 */
#pragma push /* merge_units */
extern int cSkaPlaybackList_FindPlaybackGroup(char*, int);
#if 0 /* merge_units */
extern char* Deque_Back(char*);
#endif /* merge_units */
#define Deque_Back(a0) (Deque_Back((a0))) /* merge_units */


extern char* cSkaParams_IsPlaybackActive(char*);

void* func_00198F20(void* self) {
    return self;
}

int MotionCtrl_IsSelectorPlaying(char* self, int key) {
    char* last;
    int found;

    last = cSkaParams_IsPlaybackActive(self);
    found = cSkaPlaybackList_FindPlaybackGroup(last, key);
    return found != 0;
}

/* Last element of the deque at +0x3C, offset +0xE8 into it. */
char* cSkaParams_IsPlaybackActive(char* self) {
    char* last;

    last = Deque_Back(self + 60);
    return last + 232;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198F20(void) {}
#undef Deque_Back /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198F20 */

/* merge_units: begin func_00198F90 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg_00198F90 {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg_00198F90;

typedef struct Human_00198F90 {
    char pad[0x346A];
    unsigned char value;
} Human_00198F90;

extern unsigned char g_IsMultiplayer;
extern char D_004EEE98[];
extern char D_004DA9D0[]; /* message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void cMessage_ctor_cMessageNameR(HumanMsg_00198F90* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(HumanMsg_00198F90* msg, void* target, int flags);
extern void cMessage_dtor(HumanMsg_00198F90* msg, int flags);

/* Stores the byte at +0x346C and, when g_IsMultiplayer is set and not silent, broadcasts it. */
void Actor_SetStunImmune(Human_00198F90* self, unsigned char value, int silent) {
    HumanMsg_00198F90 msg;
    self->value = value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 2;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198F90 */

/* merge_units: begin func_00199040 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg_00199040 {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg_00199040;

typedef struct Human_00199040 {
    char pad[0x346B];
    unsigned char value;
} Human_00199040;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HumanMsg_00199040* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(HumanMsg_00199040* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((HumanMsg_00198F90 *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(HumanMsg_00199040* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */



/* Stores the byte at +0x346C and, when g_IsMultiplayer is set and not silent, broadcasts it. */
void Actor_SetNotGasable(Human_00199040* self, unsigned char value, int silent) {
    HumanMsg_00199040 msg;
    self->value = value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 1;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199040(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00199040 */

/* merge_units: begin func_001990F0 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg;

typedef struct Human346C {
    char pad[0x346C];
    unsigned char value;
} Human346C;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HumanMsg* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(HumanMsg* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((HumanMsg_00198F90 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HumanMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */


/* Stores the byte at +0x346C and, when g_IsMultiplayer is set and not silent, broadcasts it. */
void cNetSetFlagMsg_Send(Human346C* self, unsigned char value, int silent) {
    HumanMsg msg;
    self->value = value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.value = value;
        msg.kind = 4;
        msg.size = 0x40;
        msg.extra = 0;
        QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_001990F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001990F0 */

/* merge_units: begin func_00199190 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x20]; signed char value; signed char which; char pad26[2]; } Msg_199190;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_199190* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_199190* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HumanMsg_00198F90 *)(a0), (a1))) /* merge_units */

extern signed char NetStream_ReadS8(void);
extern void Stream_ReadByte(signed char* out);
#if 0 /* merge_units */
extern void cNetSetFlagMsg_Send(void* self, unsigned char v, int silent);
#endif /* merge_units */
#define cNetSetFlagMsg_Send(a0, a1, a2) (cNetSetFlagMsg_Send((Human346C *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void Actor_SetStunImmune(void* self, unsigned char v, int silent);
#endif /* merge_units */
#define Actor_SetStunImmune(a0, a1, a2) (Actor_SetStunImmune((Human_00198F90 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void Actor_SetNotGasable(void* self, unsigned char v, int silent);
#endif /* merge_units */
#define Actor_SetNotGasable(a0, a1, a2) (Actor_SetNotGasable((Human_00199040 *)(a0), (a1), (a2))) /* merge_units */

void Actor_HandleNetSetFlag(void* self)
{
    Msg_199190 msg;
    signed char* wp;
    signed char* vp;
    cMessage_ctor_cMessageNameR(&msg, D_004EEE98);
    msg.vtable = D_004DA9D0;
    wp = &msg.which;
    *wp = NetStream_ReadS8();
    vp = &msg.value;
    Stream_ReadByte(vp);
    if (self) {
        signed char w = *wp;
        if (w == 0) cNetSetFlagMsg_Send(self, *vp != 0, 1);
        else if (w == 2) Actor_SetStunImmune(self, *vp != 0, 1);
        else if (w == 1) Actor_SetNotGasable(self, *vp != 0, 1);
    }
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetSetFlagMsg_Send /* merge_units */
#undef Actor_SetStunImmune /* merge_units */
#undef Actor_SetNotGasable /* merge_units */
static inline void merge_flush_func_00199190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00199190 */
