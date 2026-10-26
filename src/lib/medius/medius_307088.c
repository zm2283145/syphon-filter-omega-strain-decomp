typedef struct { int type; char pad[0x18]; int f1C[6]; int f34[23]; } ScfEnt_088;
typedef struct { int f0; ScfEnt_088 *ent; char pad[0x24]; unsigned int count; } ScfTbl_088;
extern int rt_list_buf_resize_buffer(void *dst, void *src);
int rt_udp_set_buffer_size(ScfTbl_088 *o, unsigned int idx, int which, void *p)
{
    ScfEnt_088 *e;
    int ret = 2;
    if (o == 0) return ret;
    ret = 3;
    if (idx >= o->count) return ret;
    if (o->ent == 0) return ret;
    e = &o->ent[idx];
    if (e->type != 12) return ret;
    if (p == 0) return 1;
    if (which == 0) return rt_list_buf_resize_buffer(e->f1C, p);
    if (which == 1) return rt_list_buf_resize_buffer(e->f34, p);
    return 1;
}