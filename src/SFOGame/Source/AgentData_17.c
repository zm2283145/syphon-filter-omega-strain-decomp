/*
 * SFOGame/Source/AgentData: 2 files, 00330280-003302A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00330280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector helper.
 */

#include "types.h"

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
extern ColVec *std_vector_tColumnData_ctor(ColVec *);
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
