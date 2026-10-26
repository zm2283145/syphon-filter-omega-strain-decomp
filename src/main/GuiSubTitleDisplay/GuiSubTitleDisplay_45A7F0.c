#include "types.h"
extern int D_004979A8;
extern char* D_004E1B04;
extern char D_004C1FF0[];
extern char D_004C2008[];
extern char D_004C2010[];
extern char D_1E68000[];
extern char D_1FE8000[];
extern int cMemMan_HaveAllocationInRange(void*, void*);
extern void* memset(void*, int, unsigned int);
extern int sprintf(char*, const char*, ...);
extern int mwLoadOverlay(const char*, char*);

int Overlay_Load(int id)
{
    char path[256];
    char* buf;
    char* start;
    int size;

    if (D_004979A8 == id) {
        return 1;
    }
    D_004979A8 = id;
    switch (id) {
    case 1:
        return 1;
    case 2:
        buf = D_004E1B04;
        if (buf == 0) {
            return 0;
        }
        start = D_1E68000;
        size = D_1FE8000 - start;
        if (cMemMan_HaveAllocationInRange(start, D_1FE8000)) {
            return 0;
        }
        memset(start, 0, size);
        sprintf(path, D_004C1FF0, D_004C2008, D_004C2010);
        if (!mwLoadOverlay(path, buf)) {
            return 0;
        }
        break;
    }
    return 1;
}

