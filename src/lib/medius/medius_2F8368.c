typedef struct L2F8368 { struct L2F8368 *next; struct L2F8368 *prev; int a, b; int id; int port; int c; } L2F8368;
extern L2F8368 *D_004908D8;
extern char D_00529640[], D_005296C0[], D_00529740[];
extern L2F8368 *func_002F7D68(int);
extern void func_002FB2D8(void *, int);
extern void *memset(void *, int, unsigned int);
extern void func_002F8730(int, void *);
extern void func_002F84D0(int, int, int);
int func_002F8368(int id, int port, int arg)
{
    L2F8368 *p = func_002F7D68(id);
    if (p) return 0;
    func_002FB2D8(&p, 0x30);
    memset(p, 0, 0x30);
    if (p == 0) return -1;
    p->id = id;
    p->port = port;
    p->c = 0;
    if (D_004908D8) {
        p->next = D_004908D8->next;
        p->next->prev = p;
    } else {
        D_004908D8 = p;
    }
    D_004908D8->next = p;
    p->prev = D_004908D8;
    if (id == -1) func_002F8730(id, D_00529740);
    else if ((unsigned)id >> 31) func_002F8730(id, D_00529640);
    else func_002F8730(id, D_005296C0);
    if (port != 0xFFFF && id != -1) func_002F84D0(id, 0xFFFF, arg);
    return 0;
}