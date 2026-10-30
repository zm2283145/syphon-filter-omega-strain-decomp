typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

int Libc_Strncmp(const char *s1, const char *s2, size_t n)
{
  if (n == 0)
    return 0;
  if (!(((long)s1 | (long)s2) & 7))
    {
      const char *p1;
      const char *p2;
      long t = ((long)s1 | (long)s2) & 15;
      register long lt __asm__("$7");
      register u64 ones __asm__("$9");
      __asm__("" : "+r"(t));
      lt = n < 16;
      ones = 0x0101010101010101ULL;
      __asm__ volatile ("or %0,%1,%2" : "=r"(t) : "r"(t), "r"(lt));
      p1 = s1;
      if (!t)
        {
          register u128 o __asm__("$10");
          register u128 h __asm__("$9");
          register u128 a __asm__("$2");
          register u128 b __asm__("$3");
          register long d __asm__("$2");
          register long r __asm__("$3");
          int lq;
          register u64 highs __asm__("$8");
          b = *(const u128 *)s1;
          __asm__ volatile ("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones));
          a = *(const u128 *)s2;
          highs = 0x8080808080808080ULL;
          __asm__("psubw %0,%1,%2" : "=r"(b) : "r"(b), "r"(a));
          __asm__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs));
          __asm__("pcpyud %0,%1,%2" : "=r"(d) : "r"(b), "r"(s1));
          p2 = s2;
          __asm__("or %0,%1,%2" : "=r"(r) : "r"(d), "r"(b));
          if (r)
            goto bytes;
        loop16:
          n -= 16;
          if (n == 0)
            return 0;
          a = *(const u128 *)p1;
          __asm__("pnor %0,$0,%1" : "=r"(b) : "r"(a));
          __asm__("psubb %0,%1,%2" : "=r"(a) : "r"(a), "r"(o));
          __asm__("pand %0,%1,%2" : "=r"(a) : "r"(a), "r"(b));
          __asm__("pand %0,%1,%2" : "=r"(b) : "r"(a), "r"(h));
          __asm__("pcpyud %0,%1,%2" : "=r"(d) : "r"(b), "r"(s1));
          __asm__("or %0,%1,%2" : "=r"(d) : "r"(d), "r"(b));
          if (d)
            return 0;
          p1 += 16;
          lq = n < 16;
          b = *(const u128 *)p1;
          p2 += 16;
          if (lq)
            goto out;
          a = *(const u128 *)p2;
          __asm__("psubw %0,%1,%2" : "=r"(b) : "r"(b), "r"(a));
          __asm__("pcpyud %0,%1,%2" : "=r"(d) : "r"(b), "r"(s1));
          __asm__("or %0,%1,%2" : "=r"(d) : "r"(d), "r"(b));
          if (d == 0)
            goto loop16;
        }
      else
        {
          register u64 highs __asm__("$10");
          u64 x;
          int l8;
          register u64 c __asm__("$3");
          register u64 e __asm__("$2");
          p2 = s2;
          if (n < 8)
            goto out;
          c = *(const u64 *)s1;
          e = *(const u64 *)s2;
          if (c != e)
            goto bytes;
          n -= 8;
          highs = 0x8080808080808080ULL;
        loop8:
          if (n == 0)
            return 0;
          x = *(const u64 *)p1;
          if ((x - ones) & ~x & highs)
            return 0;
          p1 += 8;
          __asm__("" : "+r"(p1));
          l8 = n < 8;
          p2 += 8;
          if (l8)
            goto out;
          c = *(const u64 *)p1;
          e = *(const u64 *)p2;
          if (c == e)
            goto next8;
        }
    out:
      s1 = p1;
      s2 = p2;
    }
bytes:
  while (n-- > 0 && *s1 == *s2)
    {
      if (n == 0 || *s1 == '\0')
        return 0;
      s1++;
      s2++;
    }
  { register int c2 __asm__("$2") = *(unsigned char *)s2; return *(unsigned char *)s1 - c2; }
next8:
  n -= 8;
  goto loop8;
}