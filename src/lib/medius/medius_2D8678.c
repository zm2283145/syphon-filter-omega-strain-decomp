#include "types.h"

extern char D_0048C438[];
extern int GetCurrentTimeMs(void);

void StartTime(void) {
    int tmp0;

    tmp0 = GetCurrentTimeMs();
    *(int*)D_0048C438 = tmp0;
}
