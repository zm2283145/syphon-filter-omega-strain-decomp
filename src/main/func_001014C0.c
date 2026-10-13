/* MW C++ runtime ExceptionHandler.cp: FindMostRecentException (from the CodeWarrior PS2 Runtime source) */
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

static inline void DecodeActiveCatchBlock(char *ap, ex_activecatchblock *acb)
{
    ap += sizeof(exaction_type);
    ap = func_00100C70(ap, &acb->cinfo_ref);
}

CatchInfo *func_001014C0(ThrowContext *context, ExceptionInfo *info)
{
    ActionIterator iter;
    exaction_type action;
    CatchInfo *catchinfo;
    ex_activecatchblock acb;

    iter.info.current_function = info->current_function;
    iter.info.exception_record = info->exception_record;
    iter.info.action_pointer = info->action_pointer;
    iter.info.exception_table_start = info->exception_table_start;
    iter.info.exception_table_end = info->exception_table_end;
    iter.info.target = info->target;
    iter.context.throwtype = context->throwtype;
    iter.context.location = context->location;
    iter.context.dtor = context->dtor;
    iter.context.catchinfo = context->catchinfo;
    iter.context.returnaddr = context->returnaddr;
    iter.context.SP = context->SP;
    iter.context.FP = context->FP;
    iter.context.throwSP = context->throwSP;
    iter.context.target = context->target;
    for (action = CurrentAction(&iter);; action = func_00101E90(&iter)) {
        switch (action) {
        case 13:
            break;

        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 15:
            continue;

        case 14:
        default:
            func_00100AB0();
        }
        break;
    }

    DecodeActiveCatchBlock(iter.info.action_pointer, &acb);
    catchinfo = (CatchInfo *)(iter.context.FP + acb.cinfo_ref);
    context->throwtype = (char *)catchinfo->typeinfo;
    context->location = catchinfo->location;
    context->dtor = 0;
    context->catchinfo = catchinfo;

    return catchinfo;
}