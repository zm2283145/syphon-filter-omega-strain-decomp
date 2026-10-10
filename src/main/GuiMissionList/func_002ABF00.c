#include "types.h"

typedef struct ObjAD {
    char pad[0xAD];
    unsigned char mode;
    char pad2[0xC0 - 0xAE];
    int unkC0;
    int unkC4;
    char pad3[4];
    int unkCC;
} ObjAD;

extern void func_002AC070(ObjAD*);

/* Changes the mode byte; on change resets three cached indices and refreshes. */
void func_002ABF00(ObjAD* o, unsigned char mode) {
    if (o->mode != mode) {
        o->mode = mode;
        o->unkCC = -1;
        o->unkC4 = -1;
        o->unkC0 = -1;
        func_002AC070(o);
    }
}
