#include "types.h"
typedef struct {
    char pad[0x188];
    int f188;
    int f18C;
    char p190[0xA0];
    unsigned char f230;
    unsigned char f231;
    unsigned char f232;
    unsigned char f233;
    unsigned char f234;
    unsigned char f235;
    unsigned char f236;
} Ply3F8000;
typedef struct { char pad[8]; int f8; } Hdr3F8000;
typedef struct { char pad[0x50008]; int f50008; } Buf3F8000;
extern char D_0055C460[];
extern char D_0055C480[];
extern char D_0055C540[];
int func_0010A3B0(Hdr3F8000* h, int p, int n, Buf3F8000* b, int x);
void func_0010D010(int n);
void func_003F5CD0(char* p, int n);
void func_003F5CF0(char* p);
int func_003F6000(char* p);
void func_003F6A20(char* p);
int func_003F6A90(char* p);
void func_003F6D20(char* p);
void func_003F6DC0(char* p);
void func_003F6E60(char* p);
void func_003F6F90(void);
void func_003F6FA0(int n);
void func_003F76C0(Buf3F8000* b, int n);
int func_003F7710(Buf3F8000* b, int* out);
void func_003F7770(Buf3F8000* b, int n);
int func_003F77F0(Buf3F8000* b, int* out);
int func_003F7870(void* s, int p, int n);
void func_003F8000(Ply3F8000* self, Hdr3F8000* hdr, Buf3F8000* buf, void* strm)
{
    int p1;
    int p2;
    int n;
    if (self->f18C > 0x800) {
        if (hdr->f8 > 10) {
            if (self->f232) {
                func_003F6F90();
                if (self->f236) func_003F6E60(D_0055C540);
                self->f232 = 0;
                self->f231 = 1;
            }
            if (self->f233) {
                func_003F6FA0(1);
                if (self->f236) func_003F6DC0(D_0055C540);
                self->f233 = 0;
                self->f231 = 0;
            }
            if (self->f235) func_003F5CF0(D_0055C480);
        }
        n = func_003F77F0(buf, &p1);
        if (self->f188 > 0 && n >= 0x10000) {
            n = func_003F7870(strm, p1, 0x10000);
            func_003F7770(buf, n);
            self->f188 -= n;
        }
        func_0010D010(5);
        n = func_003F7710(buf, &p2);
        if (n > 0) {
            n = func_0010A3B0(hdr, p2, n, buf, buf->f50008);
            func_003F76C0(buf, n);
            self->f18C -= n;
        }
        func_003F6A20(D_0055C540);
        if (!self->f230 && func_003F6000(D_0055C460)) {
            int ok = self->f236 ? func_003F6A90(D_0055C540) : 1;
            if (ok) {
                func_003F6FA0(1);
                if (self->f236) func_003F6D20(D_0055C540);
                self->f230 = 1;
            }
        }
    } else {
        func_003F5CD0(D_0055C480, 3);
    }
}

