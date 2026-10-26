#ifndef SKA_TYPES_H
#define SKA_TYPES_H

/*
 * Provisional layouts used by the skeletal animation unit (ska.cc).
 * Field names are placeholders (unkXX) unless the accessors make the meaning clear.
 */

#include "types.h"

/* Growable array header: capacity, element count, element storage. */
typedef struct SkaVec {
    int capacity;     /* 0x00 */
    int count;        /* 0x04 */
    char* data;       /* 0x08 */
} SkaVec;             /* size 0x0C */

/* Fixed stack of up to four time values (AnimContext_PushTime). */
typedef struct SkaTimeStack {
    int count;        /* 0x00 */
    float times[4];   /* 0x04 */
} SkaTimeStack;       /* size 0x14 */

/* Transition request record built by TransitionReq_Construct / TransitionReq_Reset. */
typedef struct SkaTransitionReq {
    int unk00;        /* 0x00 */
    int unk04;        /* 0x04 */
    float unk08;      /* 0x08, initialised to FLT_MAX */
    float unk0C;      /* 0x0C, initialised to FLT_MAX / transition time */
    int key;          /* 0x10, compared by TransitionReq_SameKey */
} SkaTransitionReq;   /* size 0x14 */

/* Five-float record copied by cSkaSystem_Transition_ctor_cSkaSystemTransitionR. */
typedef struct SkaFloat5 {
    float v[5];
} SkaFloat5;

/* Six-word value returned through a hidden pointer by std_deque_deleter_common_cSkaSystem_Request_make_iterator. */
typedef struct SkaWords6 {
    int w[6];
} SkaWords6;

/* Three dirty flags of an animation root. */
typedef struct SkaDirtyFlags {
    unsigned char f0, f1, f2;
} SkaDirtyFlags;

/* Object with an indexed table of 8-byte entries at +0x90. */
typedef struct SkaPair {
    int unk0;
    int unk4;
} SkaPair;

typedef struct SkaPairTableOwner {
    char pad00[0x90];
    SkaPair* table;   /* 0x90 */
} SkaPairTableOwner;

typedef struct SkaPairIndex {
    char pad00[0x20];
    int index;        /* 0x20 */
} SkaPairIndex;

/* Block array: entries of 248 bytes stored in blocks of eight. */
typedef struct SkaBlockArray {
    char pad00[0x10];
    int first;        /* 0x10, index of the first live entry */
} SkaBlockArray;

/* Pose source used by SkelBone_GetLocalOffset (XYZ at +8/+0xC/+0x10). */
typedef struct SkaPoseSrc {
    char pad00[8];
    float x;          /* 0x08 */
    float y;          /* 0x0C */
    float z;          /* 0x10 */
} SkaPoseSrc;

typedef struct SkaVec4 {
    float x, y, z;
    int w;
} SkaVec4;

/* Clip header root-motion axis flags (a nonzero byte selects that axis). */
typedef struct SkaClipFlags {
    char pad00[0x14];
    unsigned char axisX;  /* 0x14, motion axis flag X */
    unsigned char axisY;  /* 0x15 */
    unsigned char axisZ;  /* 0x16 */
} SkaClipFlags;

/* Notification table: seven 8-byte token/receiver pairs (0x38 bytes). */
typedef struct SkaNotifyTable {
    int words[14];
} SkaNotifyTable;

/* Array header (three words) followed by a flag byte; copied by cArray_cSkaSwitchItem_ctor_cArrayR/NotifyRange_CopyConstruct/cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_cArrayR. */
typedef struct SkaFlaggedVec {
    SkaVec vec;           /* 0x00 */
    unsigned char flag;   /* 0x0C */
} SkaFlaggedVec;          /* size 0x10 */

/* Record copied by cSkaAnimAnchor_TreeNode_ctor_cSkaAnimAnchorTreeNodeR: base part, a word at +0xB0 and a flagged array at +0xB4. */
typedef struct SkaRecordB0 {
    char base[0xB0];      /* 0x00, copied by cSkaAnimAnchor_TreeNodeData_ctor_cSkaAnimAnchorTreeNodeDataR */
    int unkB0;            /* 0xB0 */
    SkaFlaggedVec unkB4;  /* 0xB4 */
} SkaRecordB0;

/* Animation root fields touched in this directory. */
typedef struct SkaAnimRoot {
    char pad00[0xC0];
    int unkC0;            /* 0xC0 */
    char padC4[0x3C];
    float angular;        /* 0x100, accumulated angular motion */
} SkaAnimRoot;

/* Pair of words initialised to {0, -1}. */
typedef struct SkaHandle {
    int unk0;             /* 0x00 */
    int index;            /* 0x04, -1 when unset */
} SkaHandle;

/* Four zeroed words followed by a call (_cdeque_imp_cSkaSystem_RequestPtr_1_ctor). */
typedef struct SkaQuadWords {
    int w[4];
} SkaQuadWords;

/* Three-word header plus a flag byte at +0x0C set by cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_ctor_void. */
typedef struct SkaRelFlag {
    Rel rel;              /* 0x00 */
    unsigned char flag;   /* 0x0C */
} SkaRelFlag;

/* Object whose element array (36-byte entries) pointer sits at +0x0C. */
typedef struct SkaTable0C {
    char pad00[0xC];
    char* data;           /* 0x0C */
} SkaTable0C;

#endif
