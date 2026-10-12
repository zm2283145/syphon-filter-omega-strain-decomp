typedef struct {
    char name[16];
    unsigned short port;
} Rec_a880;

typedef struct {
    char pad[0xC];
    int tbl;
} Obj_a880;

extern char *strncpy(char *, const char *, unsigned int);
extern int func_002FAC20(int *tbl, void **h);
extern int func_002FA5F8(int *tbl, void *h, void *rec, int size);
extern int func_002FA930(int *tbl, void *h, void *data, int size);
extern void func_002FA830(int *tbl, void *h);

int func_0030A880(Obj_a880 *o, void *key, const char *name, unsigned short port,
                  void *data, unsigned short len)
{
    Rec_a880 rec;
    void *h = 0;
    int err = 0;
    int created = 0;

    if (func_002FAC20(&o->tbl, &h) != 0) return 10;
    do {
        strncpy(rec.name, name, 16);
        rec.port = port;
        if (func_002FA5F8(&o->tbl, h, &rec, sizeof(rec)) != 0) { err = 10; break; }
        created = 1;
        if (func_002FAC20(&o->tbl, &h) != 0) { err = 10; break; }
        if (func_002FA930(&o->tbl, h, key, 12) != 0) { err = 10; break; }
        if (func_002FA930(&o->tbl, h, data, len) != 0) { err = 10; break; }
    } while (0);
    if (err != 0 && created) {
        if (func_002FAC20(&o->tbl, &h) == 0) func_002FA830(&o->tbl, h);
    }
    return err;
}
