#include "types.h"

typedef struct Float4 {
    float v[4];
} Float4;

typedef struct Float3 {
    float v[3];
} Float3;

typedef struct ContactRec {
    signed char kind;        /* 0x00 */
    char pad01[3];
    char part04[0x10];       /* 0x04 */
    Float4 a;                /* 0x14 */
    Float3 b;                /* 0x24 */
    unsigned char f30;       /* 0x30 */
    unsigned char f31;       /* 0x31 */
    unsigned char f32;       /* 0x32 */
    char pad33[0xD];
    char part40[0x60];       /* 0x40 */
    char partA0[0x10];       /* 0xA0 */
    Q q[3];                  /* 0xB0 */
    float e0;                /* 0xE0 */
    float e4;                /* 0xE4 */
    char padE8[8];
} ContactRec; /* size 0xF0 */

typedef struct ContactList {
    int count;               /* 0x00 */
    char pad04[0xC];
    ContactRec recs[9];      /* 0x10 */
} ContactList;

extern void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_opAssign(void* dst, void* src);
extern void cCollisionEdge_opAssign(void* dst, void* src);
extern void cBitArray_19_opAssign(void* dst, void* src);
extern void cVector_opAssign(Q* dst, Q* src);

/* Appends a copy of src to the contact list (max 9 entries). */
void cArray_FixedCapacity_cIntermediateLedgeSearchInfo_9_PushBackActual(ContactList* list, ContactRec* src) {
    if ((unsigned int)list->count < 9) {
        ContactRec* rec = &list->recs[list->count];
        rec->kind = src->kind;
        cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_opAssign(rec->part04, src->part04);
        rec->a = src->a;
        rec->b = src->b;
        rec->f30 = src->f30;
        rec->f31 = src->f31;
        rec->f32 = src->f32;
        cCollisionEdge_opAssign(rec->part40, src->part40);
        cBitArray_19_opAssign(rec->partA0, src->partA0);
        cVector_opAssign(&rec->q[0], &src->q[0]);
        cVector_opAssign(&rec->q[1], &src->q[1]);
        cVector_opAssign(&rec->q[2], &src->q[2]);
        rec->e0 = src->e0;
        rec->e4 = src->e4;
        list->count++;
    }
}
