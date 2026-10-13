#pragma cplusplus on
#include "types.h"

struct WeakT_80F0 { char pad0[0xC]; int serial; };
struct Slot_80F0 {
    int type; char pad4[0xC]; char name[0x10]; WeakT_80F0* obj; int serial; char pad28[0x18]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
    WeakT_80F0* Get() {
        bool isNull;
        bool ok;
        WeakT_80F0* t;
        t = obj;
        isNull = !t;
        ok = true;
        if (!isNull)
            if (t->serial != serial)
                ok = false;
        return ok ? t : 0;
    }
    bool Used() { return state != 0; }
    bool Stopping() { return state == 1 || state == 3; }
};
struct Ent_80F0 { char pad0[0x50]; Slot_80F0 sub; };
struct Self_80F0;
extern "C" {
extern char D_0049F4B0[];
extern char D_0049F4F0[];
int String_CompareNoCase(char*, char*);
int sprintf(char*, const char*, ...);
void func_001C83A0(Self_80F0*, signed char, int, int);
}

extern "C" void GameSound_StopSound(Self_80F0* self, Slot_80F0* d)
{
    int matched;
    int mode;
    int done;
    int found;
    Slot_80F0* s;
    int i;
    if (d->type == 5) {
        func_001C83A0(self, d->type, 0, 0);
        return;
    }
    if (d->type == 4) {
        func_001C83A0(self, d->type, 0, 1);
        return;
    }
    matched = 0;
    mode = 0;
    done = 0;
    found = 0;
    if (d->Get())
        mode = 1;
    while (!done) {
        for (i = 0; i < 50; i++) {
            s = &((Ent_80F0*)self)[i].sub;
            if (s->Used() || s->Stopping()) {
                if (d->type == s->type && String_CompareNoCase(d->name, s->name) == 0) {
                    WeakT_80F0* a = s->Get();
                    WeakT_80F0* b = d->Get();
                    found = 1;
                    if (mode && a && a == b) {
                        matched = 1;
                        break;
                    }
                    if (!mode && !a) {
                        matched = 1;
                        break;
                    }
                    if (mode == -1) {
                        matched = 1;
                        break;
                    }
                }
            }
        }
        if (!found)
            done = 1;
        else if (matched) {
            s->state = 0;
            done = 1;
        } else if (mode == -1)
            sprintf(D_0049F4B0, D_0049F4F0, d->name);
        else if (mode == 0)
            mode = -1;
        else if (mode == 1)
            mode = 0;
    }
}
