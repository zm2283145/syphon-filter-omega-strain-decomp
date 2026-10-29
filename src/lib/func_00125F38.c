/* memcpy: Sony EE newlib memcpy (128-bit lq/sq blocks, 64-bit words, then bytes). */
typedef unsigned int size_t;
typedef int u128 __attribute__((mode(TI)));

void *memcpy(void *dst0, const void *src0, size_t len0)
{
  char *dst = dst0;
  const char *src = src0;
  u128 *aligned_dst;
  const u128 *aligned_src;
  int len = len0;

  if (!(len < 32U) && !(((long)src & 15) | ((long)dst & 15)))
    {
      aligned_dst = (u128 *)dst;
      aligned_src = (u128 *)src;
    big:
      {
        /* pinned: retail keeps the two quads in v1/v0 so the loop test lands in a0 */
        register u128 t0 __asm__("$3");
        register u128 t1 __asm__("$2");
        t0 = *aligned_src++;
        *aligned_dst++ = t0;
        t1 = *aligned_src++;
        *aligned_dst++ = t1;
      }
      len -= 32;
      if (len >= 32U) goto big;

      if (len >= 8U)
        {
        word:
          /* barrier: counts as an insn so ee-gcc's r5900 short-loop pass keeps the delay slot filled */
          __asm__ volatile ("");
          *(long *)aligned_dst = *(long *)aligned_src;
          aligned_dst = (u128 *)((long *)aligned_dst + 1);
          aligned_src = (u128 *)((long *)aligned_src + 1);
          len -= 8;
          if (len >= 8U) goto word;
        }

      dst = (char *)aligned_dst;
      src = (char *)aligned_src;
    }

  len--;
  {
    int k = -1;
    if (len != k)
      {
        int m;
        /* barrier: makes the loop's -1 a register copy of k (retail daddu a0,v0) */
        __asm__ ("" : "=r"(m) : "0"(k));
      byte:
        *dst++ = *src++;
        len--;
        if (len != m) goto byte;
      }
  }

  return dst0;
}
