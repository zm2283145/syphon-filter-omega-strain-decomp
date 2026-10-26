/*
 * main/DME: 3 files, 0042B1F0-0042B420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042B1F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc (ends 0x0042ACD0) and nellymoser_wrapper.c; network session state.
 */

#include "types.h"

extern int D_00494178;
extern int D_00494180;
extern int D_00494198;
extern char D_00497540;
extern int D_005721A8;
extern char D_005721B8;
extern char D_005721C0;
extern char D_005721D0;
extern char D_005721D8;
extern char D_005723B8;
extern int D_005723F0;
extern char D_005723F8;
extern char D_00572400;
extern char D_00572408;
extern char D_00572410;
extern char D_00572418;
extern char D_00572419;
extern char D_0057241A;
extern char D_0057241B;
extern int D_00572428;
extern int D_0057242C;
extern int D_00572430;
extern char D_00572468;
extern void Net_ResetSession(void);
extern int NetFreeAllObjects(void);
extern int NetLeave(int);
extern int NetDisconnect(int);
extern int cHeadSet_ShutdownAudio(void);

void Net_CleanupGame(void) {
    D_00497540 = 1;
    cHeadSet_ShutdownAudio();
    NetLeave(0);
    NetDisconnect(0);
    Net_ResetSession();
}

/* Clears the session flags and ids back to their defaults. */
void Net_ResetSession(void) {
    D_005721D8 = 0;
    D_005723B8 = 0;
    D_005721A8 = -1;
    D_00494180 = 4;
    D_00494178 = -1;
    D_00494198 = -1;
    D_005721C0 = 0;
    D_00572410 = 0;
    D_005723F0 = 0;
    D_00572418 = 0;
    D_00572419 = 0;
    D_0057241A = 0;
    D_0057241B = 0;
    D_00572468 = 0;
    D_00572428 = 0;
    D_0057242C = 0;
    D_00572430 = 0;
}

int cDME_Restart(void) {
    int ret;

    D_005721D0 = 0;
    D_005723F8 = 0;
    D_00572408 = 1;
    D_00572400 = 0;
    D_00497540 = 0;
    ret = NetFreeAllObjects();
    D_005721B8 = 1;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B1F0 */

/* merge_units: begin func_0042B320 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct NetworkPeerSamples {
    unsigned int values[20];
} NetworkPeerSamples;

extern "C" {
extern NetworkPeerSamples D_00572270[];
int PlayerSlots_Get(void);
}

/* Average nonzero peer samples and cap the result with the retail NaN behavior. */
extern "C" float cDME_GetConnectionStatus(int peer)
{
    float sum = 0.0f;
    int count = 0;
    if (!PlayerSlots_Get())
        return sum;
    for (int index = 0; index < 20; ++index) {
        unsigned int value = D_00572270[peer].values[index];
        if (value) {
            ++count;
            sum += (float)value;
        }
    }
    float result = (sum / (float)count) / 6144.0f;
    if (!(result <= 1.0f))
        result = 1.0f;
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B320 */

/* merge_units: begin func_0042B420 */
#pragma push /* merge_units */
typedef struct NetSessCfg_r8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* cb2C;
    int unk30;
    void* cb34;
    int pad[7];
} NetSessCfg_r8;
extern void cHeadSet_AudioRecordCallback(void);
extern void cHeadSet_AudioPlayCallback(void);
static inline void MemClear_r8(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a2, dst, 0xF
        andi $a1, n, 0xF
        or $a2, $a2, $a1
        nop
        bgtz $a2, bytes
        srl $a1, n, 4
        nop
        blez $a1, bytes
        nop
        nop
    quads:
        addi $a1, $a1, -1
        sq $zero, 0(dst)
        bgtz $a1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
void func_0042B420(NetSessCfg_r8* sess)
{
    MemClear_r8(sess, 0x54);
    sess->unk10 = 1;
    sess->unk04 = 1;
    sess->unk0C = 1;
    sess->cb34 = cHeadSet_AudioPlayCallback;
    sess->cb2C = cHeadSet_AudioRecordCallback;
    sess->unk08 = 2;
    sess->unk14 = 1;
    sess->unk20 = 2;
    sess->unk18 = 0x10;
    sess->unk24 = 0x10;
    sess->unk1C = 0x1F40;
    sess->unk28 = 0x1F40;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B420 */
