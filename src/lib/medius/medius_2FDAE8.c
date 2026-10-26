typedef struct { char pad[5]; unsigned char f5; } S;
typedef struct { char pad[0x28]; char f28[8]; int f30; } M;
typedef struct { unsigned short id; char pad[6]; int f8; char pad2[0x6C]; S *sub[2]; M *main; } O;
extern unsigned char D_004908EC;
extern int rt_msg_client_is_valid_connection(O *);
extern int rt_msg_client_update_comm_wait(O *);
extern int rt_msg_client_update_send(O *, S *);
extern int rt_msg_client_update_receive(O *, S *, unsigned char);
extern int rt_time_elapsed(void *, unsigned int *);
int rt_msg_client_update_connection(O *o, unsigned char flag)
{
    unsigned int t = 0;
    unsigned int i;
    int r;
    M *m;
    if (D_004908EC != 1) return 5;
    if (rt_msg_client_is_valid_connection(o) != 1) return 2;
    if (o->f8 == 2) {
        r = rt_msg_client_update_comm_wait(o);
        if (r) return r;
        if (o->f8 == 2) return 0;
    }
    for (i = 0; i < 2; i++) {
        if (o->sub[i] && o->sub[i]->f5 == 1) {
            r = rt_msg_client_update_send(o, o->sub[i]);
            if (r) return r;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->sub[i] && o->sub[i]->f5 == 1) {
            r = rt_msg_client_update_receive(o, o->sub[i], flag);
            if (r) return r;
        }
    }
    if (o->f8 == 8) {
        m = o->main;
        if (m->f30) {
            if (rt_time_elapsed(m->f28, &t)) return 0x18;
            if (t > 35000) return 0x19;
        }
    }
    return 0;
}

