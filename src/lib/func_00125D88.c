int _mbtowc_r(void *r, int *pwc, const char *s, unsigned int n, void *state)
{
  int dummy;
  unsigned char *t = (unsigned char *)s;
  if (pwc == 0)
    pwc = &dummy;
  if (s != 0 && n == 0)
    return -1;
  if (s == 0)
    return 0;
  *pwc = (int)*t;
  return (*t != '\0');
}