#include "types.h"
typedef struct { long long a; int b; } S;
/* Stores an 8-byte value and an int. */
void func_003C0B30(S* dst, long long* src, int b) { dst->a = *src; dst->b = b; }
