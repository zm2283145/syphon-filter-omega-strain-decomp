#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004ABE50[] = "GuiCommandCenter"; }
extern "C" { char D_004ABE68[] = "cmdcentr"; }
DEFINE_EVENT_SOUND_CHECK(func_002B0C50, D_004ABE50, D_004ABE68)
