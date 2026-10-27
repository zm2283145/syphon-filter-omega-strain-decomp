/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00357150(int);
extern int func_00357178(int);
extern int sceInsockInetAddr(void);
extern int sceInsockInetAton(int, int);
extern int sceInsockInetLnaof(void);
extern int sceInsockInetMakeaddr(int, int);
extern int sceInsockInetNetof(void);
extern int sceInsockInetNetwork(int);
extern int sceInsockInetNtoa(int);
extern int sceInsockTerminate(int);
extern int sceInsockBind(int, int, int);
extern int sceInsockConnect(int, int, int);
extern int sceInsockAccept(int, int, int);
extern int sceInsockGethostbyname(int);
extern int sceInsockGethostbyaddr(int, int, int);

int sceNetGlueThreadInit(void) {
    return 0;
}

int sceNetGlueThreadTerminate(int a0) {
    int tmp0;

    tmp0 = sceInsockTerminate(a0);
    return tmp0;
}

int sceNetGlueGethostbyaddr(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceInsockGethostbyaddr(a0, a1, a2);
    return tmp0;
}

int sceNetGlueGethostbyname(int a0) {
    int tmp0;

    tmp0 = sceInsockGethostbyname(a0);
    return tmp0;
}

int sceNetGlueInetAddr(void) {
    int tmp0;

    tmp0 = sceInsockInetAddr();
    return tmp0;
}

int sceNetGlueInetAton(int a0, int a1) {
    int tmp0;

    tmp0 = sceInsockInetAton(a0, a1);
    return tmp0;
}

int sceNetGlueInetLnaof(void) {
    int tmp0;

    tmp0 = sceInsockInetLnaof();
    return tmp0;
}

int sceNetGlueInetMakeaddr(int a0, int a1) {
    int tmp0;

    tmp0 = sceInsockInetMakeaddr(a0, a1);
    return tmp0;
}

int sceNetGlueInetNetof(void) {
    int tmp0;

    tmp0 = sceInsockInetNetof();
    return tmp0;
}

int sceNetGlueInetNetwork(int a0) {
    int tmp0;

    tmp0 = sceInsockInetNetwork(a0);
    return tmp0;
}

int sceNetGlueInetNtoa(int a0) {
    int tmp0;

    tmp0 = sceInsockInetNtoa(a0);
    return tmp0;
}

int sceNetGlueHtonl(int a0) {
    int tmp0;

    tmp0 = func_00357150(a0);
    return tmp0;
}

int sceNetGlueHtons(int a0) {
    int tmp0;

    tmp0 = func_00357178((a0 & 65535));
    return tmp0;
}

int sceNetGlueNtohl(int a0) {
    int tmp0;

    tmp0 = func_00357150(a0);
    return tmp0;
}

int sceNetGlueNtohs(int a0) {
    int tmp0;

    tmp0 = func_00357178((a0 & 65535));
    return tmp0;
}

int sceNetGlueAccept(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceInsockAccept(a0, a1, a2);
    return tmp0;
}

int sceNetGlueBind(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceInsockBind(a0, a1, a2);
    return tmp0;
}

int sceNetGlueConnect(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceInsockConnect(a0, a1, a2);
    return tmp0;
}
