typedef struct { float x, y, z; int pad; int st; int p14[3]; int *list; int p24; int n; } S7BE0b;
typedef struct { char p0[0x2C]; int last; int first; char bool34; char p35[3]; float x, y, z; } S7BE0a;
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, S7BE0a *, int, int);
void cNetPathMsg_SendPath(S7BE0a *m, int t, S7BE0b *s)
{
    if (s->n) {
        m->last = s->list[s->n - 1];
        m->first = s->list[0];
    } else {
        m->last = -1;
        m->first = -1;
    }
    m->x = s->x;
    m->y = s->y;
    m->z = s->z;
    m->bool34 = !(s->st >= 0);
    cNetObj_SendMessage_int_cMessageR_int_int(t, m, -1, -1);
}