#pragma cplusplus on
/* cGameSound_StopVAG: fades out the playing music slot(s) of a type and
 * queues a fade event that starts `next` when done (transition record 0 at
 * D_004F2CD0). Shape follows cGameSound_PauseMusic (gameSound_1C7D80.c). */
#include "alloc_guard.h"

struct Slot_83A0 {
    int type; char pad4[0xC]; char name[0x30]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
};
struct Ent_83A0 { char pad0[0x50]; Slot_83A0 sub; };
struct Trans_83A0 { Slot_83A0* from; Slot_83A0* to; unsigned char active; };
struct SndEv_83A0 { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; Trans_83A0* rec; };
extern "C" {
extern unsigned char D_0048A330;
extern Trans_83A0 D_004F2CD0[2];
extern char D_0049F4A0[];
extern char D_004D9DE0[];
extern void * const D_004DAC90[];
void* cMemMan_Allocate(int, int, char*, int);
void nCallback_SetCallback(SndEv_83A0*);
void snd_AutoVol(int, int, int, int);
int String_CompareNoCase(const char*, const char*);
}

extern "C" void cGameSound_StopVAG(Ent_83A0* self, signed char type, Slot_83A0* next, unsigned char mode)
{
    Slot_83A0* pending;
    Trans_83A0* rec;
    bool started;
    int i;
    if (D_0048A330) {
        D_004F2CD0[0].active = 0;
        D_004F2CD0[0].from = 0;
        D_004F2CD0[0].to = 0;
        D_004F2CD0[1].active = 0;
        D_004F2CD0[1].from = 0;
        D_004F2CD0[1].to = 0;
        D_0048A330 = 0;
    }
    started = false;
    pending = next;
    rec = &D_004F2CD0[0];
    if (D_004F2CD0[0].active && next) {
        rec->to = next;
        return;
    }
    for (i = 0; i < 50; i++) {
        Slot_83A0* s = &self[i].sub;
        if (type != self[i].sub.type)
            continue;
        if (!(next == 0 || (next != 0 && String_CompareNoCase(s->name, next->name))))
            continue;
        if (!s->state)
            continue;
        if (mode == 1) {
            if (s->type == 5 && s->handle) {
                SndEv_83A0* e;
                snd_AutoVol(s->handle, 0, 0x1E0, 2);
                rec->from = s;
                rec->to = 0;
                {
                    AllocGuard g;
                    e = (SndEv_83A0*)cMemMan_Allocate(0, 0x10, D_0049F4A0, 0x4C4);
                }
                if (e) {
                    e->vt = D_004D9DE0;
                    e->b4 = 0;
                    e->time = 0x7D0;
                    e->b5 = 0;
                    e->vt = (void*)D_004DAC90;
                    e->rec = rec;
                    e->rec->active = 1;
                }
                nCallback_SetCallback(e);
            } else {
                s->state = 0;
            }
        } else {
            if (s->handle) {
                SndEv_83A0* e;
                snd_AutoVol(s->handle, 0, 0x1E0, 2);
                rec->from = s;
                rec->to = pending;
                {
                    AllocGuard g;
                    e = (SndEv_83A0*)cMemMan_Allocate(0, 0x10, D_0049F4A0, 0x4DA);
                }
                if (e) {
                    e->vt = D_004D9DE0;
                    e->b4 = 0;
                    e->time = 0x7D0;
                    e->b5 = 0;
                    e->vt = (void*)D_004DAC90;
                    e->rec = rec;
                    e->rec->active = 1;
                }
                nCallback_SetCallback(e);
                started = true;
                pending = 0;
            } else {
                s->state = 0;
            }
        }
    }
    if (!started && pending)
        next->state = 2;
}
