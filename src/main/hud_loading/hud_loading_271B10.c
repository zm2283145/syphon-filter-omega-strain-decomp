#include "types.h"
typedef struct { int a; void* snd; } B5cObj;
extern void IeElement_Fade(void* s, float v);
extern void IeElement_UpdateAnimation(void* s, float v);
void LoadingScreen_SetProgress(B5cObj* o, float x) {
    if (x < 0.0f) x = 0.0f;
    if (x > 1.0f) x = 1.0f;
    if (o->snd) {
        IeElement_Fade(o->snd, 10.0f + 7.0f * x);
        IeElement_UpdateAnimation(o->snd, 7.0f);
    }
}