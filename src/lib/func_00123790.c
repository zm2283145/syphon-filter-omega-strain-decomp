extern void* func_00125660(void* d, unsigned int n);
extern void* memset(void* p, int c, unsigned int n);
struct glue_00123790 { struct glue_00123790* _next; int _niobs; void* _iobs; };
struct glue_00123790* func_00123790(void* d, int n)
{
  struct glue_00123790 *g;
  g = (struct glue_00123790 *) func_00125660 (d, sizeof (*g) + n * 0x58);
  if (g == 0)
    return 0;
  g->_next = 0;
  g->_niobs = n;
  g->_iobs = (void *) (g + 1);
  memset (g->_iobs, 0, n * 0x58);
  return g;
}