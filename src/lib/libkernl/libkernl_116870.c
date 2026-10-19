#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int ExecOSD(int, char*);                          
int func_00116670(int *, int, int);                       
void func_00116788();                                  
extern char *D_004865E0;
extern int D_00498C30;

void func_00116870(int arg0, int arg1) {
    func_00116670(&D_00498C30, arg0, arg1);
    func_00116788();
    ExecOSD(arg0, D_004865E0 + 4);
}
