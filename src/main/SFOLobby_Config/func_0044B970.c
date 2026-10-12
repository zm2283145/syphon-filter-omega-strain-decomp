#include "types.h"
extern unsigned char D_00585E68;
extern int sprintf(char*, const char*, ...);
extern char* strchr(const char*, int);
extern int strlen(const char*);
extern void func_0012B220(char*);
extern void sceCdInit(int);
extern void func_0010F6E0(void);
extern int func_00169920(void);
extern void func_00116800(char*, int, char**);
void func_0044B970(char* name, char* arg) {
    char buf[0x100];
    char* argv[2];
    int argc;
    unsigned char has;
    if (D_00585E68) sprintf(buf, "cdrom0:\\%s;1", name);
    else sprintf(buf, "host0:%s", name);
    func_0012B220(strchr(buf, ':'));
    sceCdInit(5);
    func_0010F6E0();
    argv[0] = buf;
    argv[1] = arg;
    has = arg && strlen(arg);
    argc = has + 1;
    if (D_00585E68) {
        if (func_00169920()) func_00116800("cdrom0:\\NETGUI\\NTGUI2CN.ELF;1", argc, argv);
        else func_00116800("cdrom0:\\NETGUI\\NTGUI2CP.ELF;1", argc, argv);
    } else {
        if (func_00169920()) func_00116800("host0:NETGUI/NTGUI2HN.ELF", argc, argv);
        else func_00116800("host0:NETGUI/NTGUI2HP.ELF", argc, argv);
    }
}
