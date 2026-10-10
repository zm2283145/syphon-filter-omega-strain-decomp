#include "types.h"

extern void Global_StopAllQuips(int);

/* Script native: stops all quips. */
int Script_StopAllQuips(void) {
    Global_StopAllQuips(0);
    return 0;
}
