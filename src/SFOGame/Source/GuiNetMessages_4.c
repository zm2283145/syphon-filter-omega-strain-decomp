/*
 * SFOGame/Source/GuiNetMessages: 3 files, 00346FB0-00347690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346FB0 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

#pragma cplusplus on
struct V346 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); };
extern "C" {
typedef struct { char pad[0x14]; unsigned short flags; } W346;
typedef struct { void* fn[32]; } VT346;
typedef struct { VT346* vt; char pad[0x88]; W346* w8c; W346* w90; W346* w94; int p98; int p9c; W346* wa0; W346* wa4; } O346;
typedef struct { int type; char pad[8]; char name[0x20]; char text[0x20]; } I346;
typedef struct { int a[4]; } S346;
extern int cDME_GetLobby(void);
extern void GuiTextWidget_SetText(W346*, char*, int);
extern char* nGlobalization_GetString_charP(char*);
extern void std_basic_string_char_char_traits_char_ctor_charP(S346*, char*);
extern void func_003FD740(S346*);
extern char* std_basic_string_char_char_traits_char_c_str(S346*);
extern void String_Dtor(S346*, int);
extern char* GuiLobbyScreen_GetLobbyString(O346*, int, char*, char*, int, int);

extern int Gui_Canvas(void);
extern void GuiCanvas_SetFocus(int, int);
extern char D_004BA338[];
}
extern "C" void GuiWidget_SendMessage(O346*, W346*, int, int, int);
extern "C" void GuiNetMessages_MessageSelected(O346* self, I346* info) {
    S346 s;
    char buf[0x80];
    int b0, b1, b2;
    unsigned short mask;
    if (!self->w8c || !self->w90 || !self->w94) return;
    if (!cDME_GetLobby()) return;
    b0 = (self->w8c->flags & 2) != 0;
    b1 = (self->w90->flags & 2) != 0;
    b2 = (self->w94->flags & 2) != 0;
    if (info) {
        switch (info->type) {
        case 0: case 1:
            GuiTextWidget_SetText(self->w8c, nGlobalization_GetString_charP("MB_Decline"), 0);
            GuiTextWidget_SetText(self->w90, nGlobalization_GetString_charP("MB_Accept"), 0);
            mask = ~2;
            self->w8c->flags |= 2;
            self->w90->flags |= 2;
            self->w94->flags &= ~2;
            break;
        default:
            GuiTextWidget_SetText(self->w94, nGlobalization_GetString_charP("MB_OK"), 0);
            mask = ~2;
            self->w8c->flags &= ~2;
            self->w90->flags &= ~2;
            self->w94->flags |= 2;
            break;
        }
        if (info->type == 9) {
            sprintf(buf, "[%c%s%c] - %s", 0x11, info->name, 0x10, info->text);
            GuiTextWidget_SetText(self->wa0, buf, 0);
        } else if (info->type == 10) {
            std_basic_string_char_char_traits_char_ctor_charP(&s, info->text);
            func_003FD740(&s);
            GuiTextWidget_SetText(self->wa0, std_basic_string_char_char_traits_char_c_str(&s), 0);
            String_Dtor(&s, 0);
        } else {
            int c = -1;
            char* t;
            switch (info->type) {
            case 0: c = 0x2D; break;
            case 2: c = 0x2F; break;
            case 6: c = 0x7F; break;
            case 4: c = 0x31; break;
            case 5: c = 0x32; break;
            case 1: c = 0x2E; break;
            case 3: c = 0x30; break;
            case 7: c = 0x33; break;
            case 8: c = 0x34; break;
            case 11: c = 0x87; break;
            }
            if (c == -1) t = D_004BA338;
            else t = GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, info->name, info->text, 0, 0);
            GuiTextWidget_SetText(self->wa0, t, 0);
        }
        self->wa4->flags &= mask;
    } else {
        self->w8c->flags &= ~2;
        self->w90->flags &= ~2;
        self->w94->flags &= ~2;
        GuiTextWidget_SetText(self->wa0, D_004BA338, 0);
        self->wa4->flags |= 2;
    }
    if ((self->w8c->flags & 2) && !b0) GuiWidget_SendMessage(self, self->w8c, 6, (int)"onWake", 0);
    if ((self->w90->flags & 2) && !b1) GuiWidget_SendMessage(self, self->w90, 6, (int)"onWake", 0);
    if ((self->w94->flags & 2) && !b2) GuiWidget_SendMessage(self, self->w94, 6, (int)"onWake", 0);
    GuiCanvas_SetFocus(Gui_Canvas(), 0);
    {
        int r = Gui_Canvas();
        GuiCanvas_SetFocus(r, ((V346*)self)->v15());
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00346FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00346FB0 */

/* merge_units: begin func_003473E0 */
#pragma push /* merge_units */
#pragma cplusplus on
class V_3473E0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int Activate();
};
struct P_3473E0 { char pad[0x44]; V_3473E0* obj; };
struct S_3473E0 { char pad[0x88]; P_3473E0* p88; };
struct Ev_3473E0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
extern "C" {
extern int D_00532FD0;
int GuiLobbyScreen_PushLobbyScreen(S_3473E0* o, int v);
int GuiLobbyScreen_onInput(S_3473E0* o);
int GuiNetMessages_onInput(S_3473E0* o, Ev_3473E0* ev);
}
static inline unsigned char Down_3473E0(Ev_3473E0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_3473E0(Ev_3473E0* e, int b) { unsigned char r = 0; if (Down_3473E0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_3473E0(Ev_3473E0* e, int b) { unsigned char r = 0; if (Btn_3473E0(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_3473E0(Ev_3473E0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_3473E0(Ev_3473E0* e, int b) { return Down2_3473E0(e) && e->btn == b; }
static inline bool Plain2_3473E0(Ev_3473E0* e, int b) { return Btn2_3473E0(e, b) && e->b6 == 0; }

int GuiNetMessages_onInput(S_3473E0* o, Ev_3473E0* ev)
{
    if (Plain_3473E0(ev, 0x10)) {
        if (!GuiLobbyScreen_PushLobbyScreen(o, D_00532FD0)) GuiLobbyScreen_PushLobbyScreen(o, 1);
        return 1;
    }
    if (Plain2_3473E0(ev, 0x1000) && o->p88) return o->p88->obj->Activate();
    if (Plain2_3473E0(ev, 0x4000) && o->p88) return o->p88->obj->Activate();
    if (Plain2_3473E0(ev, 0x2000)) ev->btn = 0x1000;
    else if (Plain2_3473E0(ev, 0x8000)) ev->btn = 0x4000;
    return (ev->type == 1 && ev->b2 == 0 && ev->btn == 0x800 && ev->b6 == 0) ? 1 : GuiLobbyScreen_onInput(o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003473E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003473E0 */

/* merge_units: begin func_00347690 */
#pragma push /* merge_units */
typedef struct FlagByteObj {
    char pad00[0x80];
    unsigned char flag; /* 0x80 */
} FlagByteObj;

/* Clears the flag byte at +0x80 if it is set. */
void func_00347690(FlagByteObj* obj) {
    if (obj->flag) {
        obj->flag = 0;
    }
}
static inline void merge_flush_func_00347690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00347690 */
