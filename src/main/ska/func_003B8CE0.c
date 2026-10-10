#include "types.h"
extern char D_004DFD80[]; /* base message vtable */
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

extern void NotifyTable_CopyConstruct(Track* dst, Track* src);
extern void NotifyRange_CopyConstruct(Curve* dst, Curve* src);
extern void GroupCollection_CopyConstruct(Ramp* dst, Ramp* src);

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
