#ifndef MAP_TYPES_H
#define MAP_TYPES_H

typedef struct MapItem {
    char pad00[0x24];
    int unk24;                      /* 0x24 */
} MapItem;

typedef struct MapEntry {
    MapItem* item;                  /* 0x00 */
} MapEntry;

typedef struct MapView {
    char pad00[0x94];
    float unk94;                    /* 0x94 reset to 0.25 */
} MapView;

#endif
