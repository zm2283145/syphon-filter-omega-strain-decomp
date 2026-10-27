#include "types.h"
extern int D_0048B8B0, D_0048B8B8, D_0048B8C0, D_0048B8C8, D_0048B8D8, D_0048B8E0, D_0048B8E8, D_0048B8F0;
extern int D_00506420, D_00506424, D_00506428, D_0050642C, D_00506430, D_00506434, D_00506438, D_0050643C;
extern char* D_00506440;
extern int D_00506450;
extern char* D_00506458;
extern char* D_00506460;
extern char D_00506448[], D_004DD600[];
extern char cNetKickMsg_NetReceive[];
extern int cNetMsg_RegisterMsg(void* fn, void* a, void* b);
extern void AbstractWidgetClassRep_AddClassRep(void* p);
void StaticInit_GuiGameOptions(void)
{
    D_00506420 = D_0048B8B0;
    D_00506424 = D_0048B8B8;
    D_00506428 = D_0048B8C0;
    D_0050642C = D_0048B8C8;
    D_00506430 = D_0048B8D8;
    D_00506434 = D_0048B8E0;
    D_00506438 = D_0048B8E8;
    D_0050643C = D_0048B8F0;
    D_00506440 = "cNetKickMsg";
    D_00506450 = cNetMsg_RegisterMsg(cNetKickMsg_NetReceive, D_00506448, "cNetKickMsg");
    D_00506460 = D_004DD600;
    D_00506458 = "GuiGameOptions";
    AbstractWidgetClassRep_AddClassRep(&D_00506458);
}