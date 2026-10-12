typedef struct { int pad[4]; unsigned int rec_id; void *paddr; int pid; } RpcPkt;
typedef struct { int pid; RpcPkt *table; int len; } RpcData;
extern int func_001161A0(void);
extern int func_001161F8(void);
void *func_002713C0(RpcData *rd)
{
    RpcPkt *p;
    int i, len, pid;
    func_001161A0();
    len = rd->len;
    p = rd->table;
    for (i = 0; i < len; i++, p = (RpcPkt *)((char *)p + 64)) {
        if (!(p->rec_id & 1)) {
            p->rec_id = (i << 16) | 5;
            rd->pid++;
            if (rd->pid == 1) {
                rd->pid++;
                pid = 1;
            } else pid = rd->pid;
            p->paddr = p;
            p->pid = pid;
            func_001161F8();
            return p;
        }
    }
    func_001161F8();
    return 0;
}

