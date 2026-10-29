typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
int Libc_Memcmp(const void *m1, const void *m2, size_t nn)
{
  register unsigned char *s1 __asm__("$4") = (unsigned char *) m1;
  register unsigned char *s2 __asm__("$5") = (unsigned char *) m2;
  register size_t n __asm__("$6") = nn;
  if (!(n < 16) && !((((long)s1 & 15)) | ((long)s2 & 15)))
    {
      register int c __asm__("$7");
      do
        {
          long x; register long t __asm__("$10"); register long r __asm__("$9");
          register unsigned char *p __asm__("$2");
          c = n < 32;
          { register u128 a __asm__("$3") = *(u128 *)s1; u128 b = *(u128 *)s2;
          __asm__("pxor %0,%1,%2" : "=&r"(x) : "r"(b), "r"(a));
          }
          s1 += 16;
          p = s2 + 16;
          __asm__ __volatile__("pcpyud %0,%1,%2" : "=&r"(t) : "r"(x), "r"(c));
          __asm__("or %0,%1,%2" : "=&r"(r) : "r"(t), "r"(x));
          __asm__ __volatile__("movz %0,%1,%2" : "+r"(s2) : "r"(p), "r"(r));
          if (r == 0) n -= 16;
          if (r) { s1 -= 16; break; }
        }
      while (!c);
    }
  while (n--)
    {
      if (*s1 != *s2)
        return *s1 - *s2;
      s1++;
      s2++;
    }
  return 0;
}
