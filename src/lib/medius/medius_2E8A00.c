/*
 * lib/medius: 2 files, 002E8A00-002E8C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E8A00 */
extern int NetMsg_RegisterTypeInner(void *, int, void *);
extern int D_005983E8;
extern void ServerVersionPacketHandler(void);
extern int D_005983DC;
extern void PingPacketHandler(void);
extern int D_005983EC;
extern void PacketFragmentPacketHandler(void);
extern int D_005983F0;
extern void FieldUpdatePacketHandler(void);
extern int D_005983F4;
extern void NetObjectFullUpdatePacketHandler(void);
extern int D_005983F8;
extern void DataStreamEndPacketHandler(void);
extern int D_005983FC;
extern void AcceptClientPacketHandler(void);
extern int D_00598400;
extern void DeleteNetObjectPacketHandler(void);
extern int D_00598404;
extern void RequestOwnershipPacketHandler(void);
extern int D_005983E0;
extern void GrantOwnershipPacketHandler(void);
extern int D_00598408;
extern void ReleaseOwnershipPacketHandler(void);
extern int D_0059840C;
extern void DataStreamUpdatePacketHandler(void);
extern int D_00598410;
extern void ClientUpdatePacketHandler(void);
extern int D_00598414;
extern void ClientConnectsPacketHandler(void);
extern int D_00598418;
extern void ClientLeavesPacketHandler(void);
extern int D_0059841C;
extern void RequestServersPacketHandler(void);
extern int D_005983D8;
extern void ServerResponsePacketHandler(void);
extern int D_005983E4;
extern void ArbitrateJoinPacketHandler(void);
extern int D_00598420;
extern void UpdateClientStatusPacketHandler(void);
extern int D_00598424;
extern void SMMigrateOrderPacketHandler(void);
extern int D_00598428;
extern void StreamMediaClientInfoPacketHandler(void);

void RegisterDMEmessages(void)
{
    int local;

    NetMsg_RegisterTypeInner(&D_005983E8, 0, ServerVersionPacketHandler);
    NetMsg_RegisterTypeInner(&D_005983DC, 0, PingPacketHandler);
    NetMsg_RegisterTypeInner(&D_005983EC, 0, PacketFragmentPacketHandler);
    NetMsg_RegisterTypeInner(&D_005983F0, 0, FieldUpdatePacketHandler);
    NetMsg_RegisterTypeInner(&D_005983F4, 0, NetObjectFullUpdatePacketHandler);
    NetMsg_RegisterTypeInner(&D_005983F8, 0, DataStreamEndPacketHandler);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&D_005983FC, 0, AcceptClientPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598400, 0, DeleteNetObjectPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598404, 0, RequestOwnershipPacketHandler);
    NetMsg_RegisterTypeInner(&D_005983E0, 0, GrantOwnershipPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598408, 0, ReleaseOwnershipPacketHandler);
    NetMsg_RegisterTypeInner(&D_0059840C, 0, DataStreamUpdatePacketHandler);
    NetMsg_RegisterTypeInner(&D_00598410, 0, ClientUpdatePacketHandler);
    NetMsg_RegisterTypeInner(&D_00598414, 0, ClientConnectsPacketHandler);
    NetMsg_RegisterTypeInner(&local, 0, 0);
    NetMsg_RegisterTypeInner(&D_00598418, 0, ClientLeavesPacketHandler);
    NetMsg_RegisterTypeInner(&D_0059841C, 0, RequestServersPacketHandler);
    NetMsg_RegisterTypeInner(&D_005983D8, 0, ServerResponsePacketHandler);
    NetMsg_RegisterTypeInner(&D_005983E4, 0, ArbitrateJoinPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598420, 0, UpdateClientStatusPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598424, 0, SMMigrateOrderPacketHandler);
    NetMsg_RegisterTypeInner(&D_00598428, 0, StreamMediaClientInfoPacketHandler);
}
/* merge_units: end func_002E8A00 */

/* merge_units: begin func_002E8C50 */
typedef struct { int f0; unsigned short f4; unsigned short f6; } Msg8C50;
typedef struct { char pad0[6]; unsigned short f6; char pad8[2]; unsigned short fA; } Obj8C50;
extern int D_0058806C;
extern int NetIsValidClientIndex(int);
extern int NetIGetSessionMasterClientIndex(unsigned int*, unsigned int);
extern int NetGetConnInfo(unsigned int, char**);
extern int NetGetClientInfo(unsigned int, int, char**);
extern int NetIGetClient(Obj8C50**, unsigned int, int);
extern Obj8C50* NetCreateClient(unsigned int, int);
extern unsigned short GetFreeNetObjectBlock(int);
extern unsigned short FindFreeDataStreamBlock(int);
extern void NetSendDmeMessage(int, unsigned int, int, int, int, void*);
extern void NetGetNextMigrateOrder(unsigned int, int*);
extern void SendTimebaseCorrection(int);

void AcceptClientIntoGame(unsigned int a0, int a1, int a2, int a3)
{
    Msg8C50 msg;
    unsigned int sz;
    char* p1;
    char* p2;
    Obj8C50* o;
    int x;

    p1 = 0;
    p2 = 0;
    if (a0 >= 4) return;
    if (NetIsValidClientIndex(a1) != 1) return;
    NetIGetSessionMasterClientIndex(&sz, a0);
    if (sz == 0x100) return;
    if (sz >= 0x100) return;
    if (NetGetConnInfo(a0, &p1) != 0) return;
    if (p1 == 0) return;
    if (NetGetClientInfo(a0, a1, &p2) != 0) return;
    if (p2 == 0) return;
    if (*(unsigned int*)(p1 + 0x400) != sz) return;
    o = 0;
    NetIGetClient(&o, a0, a1);
    if (o != 0) return;
    o = NetCreateClient(a0, a1);
    if (o == 0) return;
    if (a2 != 0) o->f6 = GetFreeNetObjectBlock(a2);
    if (a3 != 0) o->fA = FindFreeDataStreamBlock(a3);
    msg.f0 = D_0058806C;
    msg.f4 = o->f6;
    msg.f6 = o->fA;
    NetSendDmeMessage(0x50, a0, a1, D_005983FC, 8, &msg);
    NetGetNextMigrateOrder(a0, &x);
    if (NetGetClientInfo(a0, a1, &p2) == 0 && p2 != 0) *(int*)(p2 + 0x24) = x;
    NetSendDmeMessage(0x50, a0, a1, D_00598424, 4, &x);
    SendTimebaseCorrection(a1);
    SendTimebaseCorrection(a1);
    SendTimebaseCorrection(a1);
}
/* merge_units: end func_002E8C50 */
