#include<Windows.h>

namespace PS{
	BOOL SendPacket(char Packet_STR[]);
}

namespace PH{
	BOOL PacketHook();
	extern DWORD MapleThreadID; // TODO: make this thread safe even if unnecessary
}

