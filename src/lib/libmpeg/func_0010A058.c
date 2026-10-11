#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00109F50(int, int);                               
int func_00109F70(int, int);                            

int func_0010A058(int arg0) {
    int temp_s1;

    temp_s1 = func_00109F50(arg0, 1);
    func_00109F70(arg0, 1);
    return temp_s1;
}
