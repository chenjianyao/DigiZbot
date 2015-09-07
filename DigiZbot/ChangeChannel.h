#include <windows.h>
/*
Maple funcs (addys are from the unpacked kms client):
___:00439320 ; class CField * __cdecl get_field(void) // gets the instance of CField for SendTransferChannelRequest
___:0052EFA0 ; public: void __thiscall CField::SendTransferChannelRequest(long) // changes channel
*/

typedef void *(__cdecl *pfnget_field)(void);
typedef void(__fastcall *pfnCField__SendTransferChannelRequest)(void *pthis, void *edx, long ch);

// 56 8B ? ? ? ? ? 85 F6 74 18
pfnget_field get_field = reinterpret_cast<pfnget_field>(0x004860A0); // v103

// 6A ? 68 ? ? ? ? 64 A1 ? ? ? ? 50 83 EC ? 56 57 A1 ? ? ? ? 33 C4 50 8D 44 24 ? 64 A3 ? ? ? ? 8B 0D ? ? ? ? 85 C9
pfnCField__SendTransferChannelRequest CField__SendTransferChannelRequest =
reinterpret_cast<pfnCField__SendTransferChannelRequest>(0x0064D980); // v103

DWORD getmaplethreadid();

// the channel is zero-based (ch1 = 0, ch2 = 1, ...)
bool changechannel(long channel)
{
	try
	{
		__writefsdword(0x06B8, getmaplethreadid());
		CField__SendTransferChannelRequest(get_field(), NULL, channel);
		return true;
	}
	catch (...)
	{
		return false;
	}

	return false; // should never happen
}

HWND getmaplewnd()
{
	TCHAR buf[256] = { 0 };
	DWORD procid;

	for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT))
	{
		GetWindowThreadProcessId(hwnd, &procid);

		if (procid != GetCurrentProcessId())
			continue;

		if (!GetClassName(hwnd, buf, 256))
			continue;

		if (_tcscmp(buf, _T("MapleStoryClass")) != 0)
			continue;

		return hwnd;
	}

	return NULL;
}

DWORD getmaplethreadid()
{
	HWND hmoopla = getmaplewnd();

	if (!hmoopla)
		return 0;

	return GetWindowThreadProcessId(hmoopla, NULL);
}