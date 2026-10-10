#include "NetObjectMgr_types.h"

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

extern unsigned int func_0042B1A0(int clock);
extern int func_002EC3C8(void* key);
extern int func_002EB650(NetSessionEntry** entry, void* key);
extern int func_002EBAF8(int* id, int session);
extern void func_00432230(int peer, void* key, int mode);

static inline void service_slot(unsigned int* deadline, unsigned char* pending,
                                void** key, unsigned int interval)
{
    unsigned int previous = *deadline;
    if (previous < func_0042B1A0(1)) {
        if (*pending && !func_002EC3C8(*key))
            *pending = 0;
        *deadline = func_0042B1A0(1) + interval;
    }
}

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1)
            func_002EBAF8(&D_00494178, session);
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
