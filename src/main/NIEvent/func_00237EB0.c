#include "types.h"

typedef struct {
    float value;
    int pad4;
    int count;
    float* keys;
    int pad10;
    int pad14;
    int time;
    unsigned char active;
    char pad1D[3];
} LightTrack237EB0;

typedef struct {
    char pad0[0x24];
    int kind;
} LightEv237EB0;

typedef struct {
    char pad0[0x170];
    LightTrack237EB0 a;
    LightTrack237EB0 b;
} LightObj237EB0;

extern int* Event_GetType(LightEv237EB0* ev);
extern int D_004F7C28;
extern void func_0023E890(LightObj237EB0* self, LightEv237EB0* ev);

static inline void LightTrack_Rewind(LightTrack237EB0* t) {
    t->time = 0;
    if (t->count > 0) {
        t->value = t->keys[1];
    }
}

void cNIEventLight_v01(LightObj237EB0* self, LightEv237EB0* ev) {
    int t = *Event_GetType(ev);
    if (t == D_004F7C28) {
        switch (ev->kind) {
        case 0:
            self->a.active = 1;
            self->b.active = 1;
            break;
        case 2:
            LightTrack_Rewind(&self->a);
            LightTrack_Rewind(&self->b);
            break;
        }
    }
    func_0023E890(self, ev);
}

