#include"SendPacket.h"

#include"Asm.h"
#include <cstddef>
#include <cstdint>
#include <tchar.h>

void *SendFunction = reinterpret_cast<void *>(0x0057A970);
void *pCClientSocket = reinterpret_cast<void *>(0x015A8690);// 55 8B EC 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 53 56 57 A1 ? ? ? ? 33 C5 50 8D 45 ? 64 A3 ? ? ? ? 89 4D ? A1 ? ? ? ? 05 ? ? ? ? 8B 40 ? 05 ? ? ? ? 89 45 ?
void *SomeRetAddy = reinterpret_cast<void *>(0x0057A966);


typedef uint8_t byte;
typedef int8_t signed_byte;
typedef uint16_t word;
typedef int16_t signed_word;
typedef uint32_t dword;
typedef int32_t signed_dword;
typedef uint64_t qword; // my 64bit integers will pierce through the heavens!
typedef int64_t signed_qword;

	DWORD MapleThreadID;
	void ThreadCheck();
	void FindMapleThreadID();

namespace maple
{
	// internal maplestory packet structs
	// credits to waffle or whoever made 21st century PE

#pragma pack(push, 1)
	struct outpacket
	{
		dword fLoopback; // win32 BOOL = int. that's fucking stupid.
		union
		{
			byte *pbData;
			void *pData;
			word *pwHeader;
		};
		dword cbData;
		dword uOffset;
		dword fEncryptedByShanda;
	};
	struct inpacket
	{
		dword fLoopback; // 0
		signed_dword iState; // 2
		union
		{
			void *lpvData;
			struct
			{
				dword dw;
				word wHeader;
			} *pHeader;
			struct
			{
				dword dw;
				byte bData[0];
			} *pData;
		};
		dword dwTotalLength;
		dword dwUnknown;
		dword dwValidLength;
		dword uOffset;
	};
#pragma pack(pop)
}

void __declspec(naked) injectpacket(maple::outpacket *ppacket)
{
	__asm
	{
		// set class ptr
		mov ecx, [pCClientSocket]
			mov ecx, [ecx]

			// push packet and fake return address
			push[esp + 0x4] // ppacket
			push[SomeRetAddy]

			// send packet
			jmp[SendFunction]
	}
}

void _declspec(naked) ThreadCheck(){
	_asm{
		mov eax, 0x7EFDD000
			mov eax, [eax + 0x24]
			mov ecx, eax//using ecx
			ret
	}
}

HWND GetMooplaWnd() // TODO: move this somewhere else or inside the PH namespace
{
	TCHAR buf[200];
	DWORD procid;

	for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT))
	{
		GetWindowThreadProcessId(hwnd, &procid);

		if (procid != GetCurrentProcessId())
			continue;

		if (!GetClassName(hwnd, buf, 200))
			continue;

		if (_tcscmp(buf, _T("MapleStoryClass")) != 0)
			continue;

		return hwnd;
	}

	return NULL;
}

void FindMapleThreadID()
{
	HWND hmoopla = NULL;

	while (!hmoopla)
	{
		hmoopla = GetMooplaWnd();
		Sleep(500);
	}

	MapleThreadID = GetWindowThreadProcessId(hmoopla, NULL);
}

BOOL PH::PacketHook(){
	CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(FindMapleThreadID), NULL, 0, NULL);

	return TRUE;
}


BOOL PS::SendPacket(char Packet_STR[]){
	int Packet_Size;
	BYTE Packet[4096];
	//we can try to output &mspacket to see what it tries to recv..
	Packet_Size = Asm::ChartoByte(Packet_STR, Packet);

	if (Packet_Size == -1 || Packet_Size < 2){
		return FALSE;
	}
	/*
	//created by airride^^
	_asm{
	lea eax,[Packet]
	mov ebx,[Packet_Size]
	push 0x00
	push ebx
	push eax
	push 0x00
	push esp
	call SendFunction
	}
	*/

	// construct packet object
	maple::outpacket mspacket = { 0 };
	mspacket.cbData = Packet_Size;
	mspacket.pbData = Packet;

	// spoof thread id
	// credits to kma4 for hinting me the correct TIB thread id offset
	__writefsdword(0x06B8, MapleThreadID);

	// receive the packet
	// if you do not catch the exception receiving packets will throw exceptions frequently and not work like intended...
	try
	{
		injectpacket(&mspacket);
	}
	catch (...)
	{
		//uhm nothing
	}

	return TRUE;
}
