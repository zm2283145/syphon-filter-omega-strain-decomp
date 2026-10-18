#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class W_48D90 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    virtual void Set(int a, int b);
};
struct Arr_48D90 : W_48D90 {
    char pad4[0x8C];
    W_48D90* c90;
    W_48D90* c94;
    W_48D90* c98;
    W_48D90* c9C;
};
extern "C" {
extern char* D_00492B40;
extern char* D_00492B48;
extern char* D_00492B50;
extern char* D_00492B58;
extern char D_004ABAB0[];
extern char D_004A9C40[];
extern int D_004BA290[];
extern char D_004BA3F0[];
void GuiArrayWidget_Init(Arr_48D90* a);
W_48D90* GuiWidget_FindChildByName(void* self, char* name);
void GuiArrayWidget_ColumnWidth(void* a, int col, int w);
int sprintf(char*, const char*, ...);
char* Loc_LookupText(char* key);
void GuiTextArrayWidget_SetCellText(W_48D90* a, int col, int row, char* text);
void func_00348D90(Arr_48D90* self);
}
static inline W_48D90* cast_48D90(W_48D90* w, char* type) { return (w && w->IsA(type)) ? w : 0; }
void func_00348D90(Arr_48D90* self)
{
    int i;
    int j;
    GuiArrayWidget_Init(self);
    self->c90 = cast_48D90(GuiWidget_FindChildByName(self, D_00492B40), D_004ABAB0);
    self->c94 = cast_48D90(GuiWidget_FindChildByName(self, D_00492B48), D_004A9C40);
    self->c98 = cast_48D90(GuiWidget_FindChildByName(self, D_00492B50), D_004A9C40);
    self->c9C = cast_48D90(GuiWidget_FindChildByName(self, D_00492B58), D_004A9C40);
    self->Set(4, 0);
    for (i = 0; i < 4; i++) GuiArrayWidget_ColumnWidth(self, i, D_004BA290[i]);
    if (self->c90) {
        self->c90->Set(4, 1);
        for (j = 0; j < 4; j++) {
            /* volatile read: retail loads the width before self->c90 */
            GuiArrayWidget_ColumnWidth(self->c90, j, ((volatile int*)D_004BA290)[j]);
            if (j != 2) {
                char buf[32];
                char* t;
                sprintf(buf, D_004BA3F0, j == 3 ? 2 : j);
                t = Loc_LookupText(buf);
                if (t) GuiTextArrayWidget_SetCellText(self->c90, j, 0, t);
            }
        }
    }
}
