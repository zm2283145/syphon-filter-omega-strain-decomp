typedef struct { char name[16]; short port; } Addr;
typedef struct { char pad0[0x8C]; int sock; char pad90[0xBC - 0x90]; int state; char name[16]; int port; volatile int mode; } Conn;
extern int strlen(const char *);
extern char *strncpy(char *, const char *, int);
extern void *memset(void *, int, int);
extern int func_00307328(int, Addr *);
extern void func_002F5270(int);
extern int func_002D92B0(Conn *);
int func_002D8FB0(Conn *o, char *name, int port, int mode)
{
    Addr a;
    if (o == 0) goto fail;
    if (name == 0) return -1;
    if (strlen(name) == 0) return -1;
    if (port == 0) goto fail;
    strncpy(o->name, name, 16);
    o->port = port;
    o->mode = mode;
    o->state = 1;
    memset(&a, 0, sizeof(a));
    strncpy(a.name, name, 16);
    a.port = port;
    if (func_00307328(o->sock, &a) != 0) {
fail:
        return -1;
    }
    while (o->state == 1 && o->mode == 0) {
        func_002F5270(20);
        func_002D92B0(o);
    }
    return 0;
}


