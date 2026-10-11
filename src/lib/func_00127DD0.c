typedef struct { char pad[0xA8]; unsigned long long _rand_next; } reent_00127DD0;
extern reent_00127DD0* D_00489738;
extern unsigned long long UInt64_Multiply(unsigned long long a, unsigned long long b) __attribute__((const));
int Random_Next(void)
{
  reent_00127DD0* r = D_00489738;
  r->_rand_next = UInt64_Multiply(r->_rand_next, 6364136223846793005LL) + 1;
  return (int)((r->_rand_next >> 32) & 0x7FFFFFFF);
}