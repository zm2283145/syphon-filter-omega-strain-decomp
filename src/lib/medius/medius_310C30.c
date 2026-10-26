typedef struct { int child; char pad[0x20C]; int f210; } ScfNode_C30;
extern int rt_memory_free(void *pp);
extern int RtXml_DestroyParser(int child);
int func_00310C30(ScfNode_C30 *o)
{
    ScfNode_C30 *h = 0;
    int ret = 5;
    if (o == 0) return ret;
    h = o;
    if (h->f210) rt_memory_free(&h->f210);
    if (h->child) RtXml_DestroyParser(h->child);
    rt_memory_free(&h);
    return 0;
}