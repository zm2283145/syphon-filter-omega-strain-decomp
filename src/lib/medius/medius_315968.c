typedef struct {
    char pad0[0x208];
    unsigned char state;
    char pad209[0x218 - 0x209];
    int a;
    int b;
    int x220;
    int x224;
} Obj5968;
typedef struct {
    char pad0[0x10];
    int key;
    int b;
} Msg5968;
extern int NetStreamMediaFindValidInfo(int id, Obj5968 **out);
extern int NetIsValidConnectionIndex(int);
extern int NetIsValidClientIndex(int);
int __attribute__((weak, section(".dtors_drop"))) NetStreamMediaConvertChannelNum(Obj5968 *o, int id, int *out) { return 0; }
int NetStreamMediaEnumClientCallback(int id, int unused, Msg5968 *p)
{
    Obj5968 *o = 0;
    if (p == 0) return 0;
    if (NetStreamMediaFindValidInfo(id, &o) != 0) return 0;
    if (NetIsValidConnectionIndex(o->a) == 0) return 0;
    if (NetIsValidClientIndex(o->b) == 0) return 0;
    if (o->state == 1 && p->b == o->b) {
        if (p->key == 0) return 1;
        if (NetStreamMediaConvertChannelNum(o, p->key, &o->x224) != 0) return 0;
        {
            Obj5968 *q = o;
            q->x220 = 1;
            q->state = 0;
        }
        return 0;
    }
    return 1;
}

