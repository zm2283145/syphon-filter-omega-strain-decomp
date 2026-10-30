typedef unsigned int size_t;
typedef int u128 __attribute__((mode(TI)));

void *memset(void *m_, int c_, size_t n_)
{
  register size_t n __asm__("$6") = n_;
  register int c __asm__("$5") = c_;
  register void *m __asm__("$4") = m_;
  register char *s __asm__("$3") = (char *) m;

  if (!(n < 8) && !((long)m & 15))
    {
      register unsigned long *a __asm__("$7") = (unsigned long *) m;
      register long d __asm__("$9");
      register long b0 __asm__("$8");
      register long sh __asm__("$3");
      register long b1 __asm__("$8");
      register long buffer __asm__("$3");
      register u128 q __asm__("$8");
      register int big __asm__("$10");
      __asm__ __volatile__("" : "+r"(a));

      __asm__("" : "+r"(n));
      d = c & 0xff;
      big = n < 32;
      __asm__ __volatile__("" : "+r"(big));
      b0 = d;
      __asm__ __volatile__("" : "+r"(b0));
      sh = b0 << 8;
      b1 = sh | d;
      __asm__ ("pcpyh %0,%1" : "=r" (buffer) : "r" (b1));
      if (!big)
        {
          __asm__ ("pcpyld %0,%1,%1" : "=r" (q) : "r" (buffer));
        l1:
            __asm__ __volatile__ ("sq %0,0(%1)" : : "r" (q), "r" (a) : "memory");
            n -= 32;
            a += 2;
            __asm__("" : "+r"(a) : "r"(n));
            *(u128 *) a = q;
            a += 2;
            if (n >= 32)
              goto l1;
        }
      goto test;
    loop:
      *a++ = buffer;
      n -= 8;
    test:
      if (n >= 8)
        goto loop;
      __asm__ __volatile__("");
      s = (char *) a;
    }

  n--;
  if (n != (size_t)-1)
    {
      register size_t m1 __asm__("$2") = -1;
    bl:
      __asm__ __volatile__("sb %1,0(%0)" :: "r"(s), "r"(c) : "memory");
      n--;
      __asm__ __volatile__("addiu %0,%0,1" : "+r"(s));
      if (n != m1)
        goto bl;
    }

  return m;
}