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
extern int func_002E9A10(void* stream);
extern int func_002E9A98(SaveHeader* hdr, void* dst, int size, int count);
extern int func_002E9F08(int* out, void (*cb)(void));
extern void func_002C7630(void);

/* Reads the save header fields in order; returns the first error, or 0. */
int func_002C7460(void* stream)
{
    SaveHeader hdr;
    int handle;
    int err;
    hdr.vtable = D_004DE158;
    err = func_002E9A10(stream);
    if (err == 0) {
        err = func_002E9A98(&hdr, &hdr.version, 4, 1);
        if (err == 0) {
            err = func_002E9A98(&hdr, hdr.ids, 4, 6);
            if (err == 0) {
                err = func_002E9A98(&hdr, hdr.name, 1, 0x20);
                if (err == 0) {
                    err = func_002E9A98(&hdr, &hdr.count, 2, 1);
                    if (err == 0) {
                        err = func_002E9A98(&hdr, hdr.values, 2, 6);
                        if (err == 0) {
                            err = func_002E9A98(&hdr, &hdr.flagA, 1, 1);
                            if (err == 0) {
                                err = func_002E9A98(&hdr, &hdr.flagB, 1, 1);
                                if (err == 0) {
                                    err = func_002E9F08(&handle, func_002C7630);
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
