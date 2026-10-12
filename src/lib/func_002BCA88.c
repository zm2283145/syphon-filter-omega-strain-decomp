extern void func_002BC960(void);
extern void func_002BCA38(void);
extern void func_002BCA68(void);
extern void func_002BC828(void);
extern int func_0027C410(void*,void*,int,int);
extern char D_0051DCC0[];
int func_002BCA88(int arg) {
 struct {int v; void (*a)(void),(*b)(void),(*c)(void);} callbacks;
 callbacks.v=1;
 callbacks.a=func_002BC960;
 callbacks.b=func_002BCA38;
 callbacks.c=func_002BCA68;
 func_002BC828();
 return func_0027C410(&callbacks,D_0051DCC0,0x1000,arg);
}


