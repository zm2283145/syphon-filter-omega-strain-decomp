typedef struct { unsigned char type; unsigned char ver; unsigned short len; unsigned short id; unsigned short seq; } H2EDD08;
typedef struct { int x0; int x4; void *conn; unsigned int xC; } S2EDD08;
extern void func_002DA900(void *, int *);
extern int func_002D8B20(void *);
void func_002EDD08(S2EDD08 *s, H2EDD08 *h, int type, int len)
{
    int id = 0xFFFF;
    func_002DA900(s->conn, &id);
    h->type = type | 0x80;
    h->len = len;
    { int seq = func_002D8B20(s->conn);
      h->seq = seq;
      h->ver = s->xC;
      h->id = id; }
}


