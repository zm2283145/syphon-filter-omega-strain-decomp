#pragma cplusplus on

#include "network_admission.h"

/* Report whether any retry slot has a valid deadline at or beyond the threshold. */
extern "C" bool func_0042B4E0(void)
{
    bool unavailable = true;
    unsigned int threshold = retry_threshold();
    if ((D_00572428 >= 0x0FFFFFFE || D_00572428 < threshold) &&
        (D_0057242C >= 0x0FFFFFFE || D_0057242C < threshold) &&
        (D_00572430 >= 0x0FFFFFFE || D_00572430 < threshold))
        unavailable = false;
    return unavailable;
}
