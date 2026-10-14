typedef struct { char pad[0x98]; int n; } OA3A0;
extern int func_002D9E18(OA3A0* p, int n);
int func_002DA3A0(OA3A0* p)
{
    int r = 0;
    if (p->n > 0)
        r = func_002D9E18(p, p->n);
    return r;
}
