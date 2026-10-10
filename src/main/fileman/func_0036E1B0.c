#include "types.h"
typedef struct {
    unsigned int flags;
    char name[0x94];
    int f98;
} Hog_36E1B0;
extern char* strncpy(char* d, const char* s, unsigned int n);
int Hog_Register(Hog_36E1B0* h, const char* name, int arg, int opt) {
    h->flags = 0;
    strncpy(h->name, name, 0x80);
    h->f98 = arg;
    h->flags |= 2;
    if (opt)
        h->flags |= 4;
    return 0;
}