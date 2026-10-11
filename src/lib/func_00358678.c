typedef struct T8678 { struct T8678 *next; int x4; int id; } T8678;
typedef struct S8678 { struct S8678 *next; int x4; int id; char pad[0x44]; T8678 *x50; int x54; T8678 *x58; } S8678;
extern S8678 *D_00492CD8;

int func_00358678(void)
{
    int id = 0;
    S8678 *s;
    T8678 *t;
    for (;;) {
        for (s = D_00492CD8; s; s = s->next) {
            if (id == s->id) break;
            for (t = s->x50; t; t = t->next)
                if (id == t->id) break;
            if (t) break;
            for (t = s->x58; t; t = t->next)
                if (id == t->id) break;
            if (t) break;
        }
        if (!s) break;
        id++;
    }
    return id;
}