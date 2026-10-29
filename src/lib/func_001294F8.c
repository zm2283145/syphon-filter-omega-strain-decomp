/* strlen: newlib-style word-at-a-time scan using EE MMI (16 bytes) or 64-bit
   (8 bytes) null detection, built with EE-GCC 2.95.3. */
typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

size_t strlen(const char *s)
{
  register const char *str __asm__("$4") = s;
  register const char *start __asm__("$7") = str;
  const char *p;

  if (!((long)str & 7))
    {
      register long lo __asm__("$3");
      register u64 ones __asm__("$2");
      lo = (long)str & 15;
      ones = 0x0101010101010101ULL;
      p = str;
      if (!lo)
        {
          register u64 highs __asm__("$4");
          register long o __asm__("$8");
          register long h __asm__("$9");
          register long r __asm__("$6");
          register long m __asm__("$2");
          register long nx __asm__("$3");
          register long hi __asm__("$3");
          register u128 x __asm__("$3");
          x = *(const u128 *)p;
          __asm__("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones), "r"(x));
          __asm__ volatile ("");
          highs = 0x8080808080808080ULL;
          __asm__ ("psubb %0,%1,%2" : "=r"(m) : "r"(x), "r"(o), "r"(highs));
          __asm__ ("pnor %0,$0,%1" : "=r"(nx) : "r"(x));
          __asm__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs), "r"(nx));
          __asm__("pand %0,%1,%2" : "=r"(m) : "r"(m), "r"(nx));
          __asm__("pand %0,%1,%2" : "=r"(m) : "r"(m), "r"(h));
          __asm__("pcpyud %0,%1,%2" : "=r"(hi) : "r"(m), "r"(o));
          r = hi | m;
          if (!r)
            {
              register long m2 __asm__("$4");
              register long r2 __asm__("$3");
              register u128 x2 __asm__("$2");
            loop16:
              p += 16;
              x2 = *(const u128 *)p;
              __asm__ ("pnor %0,$0,%1" : "=r"(nx) : "r"(x2));
              __asm__ ("psubb %0,%1,%2" : "=r"(m) : "r"(x2), "r"(o), "r"(highs));
              __asm__("pand %0,%1,%2" : "=r"(m) : "r"(m), "r"(nx));
              __asm__("pand %0,%1,%2" : "=r"(m2) : "r"(m), "r"(h));
              __asm__("pcpyud %0,%1,%2" : "=r"(hi) : "r"(m2), "r"(r));
              r2 = hi | m2;
              if (!r2) goto loop16;
              __asm__ volatile ("");
            }
        }
      else
        {
          register u64 highs __asm__("$4");
          highs = 0x8080808080808080ULL;
          if (!((*(const u64 *)p - ones) & ~*(const u64 *)p & highs))
            {
              register u64 o6 __asm__("$6");
              o6 = 0x0101010101010101ULL;
            loop8:
              p += 8;
              __asm__ volatile ("");
              if (!((*(const u64 *)p - o6) & ~*(const u64 *)p & highs)) goto loop8;
            }
        }
      str = p;
    }
  if (*str) { loopb: str++; if (*str) goto loopb; }
  return str - start;
}
