#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004A9D18[] = "GuiTitleScreen"; }
extern "C" { char D_004A9D28[] = "titlescr"; }
DEFINE_EVENT_SOUND_CHECK(func_00292AD0, D_004A9D18, D_004A9D28)
