typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

char *strchr(const char *s0, int c0)
{
  register const unsigned char *s __asm__("$4") = (const unsigned char *)s0;
  register int c __asm__("$5") = c0;

  c &= 0xFF;
  if ((long)s & 7)
    goto bytes;
  {
    register u64 ones __asm__("$6");
    register u64 highs __asm__("$8");
    register u64 cc __asm__("$7");
    register long lo __asm__("$3");
    {
      register u64 v __asm__("$3");
      register u64 t __asm__("$10");
      register u64 u __asm__("$2");
      v = (u64)c << 8;
      ones = 0x0101010101010101ULL;
      __asm__("daddu %0,%1,%2" : "=r"(t) : "r"(v), "r"(c));
      lo = (long)s & 15;
      u = t << 16;
      __asm__ __volatile__ ("");
      highs = 0x8080808080808080ULL;
      __asm__ __volatile__("daddu %0,%1,%2" : "=r"(u) : "r"(u), "r"(t));
      t = u << 32;
      cc = u + t;
    }
    if (lo)
      goto path8;
  loop16:
    {
      register u128 x __asm__("$9");
      register u128 o __asm__("$10");
      register u128 h __asm__("$6");
      register u128 q __asm__("$8");
      register u128 m __asm__("$2");
      register u128 n __asm__("$3");
      register long r __asm__("$3");
      register long r1 __asm__("$2");
      x = *(const u128 *)s;
      __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones));
      __asm__ __volatile__("pnor %0,$0,%1" : "=r"(n) : "r"(x));
      __asm__ __volatile__("psubb %0,%1,%2" : "=r"(m) : "r"(x), "r"(o));
      __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs));
      __asm__ __volatile__("pand %0,%1,%2" : "=r"(m) : "r"(m), "r"(n));
      __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(q) : "r"(cc));
      __asm__ __volatile__("pand %0,%1,%2" : "=r"(m) : "r"(m), "r"(h));
      __asm__ __volatile__("pcpyud %0,%1,%2" : "=r"(n) : "r"(m), "r"(cc));
      r = (long)m | (long)n;
      if (r)
        goto bytes;
      __asm__ __volatile__("pxor %0,%1,%2" : "=r"(m) : "r"(x), "r"(q));
      __asm__ __volatile__("psubb %0,%1,%2" : "=r"(n) : "r"(m), "r"(o));
      __asm__ __volatile__("pnor %0,$0,%1" : "=r"(m) : "r"(m));
      highs = 0x8080808080808080ULL;
      __asm__ __volatile__("pand %0,%1,%2" : "=r"(n) : "r"(n), "r"(m));
      __asm__ __volatile__("pand %0,%1,%2" : "=r"(n) : "r"(n), "r"(h));
      ones = 0x0101010101010101ULL;
      __asm__ __volatile__("pcpyud %0,%1,%2" : "=r"(m) : "r"(n), "r"(c));
      r = (long)m | (long)n;
      if (!r)
        goto next16;
      goto bytes;
    }
  path8:
    {
      register u64 w __asm__("$9");
      register u64 n __asm__("$3");
      register u64 d __asm__("$2");
      register u64 e __asm__("$3");
      register u64 one __asm__("$9");
      register u64 w2 __asm__("$6");
      __asm__("" : "+r"(s));
      w = *(const u64 *)s;
      n = ~w;
      d = w - ones;
      d &= n;
      d &= highs;
      if (d)
        goto bytes;
      d = w ^ cc;
      e = d - ones;
      d = ~d;
      e &= d;
      e &= highs;
      if (e)
        goto bytes;
      __asm__("daddu %0,%1,$0" : "=r"(one) : "r"(ones));
      s += 8;
    do {
    loop8:
      w2 = *(const u64 *)s;
      d = w2 - one;
      n = ~w2;
      d &= n;
      d &= highs;
      if (d)
        goto bytes;
      d = w2 ^ cc;
      n = ~d;
      d = d - one;
      d &= n;
      d &= highs;
      if (d == 0)
        goto next8;
      goto bytes;
    } while (0);
    }
  }
  {
    register int ch __asm__("$2");
  body:
    if (ch == c)
      goto done;
    s++;
  bytes:
    ch = *s;
    if (ch)
      goto body;
  }
  __asm__ volatile ("" ::: "memory");
done:
  return (*s == c) ? (char *)s : 0;
next16:
  s += 16;
  goto loop16;
next8:
  s += 8;
  goto loop8;
}