typedef struct { int a; int b; int id; } NetObj_690;
extern int sceInetControl(void *cd, int *buf, int a, int b, void *data, int len);
int sceBInetControl(void *cd, int *buf, NetObj_690 *p, int b, void *data, int len)
{
    if (p == 0) return -0x200;
    return sceInetControl(cd, buf, p->id, b, data, len);
}