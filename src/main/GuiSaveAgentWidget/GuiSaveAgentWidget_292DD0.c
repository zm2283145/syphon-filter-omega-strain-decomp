#pragma cplusplus on

#include "types.h"
#include "label_text_refresh.h"

/* Refresh a screen label text. */
extern "C" { char D_004A9D68[] = "MC_LOADTITLE"; }
DEFINE_LABEL_TEXT_REFRESH(GuiAgentLoad_onWake, D_004A9D68)
