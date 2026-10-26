typedef struct { unsigned short id; char pad[6]; int f8; char pad2[0x78]; void (*cb)(int, int, int, int, int); } O;
typedef struct { char pad[5]; unsigned char f5; unsigned short f6; char pad2[0x34]; short f3c; } P;
extern int rt_msg_client_is_valid_connection(O *);
int __attribute__((weak, section(".dtors_drop"))) rt_msg_client_is_valid_channel(P *p0) { return 0; } /* stub: defined in same original TU; fixes first bne (non-likely) */
extern void rt_msg_get_u4byte(unsigned char *, unsigned int *);
extern int rt_msg_client_get_client_security_mode(void);
extern void rt_msg_get_u2byte(unsigned char *, unsigned short *);
extern void KM_Decrypt(int, int, unsigned int, unsigned char *, int);
extern int rt_msg_client_process_connect_complete(O *, int, unsigned char *, int);
extern int rt_msg_client_process_connect_result(O *, int, unsigned char *, int);
extern int rt_msg_client_change_state(O *, int);
extern int rt_msg_client_is_valid_connection_id(int);
extern int rt_msg_client_process_info_aux_udp(O *, int, unsigned char *, int);
extern int rt_msg_client_process_accept_aux_udp(O *, int, unsigned char *, int);
extern int rt_msg_client_process_client_connect_notify(O *, int, unsigned char *, int);
extern int rt_msg_client_process_app_message(O *, int, unsigned char *, int);
extern int rt_msg_client_process_disconnect_message(O *, int, unsigned char *, int);
extern int rt_msg_client_process_crypt_key_peer(O *, int, unsigned char *, int);
extern void KM_SetGameSessionKey(int, int, unsigned char *);
extern int rt_msg_client_process_system_message(O *, int, unsigned char *, int);
extern int rt_msg_client_process_cheat_query(O *, P *, int, unsigned char *, int);
extern int rt_msg_client_process_memory_poke(O *, P *, int, unsigned char *, int);

int rt_msg_client_process_message(O *o, P *p, int type, unsigned char *data, int len)
{
    unsigned short tmp;
    unsigned int out;
    int sub;
    int r;
    int x;
    r = 1;
    sub = (type >> 7) & 1;
    type &= 0x7F;
    out = 0;
    if (rt_msg_client_is_valid_connection(o) != r) return 2;
    if (rt_msg_client_is_valid_channel(p) != r) return 2;
    if (p->f5 != r) return 2;
    if (o->id != p->f6) return 2;
    if (data == 0) return 2;
    if (sub && len != 0) {
        rt_msg_get_u4byte(data, &out);
        data += 4;
        if (rt_msg_client_get_client_security_mode() != r) return 0x1B;
        if (out == 0) return 0x1C;
        if (type == 3 || type == 0x1B) {
            tmp = 0;
            rt_msg_get_u2byte(data, &tmp);
            tmp = 0xFFFF;
            KM_Decrypt(o->id, 0xFFFF, out, data + 2, len - 2);
        } else {
            KM_Decrypt(o->id, 0xFFFF, out, data, len);
        }
    }
    switch (type) {
    case 26:
        r = rt_msg_client_process_connect_complete(o, type, data, len);
        break;
    case 6:
    case 7:
        r = rt_msg_client_process_connect_result(o, type, data, len);
        if (r == 0x10) {
            x = rt_msg_client_change_state(o, 0xB);
            if (x != 0) return x;
            if (o->cb == 0) goto nocb;
            {
                int id = o->id;
                o->cb(id, 0, 0, 0, 3);
                if (rt_msg_client_is_valid_connection_id(id) != 0) goto nocb;
                return 0xB;
            }
        }
        break;
    case 24:
        r = rt_msg_client_process_info_aux_udp(o, type, data, len);
        break;
    case 25:
        if (o->f8 != 6) goto nocb;
        r = rt_msg_client_process_accept_aux_udp(o, type, data, len);
        break;
    case 8:
    case 9:
        r = rt_msg_client_process_client_connect_notify(o, type, data, len);
        break;
    case 2:
    case 3:
    case 10:
        r = 0;
        if (o->f8 == 8) r = rt_msg_client_process_app_message(o, type, data, len);
        break;
    nocb:
        r = 0;
        break;
    case 5:
        r = 0;
        p->f3c--;
        break;
    case 17:
        r = rt_msg_client_process_disconnect_message(o, type, data, len);
        break;
    case 19:
    case 27:
        r = rt_msg_client_process_crypt_key_peer(o, type, data, len);
        break;
    case 20:
        r = 0;
        KM_SetGameSessionKey(o->id, o->id, data);
        break;
    case 28:
        r = rt_msg_client_process_system_message(o, type, data, len);
        break;
    case 29:
        r = rt_msg_client_process_cheat_query(o, p, type, data, len);
        break;
    case 30:
        r = rt_msg_client_process_memory_poke(o, p, type, data, len);
        break;
    default:
        r = 3;
        break;
    }
    return r;
}

