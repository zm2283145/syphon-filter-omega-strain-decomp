#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
struct Top_3D0C0 { char pad[8]; void* w; };
struct Stack_3D0C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Draw(); virtual void Update(float dt);
    virtual void Show(void* p, int a); virtual void Hide(void* p);
    char pad4[0x24];
    int count;
    char pad2C[4];
    Top_3D0C0* top;
};
extern "C" {
extern void* D_004FFC04;
extern unsigned char D_00532FE8;
extern unsigned char D_00532DC8;
extern char D_00532DD0[];
extern char D_004B9B80[];
extern char D_004B9B98[];
Stack_3D0C0* Gui_GetScreenStack(void);
void* Gui_GetScreenList(void);
int FrontEnd_ClosePopup(void* ui, int id);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, void* d, int e);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
char* GuiScreen_GetLobbyString(void* self, int id, int a, int b, int c, int d);
void String_CtorCStr_13B480(void* s, char* t);
void func_0013D680(void* d, const void* s);
void String_Dtor(void* s, int f);
char* String_CStr(void* s);
void func_0033D0C0(void* self);
}
static inline void Zero3(int* p) { int* q = p; q[0] = 0; q[1] = 0; q[2] = 0; }
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct Str_3D0C0 {
    int a, b, c;
    Str_3D0C0() { Zero3(&a); }
    Str_3D0C0(char* s) { String_CtorCStr_13B480(this, s); }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~Str_3D0C0() { String_Dtor(this, 0); }
    Str_3D0C0& operator=(const Str_3D0C0& o) { func_0013D680(this, &o); return *this; }
};
void func_0033D0C0(void* self)
{
    if (D_00532FE8) {
        while (FrontEnd_ClosePopup(D_004FFC04, -1)) {
        }
        while (Gui_GetScreenStack()->count) {
            Stack_3D0C0* s = Gui_GetScreenStack();
            Gui_GetScreenStack()->Hide(s->top->w);
        }
        {
            Str_3D0C0 title(GuiScreen_GetLobbyString(self, 0x14, 0, 0, 0, 0));
            Str_3D0C0 text;
            if (D_00532DC8) {
                if (D_00532DD0[0]) text = Str_3D0C0(D_00532DD0);
                else text = Str_3D0C0(GuiScreen_GetLobbyString(self, 0x85, 0, 0, 0, 0));
            } else {
                text = Str_3D0C0(GuiScreen_GetLobbyString(self, 0x86, 0, 0, 0, 0));
            }
            D_00532DC8 = 0;
            {
                char* tx = String_CStr(&text);
                FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&title), tx, 0, 0);
            }
            {
                void* scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004B9B80, D_004B9B98);
                Gui_GetScreenStack()->Show(scr, 0);
            }
            D_00532FE8 = 0;
        }
    }
}
