extern char D_00506198[];
extern char D_00506150[];
extern char D_00505140[];
extern void func_0010FBC0(int);
extern int func_0010D050(void);
extern void func_00110760(void *, int);
extern void func_001107F8(void *, unsigned int, void *, void *, void *, void *, void *);
extern void func_00110C10(void *);
extern void func_0027D078(void);

void func_0027D160(void)
{
    func_0010FBC0(0);
    func_00110760(D_00506198, func_0010D050());
    func_001107F8(D_00506150, 0x80001101, func_0027D078, D_00505140, 0, 0, D_00506198);
    func_00110C10(D_00506198);
}