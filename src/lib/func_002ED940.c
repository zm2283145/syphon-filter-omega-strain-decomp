typedef struct {
    int a;
    char *b;
    int state;
    int time;
    unsigned int retries;
} Ent;

typedef struct Node {
    int x0;
    struct Node *next;
} Node;

typedef struct {
    char p0[8];
    int h;
    int xC;
    char p10[0x48];
    int x58;
    int n;
    Ent *ents;
} Conn;

extern int func_002D8AF0(int);
extern int func_002D8B08(int);
extern unsigned short func_002D8B20(int);
extern int func_002D9C10(int, char *, int, char *);
extern Node *func_002D9E80(int);
extern Node *func_002D9E78(int);
extern void *memcpy(void *, const void *, unsigned int);

int func_002ED940(Conn *s, int h, char *buf, char *src, int len)
{
    char pkt[0x500];
    int tmp;
    char *p = pkt;
    int first = 1;
    int mode;
    int result;
    char *data;
    int hl;
    int n;
    int i;
    char *nd;

    memcpy(pkt, buf, 8);
    data = src;
    mode = 0;
    result = 0;
again:
    {
        hl = 8;
        switch (buf[0] & 0x7F) {
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x2F:
            mode = 1;
            hl = 12;
            tmp = func_002D8AF0(s->h);
            memcpy(p + 8, &tmp, 4);
            break;
        case 0x30:
            tmp = func_002D8B08(s->h);
            if (first)
                tmp |= 0x20000000;
            if ((unsigned int)len < 0x1F9)
                tmp |= 0x40000000;
            memcpy(p + 8, &tmp, 4);
            hl = 12;
            mode = 2;
            break;
        }
        n = len;
        if ((buf[0] & 0x7F) == 0x30) {
            if (len > 0x1F8)
                n = 0x1F8;
            *(unsigned short *)(pkt + 2) = n;
        }
        memcpy(pkt + hl, data, n);
        len -= n;
        hl += n;
        data += n;
        if (s->xC > 0) {
            for (i = 0; i < s->n; i++) {
                nd = s->ents[i].b;
                if (nd == 0)
                    continue;
                if (s->x58 == 0) {
                    if (mode == 1 && (*(int *)(nd + 0x38) & 0x20000))
                        continue;
                    if (mode == 2 && (*(int *)(nd + 0x38) & 0x10000))
                        continue;
                }
                if (s->ents[i].state != 2)
                    continue;
                if (s->ents[i].a == h)
                    continue;
                if (hl != func_002D9C10(s->h, pkt, hl, nd))
                    result = -1;
            }
        } else {
            nd = (char *)func_002D9E80(s->h);
            while ((char *)func_002D9E78(s->h) != (nd = (char *)((Node *)nd)->next)) {
                if (hl != func_002D9C10(s->h, pkt, hl, nd))
                    result = -1;
            }
        }
        if (len != 0) {
            *(unsigned short *)(pkt + 6) = func_002D8B20(s->h);
            first = 0;
            goto again;
        }
    }
    return result;
}
