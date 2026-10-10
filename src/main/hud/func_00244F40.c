#include "types.h"

extern char D_004A7298[];
extern int sprintf(char* buf, const char* fmt, ...);

/* Formats seconds as minutes, seconds and tenths. */
int ScriptEvent_TimeFormat(char* buf, float seconds) {
    return sprintf(buf, D_004A7298, (int)(seconds / 60.0f), (int)seconds % 60, (int)(10.0f * seconds) % 10);
}
