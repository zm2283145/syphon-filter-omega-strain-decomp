typedef unsigned int size_t;
typedef int u128 __attribute__((mode(TI)));

void *Libc_Memmove(void *dst_, const void *src_, size_t n_)
{
  register size_t len __asm__("$6") = n_;
  register const char *src __asm__("$5") = src_;
  register char *dv __asm__("$8") = dst_;
  register char *dst __asm__("$3") = dv;

  if (src < dv)
    {
      register const char *se __asm__("$7") = src + len;
      if (dv < se)
        {
          register int m1 __asm__("$4");
          register int mv __asm__("$2") = -1;
          dst = dv + len;
          len--;
          if (len == (size_t)mv)
            goto ret;
            {
              src = se;
              __asm__("daddu %0,%1,$0" : "=r"(m1) : "r"(mv));
            bb:
              __asm__ __volatile__("addiu %0,%0,-1" : "+r"(src));
              dst--;
              {
                register char t5 __asm__("$2") = *src;
                len--;
                __asm__ __volatile__("sb %1,0(%0)" :: "r"(dst), "r"(t5) : "memory");
              }
              if (len != m1)
                goto bb;
            }
          __asm__ __volatile__("");
          return dv;
        }
    }
  if (!(len < 32) && !(((long)src | (long)dst) & 15))
    {
      register u128 *ad __asm__("$7") = (u128 *)dst;
      register const u128 *as __asm__("$5") = (const u128 *)src;
      register long *ld_ __asm__("$7");
      register const long *ls __asm__("$5");
    l1:
      {
        register u128 t1 __asm__("$3");
        register u128 t2 __asm__("$2");
        register int f __asm__("$4");
        t1 = *as++;
        len -= 32;
        f = len < 32;
        *ad++ = t1;
        t2 = *as++;
        *ad++ = t2;
        if (!f)
          goto l1;
      }
      ld_ = (long *)ad;
      ls = (const long *)as;
      if (len < 8)
        goto o2;
    l2:
      {
        register long t3 __asm__("$3") = *ls++;
        len -= 8;
        *ld_++ = t3;
      }
      if (!(len < 8))
        goto l2;
    o2:
      dst = (char *)ld_;
      src = (const char *)ls;
    }
  len--;
  {
  register int mv __asm__("$2");
  __asm__("addiu %0,$0,-1" : "=r"(mv));
  if (len != (size_t)mv)
    {
      register int m1 __asm__("$4") = mv;
    bf:
      {
        register char t4 __asm__("$2");
        __asm__ __volatile__("lbu %0,0(%1)" : "=r"(t4) : "r"(src));
        len--;
        src++;
        __asm__ __volatile__("sb %1,0(%0)" :: "r"(dst), "r"(t4) : "memory");
        __asm__ __volatile__("addiu %0,%0,1" : "+r"(dst));
      }
      if (len != m1)
        goto bf;
    }
  }
 ret:
  return dv;
}