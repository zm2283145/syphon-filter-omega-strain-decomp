#include "types.h"

typedef struct { char pad0[0x20]; int idx; char vec[4]; } TSel;
typedef struct { char pad0[0x10]; float from; float to; int chan; unsigned char sync; char pad1D[3]; int next; } TElem;
typedef struct { int n; float dt[1]; } TCtx;
typedef struct {
    TSel* sel; TElem* elem; unsigned char b8; unsigned char rev; char padA[2];
    int cur; int nxt; float t;
} TTrans;

void* cArray_cSkaSwitchItem_opIndex(void* v, int i);
TElem* cSkaSwitchItem_GetTrans(void* t, int i);
float AnimChannel_GetCurrent(TCtx* c, int i);
void* cSkaParams_GetSwitchValue(TCtx* c, int i);
int cSkaSwitchValue_CurrGoalState(void* p);
void AnimTransition_GetProgress(TTrans* t, TElem* e, float w);

/* Last frame delta: ctx->dt[n-1]; the byte-offset form keeps retail's addiu -1 / lwc1 4(..) */
#define DT(c) (*(float*)((char*)(c) + 4 + ((c)->n - 1) * 4))
int cSkaTransPlayback_NextFrame(TTrans* self, TCtx* ctx)
{
    TElem* e;
    int more;
    float w;
    do {
        e = cSkaSwitchItem_GetTrans(cArray_cSkaSwitchItem_opIndex(&self->sel->vec, self->cur), self->nxt);
        more = e->next != -1;
        if (more) self->nxt = e->next;
    } while (more);
    self->elem = e;
    if (e->chan == -1) {
        w = e->from;
    } else {
        float r = AnimChannel_GetCurrent(ctx, e->chan); w = e->from + r * (e->to - e->from);
    }
    if (w != 0.0f) {
        int target = cSkaSwitchValue_CurrGoalState(cSkaParams_GetSwitchValue(ctx, self->sel->idx));
        unsigned char done = 0;
        if (e->sync) {
            if (self->rev == 0) {
                if (target == self->cur) self->rev = 1;
            } else if (target == self->nxt) {
                self->rev = 0;
            }
        }
        if (self->rev == 0) {
            self->t += DT(ctx);
            if (!(self->t < w)) {
                self->cur = self->nxt;
                self->nxt = target;
                self->t = 0.0f;
                if (self->cur == target) done = 1;
            }
        } else {
            self->t -= DT(ctx);
            if (self->t <= 0.0f) {
                self->rev = 0;
                self->nxt = target;
                self->t = 0.0f;
                if (self->cur == target) done = 1;
            }
        }
        if (!done) {
            AnimTransition_GetProgress(self, e, w);
            return 0;
        }
    }
    return 1;
}



