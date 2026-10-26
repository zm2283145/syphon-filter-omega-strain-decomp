extern void my_open(void);
extern void my_read(void);
extern void my_close(void);
extern void initialize_mc2_socket(void);
extern int sceNetcnfifCreateCallbackThread(void*,void*,int,int);
extern char D_0051DCC0[];
int sceNetcnfifCreateMc2Thread(int arg) {
 struct {int v; void (*a)(void),(*b)(void),(*c)(void);} callbacks;
 callbacks.v=1;
 callbacks.a=my_open;
 callbacks.b=my_read;
 callbacks.c=my_close;
 initialize_mc2_socket();
 return sceNetcnfifCreateCallbackThread(&callbacks,D_0051DCC0,0x1000,arg);
}


