#ifndef MEMCARD_TYPES_H
#define MEMCARD_TYPES_H

/* Memory card state object (size unknown, at least 0x0D). */
typedef struct MemCardState {
    int unk00;              /* 0x00: passed to MemCard_MemCardMain */
    unsigned char present;  /* 0x04: MemCard_MemCardMain returned non-zero */
    char pad05[7];
    char unk0C;             /* 0x0C: cleared when not present */
} MemCardState;

#endif
