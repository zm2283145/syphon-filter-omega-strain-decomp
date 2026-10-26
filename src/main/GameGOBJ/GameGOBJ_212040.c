/*
 * main/GameGOBJ: range (2 files, 00212040-002120D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00212040 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Object_LookupById(int *);
int NetGetObject(void **);
extern unsigned char D_005723C8;
#define CLR_(b, o) { (void)*(volatile int*)((char*)(b) + (o)); F_(b, o, int) = 0; }
#pragma push
#pragma opt_common_subs off
void func_00212040(void) {
    struct { char pad[0x14]; int id[1]; int buf[2]; } sl;
    int temp_v0;
    int temp_v0_2;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (NetGetObject((void**)sl.buf) == 0) {
        temp_v0 = F_(sl.buf[0], 0x1C, int);
        sl.id[0] = F_(temp_v0, 0x10, unsigned short) | (F_(temp_v0, 0xE, unsigned short) << 0x10);
        temp_v0_2 = Object_LookupById(sl.id);
        if (temp_v0_2 != 0) {
            CLR_(temp_v0_2, 0xD0);
            CLR_(temp_v0_2, 0x128);
        }
    }
    D_005723C8 = 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00212040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00212040 */

/* merge_units: begin func_002120D0 */
#pragma push /* merge_units */
typedef struct { int priority; int count; int flags; unsigned char attr; } Prm_002120D0;
typedef struct { int x0; int x4; char pad8[4]; unsigned char xC; char padD[0x20 - 0xD]; int x20; int x24; int x28; int x2C; } Rec_002120D0;
extern int D_004F5478;
extern char D_004A4580[];
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* out, int off, int size, int count, int type, Prm_002120D0* prm);
extern int NetRegisterStructure(int* out, const char* name, int size);
extern int NetRegisterRemoteObjectCallback(int handle, void* f1, void* f2, void* f3);
extern unsigned char cPathedGOBJ_RegisterPathedGobj(Rec_002120D0* r);
extern void cElevatorGOBJ_ElevatorCreationCallback(void);
extern void cElevatorGOBJ_ElevatorUpdateCallback(void);
extern void func_00212040(void);
void NetElevatorInfo_NetRegister(void)
{
    int db;
    int handle;
    Prm_002120D0 prm;
    Rec_002120D0 rec;
    Rec_002120D0* r;
    int* p24 = &rec.x24;
    int* p2C = &rec.x2C;
    rec.x0 = 0;
    rec.x4 = 0;
    rec.xC = 0;
    rec.x20 = 0;
    *p24 = 0;
    rec.x28 = 0;
    *p2C = 0;
    prm.priority = 500;
    prm.count = 1;
    prm.attr = 0x40;
    prm.flags = 0;
    if (NetRegisterObjectStart() == 0 &&
        cPathedGOBJ_RegisterPathedGobj(&rec) &&
        (r = &rec, NetObjectField(&db, (char*)&rec.x20 - (char*)r, 4, 4, 1, &prm) == 0) &&
        NetObjectField(&db, (char*)p24 - (char*)r, 4, 4, 1, &prm) == 0 &&
        NetObjectField(&db, (char*)p2C - (char*)r, 4, 4, 1, &prm) == 0 &&
        NetRegisterStructure(&handle, D_004A4580, 0x30) == 0) {
        D_004F5478 = handle;
        NetRegisterRemoteObjectCallback(handle, cElevatorGOBJ_ElevatorCreationCallback, cElevatorGOBJ_ElevatorUpdateCallback, func_00212040);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002120D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002120D0 */
