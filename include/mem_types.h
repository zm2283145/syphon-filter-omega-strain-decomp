#ifndef MEM_TYPES_H
#define MEM_TYPES_H

/* Memory object with two int fields at 0x04/0x08 (size unknown). */
typedef struct MemObj {
    int unk00;
    int unk04;
    int unk08;
} MemObj;

#endif
