typedef unsigned int size_t;
typedef unsigned int u128 __attribute__((mode(TI)));
void *Libc_Memchr(const void *src_void, int c, size_t length)
{
  register const unsigned char *src __asm__("$4") = (const unsigned char *) src_void;
  c &= 0xff;
  if (!(length < 16) && !((long)src & 15))
    {
      register const unsigned char *p __asm__("$7") = src;
      register long sh __asm__("$3");
      register long lo0 __asm__("$2");
      register long m __asm__("$10");
      register long hi __asm__("$3");
      register long x __asm__("$8");
      register u128 mask __asm__("$9");
      register u128 hiq __asm__("$8");
      register long lo __asm__("$4");
      __asm__ __volatile__("" : "+r"(p));
      sh = (long)c << 8;
      lo0 = 0x0101010101010101L;
      __asm__("" : "+r"(lo0));
      __asm__("daddu %0,%1,%2" : "=r"(m) : "r"(sh), "r"(c));
      hi = 0x8080808080808080L;
      __asm__ __volatile__("pcpyh %0,%1" : "=r"(x) : "r"(m));
      __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(mask) : "r"(x));
      lo = lo0;
      __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(hiq) : "r"(hi));
      do
        {
          register u128 v __asm__("$2");
          register u128 ones __asm__("$10");
          register u128 n __asm__("$3");
          register long t __asm__("$3");
          register long r __asm__("$2");
          v = *(u128 *)p;
          __asm__("pxor %0,%1,%2" : "=r"(v) : "r"(v), "r"(mask));
          __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(ones) : "r"(lo));
          __asm__("pnor %0,$0,%1" : "=r"(n) : "r"(v));
          __asm__("psubb %0,%1,%2" : "=r"(v) : "r"(v), "r"(ones));
          __asm__("pand %0,%1,%2" : "=r"(v) : "r"(v), "r"(n));
          __asm__("pand %0,%1,%2" : "=r"(v) : "r"(v), "r"(hiq));
          __asm__("pcpyud %0,%1,%2" : "=r"(t) : "r"(v), "r"(mask));
          __asm__("or %0,%1,%2" : "=r"(r) : "r"(v), "r"(t));
          if (r)
            break;
          length -= 16;
          p += 16;
        }
      while (!(length < 16));
      src = p;
    }
  length--;
  if (length != (size_t)-1)
    {
      register size_t m1 __asm__("$3") = -1;
    loop:
      if (*src == c)
        goto found;
      length--;
      src++;
      if (length != m1)
        goto loop;
    }
  return 0;
found:
  return (void *) src;
}
