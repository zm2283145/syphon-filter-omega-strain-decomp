#ifndef SPECFXDEFS_TYPES_H
#define SPECFXDEFS_TYPES_H

/* Types for the SpecFxDefs directory. Layouts are provisional. */

/* One script-native argument slot (4 bytes). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* List iterator used by the push_back wrappers. */
typedef struct SpecListPos {
    void* node;
} SpecListPos;

/* Network message carrying a particle spawn request. */
typedef struct cNetSpawnParticleMsg {
    char pad00[0x24];
    int target;                 /* 0x24: object handle */
    signed char particle;       /* 0x28: particle type */
} cNetSpawnParticleMsg;

/* Particle emitter, see particle_types.h for the fields used there. */
typedef struct SpecEmitter {
    char pad00[0x1C];
    int active;                 /* 0x1C: nonzero while the emitter is alive */
} SpecEmitter;

/* Effect instance driving a particle emitter at a position. */
typedef struct SpecEmitterFx {
    unsigned char unk00;        /* 0x00 */
    unsigned char done;         /* 0x01: set once the emitter has died */
    char pad02[0x0A];
    SpecEmitter* emitter;       /* 0x0C */
    float pos[4];               /* 0x10 */
} SpecEmitterFx;

/* Object holding a 16-byte-element table at +0x20. */
typedef struct SpecTableOwner {
    char pad00[0x20];
    char* table;                /* 0x20 */
} SpecTableOwner;

#endif
