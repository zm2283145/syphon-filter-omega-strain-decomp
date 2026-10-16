/*
 * main/human: range (2 files, 001B31B0-001B33D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001B31B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char d[0x9C]; } Str;
struct Snd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Snd2 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x20];
} __attribute__((aligned(16)));
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Act {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x33B9 - 0x5C];
    unsigned char b33B9;
    char pad33BA[0x346E - 0x33BA];
    unsigned char b346E;
    unsigned char b346F;
    signed char b3470;
};
extern "C" {
extern char D_004F1FD0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern void* D_004FFC30;
extern void* D_004FFC2C;
extern unsigned char D_0053B540;
void SoundEvent_CtorFromPreset(Snd* e, void* r, void* owner);
void SoundStopMsg_Ctor(Snd2* e, void* r, void* owner);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void FileMan_Release(Str* s, int flag);
void VisionMgr_SetPendingMode(void*, int, int);
void Hud_SelectTextColorTable(void*, int);
}
extern "C" void Actor_UpdateNightVisionBlind(Act* a)
{
    signed char v = 0;
    unsigned char s;
    if (a->b346F) v = *(signed char*)&a->b346F;
    else if (a->b346E) v = *(signed char*)&a->b346E;
    s = v;
    if (s != (unsigned char)a->b3470) {
        a->b3470 = v;
        if (a->b14) {
            bool ok = 0;
            if (a->p58 && a->p58->IsOn()) ok = 1;
            if (ok) {
                int m = 0;
                switch (s) {
                case 1: m = 1; break;
                case 2: m = 2; break;
                case 3: m = 3; break;
                }
                VisionMgr_SetPendingMode(D_004FFC30, m, 0);
                Hud_SelectTextColorTable(D_004FFC2C, s == 1);
                D_0053B540 = s == 1;
            }
        }
    }
    if (s == 2) {
        if (!a->b33B9) {
            Snd ev;
            SoundEvent_CtorFromPreset(&ev, D_004F1FD0, a);
            ev.flag = 1;
            Event_Send(&ev, D_004FFB50, 0);
            a->b33B9 = 1;
            ev.vt = D_004DAE30;
            FileMan_Release(&ev.s114, -1);
            FileMan_Release(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
        }
    } else if (a->b33B9) {
        Snd2 ev;
        SoundStopMsg_Ctor(&ev, D_004F1FD0, a);
        ev.flag = 1;
        Event_Send(&ev, D_004FFB50, 0);
        a->b33B9 = 0;
        ev.vt = D_004DADF0;
        FileMan_Release(&ev.s114, -1);
        FileMan_Release(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B31B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B31B0 */

/* merge_units: begin func_001B33D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x352C]; float t; } O_1B33D0;
const float D_0048A208[2] = { 5.0f, 0.0f };
static const float dat_0048A210[2] = { 0.2f, 0.0f };
float Actor_GetShotShakePenalty(O_1B33D0* o)
{
    return 1.0f + ((*(float*)dat_0048A210) - 1.0f) * (o->t / (*(float*)D_0048A208));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B33D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B33D0 */
