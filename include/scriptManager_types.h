#ifndef SCRIPTMANAGER_TYPES_H
#define SCRIPTMANAGER_TYPES_H

/*
 * Types used by the script manager / interpreter glue (scriptManager).
 * Offsets come from the matched code. Fields named unkXX are not understood yet.
 */

#include "types.h"

/* One script-native argument word (int, float bits or pointer). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* Script manager / interpreter state; the global instance is D_00555070.
 * Only the fields used here. The evaluation stack grows downwards and sp points
 * at the top word. */
typedef struct ScriptManager {
    char pad0000[0x4E68];
    int unk4E68;                    /* 0x4E68 */
    char pad4E6C[0x4];
    int* sp;                        /* 0x4E70 evaluation stack top */
    char pad4E74[0x1C];
    int unk4E90;                    /* 0x4E90 */
} ScriptManager;

/* Loaded script: +0x48 maps script-local enum ids (>= 10) to global enum ids. */
typedef struct Script {
    char pad00[0x48];
    int* enumMap;                   /* 0x48 indexed by (local id - 10) */
} Script;

/* 12-byte enum member record; first word read by func_003DC470. */
typedef struct ScriptEnumMember {
    int unk0;
    int unk4;
    int unk8;
} ScriptEnumMember;

/* Global enum descriptor; member records at +0x0C. */
typedef struct ScriptEnum {
    char pad00[0xC];
    ScriptEnumMember* members;      /* 0x0C */
} ScriptEnum;

/* Result of func_003DCF70: global enum id at +0x14. */
typedef struct ScriptEnumEntry {
    char pad00[0x14];
    int id;                         /* 0x14 */
} ScriptEnumEntry;

/* Object that owns a script binding; +0x08 is passed as the lookup key. */
typedef struct ScriptBound {
    char pad00[0x8];
    int key;                        /* 0x08 */
} ScriptBound;

/* PtrVec followed by a flag byte. */
typedef struct OwnedVec {
    int unk0;
    int count;
    int* data;
    char unk0C;                     /* 0x0C set to 1 after init */
} OwnedVec;

/* List iterator pair used by the push_back wrappers. */
typedef struct ListPos {
    void* node;
} ListPos;

#endif
