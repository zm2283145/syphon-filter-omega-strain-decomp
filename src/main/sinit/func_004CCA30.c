#include "types.h"
extern char g_PlaySndMsgClass[];
extern char D_004F53C8[];
extern char D_004F53D8[];
extern char D_004F53E8[];
void StaticInit_GameSoundMsgNames(void)
{
    *(int*)g_PlaySndMsgClass = (int)"MSGGAME_PLAYSND";
    *(int*)D_004F53C8 = (int)"MSGGAME_PLAYVAG";
    *(int*)D_004F53D8 = (int)"MSGGAME_STOPSND";
    *(int*)D_004F53E8 = (int)"MSGGAME_PAUSEMUSIC";
}
