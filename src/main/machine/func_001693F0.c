#include "types.h"
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004FFB50[];
extern void func_0042A770(void);
extern void func_0016A970(void);
extern void World_Setup(void* w);
extern void func_0042A1B0(void);
extern void func_0042B0C0(void);
extern void func_00185840(void);
extern void NetObj_LoadNetworkData(void);
extern void func_00429D30(void);
static inline int IsHostGR(void)
{
    if (D_005721C8) return D_005721C0;
    return 1;
}
void Game_Reset(void)
{
    if (D_005721C8) func_0042A770();
    func_0016A970();
    World_Setup(D_004FFB50);
    if (D_005721C8) {
        func_0042A1B0();
        func_0042B0C0();
        if (!IsHostGR()) {
            func_00185840();
            NetObj_LoadNetworkData();
        } else {
            func_0016A970();
        }
    }
    if (D_005721C8) func_00429D30();
}