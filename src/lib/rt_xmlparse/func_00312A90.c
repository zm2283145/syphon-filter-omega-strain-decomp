extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F38[];
extern char D_004B1200[];
extern char D_004B1220[];
extern int printf(const char *, ...);
typedef struct { int type; void *a; void *b; char name[0x100]; void **arr; unsigned int n; } Node312A90;
typedef void (*StartCb312A90)(void *a, char *name, void *user);
typedef void (*EndCb312A90)(void *a, void *user);
typedef void (*TextCb312A90)(void *a, void *b, void *user);
typedef struct {
    char pad0[0x8008];
    Node312A90 *doc;
    char pad1[0x8C18 - 0x800C];
    void *user;
    char pad2[4];
    StartCb312A90 start;
    EndCb312A90 end;
    TextCb312A90 text;
} Ctx312A90;
extern int func_00312858(Ctx312A90 *c, Node312A90 **out);
extern int func_003127A8(Ctx312A90 *c, void *item);

#define CHK(x, line) \
    if ((rc = (x)) != 0) { \
        printf(D_004B0DE0, D_004B0E18, line, D_004B0F38); \
        return rc; \
    }

int func_00312A90(Ctx312A90 *c)
{
    Node312A90 *node = 0;
    Node312A90 *prev = 0;
    Node312A90 *child;
    unsigned int i, j;
    int rc;

    CHK(func_00312858(c, &node), 1019);
    while (node) {
        CHK(func_00312858(c, &node), 1023);
    }
    if (!c->doc)
        return 0;
    if (c->start)
        c->start(c->doc->a, c->doc->name, c->user);
    CHK(func_003127A8(c, c->doc), 1035);
    do {
        CHK(func_00312858(c, &node), 1039);
        if (!node)
            break;
        j = 0;
        for (i = 0; i < node->n; i++) {
            if (prev == node->arr[i]) {
                j = i + 1;
                break;
            }
        }
        if (j < node->n) {
            CHK(func_003127A8(c, node), 1054);
            if (((Node312A90 *)node->arr[j])->type == 1 && c->start)
                c->start(((Node312A90 *)node->arr[j])->a, ((Node312A90 *)node->arr[j])->name, c->user);
            else if (((Node312A90 *)node->arr[j])->type == 2 && c->text)
                c->text(((Node312A90 *)node->arr[j])->a, ((Node312A90 *)node->arr[j])->b, c->user);
            CHK(func_003127A8(c, node->arr[j]), 1070);
        } else if (j == node->n) {
            if (node->type == 1 && c->end)
                c->end(node->a, c->user);
            prev = node;
        } else {
            if (D_004B1200)
                printf(D_004B0DE0, D_004B0E18, 1086, D_004B1220);
            return 0;
        }
    } while (node);
    return 0;
}
