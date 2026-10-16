#include "types.h"
#include "fam5_timed_retry.h"
extern void GuiObjectives_Update(char*, float);
DEFINE_TIMED_RETRY(func_00462270, 0x240, 0x90, GuiObjectives_Update)
