/* MW C++ runtime NMWException.cp: __unexpected */
#pragma cplusplus on
#pragma exceptions on

typedef struct CatchInfo {
    void *location;
    void *typeinfo;
    void *dtor;
    void *sublocation;
    int pointercopy;
    void *stacktop;
} CatchInfo;

typedef struct ex_specification {
    unsigned int nspecs;
    unsigned int pcoffset;
    int cinfo_ref;
    char *specs;
} ex_specification;

extern "C" char *func_00100BC0(char *p, unsigned int *pnum);
extern "C" char *func_00100C70(char *p, int *pnum);
extern "C" char func_00100800(const char *throwtype, const char *catchtype, long *offset_result);
extern "C" void std_unexpected(void);
extern "C" void std_terminate(void);
extern "C" void std_bad_exception_dtor(void);
extern void *D_004D9050[];
extern char D_00497FB0[];

static inline char *__DecodeAddress(char *p, void **paddr)
{
    unsigned int addr;
    addr = ((unsigned char *)p)[0] | (((unsigned char *)p)[1] << 8) |
           (((unsigned char *)p)[2] << 16) | (((unsigned char *)p)[3] << 24);
    *paddr = (void *)addr;
    return p + 4;
}

static inline void DecodeSpecification(char *ap, ex_specification *sp)
{
    ap += 1;
    ap = func_00100BC0(ap, &sp->nspecs);
    ap = func_00100BC0(ap, &sp->pcoffset);
    ap = func_00100C70(ap, &sp->cinfo_ref);
    sp->specs = ap;
}

static inline int IsInSpecification(char *extype, ex_specification *spec)
{
    char *specptr = spec->specs;
    char *spectype;
    long dummy;
    int i;

    for (i = 0; i < spec->nspecs; i++) {
        __DecodeAddress(specptr, (void **)&spectype);
        if (func_00100800(extype, spectype, &dummy))
            return 1;
        specptr += 4;
    }

    return 0;
}

extern "C" void func_00102420(char *throwtype, void *location, void *dtor); /* __throw */
extern char D_00497FD0[];

extern "C" void func_00101250(CatchInfo *catchinfo)
{
    char *unexp = (char *)catchinfo->stacktop;
    ex_specification spec;

#pragma exception_magic
    try {
        std_unexpected();
    }
    catch (...) {
        DecodeSpecification(unexp, &spec);
        if (IsInSpecification((char *)((CatchInfo *)&__exception_magic)->typeinfo, &spec))
            func_00102420(0, 0, 0);
        if (IsInSpecification(D_00497FB0, &spec)) {
            void *e = D_004D9050;
            func_00102420(D_00497FD0, &e, (void *)std_bad_exception_dtor);
        }
    }
    std_terminate();
}
