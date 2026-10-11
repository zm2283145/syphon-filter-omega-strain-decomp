#include "types.h"
#include "canonical_key_copy.h"
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
char* CanonicalKey_Construct(char* d, char* s)
{
    CANONICAL_KEY_INIT(d, s)
    return d;
}
#pragma pop