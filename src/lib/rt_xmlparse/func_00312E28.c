extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0F38[];
extern char D_004B1200[];
extern char D_004B1220[];
extern int printf(const char *, ...);
typedef struct { char pad[0x10C]; void **arr; unsigned int n; } Node312E28;
typedef struct { char pad0[0x8008]; Node312E28 *doc; } Ctx312E28;
extern int func_00312858(Ctx312E28 *c, Node312E28 **out);
extern int func_003127A8(Ctx312E28 *c, void *item);
extern int func_00313150(Ctx312E28 *c);

#define CHK(x, line) \
    if ((rc = (x)) != 0) { \
        printf(D_004B0DE0, D_004B0E18, line, D_004B0F38); \
        return rc; \
    }

int func_00312E28(Ctx312E28 *c)
{
    Node312E28 *node = 0;
    Node312E28 *prev = 0;
    unsigned int i, j;
    int rc;

    CHK(func_00312858(c, &node), 1108);
    while (node) {
        CHK(func_00312858(c, &node), 1112);
    }
    if (!c->doc)
        return 0;
    CHK(func_003127A8(c, c->doc), 1118);
    do {
        CHK(func_00312858(c, &node), 1122);
        if (!node)
            break;
        for (i = 0, j = 0; i < node->n; i++) {
            if (prev == node->arr[i]) {
                j = i + 1;
                break;
            }
        }
        if (j < node->n) {
            CHK(func_003127A8(c, node), 1137);
            CHK(func_003127A8(c, node->arr[j]), 1139);
        } else if (j == node->n) {
            if ((rc = func_00313150(c)) != 0)
                printf(D_004B0DE0, D_004B0E18, 1144, D_004B0F38);
            prev = node;
        } else {
            if (D_004B1200)
                printf(D_004B0DE0, D_004B0E18, 1149, D_004B1220);
            return 0;
        }
    } while (node);
    return 0;
}
