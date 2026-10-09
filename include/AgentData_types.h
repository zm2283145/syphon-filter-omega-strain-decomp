#ifndef AGENTDATA_TYPES_H
#define AGENTDATA_TYPES_H

/*
 * cAgentData (per-agent progression: statistics, objective bits, unlocks) and
 * the objective registration table. Offsets come from the objective
 * progression research notes (constructor 0x00336700, reset 0x003361E0,
 * objective bit core 0x00333B90, registration row constructor 0x00330180).
 */

/* One script-native argument slot (4 bytes). */
typedef union AgentScriptArg {
    int i;
    float f;
    void* p;
    unsigned char u8;
} AgentScriptArg;

/*
 * Script natives copy an argument into a one-word stack array and read it back
 * through a cast; the cast keeps the original store/reload sequence.
 */
#define STACK_COPY(arr) (*(int*)(arr))

#define AGENT_STAT_COUNT 31

typedef struct cAgentData {
    char pad00[0x08];
    int stats[AGENT_STAT_COUNT];      /* 0x08: indexed by Script_cAgentData_GetStat */
    unsigned int objectiveBits[8];    /* 0x84: persistent objective completion bits */
    unsigned int missionBits[8];      /* 0xA4: per-mission objective completion bits */
    char padC4[0x8AC - 0xC4];
    unsigned char unk8AC;             /* 0x8AC: cleared by func_003361B0 */
    char pad8AD[0x8BC - 0x8AD];
    unsigned char unk8BC;             /* 0x8BC: cleared by func_003361B0 */
    char pad8BD[0x8CC - 0x8BD];
    unsigned char unk8CC;             /* 0x8CC: cleared by func_003361B0 */
    char pad8CD[0xAF0 - 0x8CD];
    unsigned char* omega;             /* 0xAF0: flag byte read by Script_cAgentData_HasOmega */
} cAgentData;

/* Objective registration row (24 bytes, built by 0x00330180). */
typedef struct ObjectiveRow {
    int key;                          /* 0x00: string-pool intern id */
    int index;                        /* 0x04: objective bit index */
    int unk08;                        /* 0x08: -1 on construction */
    int unk0C;                        /* 0x0C */
    int unk10;                        /* 0x10 */
    int points;                       /* 0x14 */
} ObjectiveRow;

/* Vector of ObjectiveRow (same layout as PtrVec). */
typedef struct ObjectiveRowVec {
    int unk0;
    int count;                        /* 0x04 */
    ObjectiveRow* data;               /* 0x08 */
} ObjectiveRowVec;

/* Vector of bytes (same layout as PtrVec). */
typedef struct ByteVec {
    int unk0;
    int count;                        /* 0x04 */
    char* data;                       /* 0x08 */
} ByteVec;

/* Game object as seen by Global_IsObjectiveComplete; only the class key. */
typedef struct AgentGObj {
    char pad00[0x4C];
    int classKey;                     /* 0x4C: compared with D_0049D010 */
} AgentGObj;

/* Generic byte-flag holder used by func_00336D90 / func_00336E10. */
typedef struct RelFlag {
    Rel rel;                          /* 0x00 */
    unsigned char flag;               /* 0x0C */
} RelFlag;

/* Sub-record at AgentRec14+4; the first 12 bytes are copied by func_0033AA30. */
typedef struct AgentRecSub {
    char unk00[12];                   /* 0x00 */
    unsigned char unk0C;              /* 0x0C */
} AgentRecSub;

/* 20-byte record copied by func_00337AB0. */
typedef struct AgentRec14 {
    signed char unk00;                /* 0x00 */
    char pad01[3];
    AgentRecSub sub;                  /* 0x04 */
} AgentRec14;

#endif
