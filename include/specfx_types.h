#ifndef SPECFX_TYPES_H
#define SPECFX_TYPES_H

/* Types for the specfx directory. Layouts are provisional. */

/* List iterator used by the push_back wrappers. */
typedef struct SpecFxListPos {
    void* node;
} SpecFxListPos;

/* Special effect base object (constructor 0x003EC1D0); registers itself in a
 * global list on construction. The vtable sits after the inline list. */
typedef struct SpecFx {
    char list[12];              /* 0x00: scalar collection */
    unsigned char unk0C;        /* 0x0C */
    char pad0D[3];
    int unk10;                  /* 0x10 */
    void* vtable;               /* 0x14 */
} SpecFx;

#endif
