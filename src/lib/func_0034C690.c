typedef struct { int a; int b; int id; } NetObj_690;
extern int func_0034B180(void *cd, int *buf, int a, int b, void *data, int len);
int func_0034C690(void *cd, int *buf, NetObj_690 *p, int b, void *data, int len)
{
    if (p == 0) return -0x200;
    return func_0034B180(cd, buf, p->id, b, data, len);
}