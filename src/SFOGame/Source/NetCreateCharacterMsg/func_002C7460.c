#include "types.h"

typedef struct {
    void* vtable;
    int version;
    int ids[6];
    short values[6];
    char name[0x20];
    unsigned char flagA;
    unsigned char flagB;
    short count;
    char pad60[0xC];
} SaveHeader;
extern char D_004DE158[];
extern int D_0051EE78;
extern int NetRegisterMessageStart(void* stream);
extern int NetMessageField(SaveHeader* hdr, void* dst, int size, int count);
extern int NetRegisterApplicationMessage(int* out, void (*cb)(void));
extern void netCreateNPC_netCreateNPCCallback(void);

/* Reads the save header fields in order; returns the first error, or 0. */
int netCreateNPC_InitNet(void* stream)
{
    SaveHeader hdr;
    int handle;
    int err;
    hdr.vtable = D_004DE158;
    err = NetRegisterMessageStart(stream);
    if (err == 0) {
        err = NetMessageField(&hdr, &hdr.version, 4, 1);
        if (err == 0) {
            err = NetMessageField(&hdr, hdr.ids, 4, 6);
            if (err == 0) {
                err = NetMessageField(&hdr, hdr.name, 1, 0x20);
                if (err == 0) {
                    err = NetMessageField(&hdr, &hdr.count, 2, 1);
                    if (err == 0) {
                        err = NetMessageField(&hdr, hdr.values, 2, 6);
                        if (err == 0) {
                            err = NetMessageField(&hdr, &hdr.flagA, 1, 1);
                            if (err == 0) {
                                err = NetMessageField(&hdr, &hdr.flagB, 1, 1);
                                if (err == 0) {
                                    err = NetRegisterApplicationMessage(&handle, netCreateNPC_netCreateNPCCallback);
                                    if (err == 0) {
                                        D_0051EE78 = handle;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return err;
}
