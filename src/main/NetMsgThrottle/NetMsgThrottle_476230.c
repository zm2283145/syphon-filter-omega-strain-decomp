/*
 * main/NetMsgThrottle: 3 files, 00476230-00476490
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00476230 */
#pragma push /* merge_units */
#include "types.h"
typedef struct H1Phys { char pad000[0x980]; Vec4 ladderRef; } H1Phys;
typedef struct H1Actor {
    char pad0000[0x3298];
    void* laddRoot;
    char pad329C[0x3310 - 0x329C];
    H1Phys* phys;
} H1Actor;
extern void* Root_GetWorldPlacement(void* root);
extern Vec4* Placement_GetPosition(void* placement);
static inline void h1_cp(Vec4* d, const Vec4* s) { *d = *s; }
#pragma peephole off
#pragma opt_propagation off
float cHuman_GetDistanceAlongLadderFromEntryPointInTermsOfNumberOfGraspableRungs(H1Actor* self) {
    H1Actor* s = self;
    if (self->phys != 0) {
        float z = Placement_GetPosition(Root_GetWorldPlacement(s->laddRoot))->z;
        Vec4 ref;
        h1_cp(&ref, &s->phys->ladderRef);
        return z - ref.z;
    }
    return 0.0f;
}
#pragma opt_propagation reset
#pragma peephole reset
#pragma pop /* merge_units */
/* merge_units: end func_00476230 */

/* merge_units: begin func_004762A0 */
#pragma push /* merge_units */
typedef struct H1LadPhys {
    char pad000[0x99C];
    unsigned char blockTop;      /* 0x99C */
    unsigned char blockBottom;   /* 0x99D */
    unsigned char pad99E;
    unsigned char snapped;       /* 0x99F */
} H1LadPhys;
typedef struct H1Actor62A0 {
    char pad0000[0x31B5];
    unsigned char slideHeld;     /* 0x31B5 */
    unsigned char exitHeld;      /* 0x31B6 */
    char pad31B7[0x31C8 - 0x31B7];
    float stickY;                /* 0x31C8 */
    char pad31CC[0x31D8 - 0x31CC];
    float slideAmount;           /* 0x31D8 */
    char pad31DC[0x3210 - 0x31DC];
    int padFlags;                /* 0x3210 */
    char pad3214[0x3310 - 0x3214];
    H1LadPhys* phys;             /* 0x3310 */
} H1Actor62A0;
static inline float h1_fabs(float x) { asm { abs.s x, x } return x; }

/* Climb intent: slide / up / down, plus the three requested values. */
void Ladder_Intent(H1Actor62A0* self, unsigned char* outSlide, unsigned char* outUp, unsigned char* outDown,
                   unsigned char* slide, unsigned char* up, unsigned char* down) {
    H1LadPhys* p = self->phys;
    unsigned char centered;
    unsigned char blockTop;
    unsigned char blockBottom;
    unsigned char onRung;
    unsigned char aligned;
    blockTop = 0;
    if (p != 0 && p->blockTop) blockTop = 1;
    blockBottom = 0;
    if (p != 0 && p->blockBottom) blockBottom = 1;
    onRung = p != 0 && p->snapped;
    aligned = onRung; if (aligned) aligned = ((self->padFlags >> 13) & 1) != 0;
    centered = aligned; if (aligned) centered = h1_fabs(self->stickY) < 0.5f;    *slide = (self->slideHeld || self->slideAmount > 0.75f) && !self->exitHeld;
    *up = !*slide && self->stickY > 0.0f && !centered && !self->exitHeld;
    *down = !*slide && self->stickY < 0.0f && !centered && !self->exitHeld;
    *outSlide = *slide && !blockTop;
    *outUp = *up && !blockBottom;
    *outDown = *down && !blockTop;
}
#pragma pop /* merge_units */
/* merge_units: end func_004762A0 */

/* merge_units: begin func_00476490 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;  /* 0x20 */
    char pad21[3];
    int action;         /* 0x24 */
    unsigned char b28;  /* 0x28 */
} NavDirMsg_h5;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void Event_Construct(NavDirMsg_h5* msg, void* name);
extern void Event_Send(NavDirMsg_h5* msg, void* target, int flags);
extern void cMessage_dtor(NavDirMsg_h5* msg, int flags);

static inline float h5_fabs(float x) { float r; asm { abs.s r, x } return r; }
int Ladder_AiNavRequest(void* actor, float* dir)
{
    float x = dir[0];
    signed char action = -1;
    if (h5_fabs(x) < 0.5f) {
        if (dir[2] < 0.0f) {
            action = 0x1F;
        } else if (!(dir[2] <= 0.0f)) {
            action = 0x20;
        }
    } else if (x < 0.0f) {
        action = 0x21;
    } else {
        action = 0x22;
    }
    if (action != -1) {
        NavDirMsg_h5 msg;
        Event_Construct(&msg, g_ActorActionMsgClass);
        msg.vtable = D_004E0840;
        msg.action = action;
        msg.b20 = 1;
        msg.b28 = 0;
        Event_Send(&msg, actor, 1);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00476490 */
