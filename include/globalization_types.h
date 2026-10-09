#ifndef GLOBALIZATION_TYPES_H
#define GLOBALIZATION_TYPES_H

/* Number of selectable languages (tables are null-terminated after this). */
#define LANGUAGE_COUNT 7

/* Object whose first word is returned by func_003FE640 (size unknown). */
typedef struct LocEntry {
    int unk00;
} LocEntry;

/* Object with an int at +0x04 cleared by func_003FEED0 (size unknown). */
typedef struct LocTable {
    int unk00;
    int unk04;
} LocTable;

#endif
