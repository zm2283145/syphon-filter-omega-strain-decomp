#pragma cplusplus on
struct W {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { char pad[0x80]; unsigned char b80; char pad81[0xB8 - 0x81]; int fB8; } UI;
typedef struct { char pad[0x68]; int flags; } Mgr;
typedef struct {
    char pad[0x78]; unsigned char b78; char pad79[0x84 - 0x79]; int f84; UI* f88;
    char pad8C[0xA8 - 0x8C]; void* fA8; char padAC[0x100 - 0xAC]; int f100; char f104[4];
} O;
extern "C" {
extern char D_004B9C60[];
extern char D_004B9C28[];
static char* D_004928E0 = D_004B9C28;
extern char D_004A7520[];
extern char g_Game[];
extern unsigned char D_00532FF0;
extern int D_00532FF8;
extern int D_00533000;
void GuiScreen_Wake(O* o);
void String_CtorCStr_13B480(String* s, const char* text);
void String_AssignString(void* list, String* s);
void String_Dtor(String* s, int flags);
void func_0033D8E0(O* o, unsigned char mode);
W* GuiWidget_FindChildByName(void* o, char* name);
void* Agent_GetSelected(void* p, int i);
char* AgentData_GetName(void* a);
void GuiTextWidget_SetText(W* w, char* s, int f);
Mgr* Gui_GetScreenStack(void);
void GuiMenuScreen_Wake(O* o);
}
static inline W* Cast(W* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiMenuScreen_Wake(O* o)
{
    W* w;
    GuiScreen_Wake(o);
    o->fA8 = 0;
    o->f100 = -1;
    {
        String s;
        String_CtorCStr_13B480(&s, D_004B9C60);
        String_AssignString(o->f104, &s);
        String_Dtor(&s, 0);
    }
    if (o->f88) {
        func_0033D8E0(o, 1);
        o->f88->fB8 = o->f84;
        o->f88->b80 = 1;
    }
    o->b78 = 1;
    w = Cast(GuiWidget_FindChildByName(o, D_004928E0), D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, AgentData_GetName(Agent_GetSelected(g_Game, -1)), 0);
    D_00532FF0 = 0;
    D_00532FF8 = 0;
    D_00533000 = 0;
    Gui_GetScreenStack()->flags |= 0xC;
    Gui_GetScreenStack()->flags |= 0x3;
}
