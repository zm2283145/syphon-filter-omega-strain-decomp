#include "types.h"

typedef struct { char pad[0x6A4]; void* xa; } SoundMgr;

extern SoundMgr* g_Hud;
extern void GuiGameScreen_AddXAAudio(void* xa, int track, int channel, int flag);

/* Plays an XA audio track when the sound manager and its XA player exist. */
void Global_PlayXA(int track, int channel)
{
    if (g_Hud && g_Hud->xa)
        GuiGameScreen_AddXAAudio(g_Hud->xa, track, channel, 1);
}
