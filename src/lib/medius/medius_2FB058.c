/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int rt_list_buf_calc_free_space(int, unsigned int *);
extern int rt_list_buf_calc_free_contiguous_space(int, unsigned int *);
int __attribute__((weak, section(".dtors_drop"))) rt_list_buf_calc_free_non_contiguous_space(int a0, unsigned int * a1) { return 0; }
extern int rt_list_buf_normalize(int, int);
int rt_list_buf_space_available(int s, int b, unsigned int n)
{
    unsigned int y = 0;
    unsigned int x = 0;
    int r;
    r = rt_list_buf_calc_free_space(s, &x);
    if (r) return r;
    if (x < n) return 3;
    r = rt_list_buf_calc_free_contiguous_space(s, &y);
    if (r) return r;
    if (y < n) {
        r = rt_list_buf_calc_free_non_contiguous_space(s, &x);
        if (r) return r;
        if (x - y >= n) {
            ((int *)s)[1] = 0;
        } else {
            r = rt_list_buf_normalize(s, b);
            if (r) return r;
        }
    }
    return 0;
}
