typedef struct { int f0; int f4; int end; int start; } X5898;
int rt_circ_buf_get_avail(X5898* p, int* out)
{
    int ret = 2;
    if (p == 0) return ret;
    if (out == 0) return ret;
    *out = p->end - p->start;
    return 0;
}
