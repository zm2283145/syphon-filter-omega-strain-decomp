typedef struct Self { char pad[0x120]; int handle; } Self;
extern void* D_004FFC04;
extern char D_004AABF0[];
extern void* func_004294C0(Self*);
extern void func_0029DE70(Self*, int);
extern int func_0033CE30(Self*, int, int, int, int, int);
extern int FrontEnd_OpenPopup(void*, int, char*, int, int, int);
extern void FrontEnd_ClosePopup(void*, int);
extern void func_002CA350(void*);
extern void func_00445570(void*);
extern int func_004456D0(void*);
extern void func_004456C0(void*);
int func_0029D020(Self* self)
{
    void* r = func_004294C0(self);
    void* g;
    int h;
    if (r == 0) {
        func_0029DE70(self, 1);
        return 0;
    }
    g = D_004FFC04;
    h = FrontEnd_OpenPopup(g, 0, D_004AABF0, func_0033CE30(self, 0xD, 0, 0, 0, 0), 0, 0);
    if (self->handle != -1) FrontEnd_ClosePopup(D_004FFC04, self->handle);
    func_002CA350(D_004FFC04);
    func_00445570(r);
    if (func_004456D0(r)) func_004456C0(r);
    FrontEnd_ClosePopup(D_004FFC04, h);
    return 1;
}
