/*
 * main/gameSound: range (4 files, 001C7D80-001C80F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C7D80 */
#pragma push /* merge_units */
typedef struct { int type; char pad[0x3C]; void* ptr; unsigned char flag; } G3S_001C7D80;
typedef struct { char pad[0x50]; G3S_001C7D80 s; char pad2[0x1B0 - 0x50 - sizeof(G3S_001C7D80)]; } G3E_001C7D80;
extern void snd_StopSound(void* p);
extern void snd_FlushSoundCommands(void);
void func_001C7D80(G3E_001C7D80* arg) {
    int i;
    G3S_001C7D80* s;
    G3E_001C7D80* e = arg;
    for (i = 0; i < 50; i++, e++) {
        s = &e->s;
        if (s->type == 5) {
            if (s->ptr) {
                snd_StopSound(s->ptr);
                s->ptr = 0;
            }
            s->flag = 0;
        }
    }
    snd_FlushSoundCommands();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7D80 */

/* merge_units: begin func_001C7E00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct SndEv_7E00 { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; unsigned char on; };
struct Slot_7E00 {
    int type; char pad4[0x3C]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
    bool NotFree() { return (state == 0) ^ 1; }
    bool NotStopping() { return !(state == 1 || state == 3); }
    unsigned char IsActive() {
        unsigned char r = 0;
        if (NotFree())
            if (NotStopping())
                r = 1;
        return r;
    }
};
struct Ent_7E00 { char pad0[0x50]; Slot_7E00 sub; };
struct Self_7E00 { char pad0[0x20]; unsigned char on; };
extern "C" {
extern char D_0049F4A0[];
extern char D_004D9DE0[];
extern void * const D_004DAC30[];
void* Mem_Alloc(int, int, char*, int);
void EventQueue_Admit(SndEv_7E00*);
void snd_AutoVol(int, int, int, int);
void snd_ContinueAllSoundsInGroup(int);
void snd_PauseAllSoundsInGroup(int);
}

extern "C" void func_001C7E00(Self_7E00* self, int on)
{
    Slot_7E00* found = 0;
    int i;
    for (i = 0; i < 50; i++) {
        Slot_7E00* s = &((Ent_7E00*)self)[i].sub;
        if (((Ent_7E00*)self)[i].sub.type == 5) {
            if (s->IsActive()) {
                found = s;
                break;
            }
        }
    }
    if (on && !self->on) {
        if (found) {
            SndEv_7E00* e;
            snd_AutoVol(found->handle, 0, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)Mem_Alloc(0, 0x10, D_0049F4A0, 0x591);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 1;
            }
            EventQueue_Admit(e);
        } else {
            snd_PauseAllSoundsInGroup(2);
        }
        self->on = 1;
    }
    if (!on && self->on) {
        if (found) {
            SndEv_7E00* e;
            snd_AutoVol(found->handle, 0x400, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)Mem_Alloc(0, 0x10, D_0049F4A0, 0x5A2);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 0;
            }
            EventQueue_Admit(e);
        } else {
            snd_ContinueAllSoundsInGroup(2);
        }
        self->on = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7E00 */

/* merge_units: begin func_001C80B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char on; } S1C80B0;
extern void snd_PauseAllSoundsInGroup(int);
extern void snd_ContinueAllSoundsInGroup(int);
void func_001C80B0(S1C80B0* s) { if (s->on) snd_PauseAllSoundsInGroup(2); else snd_ContinueAllSoundsInGroup(2); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C80B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C80B0 */

/* merge_units: begin func_001C80F0 */
#pragma push /* merge_units */
#pragma cplusplus on

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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C80F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C80F0 */
