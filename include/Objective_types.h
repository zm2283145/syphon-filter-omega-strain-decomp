#ifndef OBJECTIVE_TYPES_H
#define OBJECTIVE_TYPES_H

/*
 * Objective system types (cObjective / cObjectiveMan) and the argument block
 * passed to script-native callbacks. Offsets come from the objective research
 * notes (constructor 0x00229900, manager constructor 0x00227ED0).
 */

/* One script-native argument slot (4 bytes). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
    unsigned char u8;
} ScriptArg;

/* Objective state byte values (cObjective.state). */
#define OBJECTIVE_PENDING  0
#define OBJECTIVE_COMPLETE 1
#define OBJECTIVE_FAILED   2

typedef struct cObjective {
    char pad00[0x20];
    int id;                    /* 0x20: assigned from manager nextId */
    signed char state;         /* 0x24: OBJECTIVE_* */
    unsigned char active;      /* 0x25 */
    unsigned char type;        /* 0x26: Objective_Types (0 = Normal) */
    unsigned char multiType;   /* 0x27: 3 = Single */
    unsigned char count;       /* 0x28 */
    unsigned char notifyType;  /* 0x29: 0 = Never */
    char pad2A[2];
    int stage;                 /* 0x2C: stage bucket, -1 = global */
    char pad30[0x48];
    char* completeText;        /* 0x78 */
    char pad7C[4];
    char* failText;            /* 0x80 */
} cObjective;

#define OBJMAN_STAGE_COUNT  32
#define OBJMAN_BUCKET_SLOTS 32

typedef struct cObjectiveMan {
    char pad00[0xA4];
    int stage;                 /* 0xA4: current stage */
    int nextId;                /* 0xA8 */
    unsigned char unkAC;       /* 0xAC: flag cleared by func_002261C0 */
    char padAD[3];
    cObjective* stageObjectives[OBJMAN_STAGE_COUNT][OBJMAN_BUCKET_SLOTS]; /* 0xB0 */
    cObjective* globalObjectives[OBJMAN_BUCKET_SLOTS];                    /* 0x10B0 */
    int stageCounts[OBJMAN_STAGE_COUNT];                                  /* 0x1130 */
    int globalCount;                                                      /* 0x11B0 */
} cObjectiveMan;

#endif
