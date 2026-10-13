extern int AddIntcHandler(int, void (*)(), int);
extern void func_002FA480(int, int, void *);
extern void func_002FA478();
int func_002FA2D8(void *arg)
{
    if (arg == 0) return 2;
    func_002FA480(0, AddIntcHandler(0, func_002FA478, -1), arg);
    func_002FA480(1, AddIntcHandler(1, func_002FA478, -1), arg);
    func_002FA480(2, AddIntcHandler(2, func_002FA478, -1), arg);
    func_002FA480(3, AddIntcHandler(3, func_002FA478, -1), arg);
    func_002FA480(4, AddIntcHandler(4, func_002FA478, -1), arg);
    func_002FA480(5, AddIntcHandler(5, func_002FA478, -1), arg);
    func_002FA480(6, AddIntcHandler(6, func_002FA478, -1), arg);
    func_002FA480(7, AddIntcHandler(7, func_002FA478, -1), arg);
    func_002FA480(8, AddIntcHandler(8, func_002FA478, -1), arg);
    func_002FA480(9, AddIntcHandler(9, func_002FA478, -1), arg);
    func_002FA480(10, AddIntcHandler(10, func_002FA478, -1), arg);
    return 0;
}