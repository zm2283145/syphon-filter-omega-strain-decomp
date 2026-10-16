/*
 * main/GuiGameOptions: range (2 files, 0029A190-0029A950)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0029A190 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_A190 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsLocal(); };
struct Plr_A190 { char pad[0xC]; unsigned int flags; char pad10[0x3C]; int kind; char pad50[8]; Ctl_A190* ctl; };
struct Net_A190 { char pad[0x30]; Plr_A190* plr; };
struct Wdg_A190 { char pad[0x10]; int id; };
typedef struct Str_A190 { int a, b, c; } Str_A190;
typedef struct SoundEvP_A190 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} SoundEvP_A190;
typedef struct NetMsg_A190 {
    void* vtbl;
    char pad04[0x1C];
    unsigned char kind;
    char pad21[3];
    int slot;
    int id;
} NetMsg_A190;
struct Hud_A190 {
    char pad0[0x48];
    int popup;
    char pad4C[0x78 - 0x4C];
    int x78;
    int x7C;
    char pad80[0xB8 - 0x80];
    char xB8[4];
    unsigned char bBC, bBD, bBE, bBF;
    float fC0, fC4, fC8;
    int iCC;
    char padD0[4];
    float fD4;
    int iD8;
    char padDC[4];
    char snd[0x404 - 0xE0];
    int w404;
    Wdg_A190* w408;
    Wdg_A190* w40C;
    Wdg_A190* w410;
    Wdg_A190* w414;
    Wdg_A190* w418;
    Wdg_A190* w41C;
    Wdg_A190* w420;
    Wdg_A190* w424;
    Wdg_A190* w428;
    Wdg_A190* w42C;
    Wdg_A190* list;
};
extern "C" {
extern unsigned char D_005721C8;
extern int D_0049D010;
extern void* D_004FFC04;
extern Net_A190* D_004FFC0C;
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DD5E0[];
extern char D_004DCF10[];
extern char D_00506440[];
extern char* D_0048B900;
extern char D_004AA790[];
extern char D_004AA7A0[];
extern char D_004AA7B0[];
extern char D_004AA7C0[];
extern char D_004AA7D0[];
extern char D_004AA7E0[];
char* Loc_LookupText(char* key);
int FrontEnd_OpenPopup(void* fe, int kind, char* title, char* text, Hud_A190* owner, int id);
void String_CtorCStr_13B480(Str_A190* s, char* text);
char* String_CStr(Str_A190* s);
void String_Dtor(Str_A190* s, int flags);
void GuiGameOptions_Show(Hud_A190* self, int idx);
void GuiGameOptions_Enter(Hud_A190* self);
void func_002996D0(Hud_A190* self, int a);
void GuiGameOptions_Refresh(Hud_A190* self, int mask);
void func_0045A3A0(void* p, int mask);
void PadRumble_Start(float f, int a, int b, int c, int d);
int func_00421430(Wdg_A190* w, int idx);
int func_00421480(Wdg_A190* w, int idx);
void FrontEnd_SuspendGui(void* fe, int a);
void FrontEnd_ResumeGui(void* fe);
long long Time_GetMilliseconds(void);
void Event_Construct(void* msg, void* type);
void Transport_Send(int a, void* msg, int b, int c);
void Event_Send(void* msg, void* target, int flags);
#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void FileMan_Release(void* part, int flags);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((a0), (a1))) /* merge_units */

void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
void EffectMsg_WrapRequest(void* msg, void* action);
int func_00441CA0(Hud_A190* self, Wdg_A190* w, unsigned short msg, int sub, int text);
}
static inline unsigned char IsLocal_A190(Plr_A190* p) { unsigned char r = 0; if (p->ctl && p->ctl->IsLocal()) r = 1; return r; }
static inline int LocalId_A190(Plr_A190* p) { int id; if (D_005721C8) { if (IsLocal_A190(p)) id = ((p->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline Plr_A190* AsHuman_A190(Plr_A190* p) { return (p && p->kind == D_0049D010) ? p : 0; }

extern "C" int GuiGameOptions_HandleEvent(Hud_A190* self, Wdg_A190* w, unsigned short msg, int sub, int text)
{
    if (msg == 0 && w->id != -1) {
        GuiGameOptions_Show(self, w->id);
        return 1;
    }
    if (msg == 0x10 && sub == 1 && w->id != -1) {
        return 1;
    }
    if (msg == 0x13 && w == self->list) {
        int n = func_00421430(self->list, text);
        char* fmt = Loc_LookupText(D_004AA790);
        if (fmt && n) {
            char buf[0x80];
            void* fe;
            sprintf(buf, fmt, n);
            self->w404 = func_00421480(self->list, text);
            fe = D_004FFC04;
            FrontEnd_OpenPopup(fe, 5, Loc_LookupText(D_004AA7A0), buf, self, 0xD);
        }
        return 1;
    }
    if (msg == 2) {
        if (w->id != -1) {
            GuiGameOptions_Enter(self);
            return 1;
        }
        if (w == self->w408) {
            self->bBC = !self->bBC;
            func_0045A3A0(self->xB8, 1);
            GuiGameOptions_Refresh(self, 1);
        } else if (w == self->w40C) {
            self->bBD = !self->bBD;
            func_0045A3A0(self->xB8, 2);
            GuiGameOptions_Refresh(self, 2);
            if (self->bBD) PadRumble_Start(1.0f, 0, 1, 0xFF, 1);
        }
        if (w == self->w410) {
            self->bBE = !self->bBE;
            func_0045A3A0(self->xB8, 4);
            GuiGameOptions_Refresh(self, 4);
        }
        if (w == self->w414) {
            self->bBF = !self->bBF;
            func_0045A3A0(self->xB8, 8);
            GuiGameOptions_Refresh(self, 8);
        } else if (w == self->w424) {
            self->iCC++;
            if (self->iCC >= 2) self->iCC = 0;
            func_0045A3A0(self->xB8, 0x80);
            GuiGameOptions_Refresh(self, 0x80);
        } else if (w == self->w42C) {
            self->iD8++;
            if (self->iD8 >= 2) self->iD8 = 0;
            if (self->iD8 == 1) {
                Str_A190 t;
                Str_A190 s;
                String_CtorCStr_13B480(&t, Loc_LookupText(D_004AA7B0));
                String_CtorCStr_13B480(&s, Loc_LookupText(D_004AA7C0));
                { char* txt = String_CStr(&s); FrontEnd_OpenPopup(D_004FFC04, 5, String_CStr(&t), txt, self, 0xB); }
                GuiGameOptions_Refresh(self, 0x800);
                String_Dtor(&s, 0);
                String_Dtor(&t, 0);
            } else {
                FrontEnd_SuspendGui(D_004FFC04, 1);
                func_0045A3A0(self->xB8, 0x800);
                FrontEnd_ResumeGui(D_004FFC04);
                GuiGameOptions_Refresh(self, 0x800);
            }
        }
        return 1;
    }
    if (msg == 0x1A || msg == 0x1B) {
        if (sub == 11) {
            if (msg == 0x1A) {
                Str_A190 t;
                Str_A190 s;
                String_CtorCStr_13B480(&t, Loc_LookupText(D_004AA7D0));
                String_CtorCStr_13B480(&s, Loc_LookupText(D_004AA7E0));
                { char* txt = String_CStr(&s); self->popup = FrontEnd_OpenPopup(D_004FFC04, 5, String_CStr(&t), txt, self, 0xC); }
                self->x78 = 1;
                self->x7C = Time_GetMilliseconds();
                FrontEnd_SuspendGui(D_004FFC04, 1);
                func_0045A3A0(self->xB8, 0x800);
                FrontEnd_ResumeGui(D_004FFC04);
                String_Dtor(&s, 0);
                String_Dtor(&t, 0);
            } else {
                self->iD8 = 0;
                GuiGameOptions_Refresh(self, 0x800);
            }
            return 1;
        }
        if (sub == 12) {
            if (msg == 0x1A) {
                self->x78 = 0;
            } else {
                func_002996D0(self, 0);
            }
            return 1;
        }
        if (sub == 13) {
            if (msg == 0x1A && D_004FFC0C) {
                int id; Plr_A190* o = D_004FFC0C->plr;
                if (AsHuman_A190(o)) {
                    int slot;
                    id = self->w404;
                    slot = LocalId_A190(AsHuman_A190(o));
                    NetMsg_A190 m;
                    Event_Construct(&m, D_00506440);
                    m.vtbl = D_004DD5E0;
                    m.kind = 4;
                    m.slot = slot;
                    m.id = id;
                    Transport_Send(0, &m, -1, -1);
                    m.vtbl = D_004DCF10;
                    cMessage_dtor(&m, 0);
                }
            }
            return 1;
        }
    }
    if (msg == 0x1D) {
        if (w == self->w418) {
            SoundEvP_A190 ev;
            self->fC0 = sub / 100.0f;
            func_0045A3A0(self->xB8, 0x10);
            SoundAction_CtorVoice(self->snd, 1, D_0048B900, 0, 0);
            EffectMsg_WrapRequest(&ev, self->snd);
            ev.flag = 1;
            Event_Send(&ev, D_004FFB50, 1);
            ev.vtbl = D_004DAE30;
            FileMan_Release(ev.partB, -1);
            FileMan_Release(ev.partA, -1);
            cMessage_dtor(&ev, 0);
        } else if (w == self->w41C) {
        } else if (w == self->w420) {
            self->fC8 = sub / 100.0f;
            func_0045A3A0(self->xB8, 0x40);
        } else if (w == self->w428) {
            self->fD4 = sub / 100.0f;
            func_0045A3A0(self->xB8, 0x400);
        }
        return 1;
    }
    return func_00441CA0(self, w, msg, sub, text);
}
#undef cMessage_dtor /* merge_units */
#undef FileMan_Release /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029A190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029A190 */

/* merge_units: begin func_0029A950 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_0029A950, D_004DAE30)
#pragma pop /* merge_units */
/* merge_units: end func_0029A950 */
