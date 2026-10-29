typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int u64 __attribute__((mode(DI)));

#define DETECTNULL128V(X) ({ register long m_ __asm__("$2"); register long nx_ __asm__("$3"); register long hi_ __asm__("$4"); register long r_ __asm__("$3"); \
  __asm__("psubb %0,%2,%3\n\tpnor %1,$0,%2\n\tpand %0,%0,%1\n\tpand %0,%0,%4" : "=&r"(m_), "=&r"(nx_) : "r"(X), "r"(o), "r"(h)); \
  __asm__ __volatile__("pcpyud %0,%1,%2" : "=r"(hi_) : "r"(m_), "r"(X)); \
  r_ = m_ | hi_; r_; })
#define DETECTNULL128(X) ({ register long m_ __asm__("$2"); register long nx_ __asm__("$3"); register long hi_ __asm__("$4"); register long r_ __asm__("$3"); \
  __asm__("psubb %0,%2,%3\n\tpnor %1,$0,%2\n\tpand %0,%0,%1\n\tpand %0,%0,%4" : "=&r"(m_), "=&r"(nx_) : "r"(X), "r"(o), "r"(h)); \
  __asm__("pcpyud %0,%1,%2" : "=r"(hi_) : "r"(m_), "r"(X)); \
  r_ = m_ | hi_; r_; })

char *Libc_Strcpy(char *dst0, const char *src0)
{
  register char *ret __asm__("$7") = dst0;
  register char *dst __asm__("$3") = ret;
  const char *src = src0;
  register long t __asm__("$8") = (long)src | (long)ret;

  if (!(t & 7))
    {
      register long u __asm__("$2");
      register u64 ones __asm__("$9") = 0x0101010101010101ULL;
      register u64 highs __asm__("$4") = 0x8080808080808080ULL;
      u = t & 15;
      if (!u)
        {
          register u128 *ad __asm__("$6");
          const u128 *as = (const u128 *)src;
          register long o __asm__("$10"), h __asm__("$8");
          register u128 x __asm__("$9");
          __asm__("pcpyld %0,%1,%1" : "=r"(o) : "r"(ones));
          x = *as;
          __asm__ __volatile__("pcpyld %0,%1,%1" : "=r"(h) : "r"(highs));
          {
          register long r __asm__("$3");
          r = DETECTNULL128V(x);
          ad = (u128 *)ret;
          if (!r)
            {
            loop16:
              *ad = x;
              as++;
              x = *as;
              r = DETECTNULL128V(x);
              ad++;
              if (!r)
                goto loop16;
            }
          }
          dst = (char *)ad;
          src = (const char *)as;
        }
      else
        {
          register u64 *ad __asm__("$6") = (u64 *)dst;
          const u64 *as = (const u64 *)src;
          {
            u64 x = *as; register u64 r8 __asm__("$3");
            if (!((x - ones) & ~x & highs))
              do
                {
                  *ad = x;
                  as++;
                  x = *as;
                  { u64 nx = ~x;
                  __asm__ __volatile__("");
                  r8 = (x - ones) & nx & highs; }
                  __asm__ __volatile__("");
                  ad++;
                }
              while (!r8);
          }
          dst = (char *)ad;
          src = (const char *)as;
        }
    }
  while ((*dst++ = *src++))
    ;
  return ret;
}
