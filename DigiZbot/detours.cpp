#include <Windows.h>
#include "detours.h"
#include "Pointers.h"

#pragma comment(lib, "detours.lib")

// this assumes you have the detours.h and detours.lib in your source directory.

bool SetHook(bool bInstall, void** ppvTarget, void* pvDetour)
{
	if (DetourTransactionBegin() != NO_ERROR)
		return FALSE;

	if (DetourUpdateThread(GetCurrentThread()) == NO_ERROR)
		if ((bInstall ? DetourAttach : DetourDetach)(ppvTarget, pvDetour) == NO_ERROR)
			if (DetourTransactionCommit() == NO_ERROR)
				return TRUE;

	DetourTransactionAbort();
	return FALSE;
}

/***********************************************************************************
* StatHook                                                                      *
***********************************************************************************/

typedef void(__thiscall* _CUIStatusBar__SetNumberValue) (void *CUIStatusBar, int hp, int hpMax, int mp, int mpMax, int exp, int expMax, int tempExp);
_CUIStatusBar__SetNumberValue CUIStatusBar__SetNumberValue = reinterpret_cast<_CUIStatusBar__SetNumberValue>(CUIStatusBar__SetNumberValueAdr);

// CUIStatusBar__SetNumberValueAdr is defined in ptradr.h and is just the first address of the function where we stick our hook

int iCurHP, iMaxHP, iCurMP, iMaxMP, iCurEXP, iMaxEXP;

void __fastcall Hooked_CUIStatusBar__SetNumberValue(void *CUIStatusBar, int edx, int hp, int hpMax, int mp, int mpMax, int exp, int expMax, int tempExp)
{
	iCurHP = hp;
	iMaxHP = hpMax;
	iCurMP = mp;
	iMaxMP = mpMax;
	iCurEXP = exp;
	iMaxEXP = expMax;

	return(CUIStatusBar__SetNumberValue(CUIStatusBar, hp, hpMax, mp, mpMax, exp, expMax, tempExp));

}


bool ToggleStatHook(bool Toggle)
{
	return(SetHook(Toggle, (PVOID*)&CUIStatusBar__SetNumberValue, Hooked_CUIStatusBar__SetNumberValue));
}
