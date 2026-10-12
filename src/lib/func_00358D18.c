typedef struct S8D18 { struct S8D18 *next; struct S8D18 *prev; int id; int xC; int type; char pad[0x4C]; int x60; int x64; int x68; } S8D18;
extern void *func_003581E0(int);
extern int func_003583A0(void *, int);
extern int func_00358678(void);
extern void *func_00357D50(int);
extern void *memset(void *, int, unsigned int);
extern S8D18 *D_00492CD8;
S8D18 *D_00492CDC = 0;

int func_00358D18(int domain, int type)
{
    void *lk = func_003581E0(0);
    int id;
    S8D18 *s;
    if (!lk) return -1;
    if (domain != 2) return func_003583A0(lk, 0x60);
    id = func_00358678();
    switch (type) {
    case 2:
        type = 0;
        break;
    case 1:
    case 3:
        break;
    default:
        return func_003583A0(lk, 0x6B);
    }
    s = func_00357D50(0x6C);
    if (!s) return func_003583A0(lk, 0xC);
    memset(s, 0, 0x6C);
    s->type = type;
    s->id = id;
    s->x60 = -1;
    s->x64 = -1;
    s->x68 = -1;
    s->next = D_00492CD8;
    if (D_00492CD8) D_00492CD8->prev = s;
    else D_00492CDC = s;
    D_00492CD8 = s;
    s->prev = 0;
    func_003583A0(lk, 0);
    return id;
}