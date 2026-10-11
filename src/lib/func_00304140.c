typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; unsigned char b194; char pad2[0x1B]; void (*cb)(void *buf, int len, int code); } UpnpObj;
extern int func_00304508(UpnpObj *o, int key, int *out);
extern int func_00307928(int h, int key);
#define UPNP_MARK_FLAG(name, field, ON_ALL) void name(UpnpObj *o, int key) { int idx; if (key == -2) { ON_ALL; return; } idx = -2; if (func_00304508(o, key, &idx) != 0 || idx == -2) { func_00307928(o->h180, key); return; } o->ent[idx].field = 1; }
extern int func_00307488(int h, void *buf, unsigned short *len);
void func_00304140(UpnpObj *o, int unused, int flag)
{
    char buf[16];
    unsigned short len = 0;
    if (flag == 0) {
        if (func_00307488(o->h180, buf, &len) == 0) o->cb(buf, len, 0);
    } else {
        o->cb(buf, 0, 5);
    }
}