#include "types.h"
/* HudMap_UpdateSticks: map screen stick input: the right stick's vertical
 * axis zooms (clamped to pi/12..pi/2), the left stick's vertical axis tilts
 * (clamped to D_0048B2A0..pi/4), and the map widget is told when the sticks
 * start or stop moving (events 16 / 17). */
typedef struct { float x, y; } V2_BE80;
typedef struct { int x, y; } I2_BE80; /* the sticks are cleared as words (sw zero); float stores make MW keep &v.y in a saved register */
extern float D_004FF070;
extern unsigned char D_004FF060;
extern float D_0048B2B0;
extern float D_0048B2A0;
void Pad_GetSticks(void* pad, V2_BE80* a, V2_BE80* b, int n);
void* Gui_GetScreenStack(void);
void GuiWidget_SendEvent(void* a, void* b, int kind, int v, int f);

void HudMap_UpdateSticks(void* self, char* ply)
{
    V2_BE80 a, b, c, d;
    float lx, ly, rx, ry;
    ((I2_BE80*)&a)->x = 0;
    ((I2_BE80*)&a)->y = 0;
    ((I2_BE80*)&b)->x = 0;
    ((I2_BE80*)&b)->y = 0;
    Pad_GetSticks(ply + 0x40, &a, &b, 0);
    lx = b.x;
    ly = b.y;
    ((I2_BE80*)&c)->x = 0;
    ((I2_BE80*)&c)->y = 0;
    ((I2_BE80*)&d)->x = 0;
    ((I2_BE80*)&d)->y = 0;
    Pad_GetSticks(ply + 0x40, &c, &d, 0);
    ry = c.y;
    rx = c.x;
    if (ry > 0.0f) {
        D_004FF070 += 0.0004f * ry;
        if (D_004FF070 > 1.5707964f)
            D_004FF070 = 1.5707964f;
    }
    if (ry < 0.0f) {
        D_004FF070 += 0.0004f * ry;
        if (D_004FF070 < 0.2617994f)
            D_004FF070 = 0.2617994f;
    }
    if (ly < 0.0f) {
        D_0048B2B0 += 0.0001f * ly;
        if (D_0048B2B0 < D_0048B2A0)
            D_0048B2B0 = D_0048B2A0;
    }
    if (ly > 0.0f) {
        D_0048B2B0 += 0.0001f * ly;
        if (D_0048B2B0 > 0.7853982f)
            D_0048B2B0 = 0.7853982f;
    }
    if (0.0f == ry && 0.0f == ly && 0.0f == rx && 0.0f == lx) {
        if (D_004FF060) {
            GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 17, 9, 0);
            D_004FF060 = 0;
        }
    } else if (!D_004FF060) {
        GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 16, 9, 0);
        D_004FF060 = 1;
    }
}
