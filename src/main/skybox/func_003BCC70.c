#include "types.h"
typedef struct { int a[0x28]; } H3BC;
typedef struct { char pad[0x14C]; unsigned char b14c; } T3BC;
typedef struct { int a; char name[0x94]; T3BC* f98; } S3BC;
typedef struct { char pad[0x16C]; int f16c; unsigned char b170; char p171[3]; char f174[0x3C]; float m[24]; } O3BC;
extern void func_0036D630(O3BC*);
extern void func_00377C30(char*);
extern void func_0036DEF0(S3BC*);
extern void func_0036D990(S3BC*, int*, int);
extern void func_0036D540(O3BC*, char*, int, int);
extern char* strchr(const char*, int);
extern char* strncpy(char*, const char*, int);
extern void func_0036E540(H3BC*, char*, O3BC*, int);
extern void Model_Load(char*, H3BC*, int);
extern void func_0036E220(H3BC*, int);
O3BC* func_003BCC70(O3BC* o, S3BC* src, int arg) {
    H3BC h;
    func_0036D630(o);
    o->f16c = 0;
    func_00377C30(o->f174);
    o->m[0] = 0.0f; o->m[1] = 0.0f; o->m[2] = 0.0f; o->m[3] = 0.0f;
    o->m[4] = 0.0f; o->m[5] = 0.0f; o->m[6] = 0.0f; o->m[7] = 0.0f;
    o->m[8] = 0.0f; o->m[9] = 0.0f; o->m[10] = 0.0f; o->m[11] = 0.0f;
    o->m[12] = 0.0f; o->m[13] = 0.0f; o->m[14] = 0.0f; o->m[15] = 1.0f;
    o->m[16] = 0.0f; o->m[17] = 0.0f; o->m[18] = 0.0f; o->m[19] = 0.0f;
    o->m[20] = 0.0f; o->m[21] = 0.0f; o->m[22] = 0.0f; o->m[23] = 0.0f;
    func_0036DEF0(src);
    func_0036D990(src, &o->f16c, 0);
    if (src->f98->b14c == 2) o->b170 = 1;
    else o->b170 = 0;
    func_0036D540(o, src->name, o->f16c, 0);
    {
        char* name = src->name;
        strncpy(strchr(name, '.'), ".VUM", 4);
        func_0036E540(&h, name, o, 0);
    }
    Model_Load(o->f174, &h, arg);
    func_0036E220(&h, -1);
    return o;
}
