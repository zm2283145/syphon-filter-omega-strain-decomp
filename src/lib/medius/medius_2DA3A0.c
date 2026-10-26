typedef struct { char pad[0x98]; int n; } OA3A0;
extern int GetGrid(OA3A0* p, int n);
int GetVideoAllowedGrid(OA3A0* p)
{
    int r = 0;
    if (p->n > 0)
        r = GetGrid(p, p->n);
    return r;
}
