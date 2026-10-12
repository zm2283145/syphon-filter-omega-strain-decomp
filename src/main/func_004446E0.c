#include "types.h"
typedef struct { char name[0x14]; int ver; char data[0xFC]; char pad[0x118 - 0x114]; } Msg46A9;
typedef struct { char pad[0x26A0]; unsigned char dirty; } Mgr6E0;
extern int D_004976D8;
extern char D_005723B8;
extern char D_00584220[];
extern unsigned char D_00584231;
extern unsigned char D_00584240;
extern unsigned char D_005842C8;
extern int D_005842CC;
extern int D_005842D0;
extern int D_005842D4;
extern int D_005842D8;
extern char D_00584378[];
extern short D_0058438E;
extern short D_00584390;
extern char D_00584398[];
extern int D_005843AC;
extern int D_005843B0;
extern char D_005843F4[];
extern int D_00584508;
extern int D_00584514;
extern int D_00584520;
extern Mgr6E0* D_00585E60;
extern char D_00585E70[];
extern int D_00585E80;
extern char D_00585E90[];
int MGCLUpdate(void);
void String_Copy(char*, char*);
int func_002D0560(char*);
void func_002EBC48(int*);
void func_002EBCE0(int*);
int func_002EBEC8(int*, int);
int func_003A6BC0(void);
void func_004536B0(Mgr6E0*);
int func_00453F30(int);
void func_0046A998(Msg46A9*);
void func_0046AA18(char*);
void* memcpy(void*, const void*, unsigned int);
void* memset(void*, int, unsigned int);

int func_004446E0(int update)
{
    int status;
    int now;
    int tmp;
    Msg46A9 msg;
    int ret;

    now = 0;
    func_002EBC48(&now);
    if (D_005842C8) {
        D_00585E80 = (now - D_005842CC) / 1000;
    }
    if (update && now >= D_005842D4 + 15000) {
        D_005842D4 = now;
        memset(&msg, 0, sizeof(msg));
        String_Copy(msg.name, D_00584220);
        msg.ver = D_004976D8;
        memcpy(msg.data, D_00585E90, sizeof(msg.data));
        func_0046A998(&msg);
    }
    if (!D_00584231) {
        return -6;
    }
    if (D_00584240 && now >= D_005842D0 + 15000) {
        D_005842D0 = now;
        if (func_002EBEC8(&status, D_00584520) == 0 && status >= 0) {
            D_00584390 = status;
            D_0058438E = 1;
            func_002EBCE0(&tmp);
            ret = func_002D0560(D_00584378);
            if (ret) {
                return ret;
            }
        }
    }
    if (update && D_00584240) {
        unsigned char* dirty = &D_00585E60->dirty;
        if (*dirty || now >= D_005842D8 + 15000) {
            D_005842D8 = now;
            *dirty = 0;
            if (func_002EBEC8(&status, D_00584520)) {
                status = 1;
            }
            D_005843B0 = status;
            String_Copy(D_00584398, D_00584220);
            D_005843AC = D_004976D8;
            D_00584514 = func_003A6BC0() ? 1 : 3;
            D_00584508 = *(volatile int*)&D_00584514;
            memcpy(D_005843F4, D_00585E70, 0x18);
            func_0046AA18(D_00584398);
        }
    }
    ret = MGCLUpdate();
    if (ret == 0) {
        if (!update) {
            func_004536B0(D_00585E60);
        }
    } else if (func_00453F30(2) == 0) {
        D_005723B8 = 1;
    }
    return ret;
}

