#include "types.h"
extern char* strncpy(char*, const char*, int);
int MGCLGetMGCLVersion(char* dst) {
    strncpy(dst, "Medius Game Communication Library Version 1.50.0000", 0x40);
    return 0;
}