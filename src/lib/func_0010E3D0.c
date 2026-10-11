typedef struct { int a; int b; int c; int d; } Request_0010E3D0;
extern void func_0010D590(int kind, Request_0010E3D0* req);
void func_0010E3D0(int a, int b, unsigned short c)
{
    Request_0010E3D0 req;
    req.a = a;
    req.b = b;
    req.c = c;
    func_0010D590(-5, &req);
}
