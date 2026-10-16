#include "types.h"
extern int D_0053DC00;
extern int D_00542810;
extern int sceCdGetError(void);
/* Return the cached value when enabled, otherwise query it. */
int Cd_GetError(void)
{
    if (D_0053DC00) {
        return D_00542810;
    }
    return sceCdGetError();
}
