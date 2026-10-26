extern int AddIntcHandler(int, void (*)(), int);
extern void get_n_intc(int, int, void *);
extern void my_intc_handler();
int rt_intc_get_total_interrupt_handlers(void *arg)
{
    if (arg == 0) return 2;
    get_n_intc(0, AddIntcHandler(0, my_intc_handler, -1), arg);
    get_n_intc(1, AddIntcHandler(1, my_intc_handler, -1), arg);
    get_n_intc(2, AddIntcHandler(2, my_intc_handler, -1), arg);
    get_n_intc(3, AddIntcHandler(3, my_intc_handler, -1), arg);
    get_n_intc(4, AddIntcHandler(4, my_intc_handler, -1), arg);
    get_n_intc(5, AddIntcHandler(5, my_intc_handler, -1), arg);
    get_n_intc(6, AddIntcHandler(6, my_intc_handler, -1), arg);
    get_n_intc(7, AddIntcHandler(7, my_intc_handler, -1), arg);
    get_n_intc(8, AddIntcHandler(8, my_intc_handler, -1), arg);
    get_n_intc(9, AddIntcHandler(9, my_intc_handler, -1), arg);
    get_n_intc(10, AddIntcHandler(10, my_intc_handler, -1), arg);
    return 0;
}