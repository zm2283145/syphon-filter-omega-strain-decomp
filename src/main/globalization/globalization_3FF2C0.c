#include "types.h"

typedef struct { int words[2]; } Reader;
extern unsigned int D_0055D488;
extern int cMessage_RegisterFields(Reader* r);
extern int NetMessageField(Reader* r, unsigned char* out, int size, int count);

/* Opens a reader and reads two bytes; on success clears D_0055D488 and returns 1. */
unsigned char cCharActionMsg_RegisterFields(void)
{
    Reader r;
    unsigned char bytes[8]; /* header buffer; only the first two bytes are read here */
    unsigned char ok = 0;
    if (cMessage_RegisterFields(&r) && NetMessageField(&r, &bytes[0], 1, 1) == 0 && NetMessageField(&r, &bytes[1], 1, 1) == 0) {
        ok = 1;
        D_0055D488 = 0;
    }
    return ok;
}
