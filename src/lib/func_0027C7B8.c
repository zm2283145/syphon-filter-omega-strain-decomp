typedef struct { int result; char pad[0x30C]; } McRes;
typedef struct { char pad[0x108]; char name[0x138]; } McEnt;
extern int sceNetcnfifSync(int);
extern int sceNetcnfifGetResult(McRes *);
extern int sceNetcnfifGetCount(const char *, int);
extern int sceNetcnfifGetList(const char *, int, McEnt *, int);
extern int sceNetcnfifLoadEntry(const char *, int, const char *, const char *);
extern void *Libc_Memalign(int, int);
extern void Libc_Free(void *);
extern void FlushCache(int);
extern int strcmp(const char *, const char *);

int sceNetcnfifLoadEntryAuto(const char *path, unsigned int flags, const char *name, const char *dst)
{
    McRes res;
    McEnt *match;
    char *found;
    int mode;
    int block;
    unsigned int opts;
    McEnt *list1;
    McEnt *list2;
    McEnt *e;
    int n1;
    int n2;
    int i;
    int r;
    int cnt;

    mode = flags & 0xFFFF;
    opts = flags & 0xFFFF0000;
    found = 0;
    match = 0;
    block = 1;
    list1 = 0;
    list2 = 0;
    if (mode != 1 && mode != 2) {
        Libc_Free(list1);
        Libc_Free(list2);
        return -10;
    }
    if (opts & 0x10000)
        block = 0;
    sceNetcnfifGetCount(path, mode);
    while (sceNetcnfifSync(block))
        ;
    sceNetcnfifGetResult(&res);
    n1 = res.result;
    if (n1 <= 0)
        { Libc_Free(list1); Libc_Free(list2); return -1; }
    cnt = n1;
    list1 = Libc_Memalign(0x40, cnt * sizeof(McEnt));
    if (list1 == 0)
        { Libc_Free(list1); Libc_Free(list2); return -2; }
    FlushCache(0);
    sceNetcnfifGetList(path, mode, list1, cnt);
    while (sceNetcnfifSync(block))
        ;
    sceNetcnfifGetResult(&res);
    if (res.result < 0)
        { Libc_Free(list1); Libc_Free(list2); return -1; }
    e = list1;
    for (i = 0; i < n1; e++, i++) {
        if (strcmp(name, e->name) == 0) {
            found = (char *)e;
            break;
        }
    }
    /* dead store: keeps cnt's CSE copy of n1 alive in its own register */
    cnt = 0;
    if (found == 0)
        { Libc_Free(list1); Libc_Free(list2); return -8; }
    sceNetcnfifGetCount(path, 0);
    while (sceNetcnfifSync(block))
        ;
    sceNetcnfifGetResult(&res);
    n2 = res.result;
    if (n2 <= 0)
        { Libc_Free(list1); Libc_Free(list2); return -1; }
    list2 = Libc_Memalign(0x40, n2 * sizeof(McEnt));
    if (list2 == 0)
        { Libc_Free(list1); Libc_Free(list2); return -2; }
    FlushCache(0);
    sceNetcnfifGetList(path, 0, list2, n2);
    while (sceNetcnfifSync(block))
        ;
    sceNetcnfifGetResult(&res);
    if (res.result < 0)
        { Libc_Free(list1); Libc_Free(list2); return -1; }
    e = list2;
    for (i = 0; i < n2; i++, e++) {
        FlushCache(0);
        sceNetcnfifLoadEntry(path, 0, e->name, dst);
        while (sceNetcnfifSync(block))
            ;
        sceNetcnfifGetResult(&res);
        if (res.result < 0)
            { Libc_Free(list1); Libc_Free(list2); return -1; }
        if ((mode == 1 ? strcmp(found + 8, dst) : strcmp(found + 8, dst + 0x100)) == 0) {
            if (match != 0) {
                Libc_Free(list1);
                Libc_Free(list2);
                return -12;
            }
            match = e;
        }
    }
    if (match == 0)
        { Libc_Free(list1); Libc_Free(list2); return -8; }
    FlushCache(0);
    /* do-while(0) nesting raises match's loop-weighted ref count so global
       alloc spills found instead of match, as in retail */
    do { do {
    sceNetcnfifLoadEntry(path, 0, match->name, dst);
    } while (0); } while (0);
    while (sceNetcnfifSync(block))
        ;
    sceNetcnfifGetResult(&res);
    if (res.result < 0)
        { Libc_Free(list1); Libc_Free(list2); return -1; }
    Libc_Free(list1);
    Libc_Free(list2);
    return 0;
}




