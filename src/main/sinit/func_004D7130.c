#include "types.h"
extern float D_004BF1A0, D_004BF1A4, D_004BF1A8, D_004BF1AC, D_004BF1B0, D_004BF1B4, D_004BF1B8, D_004BF1BC;
extern char* D_005720F0;
extern char* D_005720F8;
extern char D_004E0AA0[];
extern void AbstractWidgetClassRep_AddClassRep(void* p);
void StaticInit_guiTextEditWidget(void)
{
    D_004BF1A0 = 96.0f / 255.0f;
    D_004BF1A4 = 126.0f / 255.0f;
    D_004BF1A8 = 132.0f / 255.0f;
    D_004BF1AC = 1.0f;
    D_004BF1B0 = 1.0f;
    D_004BF1B4 = 1.0f;
    D_004BF1B8 = 1.0f;
    D_004BF1BC = 1.0f;
    D_005720F8 = D_004E0AA0;
    D_005720F0 = "GuiTextEditWidget";
    AbstractWidgetClassRep_AddClassRep(&D_005720F0);
}