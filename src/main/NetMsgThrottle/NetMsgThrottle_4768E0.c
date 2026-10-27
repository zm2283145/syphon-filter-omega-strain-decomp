/*
 * main/NetMsgThrottle: 2 files, 004768E0-00476970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004768E0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int QueueMessage_cMessageR_cSystemP_int(char **, int, int);                         
int cMessage_dtor(char **, int);                           
extern char D_004DCF10;
extern char D_004E1AE0;
extern signed char *D_005061D0;
extern char D_00588038;

void func_004768E0(int arg0) {
    struct { char * f20[8]; signed char f40[4]; signed char f44[12]; } sl;
    signed char temp_v1;

    cMessage_ctor_cMessageNameR(sl.f20, &D_00588038);
    sl.f20[0] = &D_004E1AE0;
    temp_v1 = *D_005061D0;
    D_005061D0 += 1;
    sl.f44[0] = temp_v1 != 0;
    if (arg0 != 0) {
        sl.f40[0] = 1;
        QueueMessage_cMessageR_cSystemP_int(sl.f20, arg0, 1);
    }
    sl.f20[0] = &D_004DCF10;
    cMessage_dtor(sl.f20, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_004768E0 */

/* merge_units: begin func_00476970 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cActivateBodyTossMsg method; address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "loose05_types.h"

#if 0 /* merge_units */
extern unsigned char* D_005061D0; /* write cursor of a byte stream */
#endif /* merge_units */
#define D_005061D0 (*(unsigned char **)&D_005061D0) /* merge_units */


/* Appends the message's byte at +0x24 to the stream and advances the cursor. */
void cActivateBodyTossMsg_v04(BodyTossMsg* self) {
    unsigned char value;

    value = self->unk24;
    *D_005061D0 = value;
    D_005061D0 = D_005061D0 + 1;
}
#undef D_005061D0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00476970 */
