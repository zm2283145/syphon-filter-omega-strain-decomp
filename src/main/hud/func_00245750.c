#include "types.h"
#pragma mpwc_relax on
int Event_Construct(char **, char *);
int NetRead_Float(float *);
int func_00281E90(char *, int);
int Loc_LookupText(char *);
int func_0012F2C0(char *);
void func_00245800(int, int, float);
int cMessage_dtor(char **, int);
extern char D_004DC310;
extern char D_004DCF10;
extern char D_004F7DC0;
extern char D_004FFB50;

void func_00245750(void) {
    struct { char * f40[9]; float f; char s[16]; } sl;
    int text;

    Event_Construct(sl.f40, &D_004F7DC0);
    sl.f40[0] = &D_004DC310;
    sl.s[0] = 0;
    NetRead_Float(&sl.f);
    func_00281E90(sl.s, 16);
    text = sl.s[0] ? Loc_LookupText(sl.s) : 0;
    func_00245800(func_0012F2C0(&D_004FFB50), text, sl.f);
    sl.f40[0] = &D_004DCF10;
    cMessage_dtor(sl.f40, 0);
}
