/*
 * main/ska: range (6 files, 003B8CB0-003B8FB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003B8CB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


int alloc_ptr_cSkaSystem_Request_int_capacity(char* self) {
    return *(int*)(self + 4);
}

int alloc_ptr_cSkaSystem_Request_int_allocator(char* self) {
    return *(int*)(self + 0);
}

int alloc_ptr_cSkaSystem_Request_int_get(char* self) {
    return *(int*)(self + 8);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8CB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8CB0 */

/* merge_units: begin func_003B8CE0 */
#pragma push /* merge_units */
typedef struct { int unk0; int begin; int end; } RangeColl;
RangeColl* GroupCollection_CopyConstruct(RangeColl* self, RangeColl* src); /* gsynth: defined below */SkaFlaggedVec* NotifyRange_CopyConstruct(SkaFlaggedVec* dst, SkaFlaggedVec* src); /* gsynth: defined below */SkaNotifyTable* NotifyTable_CopyConstruct(SkaNotifyTable* dst, SkaNotifyTable* src); /* gsynth: defined below */extern char D_004DFD80[]; /* base message vtable */
extern char D_004DA930[]; /* blend channel vtable */

typedef struct ChannelBase {
    void* vtable;
    int w[7];
    signed char flag;
} ChannelBase;

typedef struct Channel {
    ChannelBase base;
    int target;
    signed char mode;
    int count;
    unsigned char active;
    float weight;
} Channel;

typedef struct { char data[0x38]; } Track;
typedef struct { char data[0x10]; } Curve;
typedef struct { char data[0xC]; float scale; } Ramp;

typedef struct BlendState {
    unsigned char kind;
    char pad[3];
    Track track;            /* 0x04 */
    Curve curve;            /* 0x3C */
} BlendState;

typedef struct BlendRecord {
    unsigned char type;     /* 0x00 */
    unsigned char layer;    /* 0x01 */
    int id;                 /* 0x04 */
    float f[5];             /* 0x08 */
    int a;                  /* 0x1C */
    int b;                  /* 0x20 */
    Channel ch[2];          /* 0x24, 0x5C */
    BlendState state;       /* 0x94 */
    float start;            /* 0xE0 */
    float end;              /* 0xE4 */
    Ramp ramp;              /* 0xE8 */
} BlendRecord;

#if 0 /* merge_units */
extern void NotifyTable_CopyConstruct(Track* dst, Track* src);
#endif /* merge_units */
#define NotifyTable_CopyConstruct(a0, a1) ((void)NotifyTable_CopyConstruct((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void NotifyRange_CopyConstruct(Curve* dst, Curve* src);
#endif /* merge_units */
#define NotifyRange_CopyConstruct(a0, a1) ((void)NotifyRange_CopyConstruct((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void GroupCollection_CopyConstruct(Ramp* dst, Ramp* src);
#endif /* merge_units */
#define GroupCollection_CopyConstruct(a0, a1) ((void)GroupCollection_CopyConstruct((void *)(a0), (void *)(a1))) /* merge_units */


static inline void ChannelBase_Copy(ChannelBase* d, ChannelBase* s)
{
    d->vtable = D_004DFD80;
    d->w[0] = s->w[0];
    d->w[1] = s->w[1];
    d->w[2] = s->w[2];
    d->w[3] = s->w[3];
    d->w[4] = s->w[4];
    d->w[5] = s->w[5];
    d->w[6] = s->w[6];
    d->flag = s->flag;
}

static inline void Channel_Copy(Channel* d, Channel* s)
{
    ChannelBase_Copy(&d->base, &s->base);
    d->base.vtable = D_004DA930;
    d->target = s->target;
    d->mode = s->mode;
    d->count = s->count;
    d->active = s->active;
    d->weight = s->weight;
}

static inline void BlendState_Copy(BlendState* d, BlendState* s)
{
    d->kind = s->kind;
    NotifyTable_CopyConstruct(&d->track, &s->track);
    NotifyRange_CopyConstruct(&d->curve, &s->curve);
}

static inline void Ramp_Copy(Ramp* d, Ramp* s)
{
    GroupCollection_CopyConstruct(d, s);
    d->scale = s->scale;
}

/* Copy constructor for a blend record. */
BlendRecord* BlendRecord_CopyConstruct(BlendRecord* d, BlendRecord* s)
{
    BlendState* state = &d->state;
    Ramp* ramp;
    d->type = s->type;
    d->layer = s->layer;
    d->id = s->id;
    d->f[0] = s->f[0];
    d->f[1] = s->f[1];
    d->f[2] = s->f[2];
    d->f[3] = s->f[3];
    d->f[4] = s->f[4];
    d->a = s->a;
    d->b = s->b;
    Channel_Copy(&d->ch[0], &s->ch[0]);
    Channel_Copy(&d->ch[1], &s->ch[1]);
    BlendState_Copy(state, &s->state);
    d->start = s->start;
    d->end = s->end;
    ramp = &d->ramp;
    Ramp_Copy(ramp, &s->ramp);
    return d;
}
#undef NotifyTable_CopyConstruct /* merge_units */
#undef NotifyRange_CopyConstruct /* merge_units */
#undef GroupCollection_CopyConstruct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8CE0 */

/* merge_units: begin func_003B8EB0 */
#pragma push /* merge_units */
extern void List_Construct(RangeColl* self);
extern void List_CopyRange(RangeColl* self, int end, int beginRef);

/* Copy constructor: default-initializes self, then inserts src's range. */
RangeColl* GroupCollection_CopyConstruct(RangeColl* self, RangeColl* src)
{
    int first[1];
    int last[1];
    List_Construct(self);
    first[0] = (int)&src->begin;
    last[0] = src->end;
    List_CopyRange(self, *(int*)last, *(int*)first);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8EB0 */

/* merge_units: begin func_003B8F10 */
#pragma push /* merge_units */
typedef struct Elem20 {
    char data[20];
} Elem20;
typedef struct Array20 {
    int unk0;
    int count;
    Elem20* items;
} Array20;
Array20* MotionArray_CopyConstruct(Array20* self, Array20* src); /* gsynth: defined below */
#if 0 /* merge_units */
extern SkaFlaggedVec* MotionArray_CopyConstruct(SkaFlaggedVec* dst, SkaFlaggedVec* src);
#endif /* merge_units */
#define MotionArray_CopyConstruct(a0, a1) ((SkaFlaggedVec *)MotionArray_CopyConstruct((void *)(a0), (void *)(a1))) /* merge_units */


/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* NotifyRange_CopyConstruct(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    MotionArray_CopyConstruct(dst, src);
    dst->flag = src->flag;
    return dst;
}
#undef MotionArray_CopyConstruct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8F10 */

/* merge_units: begin func_003B8F50 */
#pragma push /* merge_units */
extern void Array_CopyRange20(Array20* self, Elem20* first, Elem20* last, char alloc);

/* Copy constructor: clears the array, then inserts [src->items, src->items + count). */
Array20* MotionArray_CopyConstruct(Array20* self, Array20* src) {
    volatile char alloc[4];
    self->unk0 = 0;
    self->count = 0;
    self->items = 0;
    Array_CopyRange20(self, src->items, src->items + src->count, alloc[0]);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8F50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8F50 */

/* merge_units: begin func_003B8FB0 */
#pragma push /* merge_units */
extern void __construct_array(void* array, void* ctor, void* dtor, int elemSize, int count);
extern int func_0018A210(int, int);
extern int cSkaAnimEvent_ctor_void(int);

/* Copy-construct the notification table: construct seven 8-byte entries, then copy all fourteen words. */
SkaNotifyTable* NotifyTable_CopyConstruct(SkaNotifyTable* dst, SkaNotifyTable* src) {
    __construct_array(dst, (void*)cSkaAnimEvent_ctor_void, (void*)func_0018A210, 8, 7);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B8FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B8FB0 */
