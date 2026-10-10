#include "types.h"

/* 32-byte temporary transform/curve value. */
typedef struct Temp32 {
    Q a;
    Q b;
} Temp32;

typedef struct AnimRootBase {
    char channel0[0x20];
    char ref20[0x10];
    char channel30[0x20];
    char channel50[0x20];
    char ref70[0x10];
    char channel80[0x20];
    unsigned char flagA0;
    unsigned char flagA1;
    unsigned char flagA2;
} AnimRootBase;

extern void Root_BaseConstruct(Temp32* t);
extern void VecPair_Copy(void* channel, Temp32* t);
extern void* Vec4_GetZero(void);
extern void Vec4_Assign(void* dst, void* src);

/* Constructs the base part of an animation root: four channels, two default refs, flags cleared. */
AnimRootBase* AnimRoot_ConstructBase(AnimRootBase* self) {
    Temp32 t4, t3, t2, t1;
    Root_BaseConstruct(&t1);
    VecPair_Copy(self->channel0, &t1);
    Vec4_Assign(self->ref20, Vec4_GetZero());
    Root_BaseConstruct(&t2);
    VecPair_Copy(self->channel30, &t2);
    Root_BaseConstruct(&t3);
    VecPair_Copy(self->channel50, &t3);
    Vec4_Assign(self->ref70, Vec4_GetZero());
    Root_BaseConstruct(&t4);
    VecPair_Copy(self->channel80, &t4);
    self->flagA0 = 0;
    self->flagA1 = 0;
    self->flagA2 = 0;
    return self;
}
