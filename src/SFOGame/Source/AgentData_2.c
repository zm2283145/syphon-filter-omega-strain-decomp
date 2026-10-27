/*
 * SFOGame/Source/AgentData: 14 files, 0032FCA0-003305A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032FCA0 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { int p0, p4; int stats[1]; } A2FCA0;
static inline void Set2FCA0(A2FCA0* s, int i, int v) { s->stats[i] = v; }
#pragma opt_propagation off
int Script_cAgentData_SetStat(ScriptArg* args)
{
    int v[1];
    v[0] = args[2].i;
    Set2FCA0((A2FCA0*)args[0].p, args[1].b, *(int*)v);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FCA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FCA0 */

/* merge_units: begin func_0032FCD0 */
#pragma push /* merge_units */
typedef struct { int p0, p4; int stats[18]; int level[1]; } A2FCD0;
int Script_cAgentData_AddScore(ScriptArg* args)
{
    A2FCD0* self;
    int val;
    int idx;
    int v[1];
    v[0] = args[2].i;
    val = *(int*)v;
    idx = args[1].b;
    self = (A2FCD0*)args[0].p;
    if (idx < 31 && val > 0) {
        self->stats[idx] += val;
        if (idx < 13)
            self->level[idx] += val;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FCD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FCD0 */

/* merge_units: begin func_0032FD30 */
#pragma push /* merge_units */
#include "AgentData_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cAgentData script natives (clearance points).
 */


#if 0 /* merge_units */
extern int cAgentData_GetClearancePoints(cAgentData* agent);
#endif /* merge_units */
int cAgentData_GetClearancePoints(); /* merge_units */


/* Returns the agent's total clearance points; volatile mirrors the stack temporary. */
int Script_cAgentData_GetClearancePoints(AgentScriptArg* args) {
    volatile int points = cAgentData_GetClearancePoints(args[0].p);
    return points;
}

void cAgentData_SOBJ_init(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FD30 */

/* merge_units: begin func_0032FD70 */
#pragma push /* merge_units */
typedef struct { int key; int a; char b; int c; int d; int e; } Medal;
extern int nGlobalization_GetStringIndex(const char* name);

/* Medal constructor: resolves the name key and stores the fields; id is 10000 + index. */
Medal* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc(Medal* self, const char* name, int a, char b, int c, int d, unsigned char index)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = index + 10000;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032FD70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032FD70 */

/* merge_units: begin func_0032FE00 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
struct E_32FE00 { int id; int pad[4]; int val; };
struct O_32FE00 { int key; int id; char flag; int a; int b; int val; };
extern "C" {
extern char g_UnlockRows[];
E_32FE00* std_vector_imp_Record_begin(void* t);
E_32FE00* std_vector_imp_Record_end(void* t);
void std_vector_Record_pointer2iterator(E_32FE00** out, void* t, E_32FE00** raw);
#if 0 /* merge_units */
int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */


int nGlobalization_GetString_charP(int id);
}
static inline bool Neq_32FE00(E_32FE00* a, E_32FE00* b) { return !(a == b); }
static inline int Find_32FE00(const char* key)
{
    int k = nGlobalization_GetStringIndex(key);
    if (k > -1) {
        E_32FE00* b;
        E_32FE00* e;
        E_32FE00* t1;
        E_32FE00* t2;
        E_32FE00* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FE00* last = e; Neq_32FE00(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FE00* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(O_32FE00* self, const char* name, int id, char flag, int a, int b, const char* key)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->id = id;
    self->flag = flag;
    self->a = a;
    self->b = b;
    self->val = key ? Find_32FE00(key) : -1;
    return self;
}
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FE00 */

/* merge_units: begin func_0032FF50 */
#pragma push /* merge_units */
typedef struct { int name; int unk4; int desc; int value; int id; int extra; } Rec0032FF50;
#if 0 /* merge_units */
extern int nGlobalization_GetStringIndex(int key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((const char *)(a0))) /* merge_units */


/* Fill a rating record. */
Rec0032FF50* cAgentData_Record_ctor_charP_int_charP_int_etc(Rec0032FF50* rec, int nameKey, int extra, int descKey, int value, unsigned char id)
{
    rec->name = nGlobalization_GetStringIndex(nameKey);
    rec->extra = extra;
    rec->desc = nGlobalization_GetStringIndex(descKey);
    rec->value = value;
    rec->id = id + 10000;
    return rec;
}
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FF50 */

/* merge_units: begin func_0032FFD0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
struct E_32FFD0 { int id; int pad[4]; int val; };
struct O_32FFD0 { int key; int p4; int key2; int c; int val; int x; };
extern "C" {
#if 0 /* merge_units */
E_32FFD0* std_vector_imp_Record_begin(void* t);
#endif /* merge_units */
#define std_vector_imp_Record_begin(a0) ((E_32FFD0 *)std_vector_imp_Record_begin((a0))) /* merge_units */


#if 0 /* merge_units */
E_32FFD0* std_vector_imp_Record_end(void* t);
#endif /* merge_units */
#define std_vector_imp_Record_end(a0) ((E_32FFD0 *)std_vector_imp_Record_end((a0))) /* merge_units */


#if 0 /* merge_units */
void std_vector_Record_pointer2iterator(E_32FFD0** out, void* t, E_32FFD0** raw);
#endif /* merge_units */
#define std_vector_Record_pointer2iterator(a0, a1, a2) (std_vector_Record_pointer2iterator((E_32FE00 * *)(a0), (a1), (E_32FE00 * *)(a2))) /* merge_units */


#if 0 /* merge_units */
int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */


}
static inline bool Neq_32FFD0(E_32FFD0* a, E_32FFD0* b) { return !(a == b); }
static inline int Find_32FFD0(const char* key)
{
    int k = nGlobalization_GetStringIndex(key);
    if (k > -1) {
        E_32FFD0* b;
        E_32FFD0* e;
        E_32FFD0* t1;
        E_32FFD0* t2;
        E_32FFD0* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FFD0* last = e; Neq_32FFD0(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FFD0* cAgentData_Record_ctor_charP_int_charP_int_etc_2(O_32FFD0* self, const char* name, int x, const char* name2, int c, const char* key)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->x = x;
    self->key2 = nGlobalization_GetStringIndex(name2);
    self->c = c;
    self->val = key ? Find_32FFD0(key) : -1;
    return self;
}
#undef std_vector_imp_Record_begin /* merge_units */
#undef std_vector_imp_Record_end /* merge_units */
#undef std_vector_Record_pointer2iterator /* merge_units */
#undef nGlobalization_GetStringIndex /* merge_units */
static inline void merge_flush_func_0032FFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032FFD0 */

/* merge_units: begin func_00330110 */
#pragma push /* merge_units */
typedef struct { void* buffer; int unk4; int index; int unkC; char pad[4]; int unk14; } Obj330;

extern void* g_WeaponDatabase;
extern char* cWeaponDB_GetEntry(void* p);
#if 0 /* merge_units */
extern void* nGlobalization_GetStringIndex(char* p);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) ((void *)nGlobalization_GetStringIndex((const char *)(a0))) /* merge_units */



/* Constructor: allocates the buffer and initializes the fields; returns self. */
Obj330* cAgentData_Record_ctor_int_int(Obj330* self, int a, int b)
{
    self->buffer = nGlobalization_GetStringIndex(cWeaponDB_GetEntry(g_WeaponDatabase) + 0x80);
    self->unk14 = a;
    self->unk4 = b;
    self->index = -1;
    self->unkC = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330110(void) {}
#undef nGlobalization_GetStringIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00330110 */

/* merge_units: begin func_00330180 */
#pragma push /* merge_units */
typedef struct { int text; int unk4; int unk8; int unkC; int unk10; int unk14; } ObjectiveRow_00330180;
#if 0 /* merge_units */
extern int nGlobalization_GetStringIndex(const char* key);
#endif /* merge_units */
#define nGlobalization_GetStringIndex(a0) (nGlobalization_GetStringIndex((a0))) /* merge_units */




/* Initialises an objective row: looks up the text key and stores the parameters. */
ObjectiveRow_00330180* cAgentData_Record_ctor_charP_int_int(ObjectiveRow_00330180* row, const char* key, int a, int b)
{
    row->text = nGlobalization_GetStringIndex(key);
    row->unk14 = a;
    row->unk4 = b;
    row->unk8 = -1;
    row->unkC = 0;
    return row;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330180(void) {}
#undef nGlobalization_GetStringIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00330180 */

/* merge_units: begin func_003301E0 */
#pragma push /* merge_units */
typedef struct { int pad[4]; int level; } E301E0;
typedef struct { int a; int count; } T301E0;
extern int D_00532B34;
extern E301E0* D_00532B38;
#if 0 /* merge_units */
extern void std_vector_charPtr_push_back_charPR_2(T301E0* self, E301E0** e);
#endif /* merge_units */
int std_vector_charPtr_push_back_charPR_2(); /* merge_units */

#pragma opt_strength_reduction off
void cAgentData_GetLockedParts_cArrayP_int(T301E0* self, int level)
{
    int i;
    self->count = 0;
    for (i = 0; i < D_00532B34; i++) {
        E301E0* e[1];
        E301E0* p = &D_00532B38[i];
        e[0] = p;
        if (level < p->level)
            std_vector_charPtr_push_back_charPR_2(self, e);
    }
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_003301E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003301E0 */

/* merge_units: begin func_00330280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector helper.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value) */
int std_vector_charPtr_push_back_charPR_2(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00330280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00330280 */

/* merge_units: begin func_003302A0 */
#pragma push /* merge_units */
typedef struct { int idx; int hash; } Col;
typedef struct { int a; int count; Col *data; char owns; } ColVec;
typedef struct { char name[16]; int val; } Ent;
typedef struct { int a; int count; Ent *data; } EntVec;
typedef struct { int d[0x2A]; } FEnt;
extern EntVec D_00532B30;
extern char D_004B9280[];
extern void *cFileMan_ctor_void(void *);
extern void *cFileMan_dtor(void *, int);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(void *, const char *, int, int);
extern int cFileMan_Open(void *);
extern char *cFileMan_Read_void(void *);
extern int cFileMan_GetSize(void *);
#if 0 /* merge_units */
extern ColVec *std_vector_tColumnData_ctor(ColVec *);
#endif /* merge_units */
Rel * std_vector_tColumnData_ctor(); /* merge_units */

extern void func_0033A580(ColVec *);
extern void std_vector_deleter_tColumnData_dtor(ColVec *, int);
extern void std_vector_imp_tColumnData_insert(ColVec *, Col *, int, Col *);
extern void std_vector_imp_PartData_insert(EntVec *, Ent *, int, Ent *);
extern int atoi(const char *);
extern int strlen(const char *);
extern char *strncpy(char *, const char *, int);
#pragma opt_strength_reduction off
void cAgentData_LoadPartData(int arg)
{
    Col col;
    FEnt f;
    ColVec v;
    char line[0x200];
    Ent ent;
    unsigned char first;
    char *p;
    int left;
    int len;
    int i;
    int j;
    char *s;
    char *q;
    cFileMan_ctor_void(&f);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&f, D_004B9280, arg, 0);
    if (!(cFileMan_Open(&f) & 0xFF)) {
        p = cFileMan_Read_void(&f);
        left = cFileMan_GetSize(&f);
        first = 1;
        std_vector_tColumnData_ctor(&v);
        v.owns = 1;
        while (left > 0) {
            q = line;
            while (left > 0 && *p != '\r') {
                *q++ = *p++;
                left--;
            }
            *q = 0;
            p += 2;
            left -= 2;
            len = strlen(line);
            if (len == 0) {
                first = 1;
                func_0033A580(&v);
            } else if (first) {
                first = 0;
                {
                int *hp = &col.hash;
                Col **pd = &v.data;
                for (i = 0; i < len; i++) {
                    s = &line[i];
                    if (*s != ' ') {
                        *hp = atoi(s);
                        col.idx = i;
                        std_vector_imp_tColumnData_insert(&v, *pd + v.count, 1, &col);
                        while (i < len && *s != ' ') {
                            s++;
                            i++;
                        }
                    }
                }
                }
            } else {
                for (j = 0; j < v.count; j++) {
                    int c = v.data[j].idx;
                    if (c < len) {
                        char *b = &line[c];
                        char *e = b;
                        if (*b != ' ') {
                            int n;
                            while (*e != ' ' && *e != '\r' && *e != 0) e++;
                            n = e - b;
                            strncpy(ent.name, b, n);
                            ent.name[n] = 0;
                            ent.val = v.data[j].hash;
                            std_vector_imp_PartData_insert(&D_00532B30, D_00532B30.data + D_00532B30.count, 1, &ent);
                        }
                    }
                }
            }
        }

        std_vector_deleter_tColumnData_dtor(&v, 0);
    }
    cFileMan_dtor(&f, -1);
}
static inline void merge_flush_func_003302A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003302A0 */

/* merge_units: begin func_003305A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* std_vector_tColumnData_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void* std_vector_deleter_Record_data(char* self) {
    return self + 8;
}
static inline void merge_flush_func_003305A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003305A0 */

/* merge_units: begin func_003305D0 */
#pragma push /* merge_units */
typedef struct TpRec {
    int unk00;
    int unk04;
    unsigned char flag;
    char pad09[0x14 - 0x09];
} TpRec;

typedef struct TpList {
    int unk0;
    int count;
    TpRec* data;
    unsigned char flag;
} TpList;

typedef struct TpTable {
    int unk0;
    int count;
    ObjectiveRow* data;
    int unkC;
} TpTable;

typedef struct TpAgent {
    char pad00[0x08];
    int stats[14];
    int unk40;
    int unk44;
    char pad48[0x84 - 0x48];
    unsigned int objectiveBits[8];
} TpAgent;

extern ObjectiveRowVec D_005329F0;
extern TpTable D_00532A70[5];
extern ObjectiveRowVec D_00532AD0;

extern void cArray_Record_Begin(ObjectiveRow** out, ObjectiveRowVec* v);
extern void cArray_Record_End(ObjectiveRow** out, ObjectiveRowVec* v);
extern int cArray_Record_Iterator_opNe(ObjectiveRow** a, ObjectiveRow** b);
extern ObjectiveRow* cArray_Record_Iterator_opMul(ObjectiveRow** it);
extern ObjectiveRow** cArray_Record_Iterator_opInc(ObjectiveRow** it);
extern int cBitArray_224_opIndex(unsigned int* bits, int index);
extern ObjectiveRow** std_vector_deleter_RatingRecord_data(ObjectiveRowVec* v);
extern void func_00296FA0(TpList* l);
extern void cAgentData_GetAchievements(TpAgent* self, unsigned char kind, TpList* l);
extern void* func_00299360(TpList* l, short deleteFlag);

static inline int TpNeq(ObjectiveRow* a, ObjectiveRow* b) { return !(a == b); }

static inline int TpCompleted(TpAgent* self) {
    int sum = 0;
    ObjectiveRow* it;
    ObjectiveRow* end;
    cArray_Record_Begin(&it, &D_005329F0);
    cArray_Record_End(&end, &D_005329F0);
    while (cArray_Record_Iterator_opNe(&it, &end)) {
        if (cBitArray_224_opIndex(self->objectiveBits, cArray_Record_Iterator_opMul(&it)->index))
            sum += cArray_Record_Iterator_opMul(&it)->points;
        cArray_Record_Iterator_opInc(&it);
    }
    return sum;
}

int cAgentData_GetClearancePoints(TpAgent* self) {
    int total = 0;
    ObjectiveRow* p;
    ObjectiveRow* e;
    int i;
    TpTable* t;
    total += TpCompleted(self);
    p = *std_vector_deleter_RatingRecord_data(&D_00532AD0);
    e = *std_vector_deleter_RatingRecord_data(&D_00532AD0) + D_00532AD0.count;
    for (; TpNeq(p, e); p++) {
        if (self->stats[*(unsigned char*)&p->unk08] >= p->unk10)
            total += p->index;
    }
    for (i = 0, t = D_00532A70; i < 5; i++, t++) {
        TpList l;
        int j;
        func_00296FA0(&l);
        l.flag = 1;
        cAgentData_GetAchievements(self, i, &l);
        for (j = 0; j < l.count; j++) {
            if (l.data[(unsigned)j].flag)
                total += t->data[(unsigned)j].points;
        }
        func_00299360(&l, 0);
    }
    total += self->unk40 * 5;
    total += self->unk44 * 5;
    return total;
}
static inline void merge_flush_func_003305D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003305D0 */
