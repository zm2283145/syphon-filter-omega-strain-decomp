/*
 * SFOGame/Source/GuiLobbyScreen: 1 file, 0033D0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033D0C0 */
#pragma push /* merge_units */
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
Stack_3D0C0* Gui_Canvas(void);
void* Gui_Manager(void);
int cGameFrontEnd_PopMessageBox(void* ui, int id);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, void* d, int e);
void* GuiManager_OpenGui(void* a, char* b, char* c);
char* GuiLobbyScreen_GetLobbyString(void* self, int id, int a, int b, int c, int d);
void std_basic_string_char_char_traits_char_ctor_charP(void* s, char* t);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* d, const void* s);
void String_Dtor(void* s, int f);
char* std_basic_string_char_char_traits_char_c_str(void* s);
void func_0033D0C0(void* self);
}
static inline void Zero3(int* p) { int* q = p; q[0] = 0; q[1] = 0; q[2] = 0; }
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct Str_3D0C0 {
    int a, b, c;
    Str_3D0C0() { Zero3(&a); }
    Str_3D0C0(char* s) { std_basic_string_char_char_traits_char_ctor_charP(this, s); }
    /* out-of-line copy is weak and dropped at link (as include/alloc_guard.h) */
    __declspec(weak) __declspec(DROPDTOR) ~Str_3D0C0() { String_Dtor(this, 0); }
    Str_3D0C0& operator=(const Str_3D0C0& o) { std_basic_string_char_char_traits_char_assign_basicstringR(this, &o); return *this; }
};
void func_0033D0C0(void* self)
{
    if (D_00532FE8) {
        while (cGameFrontEnd_PopMessageBox(D_004FFC04, -1)) {
        }
        while (Gui_Canvas()->count) {
            Stack_3D0C0* s = Gui_Canvas();
            Gui_Canvas()->Hide(s->top->w);
        }
        {
            Str_3D0C0 title(GuiLobbyScreen_GetLobbyString(self, 0x14, 0, 0, 0, 0));
            Str_3D0C0 text;
            if (D_00532DC8) {
                if (D_00532DD0[0]) text = Str_3D0C0(D_00532DD0);
                else text = Str_3D0C0(GuiLobbyScreen_GetLobbyString(self, 0x85, 0, 0, 0, 0));
            } else {
                text = Str_3D0C0(GuiLobbyScreen_GetLobbyString(self, 0x86, 0, 0, 0, 0));
            }
            D_00532DC8 = 0;
            {
                char* tx = std_basic_string_char_char_traits_char_c_str(&text);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&title), tx, 0, 0);
            }
            {
                void* scr = GuiManager_OpenGui(Gui_Manager(), D_004B9B80, D_004B9B98);
                Gui_Canvas()->Show(scr, 0);
            }
            D_00532FE8 = 0;
        }
    }
}
static inline void merge_flush_func_0033D0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033D0C0 */
