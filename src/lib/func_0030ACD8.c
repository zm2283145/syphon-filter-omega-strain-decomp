typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { union { unsigned int w; unsigned char flags; } u; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[0x30]; int list; char pad2[0x48]; unsigned int f80; unsigned int f84; char pad3[0x8]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; } ScfSock;
extern int func_002FABD0(int *list, void **node);
extern unsigned int func_002FAEE8(void *node);
extern char *func_002FAED0(void *node);
extern void *func_002FAF00(void *node);

int RtUdp_CheckDuplicate(ScfSock *s, ScfPeer *e, ScfHdr *p, unsigned char *dup)
{
    ScfHdr hd;
    void *node = 0;
    int ret = 1;
    if (dup == 0) return ret;
    *dup = 0;
    if (s == 0) return ret;
    if (e == 0) return ret;
    if (p == 0) return ret;
    if (e->type != 0) {
        if ((p->u.w & 6) == 6 || (p->u.flags & 4)) {
            if ((int)(e->f84 - p->seq) >= 0 && e->f84 != 0) {
                *dup = 1;
            } else {
                if (func_002FABD0(&e->list, &node) != 0) return 10;
                while (node != 0) {
                    if (func_002FAEE8(node) != 0) {
                        *(ScfAddr12 *)&hd = *(ScfAddr12 *)func_002FAED0(node);
                        if (((hd.u.w & 6) == 6 || (hd.u.flags & 4)) && hd.seq == p->seq) {
                            *dup = 1;
                            break;
                        }
                    }
                    node = func_002FAF00(node);
                }
            }
        } else if (p->u.flags & 2) {
            if ((int)(e->f80 - p->seq) >= 0) {
                *dup = 1;
                if (e->f80 <= 0x7FFFFFFE && p->seq < 0) {
                    e->f80 = p->seq;
                    *dup = 0;
                }
            }
        }
    }
    return 0;
}
