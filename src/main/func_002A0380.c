#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004AAED8[] = "GuiTitleScreen"; }
extern "C" { char D_004AAEE8[] = "titlescr"; }
DEFINE_EVENT_SOUND_CHECK(func_002A0380, D_004AAED8, D_004AAEE8)
