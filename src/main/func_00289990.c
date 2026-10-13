#pragma cplusplus on
#include "types.h"
struct Ev_00289990 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Txt_00289990 { char pad[0x48]; char s48[4]; };
struct Ui_00289990 { char pad[0x20]; void* f20; };
struct Mgr_00289990 { char pad[0x268]; int f268; };
struct S_00289990 { char pad0[0x88]; void* p88; Txt_00289990* p8C; void* p90; Txt_00289990* p94; char pad98[0xC]; unsigned char bA4; char padA5[8]; unsigned char bAD; };
extern "C" {
extern Mgr_00289990* D_004FFC04;
extern char D_004A9730[];
extern char D_00506340[];
extern char D_00506350[];
extern unsigned char D_00506360;
int func_0033CE30(S_00289990* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_00289990* d, int e);
void func_00289440(S_00289990* self);
void func_00288E90(S_00289990* self);
Ui_00289990* Gui_GetScreenStack(void);
void func_0028A230(S_00289990* self);
void func_0028A180(S_00289990* self);
char* String_CStr(void* s);
char* strncpy(char* d, const char* s, int n);
void func_0033C320(S_00289990* self, int a);
int func_0033CEF0(S_00289990* self, Ev_00289990* ev);
}
static inline unsigned char Down_00289990(Ev_00289990* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_00289990(Ev_00289990* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_00289990(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_00289990(Ev_00289990* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_00289990(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_00289990(S_00289990* self, Ev_00289990* ev)
{
    if (Press_00289990(ev, 0x10)) {
        void* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 5, D_004A9730, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x1E);
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            if (!self->bAD)
                func_00289440(self);
            else
                func_00288E90(self);
            return 1;
        } else {
            bool c = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
            if (c) {
                if (Gui_GetScreenStack()->f20 == self->p88) {
                    func_0028A230(self);
                    return 1;
                }
                if (Gui_GetScreenStack()->f20 == self->p90) {
                    func_0028A180(self);
                    return 1;
                }
            }
        }
    }
    {
        bool d = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x20 && ev->f6 == 0;
        if (d) {
            D_00506350[0] = 0;
            D_00506340[0] = 0;
            D_00506360 = self->bA4;
            if (self->p8C && self->p94) {
                strncpy(D_00506340, String_CStr(self->p94->s48), 0xF);
                strncpy(D_00506350, String_CStr(self->p8C->s48), 0xF);
            }
            D_004FFC04->f268 = 7;
            func_0033C320(self, 5);
            return 1;
        }
    }
    return func_0033CEF0(self, ev);
}