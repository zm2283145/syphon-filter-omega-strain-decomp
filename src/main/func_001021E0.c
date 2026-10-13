/* MW C++ runtime ExceptionHandler.cp: FindExceptionRecord (+ inlined BinarySearch), from the CodeWarrior PS2 Runtime source */
typedef unsigned char exaction_type;

typedef struct CatchInfo {
    void *location;
    void *typeinfo;
    void *dtor;
    void *sublocation;
    int pointercopy;
    void *stacktop;
} CatchInfo;

typedef struct TargetContext {
    __int128 GPR[32];
    unsigned int frame_size;
    unsigned int argument_size;
    int n_saved_GPRs;
    int has_flushback;
    int has_frame_ptr;
    unsigned int n_saved_FPRs;
    float FPR[32];
} TargetContext;

typedef struct ThrowContext {
    char *throwtype;
    void *location;
    void *dtor;
    CatchInfo *catchinfo;
    char *returnaddr;
    char *SP;
    char *FP;
    char *throwSP;
    TargetContext target;
} ThrowContext;

typedef struct TargetExceptionInfo {
    int dummy;
} TargetExceptionInfo;

typedef struct ExceptionInfo {
    char *current_function;
    char *exception_record;
    char *action_pointer;
    void *exception_table_start;
    void *exception_table_end;
    TargetExceptionInfo target;
} ExceptionInfo;

typedef struct ActionIterator {
    ExceptionInfo info;
    ThrowContext context;
} ActionIterator;

typedef struct ex_catchblock {
    char *catch_type;
    unsigned int pcoffset;
    int cinfo_ref;
} ex_catchblock;

typedef struct ex_activecatchblock {
    int cinfo_ref;
} ex_activecatchblock;

typedef struct ex_specification {
    unsigned int nspecs;
    unsigned int pcoffset;
    int cinfo_ref;
    char *specs;
} ex_specification;

extern char *func_00100BC0(char *p, unsigned int *pnum); /* __DecodeUnsignedNumber */
extern char *func_00100C70(char *p, int *pnum);          /* __DecodeSignedNumber */
extern void func_00100AB0(void);                         /* terminate */
extern int func_00100800(char *throwtype, char *catchtype, long *offset_result); /* __throw_catch_compare */
extern void func_00101640(ThrowContext *context, ExceptionInfo *info, char *catcher); /* UnwindStack */
extern exaction_type func_00101E90(ActionIterator *iter); /* NextAction */
extern void func_001023B0(ThrowContext *context, ExceptionInfo *info, char *address); /* __TransferControl */

static inline char *__DecodeAddress(char *p, void **paddr)
{
    unsigned int addr;
    addr = ((unsigned char *)p)[0] | (((unsigned char *)p)[1] << 8) |
           (((unsigned char *)p)[2] << 16) | (((unsigned char *)p)[3] << 24);
    *paddr = (void *)addr;
    return p + 4;
}

static inline void DecodeCatchBlock(char *ap, ex_catchblock *cb)
{
    ap += sizeof(exaction_type);
    ap = __DecodeAddress(ap, (void **)&cb->catch_type);
    cb->catch_type = (cb->catch_type ? (cb->catch_type) : 0);
    ap = func_00100BC0(ap, &cb->pcoffset);
    ap = func_00100C70(ap, &cb->cinfo_ref);
}

static inline void DecodeSpecification(char *ap, ex_specification *sp)
{
    ap += sizeof(exaction_type);
    ap = func_00100BC0(ap, &sp->nspecs);
    ap = func_00100BC0(ap, &sp->pcoffset);
    ap = func_00100C70(ap, &sp->cinfo_ref);
    sp->specs = ap;
}

static inline exaction_type CurrentAction(const ActionIterator *iter)
{
    return iter->info.action_pointer ? *(exaction_type *)iter->info.action_pointer & 0x1F : 0;
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

static inline void HandleUnexpected(ThrowContext *context, ExceptionInfo *info, ex_specification *spec, char *unexp)
{
    CatchInfo *catchinfo;

    func_00101640(context, info, unexp);

    catchinfo = (CatchInfo *)(context->FP + spec->cinfo_ref);
    catchinfo->location = context->location;
    catchinfo->typeinfo = context->throwtype;
    catchinfo->dtor = context->dtor;
    catchinfo->stacktop = unexp;

    func_001023B0(context, info, info->current_function + spec->pcoffset);
}

typedef struct ExceptionTableIndex {
    char *function_address;
    unsigned int function_size;
    char *exception_table;
} ExceptionTableIndex;

extern int func_001024F0(ExceptionInfo *info, char *retaddr);   /* __FindExceptionTable */
extern char *func_001024A0(char *exceptionrecord);               /* __SkipUnwindInfo */

static inline ExceptionTableIndex *BinarySearch(ExceptionTableIndex *table, unsigned int tablesize, char *return_address)
{
    int i, m, n;
    ExceptionTableIndex *p;

    for (i = 0, n = tablesize - 1; i <= n;) {
        p = &table[m = ((i + n) >> 1)];
        if (return_address < p->function_address) {
            n = m - 1;
        }
        else if (return_address > p->function_address + (p->function_size & 0xFFFFFFFE)) {
            i = m + 1;
        }
        else {
            return p;
        }
    }

    return 0;
}

void func_001021E0(char *return_address, ExceptionInfo *info)
{
    ExceptionTableIndex *exceptiontable;
    char *rangetable;
    unsigned int return_offset;
    unsigned int currentPC;
    unsigned int deltaPC;
    unsigned int length;
    unsigned int actions;

    info->exception_record = 0;
    info->action_pointer = 0;

    if (!func_001024F0(info, return_address))
        return;

    return_address = (char *)((int)return_address & ~1L);

    exceptiontable = BinarySearch((ExceptionTableIndex *)info->exception_table_start,
                                  (ExceptionTableIndex *)info->exception_table_end - (ExceptionTableIndex *)info->exception_table_start,
                                  return_address);
    if (!exceptiontable)
        return;

    if ((exceptiontable->function_size & 1) != 0) {
        info->exception_record = (char *)&exceptiontable->exception_table;
    }
    else {
        info->exception_record = exceptiontable->exception_table;
    }

    info->current_function = exceptiontable->function_address;
    return_offset = return_address - exceptiontable->function_address;

    rangetable = func_001024A0(info->exception_record);

    for (currentPC = 0;;) {
        rangetable = func_00100BC0(rangetable, &deltaPC);
        if (deltaPC == 0)
            return;
        rangetable = func_00100BC0(rangetable, &length);
        rangetable = func_00100BC0(rangetable, &actions);

        currentPC += deltaPC;

        if (return_offset < currentPC)
            return;
        currentPC += length;
        if (return_offset <= currentPC)
            break;
    }

    info->action_pointer = info->exception_record + actions;
}