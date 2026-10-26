extern unsigned char D_004908EC;
extern int D_00490904;
extern int rt_msg_client_is_valid_connection(void);
extern void DorkFunk(void);
extern void rt_msg_get_ubyte(unsigned char *src, unsigned char *dst);
extern void rt_msg_get_u4byte(unsigned char *src, void *dst);
extern void rt_msg_set_ubyte(unsigned char *dst, unsigned char v);
extern int rt_msg_set_u4byte(unsigned char *dst, unsigned int v);
extern void *memcpy(void *, const void *, unsigned int);
extern int Sha1_Digest(unsigned char *a, unsigned int b, unsigned char *c, int d);
extern int Md5_Digest(unsigned char *a, unsigned int b, unsigned char *c);
extern int Sha1_Digest2(unsigned char *a, unsigned int b, unsigned char *c, unsigned int d, unsigned char *e, int f);
extern int Md5_Digest2(unsigned char *a, unsigned int b, unsigned char *c, unsigned int d, unsigned char *e);
extern int rt_thread_count_get_active_count(unsigned int *out);
extern int rt_thread_count_get_remenant_count(unsigned int *out);
extern int rt_intc_get_total_interrupt_handlers(unsigned int *out);
extern int rt_thread_count_get_thread_info(unsigned char *a, unsigned char *b, int n, unsigned int *out);
extern int NetConn_BufferMessage(void *conn, int type, int id, unsigned char *buf, unsigned short len, int flags);

int rt_msg_client_process_cheat_query(void *unused0, void *conn, void *unused2, unsigned char *pkt, unsigned int pktlen)
{
    unsigned char buf[0x200];
    unsigned char type;
    unsigned int a;
    unsigned char *b;
    unsigned int c;
    unsigned int tmp;
    unsigned char *p;
    unsigned short len;
    int st = D_004908EC;

    if (st != 1) return 5;
    if (rt_msg_client_is_valid_connection() != st) return 2;
    if (pkt == 0) return 2;
    if (pktlen < 13) return 0;
    rt_msg_get_ubyte(pkt, &type);
    rt_msg_get_u4byte(pkt + 1, &a);
    rt_msg_get_u4byte(pkt + 5, &b);
    rt_msg_get_u4byte(pkt + 9, &c);
    rt_msg_set_ubyte(buf, type);
    rt_msg_set_u4byte(buf + 1, a);
    rt_msg_set_u4byte(buf + 5, (unsigned int)b);
    p = buf + 9;
    switch (type) {
    case 0:
        {
            unsigned int n = 0x1F3;
            if (c < 0x1F3) n = c;
            c = n;
        }
        rt_msg_set_u4byte(p, c);
        memcpy(p + 4, b, c);
        len = c + 13;
        break;
    case 1:
        rt_msg_set_u4byte(p, 16);
        len = 0x1D;
        Sha1_Digest(b, c, p + 4, 16);
        break;
    case 2:
        rt_msg_set_u4byte(p, 16);
        len = 0x1D;
        Md5_Digest(b, c, p + 4);
        break;
    case 3:
        tmp = 0;
        if (!rt_thread_count_get_active_count(&tmp))
            rt_msg_set_u4byte(p, tmp);
        else
            rt_msg_set_u4byte(p, 0);
        len = 13;
        break;
    case 4:
        tmp = 0;
        if (!rt_thread_count_get_remenant_count(&tmp))
            rt_msg_set_u4byte(p, tmp);
        else
            rt_msg_set_u4byte(p, 0);
        len = 13;
        break;
    case 5:
        rt_msg_set_u4byte(p, 16);
        len = 0x1D;
        Sha1_Digest2(pkt + 13, pktlen - 13, b, c, p + 4, 16);
        break;
    case 6:
        rt_msg_set_u4byte(p, 16);
        len = 0x1D;
        Md5_Digest2(pkt + 13, pktlen - 13, b, c, p + 4);
        break;
    case 8:
        rt_msg_set_u4byte(p, 4);
        rt_msg_set_u4byte(p + 4, (unsigned int)&D_00490904);
        len = 0x11;
        break;
    case 9:
        rt_msg_set_u4byte(p, 4);
        rt_msg_set_u4byte(p + 4, (unsigned int)DorkFunk);
        len = 0x11;
        break;
    case 10:
        tmp = 0;
        if (!rt_intc_get_total_interrupt_handlers(&tmp))
            rt_msg_set_u4byte(p, tmp);
        else
            rt_msg_set_u4byte(p, 0);
        len = 13;
        break;
    case 11:
        p += 4;
        len = 13;
        {
        int r = rt_thread_count_get_thread_info(b, p, 0x1F3, &tmp);
        __asm__("" : "+r"(len)); /* empty barrier: stops gcse const-prop of len=13 (retail keeps addu/addiu on s0) */
        if (r == 0) {
            rt_msg_set_u4byte(p - 4, tmp);
            { unsigned short t = tmp; len = t + len; }
        } else {
            rt_msg_set_u4byte(p - 4, 0);
        }
        }
        break;
    case 12: {
        unsigned int i, j;
        unsigned char *found;
        rt_msg_set_u4byte(p, 4);
        p += 4;
        len = 13;
        __asm__("" : "+r"(len)); /* empty barrier: stops gcse const-prop of len=13 (retail keeps addu/addiu on s0) */
        i = 0;
        j = 13;
        found = 0;
        if (c != 0 && len < pktlen) {
            do {
                if (b[i] != pkt[j]) {
                    j = 13;
                    found = 0;
                } else if (!found)
                    found = &b[i];
                i++;
                j++;
            } while (i < c && j < pktlen);
        }
        rt_msg_set_u4byte(p, (unsigned int)found);
        len += 4;
        break;
    }
    default:
        rt_msg_set_u4byte(p, 0);
        len = 13;
        break;
    }
    NetConn_BufferMessage(conn, 0x1D, 0xFFFF, buf, len, 0);
    return 0;
}
