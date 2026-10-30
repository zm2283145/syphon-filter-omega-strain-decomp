typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

char *strncpy(char *dst0, const char *src, size_t count)
{
  register char *dst0c __asm__("$8") = dst0;
  char *dst = dst0;
  register long t __asm__("$7");
  register char *p __asm__("$7");
  register u64 ones __asm__("$9");
  register u64 highs __asm__("$10");
  register u64 x8 __asm__("$3");
  register u64 d __asm__("$2");
  register u64 y8 __asm__("$2");
  register size_t size __asm__("$9");
  register size_t big __asm__("$10");
  register int small __asm__("$2");
  register long m __asm__("$2");

  __asm__("" : "+r"(dst0c));
  t = (long)src | (long)dst;
  __asm__ volatile ("" : "+r"(t));
  big = 16;
  __asm__ volatile ("" : "+r"(big));
  m = t & 7;
  __asm__ volatile ("" : "+r"(m));
  size = 8;
  __asm__ volatile ("" : "+r"(size));
  if (m == 0)
    {
      m = t & 15;
      __asm__ ("" : "+r"(m));
      if (m == 0)
        size = big;
      __asm__ ("" : "+r"(size));
      if (m == 0)
        {
          register u64 ones1 __asm__("$7");
          register u64 highs1 __asm__("$7");
          register u128 o __asm__("$9");
          register u128 h __asm__("$10");
          register u128 x __asm__("$3");
          register u128 y __asm__("$2");
          register long r __asm__("$3");
          register long q __asm__("$2");
          small = count < size;
          if (small)
            goto bytes;
          ones1 = 0x0101010101010101ULL;
          x = *(const u128 *)src;
          __asm__ volatile ("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones1));
          __asm__ volatile ("pnor %0,$0,%1" : "=r"(x) : "r"(x));
          highs1 = 0x8080808080808080ULL;
          __asm__("psubb %0,%1,%2" : "=r"(y) : "r"(x), "r"(o));
          __asm__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs1));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(x));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(h));
          __asm__ volatile ("pcpyud %0,%1,%2" : "=r"(r) : "r"(y), "r"(dst));
          r = (long)y | r;
          p = dst0c;
          if (r != 0)
            goto out;
          x = *(const u128 *)src;
          count -= 16;
          src += 16;
          *(u128 *)p = x;
          p += 16;
          if (count < 16)
            goto out;
          y = *(const u128 *)src;
          __asm__("pnor %0,$0,%1" : "=r"(x) : "r"(y));
          __asm__("psubb %0,%1,%2" : "=r"(y) : "r"(y), "r"(o));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(x));
          __asm__("pand %0,%1,%2" : "=r"(y) : "r"(y), "r"(h));
          __asm__("pcpyud %0,%1,%2" : "=r"(r) : "r"(y), "r"(dst));
          q = (long)y | r;
          if (q == 0)
            goto next16;
          goto out;
        }
      small = count < size;
      if (small)
        goto bytes;
      x8 = *(const u64 *)src;
      ones = 0x0101010101010101ULL;
      highs = 0x8080808080808080ULL;
      d = x8 - ones;
      x8 = ~x8;
      d &= x8;
      d &= highs;
      __asm__ volatile ("");
      p = dst0c;
      if (d != 0)
        goto out;
      do
        {
          x8 = *(const u64 *)src;
        loop8:
          count -= 8;
          src += 8;
          small = count < 8;
          __asm__ volatile ("");
          *(u64 *)p = x8;
          p += 8;
          if (small)
            goto out;
          y8 = *(const u64 *)src;
        }
      while (((x8 = ~y8), (y8 = y8 - ones), (y8 &= x8), (y8 &= highs)) == 0);
    out:
      dst = p;
    }

bytes:
  {
    register size_t c __asm__("$2");
  top:
    c = count;
    if (count == 0)
      goto end;
    __asm__ ("" : : "r"(c));
    --count;
    if ((*dst++ = *src++) != '\0')
      goto top;
    {
            size_t c2;
            if (count-- > 0)
              do
                {
                __asm__ volatile ("sb $0,0(%0)" : : "r"(dst));
                c2 = count;
                dst++;
                __asm__ volatile ("addiu %0,%0,-1" : "+r"(count));
                }
              while (c2);
    }
  }
 end:
  return dst0c;
  do
    {
      register u128 x __asm__("$3");
    next16:
      x = *(const u128 *)src;
      goto loop8;
    }
  while (0);
}