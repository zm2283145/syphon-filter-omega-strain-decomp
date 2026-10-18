/*
 * main/NPCInfoObject: range (2 files, 00434740-00434AA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "NetObjectMgr_types.h"
#include "types.h"

/* merge_units: begin func_00434740 */
#pragma push /* merge_units */
extern unsigned int D_00582B60;
extern unsigned int D_00582B68;
extern unsigned int D_00582B70;
extern unsigned int D_00582B78;
extern unsigned int D_00582B80;
extern unsigned char D_005827C8;
extern unsigned char D_005827D0;
extern unsigned char D_005827D8;
extern unsigned char D_005827E0;
extern unsigned char D_005827E8;
extern void* D_00582A78;
extern void* D_00582A80;
extern void* D_00582A88;
extern void* D_00582A90;
extern void* D_00582A98;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern int D_00494178;

extern unsigned int Net_GetClock(int clock);
extern int func_002EC3C8(void* key);
extern int func_002EB650(NetSessionEntry** entry, void* key);
extern int NetGame_InitLocalSlot(int* id, int session);
extern void func_00432230(int peer, void* key, int mode);

static inline void service_slot(unsigned int* deadline, unsigned char* pending,
                                void** key, unsigned int interval)
{
    unsigned int previous = *deadline;
    if (previous < Net_GetClock(1)) {
        if (*pending && !func_002EC3C8(*key))
            *pending = 0;
        *deadline = Net_GetClock(1) + interval;
    }
}

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1)
            NetGame_InitLocalSlot(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

/* Service five pending NPC requests on their independent polling intervals. */
void func_00434740(void)
{
    service_slot(&D_00582B60, &D_005827C8, &D_00582A78, 120);
    service_slot(&D_00582B68, &D_005827D0, &D_00582A80, 150);
    service_slot(&D_00582B70, &D_005827D8, &D_00582A88, 180);
    service_slot(&D_00582B78, &D_005827E0, &D_00582A90, 210);
    service_slot(&D_00582B80, &D_005827E8, &D_00582A98, 240);
}

/* Queue a remote-peer request by key, or process a local/missing entry directly. */
void func_00434920(void* unused, void* key)
{
    NetSessionEntry* entry;
    func_002EB650(&entry, key);
    if (entry && entry->id != current_peer()) {
        if (key == D_00582A78)
            D_005827C8 = 1;
        else if (key == D_00582A80)
            D_005827D0 = 1;
        else if (key == D_00582A88)
            D_005827D8 = 1;
        else if (key == D_00582A90)
            D_005827E0 = 1;
        else if (key == D_00582A98)
            D_005827E8 = 1;
    } else {
        func_00432230(current_peer(), key, -2);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434740 */

/* merge_units: begin func_00434AA0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_00434BB0(char *, void **);                      
extern char D_004BFCA0;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_00582AF0;

void func_00434AA0(int d0, char * arg1) {
    char * sp3C;
    char * temp_s0;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x14, &D_004BFCA0, 0x30B);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp3C = temp_s0;
    func_00434BB0(&D_00582AF0, &sp3C);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434AA0 */
