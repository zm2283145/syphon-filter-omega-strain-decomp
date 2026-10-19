#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004ABE50[] = "GuiCommandCenter"; }
extern "C" { char D_004ABE68[] = "cmdcentr"; }
DEFINE_EVENT_SOUND_CHECK(GuiZeusShell_HandleInput, D_004ABE50, D_004ABE68)
