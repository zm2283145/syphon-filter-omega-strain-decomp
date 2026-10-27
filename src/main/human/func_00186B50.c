#include "types.h"
/* cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration: retarget to the last key and rescale the blend rates for a new duration */
typedef struct Pt1HkKey { float t; float value; } Pt1HkKey;
typedef struct Pt1HkSrc { char pad[0x10]; float value; } Pt1HkSrc;
typedef struct Pt1HkHeading {
    char pad0[0x30];
    float target;
    char pad34[0x3C - 0x34];
    float rateA;
    char pad40[4];
    float rateB;
    float duration;
    float invDuration;
    Pt1HkSrc* src;
    float srcValue;
    char pad58[4];
    int count;
    Pt1HkKey* keys;
} Pt1HkHeading;
void cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(Pt1HkHeading* h, float duration)
{
    float k;
    float inv;
    h->target = ((Pt1HkKey*)((char*)h->keys + (h->count << 3)))[-1].value;
    if (duration < 0.0f)
        return;
    k = duration * h->invDuration;
    h->rateA = h->rateA * k;
    h->rateB = h->rateB * k;
    h->duration = duration;
    h->invDuration = duration != 0.0f ? 1.0f / duration : 0.0f;
    h->srcValue = h->src->value;
}