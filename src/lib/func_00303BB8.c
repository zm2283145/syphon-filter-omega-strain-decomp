typedef struct { int h; int a; int b; } RtUdpSlot;
typedef struct { int type; int f4; int f8; int pad[7]; } RtUdpPeer;
typedef struct { RtUdpSlot slot[32]; void *h180; RtUdpPeer *ent; } RtUdpObj;
extern int func_00304578(RtUdpObj *o, int *type, int *peer);
extern int func_00304618(RtUdpObj *o, int *idx);
extern void func_00308380(void *h, int key);
extern void func_00308278(void *h, int key);
extern void func_003079E0(void *h, int key, int idx, int x);
extern void func_002F9728(void *buf);
extern void func_002F8C50(int a, int idx, void *buf);
extern int func_003060F0(int *t, unsigned int *out);
extern void func_003060C0(int *t);

void func_00303BB8(RtUdpObj *o, int key)
{
    char buf[0x40];
    int type;
    int peer;
    int idx;
    unsigned int el;
    unsigned int i;
    unsigned int fr;
    RtUdpSlot *s;

    type = 0;
    peer = -2;
    idx = -2;
    if (func_00304578(o, &type, &peer) == 0) {
        if (type == 7) {
            if (func_00304618(o, &idx) == 0) {
                if (idx != -2) {
                    /* pinned copy: retail shares one -1 register for the store and the 4th arg */
                    register int m1 asm("$7") = -1;
                    o->ent[idx].type = 2;
                    o->ent[idx].f4 = key;
                    o->ent[idx].f8 = m1;
                    func_003079E0(o->h180, key, idx, m1);
                    func_002F9728(buf);
                    func_002F8C50(-1, idx, buf);
                    func_00308278(o->h180, key);
                } else {
                    func_00308380(o->h180, key);
                }
            }
        } else {
            fr = 32;
            for (i = 0; i < 32; i++) {
                if (o->slot[i].h == key) {
                    func_003060F0(&o->slot[i].a, &el);
                    if (el <= 30000)
                        return;
                    func_00308380(o->h180, key);
                    o->slot[i].h = -1;
                    return;
                }
                if (o->slot[i].h == -1 && fr == 32)
                    fr = i;
            }
            if (fr != 32) {
                o->slot[fr].h = key;
                func_003060C0(&o->slot[fr].a);
            } else {
                func_00308380(o->h180, key);
            }
        }
    }
}





