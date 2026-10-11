typedef struct { char pad[0x14]; char name[0x12]; unsigned short port; char pad2[0x28]; int busy; } ScfSvc_B60;
extern char *strncpy(char *d, const char *s, unsigned int n);
int func_0030EB60(ScfSvc_B60 *o, char *dst, unsigned short *port)
{
    int ret = 2;
    if (o == 0) return ret;
    if (o->busy != 0) return 7;
    if (dst == 0) return ret;
    if (port == 0) return ret;
    strncpy(dst, o->name, 16);
    *port = o->port;
    return 0;
}