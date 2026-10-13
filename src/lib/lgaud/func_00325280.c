#include "lgaud.h"

int lgAudEnumHint(int *hint)
{
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (hint == 0) {
        printf("lgAudEnumHint: invalid parameter (hint)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    *hint = *lgAud_enumHint;
    *lgAud_enumHint = 0;
    return 0;
}
