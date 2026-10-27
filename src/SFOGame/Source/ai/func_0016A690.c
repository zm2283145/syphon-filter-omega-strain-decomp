#include "types.h"

typedef struct { int priority; int count; int flags; unsigned char attr; } ThreadParams;
extern int D_004EE610;
extern int NetRegisterObjectStart(int a);
extern int NetObjectField(int* out, int a, int b, int c, int size, ThreadParams* params);
extern int NetRegisterStructure(int* out, const char* name, int size);
extern int NetRegisterRemoteObjectCallback(int handle, void* f1, void* f2, void* f3);
extern void cTeam_TeamCreationCallback(void);
extern void cTeam_TeamUpdateCallback(void);
extern void cTeam_TeamDeleteCallback(void);

/* Initialises the service: creates its worker and handle and installs the callbacks; returns 1 on success. */
unsigned char cTeam_InitNet(int a)
{
    unsigned char result;
    ThreadParams params;
    int handle;
    int worker;
    params.priority = 100;
    result = 0;
    params.flags = 0;
    params.count = 1;
    params.attr = 0x40;
    if (NetRegisterObjectStart(a) == 0 &&
        NetObjectField(&worker, 0, 1, 1, 0x100, &params) == 0 &&
        NetRegisterStructure(&handle, "cTeamDataStruct", 0x100) == 0 &&
        NetRegisterRemoteObjectCallback(handle, cTeam_TeamCreationCallback, cTeam_TeamUpdateCallback, cTeam_TeamDeleteCallback) == 0) {
        result = 1;
        D_004EE610 = handle;
    }
    return result;
}
