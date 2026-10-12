#pragma cplusplus on
#include "types.h"

struct VC00414B30 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };

struct Node414B30 {
    char pad0[0x1C];
    Node414B30* next;     /* 0x1C */
    Node414B30* focus;    /* 0x20 */
    char pad24[0x20];
    VC00414B30* obj;      /* 0x44 */
};

extern "C" void func_00414B30(Node414B30* self, Node414B30* w) {
    if (w != self->focus) {
        if (self->focus) {
            self->focus->obj->v8();
        }
        self->focus = w;
        if (self->focus) {
            self->focus->obj->v7();
            if (w == self->focus) {
                for (; w; w = w->next) {
                    if (w == self) break;
                    w->focus = self->focus;
                }
            }
        }
    }
}
