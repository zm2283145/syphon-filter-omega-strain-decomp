#pragma cplusplus on
#include "types.h"

struct Cam26D720 {
    char pad[0x100];
    char x100[0x504];
    unsigned char x604;
    char pad605[0xF];
    float x614;
    float x618;
    float x61C;
    float x620;
    float x624;
};

struct Self26D720 {
    char pad[8];
    int* x8;
    void* xC;
};

extern "C" {
extern Cam26D720* g_Hud;
extern float D_004FF030;
extern float D_004FF038;
extern float D_004FF040;
extern float D_004FF048;
extern float D_004FF050;
extern unsigned char D_004FF060;
void cIE_GOBJ_AnimateOff(void* p);
void cMap_ClearCallouts(Self26D720* self);
void cInterfaceModel_Activate(int a, int b, int c);
void cInfoBar_ClearPriorityMessages(void* p, int a, int b);
void* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
}

inline void SetA_26D720(Cam26D720* c, float a, float b) { c->x620 = a; c->x624 = b; }
inline void SetB_26D720(Cam26D720* c, float x, float y, float z) { c->x614 = x; c->x618 = y; c->x61C = z; }
extern "C" void cMap_Deactivate(Self26D720* self) {
    Cam26D720* cam;
    if (self->xC) {
        cIE_GOBJ_AnimateOff(self->xC);
        self->xC = 0;
    }
    cMap_ClearCallouts(self);
    cInterfaceModel_Activate(*self->x8, 0, 0);
    cam = g_Hud;
    SetA_26D720(cam, D_004FF030, D_004FF038);
    SetB_26D720(cam, D_004FF040, D_004FF048, D_004FF050);
    cam->x604 = 0;
    cInfoBar_ClearPriorityMessages(cam->x100, 2, 1);
    if (D_004FF060) {
        void* a = Gui_Canvas();
        GuiWidget_SendMessage(a, Gui_Canvas(), 0x11, 9, 0);
        D_004FF060 = 0;
    }
}

