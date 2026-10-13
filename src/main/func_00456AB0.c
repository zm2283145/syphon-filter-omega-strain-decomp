#pragma cplusplus on
#include "types.h"
struct VObj_456AB0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct C_456AB0 { char p[0x14]; unsigned short flags; };
struct W_456AB0 { char p[0x10]; int focus; char p14[0x8C - 0x14]; C_456AB0* f8C; void* items[8]; int id; };
extern "C" {
extern char D_004C1C60[];
extern char D_004C1C70[];
extern char D_004C1A38[];
extern char D_004A7520[];
extern unsigned char D_004FFBB7;
void func_00368760(W_456AB0*);
VObj_456AB0* GuiWidget_FindChildByName(W_456AB0*, char*);
int sprintf(char*, const char*, ...);
char* Loc_LookupText(char*);
void func_0041BEB0(VObj_456AB0*, char*, int);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void*, void*);
}

extern "C" void func_00456AB0(W_456AB0* self)
{
    VObj_456AB0* o;
    char buf[16];
    func_00368760(self);
    self->id = 0;
    o = GuiWidget_FindChildByName(self, D_004C1C60);
    o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
    if (o) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = Loc_LookupText(buf);
        if (s) func_0041BEB0(o, s, 0);
        else func_0041BEB0(o, D_004C1A38, 0);
    }
    if (self->focus != -1)
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->items[self->focus]);
    if (self->f8C) {
        if (D_004FFBB7) self->f8C->flags |= 2;
        else self->f8C->flags &= ~2;
    }
}
