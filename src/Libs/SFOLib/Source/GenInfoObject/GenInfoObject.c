/*
 * main/GenInfoObject: 2 files, 00438AE0-00438C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00438AE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int id; unsigned int a : 4; unsigned int b : 4; } T_438AE0;
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm_38AE0;
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm_38AE0* prm);
extern int NetRegisterStructure(int* table, char* name, int size);
extern int NetRegisterRemoteObjectCallback(int table, void* a, void* b, void* c);
extern int D_00497570;
extern void cGenInfoObject_GenInfoCreationCallback();
extern void func_00439390();
extern void cGenInfoObject_GenInfoDeleteCallback();

static inline void Reset_38AE0(T_438AE0* r)
{
    r->id = -1;
    r->a = 15;
    r->b = 0;
}

unsigned char cGenInfoObject_InitNet(void)
{
    int db;
    Prm_38AE0 prm;
    T_438AE0 arr[55];
    unsigned char ok = 0;
    T_438AE0* p;
    int i;
    int err;
    p = arr;
    do { Reset_38AE0(p); p++; } while (p != arr + 55);
    prm.flags = 0;
    prm.max = 500;
    prm.ver = 1;
    prm.mode = 0x40;
    if (NetRegisterObjectStart() == 0) {
        T_438AE0* q = arr;
        T_438AE0* base = q;
        for (i = 0; i < 55; i++, q++)
            err = NetObjectField(&db, (char*)q - (char*)base, 1, 1, 8, &prm);
        if (err == 0 && NetRegisterStructure(&D_00497570, "tGenInfoStruct", 0x1B8) == 0) {
            NetRegisterRemoteObjectCallback(D_00497570, cGenInfoObject_GenInfoCreationCallback, func_00439390, cGenInfoObject_GenInfoDeleteCallback);
            ok = 1;
        }
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_00438AE0 */

/* merge_units: begin func_00438C20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_00583880;
extern int D_00583888;

void cGenInfoObject_GenInfoDeleteCallback(void) {
    D_00583888 = 0;
    D_00583880 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00438C20 */
