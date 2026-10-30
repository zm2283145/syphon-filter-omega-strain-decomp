typedef unsigned int u128 __attribute__((mode(TI)));
extern char *Libc_Strcpy(char *, const char *);

char *Libc_Strcat(char *s1, const char *s2)
{
  register char *b __asm__("$4");
  register char *s __asm__("$16");
  {
    register u128 s16 __asm__("$16");
    __asm__("move %0,%1" : "=r"(s16) : "r"(s1));
  }
  if ((long)s & 7)
    {
      b = s1;
      goto bytes;
    }
  {
    register unsigned long m1 __asm__("$3");
    register unsigned long m8 __asm__("$4");
    register unsigned long x __asm__("$6");
    register long a15 __asm__("$2") = (long)s & 15;
    m1 = 0x0101010101010101;
    m8 = 0x8080808080808080;
    x = *(unsigned long *)s;
    if (a15)
      goto eight;
    {
      register u128 q1 __asm__("$7");
      register u128 q8 __asm__("$8");
      register u128 *p __asm__("$6");
      register u128 v __asm__("$2");
      register u128 t __asm__("$3");
      register unsigned long hi __asm__("$2");
      register unsigned long r __asm__("$3");
      v = *(u128 *)s;
      __asm__("pcpyld %0,%1,%1" : "=r"(q1) : "r"(m1), "r"(v));
      __asm__("pcpyld %0,%1,%1" : "=r"(q8) : "r"(m8), "r"(q1));
      __asm__("psubb %0,%1,%2" : "=r"(t) : "r"(v), "r"(q1), "r"(q8));
      __asm__("pnor %0,$0,%1" : "=r"(v) : "r"(v));
      __asm__("pand %0,%1,%2" : "=r"(t) : "r"(t), "r"(v));
      __asm__("pand %0,%1,%2" : "=r"(t) : "r"(t), "r"(q8));
      __asm__("pcpyud %0,%1,%1" : "=r"(hi) : "r"(t));
      {
        register unsigned long tl __asm__("$3");
        r = hi | tl;
      }
      __asm__ __volatile__("");
      b = s;
      if (r)
        goto bytes;
      p = (u128 *)(b + 16);
      {
      register u128 w __asm__("$2");
      register u128 n __asm__("$3");
      register unsigned long h __asm__("$3");
      register unsigned long rr __asm__("$2");
      register unsigned long wl __asm__("$2");
      goto first16;
      top16:
        p++;
      first16:
        w = *p;
        __asm__("pnor %0,$0,%1" : "=r"(n) : "r"(w), "r"(b));
        __asm__("psubb %0,%1,%2" : "=r"(w) : "r"(w), "r"(q1));
        __asm__("pand %0,%1,%2" : "=r"(w) : "r"(w), "r"(n));
        __asm__("pand %0,%1,%2" : "=r"(w) : "r"(w), "r"(q8));
        __asm__("pcpyud %0,%1,%1" : "=r"(h) : "r"(w));
        rr = wl | h;
      if (rr == 0)
        goto top16;
      }
      b = (char *)p;
      goto bytes;
    }
  eight:
    {
      register unsigned long c1 __asm__("$7");
      register unsigned long c8 __asm__("$8");
      register unsigned long *p __asm__("$6");
      register unsigned long t __asm__("$3");
      register unsigned long nx __asm__("$2");
      __asm__("move %0,%1" : "=r"(c1) : "r"(m1));
      __asm__("move %0,%1" : "=r"(c8) : "r"(m8));
      t = x - m1;
      __asm__ __volatile__("");
      nx = ~x;
      t &= nx;
      t &= m8;
      b = s;
      if (t)
        goto bytes;
      p = (unsigned long *)(s + 8);
      {
        register unsigned long w __asm__("$2");
        register unsigned long n __asm__("$3");
        goto first8;
      top8:
            p++;
          first8:
            w = *p;
            n = ~w;
            w -= c1;
            w &= n;
            w &= c8;
            __asm__("" : : "r"(b));
        if (w == 0)
          goto top8;
      }
      b = (char *)p;
    }
  }
bytes:
  {
    register int c __asm__("$2");
    goto bfirst;
  btop:
        b++;
      bfirst:
        c = *b;
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("");
    if (c)
      goto btop;
  }
  Libc_Strcpy(b, s2);
  {
    register u128 x31 __asm__("$31");
    __asm__ __volatile__("" : "=r"(x31));
  }
  return s;
}