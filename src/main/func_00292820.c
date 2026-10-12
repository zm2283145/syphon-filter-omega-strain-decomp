#pragma cplusplus on

#include "types.h"
#include "event_sound_check.h"

/* Play a sound on a matching event. */
extern "C" { char D_004A9C80[] = "GuiAgentCreate"; }
extern "C" { char D_004A9C90[] = "AGENTNEW"; }
DEFINE_EVENT_SOUND_CHECK(func_00292820, D_004A9C80, D_004A9C90)
