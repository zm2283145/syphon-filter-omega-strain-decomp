#include "types.h"
long long DMATAG3(long long a, int b, long long c)
{
    long long r = c << 32; r |= b << 28; r |= a; return r;
}
