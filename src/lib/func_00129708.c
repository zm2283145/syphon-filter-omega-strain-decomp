typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

char *Libc_Strncat(char *s1, const char *s2, size_t n)
{
  register char *s __asm__("$8") = s1;
  __asm__("" : "+r"(s));

  if (((long)s & 7) == 0)
    {
      register char *p __asm__("$7");
      register long m15 __asm__("$3") = (long)s & 15;
      if (m15 == 0)
        {
          register u64 ones __asm__("$7") = 0x0101010101010101ULL;
          register u64 highs __asm__("$4");
          register u128 o __asm__("$9");
          register u128 h __asm__("$10");
          register u128 x __asm__("$2");
          register u128 y __asm__("$3");
          register long r __asm__("$3");
          register long q __asm__("$2");
          x = *(u128 *)s;
          __asm__("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones));
          highs = 0x8080808080808080ULL;
          __asm__("psubb %0,%1,%2" : "=r"(y) : "r"(x), "r"(o));
          __asm__ volatile ("pnor %0,$0,%1" : "=r"(x) : "r"(x));
          __asm__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(x));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(h));
          __asm__("pcpyud %0,%1,%2" : "=r"(q) : "r"(y), "r"(highs));
          __asm__ volatile ("or %0,%1,%2" : "=r"(r) : "r"(y), "r"(q));
          p = s;
          if (r == 0)
            {
              p += 16;
              do
              {
                x = *(u128 *)p;
                __asm__("pnor %0,$0,%1" : "=r"(y) : "r"(x));
                __asm__("psubb %0,%1,%2" : "=r"(x) : "r"(x), "r"(o));
                __asm__("pand %0,%1,%2" : "=r"(x) : "r"(x), "r"(y));
                __asm__("pand %0,%1,%2" : "=r"(x) : "r"(x), "r"(h));
                __asm__ volatile ("pcpyud %0,%1,%2" : "=r"(r) : "r"(x), "r"(highs));
                q = (long)x | r;
                p += 16;
              }
              while (q == 0);
              p -= 16;
            }
        }
      else
        {
          register u64 ones __asm__("$9");
          register u64 highs __asm__("$4");
          register u64 x __asm__("$2");
          register u64 d __asm__("$3");
          x = *(u64 *)s;
          ones = 0x0101010101010101ULL;
          highs = 0x8080808080808080ULL;
          p = s;
          d = x - ones;
          x = ~x;
          d &= x;
          d &= highs;
          if (d == 0)
            do
              {
                p += 8;
                x = *(u64 *)p;
              }
            while (((x - ones) & ~x & highs) == 0);
        }
      s1 = p;
    }

  while (*s1)
    s1++;

  while (n-- != 0 && (*s1++ = *s2++))
    {
      if (n == 0)
        *s1 = '\0';
    }

  return s;
}