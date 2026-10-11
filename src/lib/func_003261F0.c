extern int func_003260F0(void);
extern void func_0010D210(unsigned int *cfg);
#define SCF_CFG_GET(name, override, expr) extern unsigned char override; int name(void) { unsigned int cfg; if (func_003260F0() == 0) { func_0010D210(&cfg); return expr; } return override; }

SCF_CFG_GET(func_003261F0, D_004914A5, cfg & 1)
