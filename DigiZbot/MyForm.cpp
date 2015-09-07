#include "Pointers.h"
#include "MyForm.h"
#include "Sendpacket.h"
#include "detours.h" 
#include "tchar.h"
#include "detours.h"
#include "Asm.h"


#pragma comment(lib, "detours.lib")

using namespace DigiZbot;
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm); //change Form1 this to the name of your Form
	Application::Exit();
}

#pragma warning (disable: 4309)
#pragma warning (disable: 4305)
#pragma warning (disable: 4793)
#pragma warning (disable: 4102)

static BOOL bChild = FALSE;
static HWND hMapleStory, hParent;


void EmbedMapleStory(HWND hWnd)
{
	

	if (!bChild)
	{
		if (hMapleStory)
		{
			hParent = SetParent(hMapleStory, hWnd);
			if (hParent)
			{
				bChild = TRUE;
				SetWindowPos(hMapleStory, 0, -3, -25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			}
		}
	}
	else
	{
		SetParent(hMapleStory, hParent);
		bChild = FALSE;
	}
}

void SendKey(UINT key)
{
	::PostMessage(hMapleStory, WM_KEYDOWN, key, ::MapVirtualKey(key, 0) << 16);
}

void AutoAttack()
{
	while (bAttackEnabled)
	{
		SendKey(dwAttackKey);
		Sleep(100);
	}
}

DWORD dwJDA1 = 0x00F0A346; //74 ?? 3B 5C 24 ?? 75 ?? 8B 4C 24 ?? 6A ?? 03 C1
DWORD dwJDA2 = 0x0085F38A; //7D ?? 8B 16 8B 52 ?? 8D 44 24 ?? 50
DWORD dwJDA3 = 0x00F0A3A1; //74 ?? 8B CF C7 87 ?? ?? ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 6A ?? 6A ?? 8B CF 89 87 ?? ?? ?? ?? E8 ?? ?? ?? ?? 5D
BYTE bEnableJDA1[] = { 0xEB };
BYTE bEnableJDA2[] = { 0xEB };
BYTE bEnableJDA3[] = { 0x90, 0x90 };
BYTE bDisableJDA1[] = { 0x74 };
BYTE bDisableJDA2[] = { 0x7D };
BYTE bDisableJDA3[] = { 0x74, 0x22 };

void MyForm::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwJDA1, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwJDA2, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwJDA3, 2, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->JDA->Checked)
	{
		memcpy(reinterpret_cast<void*>(dwJDA1), bEnableJDA1, sizeof(bEnableJDA1));
		memcpy(reinterpret_cast<void*>(dwJDA2), bEnableJDA2, sizeof(bEnableJDA2));
		memcpy(reinterpret_cast<void*>(dwJDA3), bEnableJDA3, sizeof(bEnableJDA3));
	}
	else
	{
		memcpy(reinterpret_cast<void*>(dwJDA1), bDisableJDA1, sizeof(bDisableJDA1));
		memcpy(reinterpret_cast<void*>(dwJDA2), bDisableJDA2, sizeof(bDisableJDA2));
		memcpy(reinterpret_cast<void*>(dwJDA3), bDisableJDA3, sizeof(bDisableJDA3));
	}

	VirtualProtect((LPVOID)dwJDA1, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwJDA2, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwJDA3, 2, oldProtect, &oldProtect);
}

DWORD dwMobFreeze = 0x0088A332; //74 ? 83 7D ? ? 74 ? 8B CE E8 ? ? ? ? 85 C0
BYTE bEnableMobFreeze[] = { 0x75 };
BYTE bDisableMobFreeze[] = { 0x74 };

void MyForm::checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwMobFreeze, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->MobFreeze->Checked)
	{
		memcpy((void*)dwMobFreeze, bEnableMobFreeze, sizeof(bEnableMobFreeze));
	}
	else
	{
		memcpy((void*)dwMobFreeze, bDisableMobFreeze, sizeof(bDisableMobFreeze));
	}

	VirtualProtect((LPVOID)dwMobFreeze, 1, oldProtect, &oldProtect);
}

DWORD dwGnD = 0x00F3C2B1; //00 00 00 00 8B 95 ?? ?? ?? ?? 89 55 ?? 8B 85 ?? ?? ?? ?? 50 E8 ?? ?? ?? ?? 83 C4 ?? 85 C0
BYTE bEnableGnD[] = { 0x01 };
BYTE bDisableGnD[] = { 0x00 };

void MyForm::checkBox1_CheckedChanged_2(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwGnD, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->GnD->Checked)
	{
		memcpy((void*)dwGnD, bEnableGnD, sizeof(bEnableGnD));
	}
	else
	{
		memcpy((void*)dwGnD, bDisableGnD, sizeof(bDisableGnD));
	}

	VirtualProtect((LPVOID)dwGnD, 1, oldProtect, &oldProtect);
}


DWORD dwNoDamageShown1 = 0x004C2155; //7C ?? B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B C4 6A ?? 50
DWORD dwNoDamageShown2 = 0x00860F34; //0F 84 ?? ?? ?? ?? 2D ?? ?? ?? ?? 75 ?? 85 DB 74 ?? 8B 13
DWORD dwNoDamageShown3 = 0x00858AC8; //7E ?? 8B 54 24 ?? 52 8B 54 24 ?? 52 51
DWORD dwNoDamageShown4 = 0x00858AF0; //75 ?? 8B 44 24 ?? 50 6A ?? 51
DWORD dwNoDamageShown5 = 0x00858B15; //7D ?? 8B 4C 24 ?? 8B 54 24 ?? 51 52
BYTE bEnableNoDamageShown1[] = { 0x7C, 0x00 };
BYTE bEnableNoDamageShown2[] = { 0x90, 0xE9 };
BYTE bEnableNoDamageShown3[] = { 0xEB };
BYTE bEnableNoDamageShown4[] = { 0XEB };
BYTE bEnableNoDamageShown5[] = { 0XEB };
BYTE bDisableNoDamageShown1[] = { 0x7C, 0x1C};
BYTE bDisableNoDamageShown2[] = { 0x0F, 0x84 };
BYTE bDisableNoDamageShown3[] = { 0x7E};
BYTE bDisableNoDamageShown4[] = { 0x75 };
BYTE bDisableNoDamageShown5[] = { 0x7D };

void MyForm::checkBox1_CheckedChanged_3(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwNoDamageShown1, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown2, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown3, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown4, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown5, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	if (this->NDS->Checked)
	{
		memcpy((void*)dwNoDamageShown1, bEnableNoDamageShown1, sizeof(bEnableNoDamageShown1));
		memcpy((void*)dwNoDamageShown2, bEnableNoDamageShown2, sizeof(bEnableNoDamageShown2));
		memcpy((void*)dwNoDamageShown3, bEnableNoDamageShown3, sizeof(bEnableNoDamageShown3));
		memcpy((void*)dwNoDamageShown4, bEnableNoDamageShown4, sizeof(bEnableNoDamageShown4));
		memcpy((void*)dwNoDamageShown3, bEnableNoDamageShown5, sizeof(bEnableNoDamageShown3));
	}
	else
	{
		memcpy((void*)dwNoDamageShown1, bDisableNoDamageShown1, sizeof(bDisableNoDamageShown1));
		memcpy((void*)dwNoDamageShown2, bDisableNoDamageShown2, sizeof(bDisableNoDamageShown2));
		memcpy((void*)dwNoDamageShown3, bDisableNoDamageShown3, sizeof(bDisableNoDamageShown3));
		memcpy((void*)dwNoDamageShown4, bDisableNoDamageShown4, sizeof(bDisableNoDamageShown4));
		memcpy((void*)dwNoDamageShown5, bDisableNoDamageShown5, sizeof(bDisableNoDamageShown5));
	}

	VirtualProtect((LPVOID)dwNoDamageShown1, 2, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown2, 2, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown3, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown4, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoDamageShown5, 1, oldProtect, &oldProtect);
}

DWORD dwNoFadeStages1 = 0x0052FAE0; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C9
DWORD dwNoFadeStages2 = 0x009F1DC0; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 84 24 ?? ?? ?? ?? 64 A3 ?? ?? ?? ?? A1 ?? ?? ?? ?? 85 C0 74 ?? 8B F0
BYTE bEnableNoFadeStages1[] = { 0xC2, 0x04, 0x00 };
BYTE bEnableNoFadeStages2[] = { 0xC2, 0x04, 0x00 };
BYTE bDisableNoFadeStages1[] = { 0x6A, 0xFF, 0x68 };
BYTE bDisableNoFadeStages2[] = { 0x6A, 0xFF, 0x68 };

void MyForm::checkBox1_CheckedChanged_4(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwNoFadeStages1, 3, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoFadeStages2, 3, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NFS->Checked)
	{
		memcpy((void*)dwNoFadeStages1, bEnableNoFadeStages1, sizeof(bEnableNoFadeStages1));
		memcpy((void*)dwNoFadeStages2, bEnableNoFadeStages2, sizeof(bEnableNoFadeStages2));
	}
	else
	{
		memcpy((void*)dwNoFadeStages1, bDisableNoFadeStages1, sizeof(bDisableNoFadeStages1));
		memcpy((void*)dwNoFadeStages2, bDisableNoFadeStages2, sizeof(bDisableNoFadeStages2));
	}

	VirtualProtect((LPVOID)dwNoFadeStages1, 3, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoFadeStages2, 3, oldProtect, &oldProtect);
}


DWORD dwNoCloud1 = 0x0081F130; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? 8B E9 8B 75 ?? 89 74 24 ?? 85 F6
DWORD dwNoCloud2 = 0x0081BA80; //55 8D 6C 24 ?? 83 EC ?? 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? A1 ?? ?? ?? ?? 33 C5 89 45 ?? 53 56 57 50 8D 45 ?? 64 A3 ?? ?? ?? ?? 89 4D ?? 51
BYTE bEnableNoCloud1[] = { 0xC3 };
BYTE bEnableNoCloud2[] = { 0xC2, 0x08, 0x00 };
BYTE bDisableNoCloud1[] = { 0x6A };
BYTE bDisableNoCloud2[] = { 0x55, 0x8D, 0x6C };

void MyForm::checkBox1_CheckedChanged_5(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwNoCloud1, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwNoCloud2, 3, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NB->Checked)
	{
		memcpy((void*)dwNoCloud1, bEnableNoCloud1, sizeof(bEnableNoCloud1));
		memcpy((void*)dwNoCloud2, bEnableNoCloud2, sizeof(bEnableNoCloud2));
	}
	else
	{
		memcpy((void*)dwNoCloud1, bDisableNoCloud1, sizeof(bDisableNoCloud1));
		memcpy((void*)dwNoCloud2, bDisableNoCloud2, sizeof(bDisableNoCloud2));
	}

	VirtualProtect((LPVOID)dwNoCloud1, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwNoCloud2, 3, oldProtect, &oldProtect);
}



DWORD dwPerfectLoot1 = 0x0055EC07; //89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? 5E C2 ?? ?? CC CC CC CC
DWORD dwPerfectLoot2 = 0x00611EE5; //0D ?? ?? ?? ?? 83 C4 ?? E9 ?? ?? ?? ?? DD 05 ?? ?? ?? ?? DC C9
DWORD dwPerfectLoot3 = 0x004A5969; //81 FE ?? ?? ?? ?? 0F 8D ?? ?? ?? ?? 85 ED 0F 84 ?? ?? ?? ?? 81 FE ?? ?? ?? ?? BF ?? ?? ?? ?? 7E ?? B8 ?? ?? ?? ?? 2B C6
BYTE bEnablePerfectLoot1[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnablePerfectLoot2[] = { 0x25 };
BYTE bEnablePerfectLoot3[] = { 0x81, 0xFE, 0x00, 0x00, 0x00, 0x00 };
BYTE bDisablePerfectLoot1[] = { 0x89, 0x86, 0x40, 0x21, 0x00, 0x00 };
BYTE bDisablePerfectLoot2[] = { 0x0D };
BYTE bDisablePerfectLoot3[] = { 0x81, 0xFE, 0xBC, 0x02, 0x00, 0x00 };

void MyForm::checkBox1_CheckedChanged_6(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwPerfectLoot1, 6, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPerfectLoot2, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPerfectLoot3, 6, PAGE_EXECUTE_READWRITE, &oldProtect);
	if (this->PL->Checked)
	{
		memcpy((void*)dwPerfectLoot1, bEnablePerfectLoot1, sizeof(bEnablePerfectLoot1));
		memcpy((void*)dwPerfectLoot2, bEnablePerfectLoot2, sizeof(bEnablePerfectLoot2));
		memcpy((void*)dwPerfectLoot3, bEnablePerfectLoot3, sizeof(bEnablePerfectLoot3));
	}
	else
	{
		memcpy((void*)dwPerfectLoot1, bDisablePerfectLoot1, sizeof(bDisablePerfectLoot1));
		memcpy((void*)dwPerfectLoot2, bDisablePerfectLoot2, sizeof(bDisablePerfectLoot2));
		memcpy((void*)dwPerfectLoot3, bDisablePerfectLoot3, sizeof(bDisablePerfectLoot3));
	}

	VirtualProtect((LPVOID)dwPerfectLoot1, 6, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPerfectLoot2, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPerfectLoot3, 6, oldProtect, &oldProtect);
}

DWORD dwUnlimitedAttack = 0x00EF98C0; //7E ?? 83 F8 ?? 7D ?? 8B 41 ?? 2B C2
BYTE bEnableUnlimitedAttack[] = { 0xEB };
BYTE bDisableUnlimitedAttack[] = { 0x7E };

void MyForm::checkBox1_CheckedChanged_7(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwUnlimitedAttack, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->UA->Checked)
	{
		memcpy((void*)dwUnlimitedAttack, bEnableUnlimitedAttack, sizeof(bEnableUnlimitedAttack));
	}
	else
	{
		memcpy((void*)dwUnlimitedAttack, bDisableUnlimitedAttack, sizeof(bDisableUnlimitedAttack));
	}

	VirtualProtect((LPVOID)dwUnlimitedAttack, 1, oldProtect, &oldProtect);
}

DWORD dwUnlimitedMP = 0x00F29312; //7D ?? 33 FF 81 FB ?? ?? ?? ?? 75 ?? 8B 6C 24 ?? 8B CD
BYTE bEnableUnlimitedMP[] = { 0x90, 0x90 };
BYTE bDisableUnlimitedMP[] = { 0x7D, 0x02 };

void MyForm::checkBox1_CheckedChanged_8(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwUnlimitedMP, 2, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->UMP->Checked)
	{
		memcpy((void*)dwUnlimitedMP, bEnableUnlimitedMP, sizeof(bEnableUnlimitedMP));
	}
	else
	{
		memcpy((void*)dwUnlimitedMP, bDisableUnlimitedMP, sizeof(bDisableUnlimitedMP));
	}

	VirtualProtect((LPVOID)dwUnlimitedMP, 2, oldProtect, &oldProtect);
}


DWORD dwPinPicTyper1 = 0x007EA316; // 0F ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 89 ?? ?? ?? C6 ?? ?? ?? ?? 85 ?? 0F ?? ?? ?? ?? ?? 6A
DWORD dwPinPicTyper2 = 0x007EB877; // 0F ?? ?? ?? ?? ?? 68 ?? ?? ?? ?? B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 89 ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? 85 ?? 0F ?? ?? ?? ?? ?? 6A ?? 8B ?? E8 ?? ?? ?? ?? 85 ?? 0F ?? ?? ?? ?? ?? 83 ?? ?? 74
DWORD dwPinPicTyper3 = 0x009EE576; // 0F ?? ?? ?? ?? ?? 6A ?? 6A ?? 51 8B ?? 89 ?? ?? ?? 68 ?? ?? ?? ?? 50 E8
DWORD dwPinPicTyper4 = 0x009ED516; // 01 ?? 00 ?? 89 ?? ?? 89 ?? ?? E8 ?? ?? ?? ?? 89
DWORD dwPinPicTyper5 = 0x009ED532; // E8 ?? ?? ?? ?? EB ?? 33 ?? C6 ?? ?? ?? 85 ?? 0F ?? ?? ?? ?? ?? 83 ?? ?? 0F ?? ?? ?? ?? ?? 8D ?? ?? 85 ?? 74 ?? 8D ?? ?? 51 FF ?? ?? ?? ?? ?? 8B ?? ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 85 ?? 74 ?? 83
DWORD dwPinPicTyper6 = 0x00964577; // 74 17 8B C8 E8 ?? ?? ?? ?? 8B ?? ?? ?? 64 89 ?? ?? ?? ?? ?? 59 83 C4 ?? ?? ?? C0 8B ?? ?? ?? 64 89 ?? ?? ?? ?? ?? 59 83 C4 ?? C3 CC CC CC CC CC CC CC CC CC CC CC CC CC CC 8B
BYTE bEnablePinPicTyper1[] = {0x0F, 0x84};
BYTE bEnablePinPicTyper2[] = {0x0F, 0x84};
BYTE bEnablePinPicTyper3[] = {0x90, 0xE9};
BYTE bEnablePinPicTyper4[] = {  0x00};
BYTE bEnablePinPicTyper5[] = { 0xE8, 0x09, 0x63 };
BYTE bEnablePinPicTyper6[] = {  0xEB};
BYTE bDisablePinPicTyper1[] = {0x0F, 0x85};
BYTE bDisablePinPicTyper2[] = {0x0F, 0x85};
BYTE bDisablePinPicTyper3[] = {0x0F, 0x84 };
BYTE bDisablePinPicTyper4[] = {  0x01};
BYTE bDisablePinPicTyper5[] = { 0xE8, 0xB9, 0xA9};
BYTE bDisablePinPicTyper6[] = {  0x74 };
void MyForm::checkBox1_CheckedChanged_9(System::Object^  sender, System::EventArgs^  e)
{
	/*unsigned long oldProtect;

	VirtualProtect((LPVOID)dwPinPicTyper1, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper2, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper3, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper4, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper5, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper6, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
	if (this->PPtyper->Checked)
	{
		memcpy((void*)dwPinPicTyper1, bEnablePinPicTyper1, sizeof(bEnablePinPicTyper1));
		memcpy((void*)dwPinPicTyper2, bEnablePinPicTyper2, sizeof(bEnablePinPicTyper2));
		memcpy((void*)dwPinPicTyper3, bEnablePinPicTyper3, sizeof(bEnablePinPicTyper3));
		memcpy((void*)dwPinPicTyper4, bEnablePinPicTyper4, sizeof(bEnablePinPicTyper4));
		memcpy((void*)dwPinPicTyper5, bEnablePinPicTyper5, sizeof(bEnablePinPicTyper5));
		memcpy((void*)dwPinPicTyper6, bEnablePinPicTyper6, sizeof(bEnablePinPicTyper6));
	}
	else
	{
		memcpy((void*)dwPinPicTyper1, bDisablePinPicTyper1, sizeof(bDisablePinPicTyper1));
		memcpy((void*)dwPinPicTyper2, bDisablePinPicTyper2, sizeof(bDisablePinPicTyper2));
		memcpy((void*)dwPinPicTyper3, bDisablePinPicTyper3, sizeof(bDisablePinPicTyper3));
		memcpy((void*)dwPinPicTyper4, bDisablePinPicTyper4, sizeof(bDisablePinPicTyper4));
		memcpy((void*)dwPinPicTyper5, bDisablePinPicTyper5, sizeof(bDisablePinPicTyper5));
		memcpy((void*)dwPinPicTyper6, bDisablePinPicTyper6, sizeof(bDisablePinPicTyper6));
	}

	VirtualProtect((LPVOID)dwPinPicTyper1, 2, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper2, 2, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper3, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper4, 1, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper5, 5, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwPinPicTyper6, 1, oldProtect, &oldProtect);*/
}


DWORD dwNoMobReaction = 0x00872920; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? 8B F1 89 74 24 ?? A1 ?? ?? ?? ?? 33 DB
BYTE bEnableNoMobReaction[] = { 0xC2, 0x58, 0x00};
BYTE bDisableNoMobReaction[] = { 0x6A, 0xFF, 0x68 };

void MyForm::checkBox1_CheckedChanged_10(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoMobReaction, 3, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NMR->Checked)
	{
		memcpy((void*)dwNoMobReaction, bEnableNoMobReaction, sizeof(bEnableNoMobReaction));
	}
	else
	{
		memcpy((void*)dwNoMobReaction, bDisableNoMobReaction, sizeof(bDisableNoMobReaction));
	}

	VirtualProtect((LPVOID)dwNoMobReaction, 2, oldProtect, &oldProtect);
}

DWORD AutoSkillKey;
bool AutoskillExit;

void MyForm::nudSkillDelay1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillDelay1 = Convert::ToInt32(this->nudSkillDelay1->Text) * 1000;
}

void AutoSkill1()
{
	while (!AutoskillExit)//! means it's false, remove the ! and it will become true, depends on what you want to code heh.
	{
		SendKey(AutoSkillKey);
		Sleep(SkillDelay1);
	}
}

void MyForm::checkBox1_CheckedChanged_11(System::Object^ sender, System::EventArgs^ e)
{
	if (this->AS1->Checked == true)
	{
		SkillDelay1 = Convert::ToInt32(this->nudSkillDelay1->Text) * 1000;
		AutoskillExit = false;
		NewThread(AutoSkill1);
	}

	else//if not checked
	{
		AutoskillExit = true;
	}
}

void MyForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) // this func executes everytime you make a new selection.
{
	switch (this->comboBox1->SelectedIndex)//current index selection, first one is 0. // this is the int returned from combobox
	{
	case 0: // and so on
		AutoSkillKey = 0x41;//A.
		break;

	case 1:
		AutoSkillKey = 0x42;//B
		break;

	case 2:
		AutoSkillKey = 0x43;//C
		break;


	case 3:
		AutoSkillKey = 0x44;//D
		break;

	case 4:
		AutoSkillKey = 0x45;//E
		break;

	case 5:
		AutoSkillKey = 0x46;//F
		break;

	case 6:
		AutoSkillKey = 0x47;//G
		break;

	case 7:
		AutoSkillKey = 0x48;//H
		break;

	case 8:
		AutoSkillKey = 0x49;//I.
		break;

	case 9:
		AutoSkillKey = 0x4A;//J
		break;

	case 10:
		AutoSkillKey = 0x4B;//K
		break;

	case 11:
		AutoSkillKey = 0x4C;//L
		break;

	case 12:
		AutoSkillKey = 0x4D;//M
		break;

	case 13:
		AutoSkillKey = 0x4E;//N
		break;

	case 14:
		AutoSkillKey = 0x4F;//O
		break;

	case 15:
		AutoSkillKey = 0x50;//P
		break;

	case 16:
		AutoSkillKey = 0x51;//Q
		break;

	case 17:
		AutoSkillKey = 0x52;//R
		break;

	case 18:
		AutoSkillKey = 0x53;//S
		break;

	case 19:
		AutoSkillKey = 0x54;//T
		break;

	case 20:
		AutoSkillKey = 0x55;//U
		break;

	case 21:
		AutoSkillKey = 0x56;//V
		break;

	case 22:
		AutoSkillKey = 0x57;//W
		break;

	case 23:
		AutoSkillKey = 0x58;//X
		break;

	case 24:
		AutoSkillKey = 0x59;//Y
		break;

	case 25:
		AutoSkillKey = 0x5A;//Z
		break;

	case 26:
		AutoSkillKey = 0xA0;//Left Shift
		break;

	case 27:
		AutoSkillKey = 0x11;//Control//your keycodes fail xD o-o, why. Control is A0i think you'll find...
		break;

	case 28:
		AutoSkillKey = 0x21;//Page Up
		break;

	case 29:
		AutoSkillKey = 0x22;//Page Down
		break;

	case 30:
		AutoSkillKey = 0x23;//End
		break;

	case 31:
		AutoSkillKey = 0x24;//Home
		break;

	case 32:
		AutoSkillKey = 0x2E;//Delete
		break;
	default:
		AutoSkillKey = 0xA0;//shift, if mistake/fail, it will always pick default // this will never happen as long as you don't add to many options to your combobox
		break;
	}
}

DWORD AutoSkillKey2;
bool AutoskillExit2;


void MyForm::nudSkillDelay2_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillDelay2 = Convert::ToInt32(this->nudSkillDelay2->Text) * 1000;
}

void AutoSkill2()
{
	while (!AutoskillExit)//! means it's false, remove the ! and it will become true, depends on what you want to code heh.
	{
		SendKey(AutoSkillKey2);
		Sleep(SkillDelay2);
	}
}

void MyForm::checkBox1_CheckedChanged_24(System::Object^ sender, System::EventArgs^ e)
{
	if (this->As2->Checked == true)
	{
		SkillDelay2 = Convert::ToInt32(this->nudSkillDelay2->Text) * 1000;
		AutoskillExit = false;
		NewThread(AutoSkill2);
	}

	else//if not checked
	{
		AutoskillExit2 = true;
	}
}

void MyForm::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) // this func executes everytime you make a new selection.
{
	switch (this->comboBox2->SelectedIndex)//current index selection, first one is 0. // this is the int returned from combobox
	{
	case 0: // and so on
		AutoSkillKey2 = 0x41;//A.
		break;

	case 1:
		AutoSkillKey2 = 0x42;//B
		break;

	case 2:
		AutoSkillKey2 = 0x43;//C
		break;


	case 3:
		AutoSkillKey2 = 0x44;//D
		break;

	case 4:
		AutoSkillKey2 = 0x45;//E
		break;

	case 5:
		AutoSkillKey2 = 0x46;//F
		break;

	case 6:
		AutoSkillKey2 = 0x47;//G
		break;

	case 7:
		AutoSkillKey2 = 0x48;//H
		break;

	case 8:
		AutoSkillKey2 = 0x49;//I.
		break;

	case 9:
		AutoSkillKey2 = 0x4A;//J
		break;

	case 10:
		AutoSkillKey2 = 0x4B;//K
		break;

	case 11:
		AutoSkillKey2 = 0x4C;//L
		break;

	case 12:
		AutoSkillKey2 = 0x4D;//M
		break;

	case 13:
		AutoSkillKey2 = 0x4E;//N
		break;

	case 14:
		AutoSkillKey2 = 0x4F;//O
		break;

	case 15:
		AutoSkillKey2 = 0x50;//P
		break;

	case 16:
		AutoSkillKey2 = 0x51;//Q
		break;

	case 17:
		AutoSkillKey2 = 0x52;//R
		break;

	case 18:
		AutoSkillKey2 = 0x53;//S
		break;

	case 19:
		AutoSkillKey2 = 0x54;//T
		break;

	case 20:
		AutoSkillKey2 = 0x55;//U
		break;

	case 21:
		AutoSkillKey2 = 0x56;//V
		break;

	case 22:
		AutoSkillKey2 = 0x57;//W
		break;

	case 23:
		AutoSkillKey2 = 0x58;//X
		break;

	case 24:
		AutoSkillKey2 = 0x59;//Y
		break;

	case 25:
		AutoSkillKey2 = 0x5A;//Z
		break;

	case 26:
		AutoSkillKey2 = 0xA0;//Left Shift
		break;

	case 27:
		AutoSkillKey2 = 0x11;//Control//your keycodes fail xD o-o, why. Control is A0i think you'll find...
		break;

	case 28:
		AutoSkillKey2 = 0x21;//Page Up
		break;

	case 29:
		AutoSkillKey2 = 0x22;//Page Down
		break;

	case 30:
		AutoSkillKey2 = 0x23;//End
		break;

	case 31:
		AutoSkillKey2 = 0x24;//Home
		break;

	case 32:
		AutoSkillKey2 = 0x2E;//Delete
		break;
	default:
		AutoSkillKey2 = 0xA0;//shift, if mistake/fail, it will always pick default // this will never happen as long as you don't add to many options to your combobox
		break;
	}
}

DWORD AutoSkillKey3;
bool AutoskillExit3;


void MyForm::nudSkillDelay3_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillDelay3 = Convert::ToInt32(this->nudSkillDelay3->Text) * 1000;
}

void AutoSkill3()
{
	while (!AutoskillExit3)//! means it's false, remove the ! and it will become true, depends on what you want to code heh.
	{
		SendKey(AutoSkillKey3);
		Sleep(SkillDelay3);
	}
}

void MyForm::checkBox1_CheckedChanged_25(System::Object^ sender, System::EventArgs^ e)
{
	if (this->As3->Checked == true)
	{
		SkillDelay3 = Convert::ToInt32(this->nudSkillDelay3->Text) * 1000;
		AutoskillExit3 = false;
		NewThread(AutoSkill3);
	}

	else//if not checked
	{
		AutoskillExit3 = true;
	}
}

void MyForm::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) // this func executes everytime you make a new selection.
{
	switch (this->comboBox3->SelectedIndex)//current index selection, first one is 0. // this is the int returned from combobox
	{
	case 0: // and so on
		AutoSkillKey3 = 0x41;//A.
		break;

	case 1:
		AutoSkillKey3 = 0x42;//B
		break;

	case 2:
		AutoSkillKey3 = 0x43;//C
		break;


	case 3:
		AutoSkillKey3 = 0x44;//D
		break;

	case 4:
		AutoSkillKey3 = 0x45;//E
		break;

	case 5:
		AutoSkillKey3 = 0x46;//F
		break;

	case 6:
		AutoSkillKey3 = 0x47;//G
		break;

	case 7:
		AutoSkillKey3 = 0x48;//H
		break;

	case 8:
		AutoSkillKey3 = 0x49;//I.
		break;

	case 9:
		AutoSkillKey3 = 0x4A;//J
		break;

	case 10:
		AutoSkillKey3 = 0x4B;//K
		break;

	case 11:
		AutoSkillKey3 = 0x4C;//L
		break;

	case 12:
		AutoSkillKey3 = 0x4D;//M
		break;

	case 13:
		AutoSkillKey3 = 0x4E;//N
		break;

	case 14:
		AutoSkillKey3 = 0x4F;//O
		break;

	case 15:
		AutoSkillKey3 = 0x50;//P
		break;

	case 16:
		AutoSkillKey3 = 0x51;//Q
		break;

	case 17:
		AutoSkillKey3 = 0x52;//R
		break;

	case 18:
		AutoSkillKey3 = 0x53;//S
		break;

	case 19:
		AutoSkillKey3 = 0x54;//T
		break;

	case 20:
		AutoSkillKey3 = 0x55;//U
		break;

	case 21:
		AutoSkillKey3 = 0x56;//V
		break;

	case 22:
		AutoSkillKey3 = 0x57;//W
		break;

	case 23:
		AutoSkillKey3 = 0x58;//X
		break;

	case 24:
		AutoSkillKey3 = 0x59;//Y
		break;

	case 25:
		AutoSkillKey3 = 0x5A;//Z
		break;

	case 26:
		AutoSkillKey3 = 0xA0;//Left Shift
		break;

	case 27:
		AutoSkillKey3 = 0x11;//Control//your keycodes fail xD o-o, why. Control is A0i think you'll find...
		break;

	case 28:
		AutoSkillKey3 = 0x21;//Page Up
		break;

	case 29:
		AutoSkillKey3 = 0x22;//Page Down
		break;

	case 30:
		AutoSkillKey3 = 0x23;//End
		break;

	case 31:
		AutoSkillKey3 = 0x24;//Home
		break;

	case 32:
		AutoSkillKey3 = 0x2E;//Delete
		break;
	default:
		AutoSkillKey3 = 0xA0;//shift, if mistake/fail, it will always pick default // this will never happen as long as you don't add to many options to your combobox
		break;
	}
}

DWORD AutoSkillKey4;
bool AutoskillExit4;

void MyForm::nudSkillDelay4_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillDelay4 = Convert::ToInt32(this->nudSkillDelay4->Text) * 1000;
}

void AutoSkill4()
{
	while (!AutoskillExit4)//! means it's false, remove the ! and it will become true, depends on what you want to code heh.
	{
		SendKey(AutoSkillKey4);
		Sleep(SkillDelay4);
	}
}

void MyForm::checkBox1_CheckedChanged_26(System::Object^ sender, System::EventArgs^ e)
{
	if (this->As4->Checked == true)
	{
		SkillDelay4 = Convert::ToInt32(this->nudSkillDelay4->Text) * 1000;
		AutoskillExit4 = false;
		NewThread(AutoSkill4);
	}

	else//if not checked
	{
		AutoskillExit4 = true;
	}
}

void MyForm::comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) // this func executes everytime you make a new selection.
{
	switch (this->comboBox4->SelectedIndex)//current index selection, first one is 0. // this is the int returned from combobox
	{
	case 0: // and so on
		AutoSkillKey4 = 0x41;//A.
		break;

	case 1:
		AutoSkillKey4 = 0x42;//B
		break;

	case 2:
		AutoSkillKey4 = 0x43;//C
		break;


	case 3:
		AutoSkillKey4 = 0x44;//D
		break;

	case 4:
		AutoSkillKey4 = 0x45;//E
		break;

	case 5:
		AutoSkillKey4 = 0x46;//F
		break;

	case 6:
		AutoSkillKey4 = 0x47;//G
		break;

	case 7:
		AutoSkillKey4 = 0x48;//H
		break;

	case 8:
		AutoSkillKey4 = 0x49;//I.
		break;

	case 9:
		AutoSkillKey4 = 0x4A;//J
		break;

	case 10:
		AutoSkillKey4 = 0x4B;//K
		break;

	case 11:
		AutoSkillKey4 = 0x4C;//L
		break;

	case 12:
		AutoSkillKey4 = 0x4D;//M
		break;

	case 13:
		AutoSkillKey4 = 0x4E;//N
		break;

	case 14:
		AutoSkillKey4 = 0x4F;//O
		break;

	case 15:
		AutoSkillKey4 = 0x50;//P
		break;

	case 16:
		AutoSkillKey4 = 0x51;//Q
		break;

	case 17:
		AutoSkillKey4 = 0x52;//R
		break;

	case 18:
		AutoSkillKey4 = 0x53;//S
		break;

	case 19:
		AutoSkillKey4 = 0x54;//T
		break;

	case 20:
		AutoSkillKey4 = 0x55;//U
		break;

	case 21:
		AutoSkillKey4 = 0x56;//V
		break;

	case 22:
		AutoSkillKey4 = 0x57;//W
		break;

	case 23:
		AutoSkillKey4 = 0x58;//X
		break;

	case 24:
		AutoSkillKey4 = 0x59;//Y
		break;

	case 25:
		AutoSkillKey4 = 0x5A;//Z
		break;

	case 26:
		AutoSkillKey4 = 0xA0;//Left Shift
		break;

	case 27:
		AutoSkillKey4 = 0x11;//Control//your keycodes fail xD o-o, why. Control is A0i think you'll find...
		break;

	case 28:
		AutoSkillKey4 = 0x21;//Page Up
		break;

	case 29:
		AutoSkillKey4 = 0x22;//Page Down
		break;

	case 30:
		AutoSkillKey4 = 0x23;//End
		break;

	case 31:
		AutoSkillKey4 = 0x24;//Home
		break;

	case 32:
		AutoSkillKey4 = 0x2E;//Delete
		break;
	default:
		AutoSkillKey4 = 0xA0;//shift, if mistake/fail, it will always pick default // this will never happen as long as you don't add to many options to your combobox
		break;
	}
}

DWORD AutoSkillKey5;
bool AutoskillExit5;

void MyForm::nudSkillDelay5_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillDelay5 = Convert::ToInt32(this->nudSkillDelay5->Text) * 1000;
}

void AutoSkill5()
{
	while (!AutoskillExit5)//! means it's false, remove the ! and it will become true, depends on what you want to code heh.
	{
		SendKey(AutoSkillKey5);
		Sleep(SkillDelay5);
	}
}

void MyForm::checkBox1_CheckedChanged_27(System::Object^ sender, System::EventArgs^ e)
{
	if (this->As5->Checked == true)
	{
		SkillDelay5 = Convert::ToInt32(this->nudSkillDelay5->Text) * 1000;
		AutoskillExit5 = false;
		NewThread(AutoSkill5);
	}

	else//if not checked
	{
		AutoskillExit5 = true;
	}
}

void MyForm::comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) // this func executes everytime you make a new selection.
{
	switch (this->comboBox5->SelectedIndex)//current index selection, first one is 0. // this is the int returned from combobox
	{
	case 0: // and so on
		AutoSkillKey5 = 0x41;//A.
		break;

	case 1:
		AutoSkillKey5 = 0x42;//B
		break;

	case 2:
		AutoSkillKey5 = 0x43;//C
		break;


	case 3:
		AutoSkillKey5 = 0x44;//D
		break;

	case 4:
		AutoSkillKey5 = 0x45;//E
		break;

	case 5:
		AutoSkillKey5 = 0x46;//F
		break;

	case 6:
		AutoSkillKey5 = 0x47;//G
		break;

	case 7:
		AutoSkillKey5 = 0x48;//H
		break;

	case 8:
		AutoSkillKey5 = 0x49;//I.
		break;

	case 9:
		AutoSkillKey5 = 0x4A;//J
		break;

	case 10:
		AutoSkillKey5 = 0x4B;//K
		break;

	case 11:
		AutoSkillKey5 = 0x4C;//L
		break;

	case 12:
		AutoSkillKey5 = 0x4D;//M
		break;

	case 13:
		AutoSkillKey5 = 0x4E;//N
		break;

	case 14:
		AutoSkillKey5 = 0x4F;//O
		break;

	case 15:
		AutoSkillKey5 = 0x50;//P
		break;

	case 16:
		AutoSkillKey5 = 0x51;//Q
		break;

	case 17:
		AutoSkillKey5 = 0x52;//R
		break;

	case 18:
		AutoSkillKey5 = 0x53;//S
		break;

	case 19:
		AutoSkillKey5 = 0x54;//T
		break;

	case 20:
		AutoSkillKey5 = 0x55;//U
		break;

	case 21:
		AutoSkillKey5 = 0x56;//V
		break;

	case 22:
		AutoSkillKey5 = 0x57;//W
		break;

	case 23:
		AutoSkillKey5 = 0x58;//X
		break;

	case 24:
		AutoSkillKey5 = 0x59;//Y
		break;

	case 25:
		AutoSkillKey5 = 0x5A;//Z
		break;

	case 26:
		AutoSkillKey5 = 0xA0;//Left Shift
		break;

	case 27:
		AutoSkillKey5 = 0x11;//Control//your keycodes fail xD o-o, why. Control is A0i think you'll find...
		break;

	case 28:
		AutoSkillKey5 = 0x21;//Page Up
		break;

	case 29:
		AutoSkillKey5 = 0x22;//Page Down
		break;

	case 30:
		AutoSkillKey5 = 0x23;//End
		break;

	case 31:
		AutoSkillKey5 = 0x24;//Home
		break;

	case 32:
		AutoSkillKey5 = 0x2E;//Delete
		break;
	default:
		AutoSkillKey5 = 0xA0;//shift, if mistake/fail, it will always pick default // this will never happen as long as you don't add to many options to your combobox
		break;
	}
}

DWORD dwFullGodMode1 = 0x00F6D820; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 81 EC ?? ?? ?? ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 84 24 ?? ?? ?? ?? 64 A3 ?? ?? ?? ?? 8B F1 C7 44 24 ?? ?? ?? ?? ?? 8B 2D ?? ?? ?? ?? 8D 84 24 ?? ?? ?? ?? 50 8B CD
DWORD dwFullGodMode2 = 0x00844870; //55 8D 6C 24 ?? 83 EC ?? 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? A1 ?? ?? ?? ?? 33 C5 89 45 ?? 53 56 57 50 8D 45 ?? 64 A3 ?? ?? ?? ?? 8B F9 8B 87 ?? ?? ?? ?? 8B 88 ?? ?? ?? ?? 51
BYTE bEnableFullGodMode1[] = { 0xC2, 0x04, 0x00 };
BYTE bEnableFullGodMode2[] = { 0xC2, 0x04, 0x00 };
BYTE bDisableFullGodMode1[] = { 0x6A, 0xFF, 0x68 };
BYTE bDisableFullGodMode2[] = { 0x55, 0x8D, 0x6C };

void MyForm::checkBox1_CheckedChanged_12(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwFullGodMode1, 3, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwFullGodMode2, 3, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->FGM->Checked)
	{
		memcpy((void*)dwFullGodMode1, bEnableFullGodMode1, sizeof(bEnableFullGodMode1));
		memcpy((void*)dwFullGodMode2, bEnableFullGodMode2, sizeof(bEnableFullGodMode2));
	}
	else
	{
		memcpy((void*)dwFullGodMode1, bDisableFullGodMode1, sizeof(bDisableFullGodMode1));
		memcpy((void*)dwFullGodMode2, bDisableFullGodMode2, sizeof(bDisableFullGodMode2));
	}

	VirtualProtect((LPVOID)dwFullGodMode1, 3, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwFullGodMode2, 3, oldProtect, &oldProtect);
}

DWORD dwNoMagnusBalls = 0x00699BF0; //55 8B EC 83 E4 ?? 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? 8B E9 33 C9
BYTE bEnableNoMagnusBalls[] = { 0xC3 };
BYTE bDisableNoMagnusBalls[] = { 0x55 };

void MyForm::checkBox1_CheckedChanged_13(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoMagnusBalls, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NMB->Checked)
	{
		memcpy((void*)dwNoMagnusBalls, bEnableNoMagnusBalls, sizeof(bEnableNoMagnusBalls));
	}
	else
	{
		memcpy((void*)dwNoMagnusBalls, bDisableNoMagnusBalls, sizeof(bDisableNoMagnusBalls));
	}

	VirtualProtect((LPVOID)dwNoMagnusBalls, 1, oldProtect, &oldProtect);
}

DWORD dwNoSkillEffect = 0x00ECD860; //0F 85 ?? ?? ?? ?? 8B 7D ?? 3B FB 0F 84 ?? ?? ?? ?? 8B 06
BYTE bEnableNoSkillEffect[] = { 0x90, 0xE9 };
BYTE bDisableNoSkillEffect[] = { 0x0F, 0x85 };

void MyForm::checkBox1_CheckedChanged_14(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoSkillEffect, 2, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NSE->Checked)
	{
		memcpy((void*)dwNoSkillEffect, bEnableNoSkillEffect, sizeof(bEnableNoSkillEffect));
	}
	else
	{
		memcpy((void*)dwNoSkillEffect, bDisableNoSkillEffect, sizeof(bDisableNoSkillEffect));
	}

	VirtualProtect((LPVOID)dwNoSkillEffect, 2, oldProtect, &oldProtect);
}

DWORD dwLogoSkipper = 0x008018E9; //74 ?? 2B F8 81 FF ?? ?? ?? ?? 0F 86 ?? ?? ?? ?? 5F
BYTE bEnableLogoSkipper[] = { 0x75 };
BYTE bDisableLogoSkipper[] = { 0x74 };

void MyForm::checkBox1_CheckedChanged_15(System::Object^  sender, System::EventArgs^  e)
{
	/*unsigned long oldProtect;
	VirtualProtect((LPVOID)dwLogoSkipper, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->LS->Checked)
	{
		memcpy((void*)dwLogoSkipper, bEnableLogoSkipper, sizeof(bEnableLogoSkipper));
	}
	else
	{
		memcpy((void*)dwLogoSkipper, bDisableLogoSkipper, sizeof(bDisableLogoSkipper));
	}

	VirtualProtect((LPVOID)dwLogoSkipper, 1, oldProtect, &oldProtect);*/
}

DWORD dwScareMobs = 0x0088A204; //74 ?? 8B CE E8 ?? ?? ?? ?? 85 C0 75 ?? 8B CE E8 ?? ?? ?? ?? 8B B8 ?? ?? ?? ?? 3B FB
BYTE bEnableScareMobs[] = { 0x75 };
BYTE bDisableScareMobs[] = { 0x74 };

void MyForm::checkBox1_CheckedChanged_16(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwScareMobs, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->SM->Checked)
	{
		memcpy((void*)dwScareMobs, bEnableScareMobs, sizeof(bEnableScareMobs));
	}
	else
	{
		memcpy((void*)dwScareMobs, bDisableScareMobs, sizeof(bDisableScareMobs));
	}

	VirtualProtect((LPVOID)dwScareMobs, 1, oldProtect, &oldProtect);
}

DWORD dwCPUhack1 = 0x00826753; // E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 51 8B C4
DWORD dwCPUhack2 = 0x0082674C; // E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 51 8B C4
DWORD dwCPUhack3 = 0x00826745; // E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 51 8B C4
DWORD dwCPUhack4 = 0x0050C688; // E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B CF
DWORD dwCPUhack5 = 0x0081BA80; // 55 8D 6C 24 ?? 83 EC ?? 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? A1 ?? ?? ?? ?? 33 C5 89 45 ?? 53 56 57 50 8D 45 ?? 64 A3 ?? ?? ?? ?? 89 4D ?? 51
BYTE bEnableCPUhack1[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableCPUhack2[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableCPUhack3[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableCPUhack4[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableCPUhack5[] = { 0xC2, 0x08, 0x00 };
BYTE bDisableCPUhack1[] = { 0xE8, 0x88, 0x83, 0xFF, 0xFF };
BYTE bDisableCPUhack2[] = { 0xE8, 0x5F, 0x95, 0xFF, 0xFF };
BYTE bDisableCPUhack3[] = { 0xE8, 0x56, 0xF7, 0xFF, 0xFF };
BYTE bDisableCPUhack4[] = { 0xE8, 0xFD, 0x45, 0xFF, 0xFF };
BYTE bDisableCPUhack5[] = { 0x55, 0x8D, 0x6C };

void MyForm::checkBox1_CheckedChanged_17(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;

	VirtualProtect((LPVOID)dwCPUhack1, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack2, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack3, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack4, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack5, 3, PAGE_EXECUTE_READWRITE, &oldProtect);
	if (this->CPU->Checked)
	{
		memcpy((void*)dwCPUhack1, bEnableCPUhack1, sizeof(bEnableCPUhack1));
		memcpy((void*)dwCPUhack2, bEnableCPUhack2, sizeof(bEnableCPUhack2));
		memcpy((void*)dwCPUhack3, bEnableCPUhack3, sizeof(bEnableCPUhack3));
		memcpy((void*)dwCPUhack4, bEnableCPUhack4, sizeof(bEnableCPUhack4));
		memcpy((void*)dwCPUhack5, bEnableCPUhack5, sizeof(bEnableCPUhack5));
	}
	else
	{
		memcpy((void*)dwCPUhack1, bDisableCPUhack1, sizeof(bDisableCPUhack1));
		memcpy((void*)dwCPUhack2, bDisableCPUhack2, sizeof(bDisableCPUhack2));
		memcpy((void*)dwCPUhack3, bDisableCPUhack3, sizeof(bDisableCPUhack3));
		memcpy((void*)dwCPUhack4, bDisableCPUhack4, sizeof(bDisableCPUhack4));
		memcpy((void*)dwCPUhack5, bDisableCPUhack5, sizeof(bDisableCPUhack5));
	}

	VirtualProtect((LPVOID)dwCPUhack1, 5, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack2, 5, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack3, 5, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack4, 5, oldProtect, &oldProtect);
	VirtualProtect((LPVOID)dwCPUhack5, 3, oldProtect, &oldProtect);
}

DWORD dwNoBreath = 0x00504B23; //79 ?? 8B 86 ?? ?? ?? ?? 8B D0 83 E2 ?? C7 86 ?? ?? ?? ?? ?? ?? ?? ?? 83 FA ?? 75 ?? 8B 16
BYTE bEnableNoBreath[] = { 0x90, 0x90 };
BYTE bDisableNoBreath[] = { 0x79, 0x2C };

void MyForm::checkBox1_CheckedChanged_18(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoBreath, 2, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NoBreath->Checked)
	{
		memcpy((void*)dwNoBreath, bEnableNoBreath, sizeof(bEnableNoBreath));
	}
	else
	{
		memcpy((void*)dwNoBreath, bDisableNoBreath, sizeof(bDisableNoBreath));
	}

	VirtualProtect((LPVOID)dwNoBreath, 2, oldProtect, &oldProtect);
}

DWORD dwNoMobKB = 0x00872DF9; //04 ?? C9 EB ?? 8B CF 8D 56 ?? E8 ?? ?? ?? ?? 8B 8C 24 ?? ?? ?? ?? 8D 96 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 8C 24 ?? ?? ?? ?? 8D 96 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 8C 24 ?? ?? ?? ?? 8D 96 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8D 9E ?? ?? ?? ?? 8B D3
BYTE bEnableNoMobKB[] = { 0x00 };
BYTE bDisableNoMobKB[] = { 0x04 };

void MyForm::checkBox1_CheckedChanged_19(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoMobKB, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NoMobKB->Checked)
	{
		memcpy((void*)dwNoMobKB, bEnableNoMobKB, sizeof(bEnableNoMobKB));
	}
	else
	{
		memcpy((void*)dwNoMobKB, bDisableNoMobKB, sizeof(bDisableNoMobKB));
	}

	VirtualProtect((LPVOID)dwNoMobKB, 1, oldProtect, &oldProtect);
}

DWORD dwNoKB = 0x00A350FB; //01 00 00 00 D8 D1 DF E0 F6 C4 ?? 7A ?? DC 91 ?? ?? ?? ?? DF E0 F6 C4 ?? 7A ?? D9 C0
BYTE bEnableNoKB[] = { 0x00 };
BYTE bDisableNoKB[] = { 0x01 };

void MyForm::checkBox1_CheckedChanged_20(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwNoKB, 1, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->NoKB->Checked)
	{
		memcpy((void*)dwNoKB, bEnableNoKB, sizeof(bEnableNoKB));
	}
	else
	{
		memcpy((void*)dwNoKB, bDisableNoKB, sizeof(bDisableNoKB));
	}

	VirtualProtect((LPVOID)dwNoKB, 1, oldProtect, &oldProtect);
}

DWORD dwFullMobDisarm = 0x008896B6; //75 ?? 8B CE E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 8B 96 ?? ?? ?? ?? 52
BYTE bEnableFullMobDisarm[] = { 0xE9, 0x43, 0x04, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90}; //8B 86 ?? ?? ?? ?? 85 C0 0F 84 ?? ?? ?? ?? 2B 45 ?? 0F 89 ?? ?? ?? ?? C7 45 ?? ?? ?? ?? ?? 8D 55 ?? 68 ?? ?? ?? ?? 52
BYTE bDisableFullMobDisarm[] = {0x75, 0x15, 0x8B, 0xCE, 0xE8, 0xC1, 0xC6, 0xFE, 0xFF};

void MyForm::checkBox1_CheckedChanged_21(System::Object^  sender, System::EventArgs^  e)
{
	unsigned long oldProtect;
	VirtualProtect((LPVOID)dwFullMobDisarm, 9, PAGE_EXECUTE_READWRITE, &oldProtect);

	if (this->FMD->Checked)
	{
		memcpy((void*)dwFullMobDisarm, bEnableFullMobDisarm, sizeof(bEnableFullMobDisarm));
	}
	else
	{
		memcpy((void*)dwFullMobDisarm, bDisableFullMobDisarm, sizeof(bDisableFullMobDisarm));
	}

	VirtualProtect((LPVOID)dwFullMobDisarm, 9, oldProtect, &oldProtect);
}

BOOL WriteMemory(DWORD dwAddress, const void* cpvPatch, DWORD dwSize)
{
	//http://www.progamercity.net/c-code/369-c-memory-writing-functions.html
	DWORD dwProtect;

	if (VirtualProtect((void*)dwAddress, dwSize, PAGE_READWRITE, &dwProtect)) //Unprotect the memory
		memcpy((void*)dwAddress, cpvPatch, dwSize); //Write our patch
	else
		return false; //Failed to unprotect, so return false..

	return VirtualProtect((void*)dwAddress, dwSize, dwProtect, new DWORD); //Reprotect the memory
}

void JumpCall(BOOL bFunction, DWORD dwAddress, LPVOID lpvDestination, size_t cNops)
{
	DWORD dwProtection;
	VirtualProtect(reinterpret_cast<LPVOID>(dwAddress), 16, PAGE_READWRITE, &dwProtection);
	//TRUE=E9 = JMP
	//FALSE=E8 = CALL
	*reinterpret_cast<LPBYTE>(dwAddress) = (bFunction ? 0xE9 : 0xE8);
	*reinterpret_cast<DWORD*>(dwAddress + 1) = reinterpret_cast<DWORD>(lpvDestination)-dwAddress - 5;
	memset(reinterpret_cast<LPVOID>(dwAddress + 5), 0x90, cNops);

	VirtualProtect(reinterpret_cast<LPVOID>(dwAddress), 16, dwProtection, new DWORD);
}

DWORD fusionaddy = 0x0088C5C2;
DWORD fusionret = fusionaddy + 0x08;
BYTE Fusiondisable[] = { 0x89, 0x34, 0x81, 0x40, 0x89, 0x44, 0x24, 0x1C };

void __declspec(naked) FusionEnable() {
	__asm {
	
	Hook:
		mov[ecx + eax * 4], esi
			inc eax
			cmp eax, [esp + 0x68]
			jl Hook
			mov[esp + 0x1C], eax
			jmp [fusionret]


	}
}

void MyForm::checkBox1_CheckedChanged_22(System::Object^  sender, System::EventArgs^  e) {
	if (this->FA->Checked == true) {
		JumpCall(TRUE, fusionaddy, FusionEnable, 3);
	}
	else {
		//JumpCall(TRUE, fusionaddy, Fusiondisable, 3);
		//memcpy((void*)fusionaddy, Fusiondisable, sizeof(Fusiondisable));
		//WriteMemory(fusionaddy, 8, 0x89, 0x34, 0x81, 0x40, 0x89, 0x44, 0x24, 0x1C);
		WriteMemory(fusionaddy, Fusiondisable, sizeof(Fusiondisable));
	}
}

DWORD nobuffaddy = 0x00EBB660;
DWORD nobuffret = nobuffaddy + 0x05;
BYTE nobuffdisable[] = { 0x83, 0xEC, 0x1C, 0x53, 0x57 };

void __declspec(naked) NoBuffEnable() {
	__asm {
	       newmem:
	    	cmp dword ptr[esp], 0x00F859E2 //83 ? ? ? ? 0 0 74 ? e8 ? ? ? ? 8b ? ? ? ? ? 8b
			jne originalcode
			retn 0x10

	     	originalcode :
					 sub esp, 0x1C
					 push ebx
					 push edi
					 jmp [nobuffret]

					 nobuffaddy: //83 ec ? ? ? 33 ? ? 8b ? ? 89 ? ? 18 89 ? ? 10 e8
	               	jmp [newmem]
	            	nobuffret:

	}
}

void MyForm::checkBox1_CheckedChanged_23(System::Object^  sender, System::EventArgs^  e) {
	if (this->NBD->Checked == true) {
		JumpCall(TRUE, nobuffaddy, NoBuffEnable, 0);
	}
	else {
		//JumpCall(TRUE, fusionaddy, Fusiondisable, 3);
		//memcpy((void*)fusionaddy, Fusiondisable, sizeof(Fusiondisable));
		//WriteMemory(fusionaddy, 8, 0x89, 0x34, 0x81, 0x40, 0x89, 0x44, 0x24, 0x1C);
		WriteMemory(nobuffaddy, nobuffdisable, sizeof(nobuffdisable));
	}
}


DWORD mobdeathcountaddy = 0x0088EA40; // E8 ?? ?? ?? ?? EB ?? 8B CE E8 ?? ?? ?? ?? EB ??
DWORD mobdeathret = mobdeathcountaddy + 0x05;
DWORD killcountcall = 0x00881250;
DWORD mobdeathcountDisable[] = { killcountcall };

void __declspec(naked) MobDeathCountEnable() {
	__asm {
		jmp hook
		hookret :

	hook :
		inc[KillCount]
		call[killcountcall] //call to Cmob::OnDie()
		jmp[mobdeathret]

	}
}



void MyForm::bEmbedMS_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Width = 1150;
	this->Height = 631;
	this->panel1->Location = System::Drawing::Point(799, -1);
	HWND EmbedWindow = (HWND)this->Handle.ToPointer();
	EmbedMapleStory(EmbedWindow);
	this->bEmbedMS->Enabled = false;
}


void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	hMapleStory = FindWindowA("MapleStoryClass", 0);
	DWORD pID = GetCurrentProcessId();
	this->Text = "DigiZbot EMS V104 - pID: " + pID;
	JumpCall(TRUE, mobdeathcountaddy, MobDeathCountEnable, 0);
	memcpy((void*)dwLogoSkipper, bEnableLogoSkipper, sizeof(bEnableLogoSkipper));
	memcpy((void*)dwPinPicTyper1, bEnablePinPicTyper1, sizeof(bEnablePinPicTyper1));
	memcpy((void*)dwPinPicTyper2, bEnablePinPicTyper2, sizeof(bEnablePinPicTyper2));
	memcpy((void*)dwPinPicTyper3, bEnablePinPicTyper3, sizeof(bEnablePinPicTyper3));
	memcpy((void*)dwPinPicTyper4, bEnablePinPicTyper4, sizeof(bEnablePinPicTyper4));
	memcpy((void*)dwPinPicTyper5, bEnablePinPicTyper5, sizeof(bEnablePinPicTyper5));
	memcpy((void*)dwPinPicTyper6, bEnablePinPicTyper6, sizeof(bEnablePinPicTyper6));

}

bool WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
	__try { *(int*)(*(unsigned long*)ulBase + iOffset) = iValue; return true; }
	__except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

unsigned long ReadPointer(unsigned long ulBase, int iOffset)
{
	__try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
	__except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}

unsigned long GetValue(unsigned long ulBase, int iOffset)
{
	__try { return *(unsigned long*)(ulBase + iOffset); }
	__except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}

bool WriteValue(unsigned long ulBase, int iOffset, int iValue)
{
	__try { *(int*)(ulBase + iOffset) = iValue; return true; }
	__except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}


int getPeople()
{
	return (int)ReadPointer(PeopleBasePtr, PeopleCountOffset);
}

int getWorld()
{
	return (int)ReadPointer(ServerPtr, WorldOffset);
}

int getChannel()
{
	return (int)ReadPointer(ServerPtr, ChannelOffset);
}

int getMobCount()
{
	return (int)ReadPointer(MobAddy, MobCountOffset);
}

int getMapID()
{
	return (int)ReadPointer(CharMapInfoAddy, MapIdOffset);
}

int getCharX()
{
	return (int)ReadPointer(CharMapInfoAddy, CharXOffset);
}

int getCharY()
{
	return (int)ReadPointer(CharMapInfoAddy, CharYOffset);
}

int GetCurrentEXPP()
{
	return (int)ReadPointer(StatsBase, EXP);
}

DWORD Stat = 0x00DBC890; // E8 ? ? ? ? 83 ? ? 8B ? 89 ? ? ? 68 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 8B ? ? ? E8 - "call"
DWORD StatReturn = Stat + 0x07; // 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 55 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? 8B F1 A1 ?? ?? ?? ?? 8B 48 ??
BYTE statdisable[] = { 0x6A, 0xFF, 0x68, 0xD0, 0x66 };


int CurrentHealth = 0, MaximumHealth = 0, CurrentMana = 0, MaximumMana = 0, CurrentExperience = 0, MaximumExperience = 0;

void __declspec(naked) StatHookHook()
{
	__asm
	{
		mov eax, [esp + 0x04]
			mov[CurrentHealth], eax
			mov eax, [esp + 0x08]
			mov[MaximumHealth], eax
			mov eax, [esp + 0x0C]
			mov[CurrentMana], eax
			mov eax, [esp + 0x010]
			mov[MaximumMana], eax
			mov eax, [esp + 0x014]
			mov[CurrentExperience], eax
			mov eax, [esp + 0x018]
			mov[CurrentExperience + 0x04], eax
			mov eax, [esp + 0x01C]
			mov[MaximumExperience], eax
			mov eax, [esp + 0x020]
			mov[MaximumExperience + 0x04], eax
			push - 0x01
			push 0x012566D0 // "OriginalOpcode"
			jmp StatReturn
	}
}


void StatHookFunction(bool Enable)
{
	Asm::Write_Hook("jmp", Stat, (DWORD)StatHookHook, 2);
}

void MyForm::checkBox1_CheckedChanged_28(System::Object^  sender, System::EventArgs^  e) {
	if (this->HookStats->Checked == true) {

		JumpCall(TRUE, Stat, StatHookHook, 0);
	}
	else
	{

		WriteMemory(Stat, statdisable, sizeof(statdisable));
	}
}
void MyForm::tInfo_Tick(System::Object^  sender, System::EventArgs^  e)
{

	this->lPeople->Text = "People: " + getPeople().ToString();
	Channel = System::Convert::ToInt32(getChannel() + 1);
	this->lChannel->Text = "Channel:" + Channel;
	this->lMonsters->Text = "Mobs: " + getMobCount().ToString();
	this->MapID->Text = "Map ID: " + getMapID().ToString();
	this->CharXY->Text = "Char X,Y:" + getCharX().ToString() + "," + getCharY().ToString();
	this->lKillCount->Text = "Kill Count: " + KillCount.ToString();
	this->ZCurrentEXP->Text = "Current EXP: " + GetCurrentEXPP().ToString();

	switch (getWorld())
	{
	case 0:
	
		this->lWorld->Text = "World: Kradia";
		break;

	case 1:
		
		this->lWorld->Text = "World: Demethos" ;
		break;

	case 2:

		this->lWorld->Text = "World: Supreme";
		break;
	}
}


void MyForm::nudCCPeople_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	CCPeople = Convert::ToInt32(this->nudCCPeople->Text);
}


void MyForm::cbAutoCCPeople_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->cbAutoCCPeople->Checked)
	{
		CCPeople = Convert::ToInt32(this->nudCCPeople->Text);
		AutoCCPeopleEnabled = true;
		NewThread(AutoCCPeople);
	}
	else
	{
		AutoCCPeopleEnabled = false;
	}
}
int channel;
void DoCC()
{
	
	Sleep(5000);
	int NextChannel = rand() % 14;
     if (NextChannel == 0) { PS::SendPacket("4B 00 00 27 64 72 2A"); }
	 else if (NextChannel == 1) { PS::SendPacket("4B 00 01 27 64 72 2A"); }
	 else if (NextChannel == 2) { PS::SendPacket("4B 00 02 27 64 72 2A"); }
	 else if (NextChannel == 3) { PS::SendPacket("4B 00 03 27 64 72 2A"); }
	 else if (NextChannel == 4) { PS::SendPacket("4B 00 04 27 64 72 2A"); }
	 else if (NextChannel == 5) { PS::SendPacket("4B 00 05 27 64 72 2A"); }
	 else if (NextChannel == 6) { PS::SendPacket("4B 00 06 27 64 72 2A"); }
	 else if (NextChannel == 7) { PS::SendPacket("4B 00 07 27 64 72 2A"); }
	 else if (NextChannel == 8) { PS::SendPacket("4B 00 08 27 64 72 2A"); }
	 else if (NextChannel == 9) { PS::SendPacket("4B 00 09 27 64 72 2A"); }
	 else if (NextChannel == 10) { PS::SendPacket("4B 00 0A 27 64 72 2A"); }
	 else if (NextChannel == 11) { PS::SendPacket("4B 00 0B 27 64 72 2A"); }
	 else if (NextChannel == 12) { PS::SendPacket("4B 00 0C 27 64 72 2A"); }
	 else if (NextChannel == 13) { PS::SendPacket("4B 00 0D 27 64 72 2A"); }

}


void AutoCCPeople()
{
	while (AutoCCPeopleEnabled)
	{
		if (getPeople() >= CCPeople)
		{
			DoCC();
		}
		Sleep(50);
	}
	if (!AutoCCPeopleEnabled)
	{
		ExitThread(0);
	}
}

void MyForm::nudCCDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	CCDelay = Convert::ToInt32(this->nudCCDelay->Text) * 1000;
}


void MyForm::checkBox1_CheckedChanged_32(System::Object^  sender, System::EventArgs^  e)
{
	if (this->cbAutoCCDelay->Checked)
	{
		CCDelay = Convert::ToInt32(this->nudCCDelay->Text) * 1000;
		AutoCCDelayEnabled = true;
		NewThread(AutoCCDelay);
	}
	else
	{
		AutoCCDelayEnabled = false;
	}
}

void AutoCCDelay()
{
	while (AutoCCDelayEnabled)
	{
		Sleep(CCDelay);
		DoCC();
	}
	if (!AutoCCDelayEnabled)
	{
		ExitThread(0);
	}
}


int Counter = 0;
int Delay = 1000;
DWORD SkillID = 0x00000000;
DWORD skillinjectaddy1 = 0x00F8BB7C;
DWORD skillinjectaddy2 = 0x00F8BBA5;
DWORD skillinjectaddy3 = 0x00F8BCA0;
DWORD skillinjectaddy4 = 0x00F8BCB4;
DWORD skillinjectaddy5 = 0x00F8BCBA;
DWORD skillinjectret1 = 0x00F8BD55;
DWORD skillinjectret2 = 0x00F8BD62;
DWORD skillinjectret3 = 0x00F3C29D;
DWORD skillinjectret4 = 0x00F29308;
BYTE bEnableSkillinject1[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableSkillinject2[] = { 0xE9, 0xEC, 0x00, 0x00, 0x00, 0x00 };
BYTE bEnableSkillinject3[] = { 0x74 };
BYTE bEnableSkillinject4[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableSkillinjectret1[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableSkillinjectret2[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE bEnableSkillinjectret3[] = { 0x74 };
BYTE bEnableSkillinjectret4[] = { 0x7D, 0x00 };
BYTE skillinjectdisable1[] = { 0x0F, 0x84, 0x95, 0x02, 0x00, 0x00 };
BYTE skillinjectdisable2[] = { 0x0F, 0x84 };
BYTE skillinjectdisable3[] = { 0x75 };
BYTE skillinjectdisable4[] = { 0x0F, 0x85, 0x53, 0x01, 0x00, 0x00, 0x8B, 0x8E, 0x14, 0x96, 0x00, 0x00 };
BYTE skillinjectdisable5[] = { 0x8B, 0x8E, 0x14, 0x96, 0x00, 0x00 };
BYTE skillinjectdisable6[] = { 0x0F, 0x87, 0xB2, 0x00, 0x00, 0x00 };
BYTE skillinjectdisable7[] = { 0xFF, 0x24, 0x85, 0xE0, 0x6C, 0xF4, 0x00 };
BYTE skillinjectdisable8[] = { 0x75 };
BYTE skillinjectdisable9[] = { 0x7D, 0x06 };

DWORD skillinjectreturn = 0x00F46B7A + 6;//original address + 6 bytes = return address

void __declspec(naked) skillinjectEnable() {
	__asm {
		push eax
			mov eax, [Counter]
			cmp eax, [Delay]
			pop eax
			jge SkillInjection_inject

			inc[Counter]
			mov ecx, [esi + 0x000096C4]
			jmp skillinjectreturn
			
		SkillInjection_inject:
		mov[Counter], 0
			mov ecx, [SkillID]
			jmp skillinjectreturn

  }
}
//
void MyForm::skillID_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	
}

void MyForm::textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	
}

void MyForm::checkBox1_CheckedChanged_29(System::Object^  sender, System::EventArgs^  e) {
	if (this->skillinject->Checked == true) {
		SkillID = Convert::ToInt32(this->skillID->Text);
		Delay = Convert::ToInt32(this->SkillinjectDelay->Text);
		WriteMemory(skillinjectaddy1, bEnableSkillinject1, sizeof(bEnableSkillinject1));
		WriteMemory(skillinjectaddy2, bEnableSkillinject2, sizeof(bEnableSkillinject2));
		WriteMemory(skillinjectaddy3, bEnableSkillinject3, sizeof(bEnableSkillinject3));
		WriteMemory(skillinjectaddy4, bEnableSkillinject4, sizeof(bEnableSkillinject4));
		JumpCall(TRUE, skillinjectaddy5, skillinjectEnable, 0);
		WriteMemory(skillinjectret1, bEnableSkillinjectret1, sizeof(bEnableSkillinjectret1));
		WriteMemory(skillinjectret2, bEnableSkillinjectret2, sizeof(bEnableSkillinjectret2));
		WriteMemory(skillinjectret3, bEnableSkillinjectret3, sizeof(bEnableSkillinjectret3));
		WriteMemory(skillinjectret4, bEnableSkillinjectret4, sizeof(bEnableSkillinjectret4));
	}
	else {
		WriteMemory(skillinjectaddy1, skillinjectdisable1, sizeof(skillinjectdisable1));
		WriteMemory(skillinjectaddy2, skillinjectdisable2, sizeof(skillinjectdisable2));
		WriteMemory(skillinjectaddy3, skillinjectdisable3, sizeof(skillinjectdisable3));
		WriteMemory(skillinjectaddy4, skillinjectdisable4, sizeof(skillinjectdisable4));
		WriteMemory(skillinjectaddy5, skillinjectdisable5, sizeof(skillinjectdisable5));
		WriteMemory(skillinjectret1, skillinjectdisable6, sizeof(skillinjectdisable6));
		WriteMemory(skillinjectret2, skillinjectdisable7, sizeof(skillinjectdisable7));
		WriteMemory(skillinjectret3, skillinjectdisable8, sizeof(skillinjectdisable8));
		WriteMemory(skillinjectret4, skillinjectdisable9, sizeof(skillinjectdisable9));
	}
}

int TotalIncMeso = 0;

int LastIncMeso = 0; 

DWORD mesocount = 0x010D8EA9;//8B 4C 24 ?? 55 E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? 3B C3
DWORD mesoret = mesocount + 0x05;
BYTE mesocountdisable[] = { 0x8B, 0x4C, 0x24, 0x18, 0x55 };

void __declspec(naked) mesocountEnable() {
	__asm {
		jmp hook
		mesoret :

	hook :
		add[TotalIncMeso], ebp
		mov[LastIncMeso], ebp
		mov ecx, [esp + 0x18]
		push ebp
		jmp mesoret

	}
}

void MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (MC->Checked)// if MC->Checked == true
	{
		label8->Text = Convert::ToString(TotalIncMeso)+" mesos";
		label9->Text = (TotalIncMeso / 1000.0).ToString("f2") + " k mesos";
		label10->Text = (TotalIncMeso / 1000000.0).ToString("f2") + " million mesos";
		label11->Text = Convert::ToString(TotalIncMeso / 1000000000) + " billion mesos";
		
	
	}
	else
	{
		label8->Text = "0"+" mesos";
        label9->Text = "0" + " k mesos";
		label10->Text = "0" + " million mesos";
		label11->Text = "0" + " billion mesos";

	}
}


void MyForm::checkBox1_CheckedChanged_30(System::Object^  sender, System::EventArgs^  e) {
	if (this->MC->Checked == true) {
		JumpCall(TRUE, mesocount, mesocountEnable, 0);
	}
	else
	{
		TotalIncMeso = 0;
		WriteMemory(mesocount, mesocountdisable, sizeof(mesocountdisable));
	}
}

DWORD vacright = 0x010117A0; //75 ?? DC 11 DF E0 F6 C4 ?? 75 ?? D9 C9
BYTE vacrightenable[] = { 0x75, 0x48 };
BYTE vacrightdisable[] = {0x75, 0x23};


void MyForm::checkBox1_CheckedChanged_31(System::Object^  sender, System::EventArgs^  e) {
	if (this->VR->Checked == true) {
		WriteMemory(vacright, vacrightenable, sizeof(vacrightenable));
	}
	else
	{
		WriteMemory(vacright, vacrightdisable, sizeof(vacrightdisable));
	}
}

DWORD mobspeedup = 0x008A5ED3; //75 ? 33 DB 8D ?? ?? 00 00 00
BYTE mobspeedupenable[] = { 0x90, 0x90 };
BYTE mobspeedupdisable[] = { 0x75, 0x9B };

void MyForm::MSU_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->MSU->Checked == true) {
		WriteMemory(mobspeedup, mobspeedupenable, sizeof(mobspeedupenable));
	}
	else
	{
		WriteMemory(mobspeedup, mobspeedupdisable, sizeof(mobspeedupdisable));
	}
}

DWORD hwid = 0x007B86A0; //6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? 33 C4
DWORD hwid2 = 0x01106D60;//81 EC ?? ?? ?? ?? 33 C0 53 89 44 24 ?? 56
BYTE hwidenable[] = { 0xC2, 0x04, 0x00 };
BYTE hwidenable2[] = { 0xC3 };
BYTE hwiddisable[] = { 0x6A, 0xFF, 0x68 };
BYTE hwiddisable2[] = { 0x81 };

void MyForm::checkBox1_CheckedChanged_33(System::Object^  sender, System::EventArgs^  e) {
	if (this->MSU->Checked == true) {
		WriteMemory(hwid, hwidenable, sizeof(hwidenable));
		WriteMemory(hwid2, hwidenable2, sizeof(hwidenable2));
	}
	else
	{
		WriteMemory(hwid, hwiddisable, sizeof(hwiddisable));
		WriteMemory(hwid2, hwiddisable2, sizeof(hwiddisable2));
	}
}

DOUBLE ReadDoublePointer(DWORD ulBase, INT iOffset)
{
	__try
	{
		return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset));
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0.0;
	}
}
double GetCurrentEXP()
{
	return(double)ReadDoublePointer(CharBasePtr, EXPOffset);
}



double yEXP, cEXP, lEXP, gEXP, nEXP, hEXP, mmEXP, ddEXP;

int Interval = 6000;
double Expold = 0;
double Expnew = 0;
double Expdif = 0;
int Interval2 = Interval / 1000;


void MyForm::cbTopMost_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->TopMost = this->cbTopMost->Checked;
}


void MyForm::tEXP_Tick(System::Object^  sender, System::EventArgs^  e)
{

       yEXP = CurrentExperience;
       mmEXP = MaximumExperience;
       ddEXP = yEXP / mmEXP *100.00;
	   lEXP = 100 - ddEXP;

		double mEXP = (lEXP / gEXP);
    	double hEXP = ((lEXP / gEXP) / 60);


		
     	this->lCurrentEXP->Text = ddEXP.ToString("f2") + "%";

    	this->lEXPTillLevelUp->Text = lEXP.ToString("f2") + "%";
		this->lMinutesTillLevelUp->Text = mEXP.ToString("f0");
		this->lHoursToLevelUp->Text = hEXP.ToString("f0");
					
	while (expTimerbool)
		{
		Expold = CurrentExperience;
		Sleep(Interval);
		Expnew = CurrentExperience;
		Expdif = Expnew - Expold;
		double x = (int)(Expdif * 100 + 0.5) / 100.0;
		int Interval2 = Interval / 1000;
		this->lEXPMinute->Text = (x.ToString() + "% in " + Interval2.ToString() + " Seconds.");

	}
}
	
		


void MyForm::tFirst_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (this->cbFirst->Checked)
	{
		cEXP = CurrentExperience;
		this->tSecond->Enabled = true;
		this->cbFirst->Checked = false;
	}

	if (this->cbSecond->Checked)
	{
		nEXP = CurrentExperience;
		gEXP = (nEXP - cEXP);
		this->cbSecond->Checked = false;
		this->cbFirst->Checked = true;
	}
}

void MyForm::tSecond_Tick(System::Object^ sender, System::EventArgs^ e)
{
	this->cbSecond->Checked = true;
	this->tSecond->Enabled = false;
}


