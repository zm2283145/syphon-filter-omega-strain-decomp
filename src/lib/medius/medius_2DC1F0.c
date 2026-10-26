typedef struct { char pad[0x24]; void (*cb)(int); char pad2[0x14]; int arg; } XC1F0;
extern void rt_memory_free(XC1F0** pp);
void DestroyCodec(XC1F0* p)
{
    if (p) {
        if (p->cb)
            p->cb(p->arg);
        rt_memory_free(&p);
    }
}
