#include "types.h"
#pragma cplusplus on
struct V346 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); };
extern "C" {
typedef struct { char pad[0x14]; unsigned short flags; } W346;
typedef struct { void* fn[32]; } VT346;
typedef struct { VT346* vt; char pad[0x88]; W346* w8c; W346* w90; W346* w94; int p98; int p9c; W346* wa0; W346* wa4; } O346;
typedef struct { int type; char pad[8]; char name[0x20]; char text[0x20]; } I346;
typedef struct { int a[4]; } S346;
extern int func_004294C0(void);
extern void func_0041BEB0(W346*, char*, int);
extern char* Loc_LookupText(char*);
extern int sprintf(char*, const char*, ...);
extern void String_CtorCStr_13B480(S346*, char*);
extern void func_003FD740(S346*);
extern char* String_CStr(S346*);
extern void func_00138B70(S346*, int);
extern char* func_0033CE30(O346*, int, char*, char*, int, int);

extern int Gui_GetScreenStack(void);
extern void GuiScreen_SetFocus(int, int);
extern char D_004BA338[];
}
extern "C" void func_0041E0F0(O346*, W346*, int, int, int);
extern "C" void func_00346FB0(O346* self, I346* info) {
    S346 s;
    char buf[0x80];
    int b0, b1, b2;
    unsigned short mask;
    if (!self->w8c || !self->w90 || !self->w94) return;
    if (!func_004294C0()) return;
    b0 = (self->w8c->flags & 2) != 0;
    b1 = (self->w90->flags & 2) != 0;
    b2 = (self->w94->flags & 2) != 0;
    if (info) {
        switch (info->type) {
        case 0: case 1:
            func_0041BEB0(self->w8c, Loc_LookupText("MB_Decline"), 0);
            func_0041BEB0(self->w90, Loc_LookupText("MB_Accept"), 0);
            mask = ~2;
            self->w8c->flags |= 2;
            self->w90->flags |= 2;
            self->w94->flags &= ~2;
            break;
        default:
            func_0041BEB0(self->w94, Loc_LookupText("MB_OK"), 0);
            mask = ~2;
            self->w8c->flags &= ~2;
            self->w90->flags &= ~2;
            self->w94->flags |= 2;
            break;
        }
        if (info->type == 9) {
            sprintf(buf, "[%c%s%c] - %s", 0x11, info->name, 0x10, info->text);
            func_0041BEB0(self->wa0, buf, 0);
        } else if (info->type == 10) {
            String_CtorCStr_13B480(&s, info->text);
            func_003FD740(&s);
            func_0041BEB0(self->wa0, String_CStr(&s), 0);
            func_00138B70(&s, 0);
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
            else t = func_0033CE30(self, (unsigned char)c, info->name, info->text, 0, 0);
            func_0041BEB0(self->wa0, t, 0);
        }
        self->wa4->flags &= mask;
    } else {
        self->w8c->flags &= ~2;
        self->w90->flags &= ~2;
        self->w94->flags &= ~2;
        func_0041BEB0(self->wa0, D_004BA338, 0);
        self->wa4->flags |= 2;
    }
    if ((self->w8c->flags & 2) && !b0) func_0041E0F0(self, self->w8c, 6, (int)"onWake", 0);
    if ((self->w90->flags & 2) && !b1) func_0041E0F0(self, self->w90, 6, (int)"onWake", 0);
    if ((self->w94->flags & 2) && !b2) func_0041E0F0(self, self->w94, 6, (int)"onWake", 0);
    GuiScreen_SetFocus(Gui_GetScreenStack(), 0);
    {
        int r = Gui_GetScreenStack();
        GuiScreen_SetFocus(r, ((V346*)self)->v15());
    }
}
