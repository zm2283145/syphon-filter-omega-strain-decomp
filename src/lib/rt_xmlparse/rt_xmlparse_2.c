/*
 * lib/rt_xmlparse: 3 files, 003111E0-00311418
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003111E0 */
extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EC0[];
extern char D_004B0F50[];
extern int printf(const char *, ...);
extern int Net_AllocZeroed(void **pp, unsigned long size);
typedef struct { void *ptr; unsigned int size; } Slot3111E0;
typedef struct { Slot3111E0 slot[0x1000]; unsigned int limit; unsigned int used; } Ctx3111E0;
int RtXml_Alloc(Ctx3111E0 *c, void **pp, unsigned int size)
{
    unsigned int i;
    int r;
    if (c->used + size <= c->limit) {
        for (i = 0; i < 0x1000; i++) {
            if (c->slot[i].ptr == 0) {
                r = Net_AllocZeroed(pp, size);
                if (r != 0) {
                    printf(D_004B0DE0, D_004B0E18, 0x19A, D_004B0EC0);
                    return 2;
                }
                if (*pp == 0) {
                    printf(D_004B0DE0, D_004B0E18, 0x19B, D_004B0F50);
                    return 2;
                }
                c->slot[i].ptr = *pp;
                c->slot[i].size = size;
                c->used += size;
                return r;
            }
        }
    }
    return 2;
}
/* merge_units: end func_003111E0 */

/* merge_units: begin func_00311320 */
extern int func_002FB3C0(void *p);
typedef struct { void *ptr; int size; } Slot311320;
typedef struct { Slot311320 slot[0x1000]; int count; int used; } Ctx311320;
int RtXml_Free(Ctx311320 *c, void **pp)
{
    unsigned int i;
    for (i = 0; i < 0x1000; i++) {
        if (*pp == c->slot[i].ptr) {
            func_002FB3C0(pp);
            c->used -= c->slot[i].size;
            *pp = 0;
            c->slot[i].ptr = 0;
            c->slot[i].size = 0;
            break;
        }
    }
    if (*pp) {
        if ("Freeing a pointer that wasn't alloc'd by me!")
            printf(D_004B0DE0, D_004B0E18, 0x1BB, "!\"Freeing a pointer that wasn't alloc'd by me!\"");
        func_002FB3C0(pp);
    }
    return 0;
}
/* merge_units: end func_00311320 */

/* merge_units: begin func_00311418 */
extern char D_004B0F38[];
extern int String_CompareN(const char *, const char *, unsigned int);
typedef struct { int type; char *str; unsigned int len; } Node311418;
typedef struct {
    char pad0[0x8008];
    void *doc;
    char pad1[0x840C - 0x800C];
    int x840C;
    int state;
    char buf[0x800];
    unsigned int len;
    char pad2[5];
    unsigned char flag;
} Ctx311418;
extern int RtXml_NodeStackPop(Ctx311418 *c, Node311418 **pnode);
extern int func_003130F8(Ctx311418 *c, Node311418 **pnode);
extern int func_00313200(Ctx311418 *c, Node311418 *n);
extern int func_003132E0(Ctx311418 *c, Node311418 *n);
extern int RtXml_AddChild(Ctx311418 *c, Node311418 *parent, Node311418 *n);
extern int RtXml_NodeStackPush(Ctx311418 *c, Node311418 *n);
extern int func_003133C0(Ctx311418 *c, Node311418 *n);

#define CHK(x, line) \
    if ((rc = (x)) != 0) { \
        printf(D_004B0DE0, D_004B0E18, line, D_004B0F38); \
        return rc; \
    }
#define TOSS(line) \
    if ("Tossing character data!") \
        printf(D_004B0DE0, D_004B0E18, line, "!\"Tossing character data!\"");
#define APPEND(line) \
    if (c->len < 0x800) { \
        c->buf[c->len] = buf[i]; \
        c->len++; \
    } else if ("buffer overflow") \
        printf(D_004B0DE0, D_004B0E18, line, "!\"buffer overflow\"");

int func_00311418(Ctx311418 *c, char *buf, unsigned int len)
{
    int rc = 0;
    unsigned int i;
    int done;
    Node311418 *node;
    Node311418 *n4;

    for (i = 0, done = 0; i < len; i++, done = 0) {
        switch (buf[i]) {
        case '<':
            if (c->state == 0x18) {
                c->state = 0;
                done = 1;
            }
            break;
        case '>':
            if (c->state == 2) c->state = 1;
            else if (c->state == 4) c->state = 1;
            else if (c->state == 5) c->state = 1;
            else if (c->state == 9) c->state = 0xA;
            else if (c->state == 0xE) c->state = 0xF;
            else if (c->state == 0x13) c->state = 1;
            break;
        case '/':
            if (c->state == 0) { c->state = 0xB; done = 1; }
            else if (c->state == 2) { c->state = 9; done = 1; }
            else if (c->state == 4) { c->state = 9; done = 1; }
            else if (c->state == 5) { c->state = 9; done = 1; }
            break;
        case '?':
            if (c->state == 0) { c->state = 0xC; done = 1; }
            else if (c->state == 0xD) { c->state = 0xE; done = 1; }
            break;
        case '!':
            if (c->state == 0) { c->state = 0x10; done = 1; }
            break;
        case '=':
            if (c->state == 5) { c->state = 6; done = 1; }
            break;
        case '"':
            if (c->state == 6) { c->state = 7; done = 1; }
            else if (c->state == 8) { c->state = 4; done = 1; }
            break;
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            if (c->state == 2) c->state = 3;
            break;
        }
        if (done) continue;
        node = 0;
        n4 = 0;
        switch (c->state) {
        case 0:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x25C);
                if (node) {
                    CHK(func_003130F8(c, &n4), 0x260);
                    CHK(func_00313200(c, n4), 0x263);
                    CHK(RtXml_AddChild(c, node, n4), 0x266);
                    CHK(RtXml_NodeStackPush(c, node), 0x269);
                } else {
                    c->buf[c->len] = 0;
                    TOSS(0x26E);
                    c->len = 0;
                }
            }
            APPEND(0x278);
            c->state = 2;
            break;
        case 1:
        case 3:
        case 15:
        case 23:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x283);
                if (node) {
                    if (String_CompareN(c->buf, node->str, node->len) == 0 && node->len == c->len) {
                        c->buf[c->len] = 0;
                        c->len = 0;
                        if (c->x840C == 0) c->state = 0x1A;
                    } else if (c->flag) {
                        c->flag = 0;
                        CHK(func_003133C0(c, node), 0x298);
                        CHK(RtXml_NodeStackPush(c, node), 0x29B);
                    } else {
                        CHK(func_003130F8(c, &n4), 0x2A1);
                        CHK(func_003132E0(c, n4), 0x2A4);
                        CHK(RtXml_AddChild(c, node, n4), 0x2A7);
                        CHK(RtXml_NodeStackPush(c, node), 0x2AA);
                        CHK(RtXml_NodeStackPush(c, n4), 0x2AD);
                    }
                } else {
                    CHK(func_003130F8(c, &n4), 0x2B4);
                    CHK(func_003132E0(c, n4), 0x2B7);
                    if (!(0 == c->doc))
                        printf(D_004B0DE0, D_004B0E18, 0x2B9, "NULL == p_iparser->doc");
                    c->doc = n4;
                    CHK(RtXml_NodeStackPush(c, n4), 0x2BD);
                }
            }
            if (c->state == 3) {
                c->state = 4;
                c->flag = 1;
            } else if (c->state != 0x1A) {
                c->state = 0x18;
            }
            break;
        case 2:
            APPEND(0x2D1);
            break;
        case 4:
        case 7:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x2D9);
                CHK(func_003133C0(c, node), 0x2DC);
                CHK(RtXml_NodeStackPush(c, node), 0x2DF);
            }
            if (c->state == 4) c->state = 5;
            else if (c->state == 7) c->state = 8;
        case 5:
        case 8:
            APPEND(0x2F2);
            break;
        case 10:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x2F9);
                if (node) {
                    if (!c->flag) {
                        CHK(func_003130F8(c, &n4), 0x2FF);
                        CHK(func_003132E0(c, n4), 0x302);
                        CHK(RtXml_AddChild(c, node, n4), 0x305);
                        CHK(RtXml_NodeStackPush(c, node), 0x308);
                    } else {
                        c->flag = 0;
                        if (c->len) {
                            CHK(func_003133C0(c, node), 0x311);
                        }
                    }
                } else {
                    c->buf[c->len] = 0;
                    TOSS(0x319);
                    c->len = 0;
                }
            } else {
                CHK(RtXml_NodeStackPop(c, &node), 0x320);
            }
            c->state = 0x18;
            break;
        case 11:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x329);
                if (node) {
                    CHK(func_003130F8(c, &n4), 0x32D);
                    CHK(func_00313200(c, n4), 0x330);
                    CHK(RtXml_AddChild(c, node, n4), 0x333);
                    CHK(RtXml_NodeStackPush(c, node), 0x336);
                } else {
                    c->buf[c->len] = 0;
                    TOSS(0x33B);
                    c->len = 0;
                }
            }
            APPEND(0x345);
            c->state = 2;
            break;
        case 12:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x34D);
                if (node) {
                    CHK(func_003130F8(c, &n4), 0x351);
                    CHK(func_00313200(c, n4), 0x354);
                    CHK(RtXml_AddChild(c, node, n4), 0x357);
                    CHK(RtXml_NodeStackPush(c, node), 0x35A);
                } else {
                    c->buf[c->len] = 0;
                    TOSS(0x35F);
                    c->len = 0;
                }
            }
            c->state = 0xD;
            break;
        case 16:
            if (c->len) {
                CHK(RtXml_NodeStackPop(c, &node), 0x36F);
                if (node) {
                    CHK(func_003130F8(c, &n4), 0x373);
                    CHK(func_00313200(c, n4), 0x376);
                    CHK(RtXml_AddChild(c, node, n4), 0x379);
                    CHK(RtXml_NodeStackPush(c, node), 0x37C);
                } else {
                    c->buf[c->len] = 0;
                    TOSS(0x381);
                    c->len = 0;
                }
            }
            c->state = 0x13;
            break;
        case 13:
        case 19:
            c->buf[c->len] = 0;
            c->len = 0;
            break;
        case 24:
            APPEND(0x394);
            break;
        case 6:
        case 25:
        case 26:
            break;
        default:
            if ("Invalid state")
                printf(D_004B0DE0, D_004B0E18, 0x39C, "!\"Invalid state\"");
            break;
        }
    }
    return rc;
}
/* merge_units: end func_00311418 */
