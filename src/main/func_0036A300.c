#include "types.h"
extern void Font_DrawString(int a0, int a1, int a2, float x, float y, float z, float p, float q, float r);
void cFont_Display_charP_tRGBAR_int_int_etc(int a0, int a1, int a2, int ix, int iy, float z) {
    Font_DrawString(a0, a1, a2, (float)ix, (float)iy, z, 0.0f, 0.0f, 0.0f);
}
