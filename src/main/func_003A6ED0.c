#include "types.h"
extern int D_0053DC00;
extern int D_00542810;
extern int func_00119B88(void);
/* Return the cached value when enabled, otherwise query it. */
int func_003A6ED0(void)
{
    if (D_0053DC00) {
        return D_00542810;
    }
    return func_00119B88();
}
