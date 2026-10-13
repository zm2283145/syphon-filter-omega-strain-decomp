typedef struct UpnpD2B8 UpnpD2B8;
typedef struct {
    int sock;
    int parser;
    int arg;
    char pad[0x1024 - 0xC];
    int status;
    char pad2[0x2060 - 0x1028];
    void (*cb)(UpnpD2B8 *u, int r, int arg);
} UpCtxD2B8;
typedef struct {
    char name[12][0x100];
    char value[12][0x100];
    unsigned int count;
} UpListD2B8;
struct UpnpD2B8 { char pad[4]; char host[0x20]; unsigned short port; char pad26[0x50 - 0x26]; int state; unsigned char busy; char pad2[3]; UpCtxD2B8 *ctx; };
extern int func_0030BC98(UpnpD2B8 *u, unsigned char *done);
extern int func_00310C90(int p, char *s, int a, int b);
extern int func_00310D20(int p, UpListD2B8 **out);
extern int String_CompareN(char *a, char *b, int n);
extern int func_0012AF90(char *s, char **end, int base);
extern int func_00310C30(int p);
extern void func_002F5DB0(int s);
extern void *memset(void *d, int c, unsigned int n);
extern char D_004AFF28[];
extern char D_004B0008[];
extern char D_004B0020[];
extern char D_004B00A8[];
int func_0030D2B8(UpnpD2B8 *u)
{
    unsigned char done = 0;
    int r = func_0030BC98(u, &done);
    UpCtxD2B8 *c;
    if (r == 0 && done == 0) goto out;
    if (u->ctx->status == 200) {
      if (done != 0) {
        if (func_00310C90(u->ctx->parser, D_004AFF28, 0, 1) == 0) {
        UpListD2B8 *list = 0;
        if (func_00310D20(u->ctx->parser, &list) == 0) {
            int a = 0;
            int b = 0;
            unsigned int i = 0;
            unsigned char k = 0;
            for (; i < list->count; i++) {
                    if (String_CompareN(list->name[i], D_004B0008, 0x100) == 0 && String_CompareN(list->value[i], u->host, 0x100) == 0) {
                        a = 1;
                    } else if (String_CompareN(list->name[i], D_004B0020, 0x100) == 0) {
                        if (u->port == (unsigned short)func_0012AF90(list->value[i], 0, 10))
                            b = 1;
                    } else if (String_CompareN(list->name[i], D_004B00A8, 0x100) == 0) {
                        k = func_0012AF90(list->value[i], 0, 10);
                    }
            }
            if (a && b && k) r = 0; else r = 13;
        }
        }
      } else {
        r = 11;
      }
    } else {
        r = 11;
    }
clean:
    func_00310C30(u->ctx->parser);
    {
        UpCtxD2B8 *c1 = u->ctx;
        c1->parser = 0;
        func_002F5DB0(c1->sock);
    }
    u->ctx->sock = 0;
    memset(&u->ctx->status, 0, 0x100C);
    {
        UpCtxD2B8 *c2 = u->ctx;
        c2->cb(u, r, c2->arg);
    }
    {
        UpCtxD2B8 *c3 = u->ctx;
        u->state = 0;
        c3->cb = 0;
    }
out:
    return r;
}
