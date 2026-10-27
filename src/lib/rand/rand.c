/* newlib rand.c: srand and rand.  Compiler: EE-GCC 2.96 -O2 -G0. */
struct _reent { char pad[0xA8]; unsigned long long _rand_next; };   /* long is 64-bit on EE-GCC */
extern struct _reent *D_00489738;   /* _impure_ptr */
#define _REENT D_00489738
extern unsigned long long UInt64_Multiply(unsigned long long a, unsigned long long b) __attribute__((const));

void srand(unsigned int seed)   /* srand */
{
    _REENT->_rand_next = seed;
}

int Libc_Rand(void)   /* rand */
{
    struct _reent *r = _REENT;

    r->_rand_next = UInt64_Multiply(r->_rand_next, 6364136223846793005LL) + 1;
    return (int)((r->_rand_next >> 32) & 0x7FFFFFFF);
}