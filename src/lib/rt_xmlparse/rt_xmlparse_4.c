/*
 * lib/rt_xmlparse: 2 files, 00312A90-00312E28
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00312A90 */
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
extern int RtXml_NodeStackPop(Ctx312A90 *c, Node312A90 **out);
extern int RtXml_NodeStackPush(Ctx312A90 *c, void *item);

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

    CHK(RtXml_NodeStackPop(c, &node), 1019);
    while (node) {
        CHK(RtXml_NodeStackPop(c, &node), 1023);
    }
    if (!c->doc)
        return 0;
    if (c->start)
        c->start(c->doc->a, c->doc->name, c->user);
    CHK(RtXml_NodeStackPush(c, c->doc), 1035);
    do {
        CHK(RtXml_NodeStackPop(c, &node), 1039);
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
            CHK(RtXml_NodeStackPush(c, node), 1054);
            if (((Node312A90 *)node->arr[j])->type == 1 && c->start)
                c->start(((Node312A90 *)node->arr[j])->a, ((Node312A90 *)node->arr[j])->name, c->user);
            else if (((Node312A90 *)node->arr[j])->type == 2 && c->text)
                c->text(((Node312A90 *)node->arr[j])->a, ((Node312A90 *)node->arr[j])->b, c->user);
            CHK(RtXml_NodeStackPush(c, node->arr[j]), 1070);
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
/* merge_units: end func_00312A90 */

/* merge_units: begin func_00312E28 */
typedef struct { char pad[0x10C]; void **arr; unsigned int n; } Node312E28;
typedef struct { char pad0[0x8008]; Node312E28 *doc; } Ctx312E28;
#if 0 /* merge_units */
extern int RtXml_NodeStackPop(Ctx312E28 *c, Node312E28 **out);
#endif /* merge_units */
#define RtXml_NodeStackPop(a0, a1) (RtXml_NodeStackPop((Ctx312A90 *)(a0), (Node312A90 * *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int RtXml_NodeStackPush(Ctx312E28 *c, void *item);
#endif /* merge_units */
#define RtXml_NodeStackPush(a0, a1) (RtXml_NodeStackPush((Ctx312A90 *)(a0), (a1))) /* merge_units */

extern int func_00313150(Ctx312E28 *c);
int func_00312E28(Ctx312E28 *c)
{
    Node312E28 *node = 0;
    Node312E28 *prev = 0;
    unsigned int i, j;
    int rc;

    CHK(RtXml_NodeStackPop(c, &node), 1108);
    while (node) {
        CHK(RtXml_NodeStackPop(c, &node), 1112);
    }
    if (!c->doc)
        return 0;
    CHK(RtXml_NodeStackPush(c, c->doc), 1118);
    do {
        CHK(RtXml_NodeStackPop(c, &node), 1122);
        if (!node)
            break;
        for (i = 0, j = 0; i < node->n; i++) {
            if (prev == node->arr[i]) {
                j = i + 1;
                break;
            }
        }
        if (j < node->n) {
            CHK(RtXml_NodeStackPush(c, node), 1137);
            CHK(RtXml_NodeStackPush(c, node->arr[j]), 1139);
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
#undef RtXml_NodeStackPop /* merge_units */
#undef RtXml_NodeStackPush /* merge_units */
/* merge_units: end func_00312E28 */
