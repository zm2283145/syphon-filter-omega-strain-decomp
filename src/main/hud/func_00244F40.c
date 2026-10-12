#include "types.h"

extern int sprintf(char* buf, const char* fmt, ...);

/* Formats seconds as minutes, seconds and tenths. */
int ScriptEvent_TimeFormat(char* buf, float seconds) {
    return sprintf(buf, "%.2d:%.2d.%d", (int)(seconds / 60.0f), (int)seconds % 60, (int)(10.0f * seconds) % 10);
}
