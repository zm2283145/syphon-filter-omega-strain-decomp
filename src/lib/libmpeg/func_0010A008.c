#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int _sysbitNext();                                
int _sysbitFlush(int, int);                            

int _sysbitGet(int arg0, int arg1) {
    int temp_s2;

    temp_s2 = _sysbitNext();
    _sysbitFlush(arg0, arg1);
    return temp_s2;
}
