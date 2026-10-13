typedef struct { int a; int b; int c; } Opts;
typedef struct { unsigned char f0; unsigned char used; char pad2[2]; int f4; Opts opts; unsigned short port; char name[1]; } Ent;
extern int func_002F66B8(int *);
extern int func_002F6758(int, Ent **);
extern int func_002F5C58(Opts *);
extern int func_002F7B78(int *, char *, unsigned short *, Opts *, char *);
extern int func_002F6728(int);
int func_002F5C98(int *out, char *name, unsigned short port, Opts *opts)
{
    int id;
    Ent *e = 0;
    int r;
    if (out == 0) return 2;
    *out = 0;
    r = func_002F66B8(&id);
    if (r) return r;
    r = func_002F6758(id, &e);
    if (r) return r;
    if (e == 0) return 0xA;
    if (opts) {
        e->opts = *opts;
    } else {
        r = func_002F5C58(&e->opts);
        if (r) goto err;
    }
    r = func_002F7B78(&e->f4, name, &port, &e->opts, e->name);
    if (r) {
err:
        func_002F6728(id);
        return r;
    }
    e->port = port;
    e->used = 1;
    *out = id;
    return 0;
}

