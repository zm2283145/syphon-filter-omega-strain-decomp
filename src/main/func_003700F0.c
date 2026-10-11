#include "types.h"
long long func_003700F0(long long a, int b, long long c)
{
    long long r = c << 32; r |= b << 28; r |= a; return r;
}
