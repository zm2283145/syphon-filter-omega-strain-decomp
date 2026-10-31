#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct Item { void* what; float start; float end; };
struct Wrap { Item* p; };
struct It {
    Wrap m;
    It(Item* e) { m.p = e; }
    It(const It& o) { m.p = o.m.p; } It(const Wrap& w) : m(w) {} 
    Item* operator->() const { return &*m.p; }
    bool operator==(const It& o) const { return m.p == o.m.p; }
    bool operator!=(const It& o) const { return !(m.p == o.m.p); }
    void Inc() { m.p++; }
};
struct SwItem { void* what; char pad[16]; };
struct Switch { char pad[0x2C]; SwItem* items; };
struct Blend { char vec[4]; int n; Item* first; char padC[4]; float d0, d1; int pid; unsigned char rev; unsigned char sinus; };
struct TP { Switch* sw; Blend* trans; unsigned char active, isRev; int cur; int nxt; float timer; unsigned char needInterp; float interp; void* w0; void* w1; };
extern "C" Item** std_vector_deleter_cSkaBlendSequenceItem_data_void_2(const void* v);
static inline float MinF(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float Clamp01(float x) { float r; float hi; int t; asm { lui t, 0x3F80; mtc1 zero, r; mtc1 t, hi; max.s r, x, r; min.s r, r, hi } return r; }
// hi is read from v1, loaded by a separate asm at the start of the block
static inline float Clamp01W(float x) { float r; asm { mtc1 zero, r; mtc1 v1, f4; max.s r, x, r; min.s r, r, f4 } return r; }
static inline It End(const Blend* b) { return It(*std_vector_deleter_cSkaBlendSequenceItem_data_void_2(b) + b->n); }

static inline void* What(TP* s, int st) { return s->sw->items[st].what; }
extern "C" void cSkaTransPlayback_UpdateWhatToPlay(TP* self, const Blend* trans, float duration)
{
    void* play0; void* play1;
    float tn = MinF(1.0f, self->timer / duration);
    int listSize = trans->n;
    play0 = What(self, self->cur);
    play1 = What(self, self->nxt);
    It end = End(trans);
    It prev = end;
    It next = listSize > 0 ? It(trans->first) : end;
    float prevEnd = 0.0f;
    for (int i = 0; i < listSize + 1; i++) {
        if (i == listSize) next = It(end.m);
        bool notEnd = next != end;
        float nextStart = notEnd ? next->start : 1.0f;
        if (tn <= nextStart) {
            if (tn <= prevEnd) {
                self->w0 = (prev == end) ? play0 : (play0 = prev->what);
                self->w1 = self->w0;
                self->interp = 1.0f;
                self->needInterp = 0;
                return;
            } else {
                self->w0 = (prev == end) ? play0 : (play0 = prev->what);
                self->w1 = (next == end) ? play1 : (play1 = next->what);
                if (!trans->sinus) {
                    self->interp = Clamp01((tn - prevEnd) / (nextStart - prevEnd));
                } else {
                    asm { lui v1, 0x3F80 }
                    float x2;
                    float x = (tn - prevEnd) / (nextStart - prevEnd);
                    x2 = x * x;
                    x *= x2;
                    float c2 = 2.0f;
                    float c3 = 3.0f;
                    c3 *= x2;
                    c2 *= x;
                    float v = c3 - c2;
                    self->interp = Clamp01W(v);
                }
                self->needInterp = 1;
            }
            return;
        }
        prev = next;
        prevEnd = notEnd ? next->end : 1.0f;
        next.Inc();
    }
}









