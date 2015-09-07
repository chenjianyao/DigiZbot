#define Pointers_H
#include <windows.h>
#include <stdint.h>


//Variables (global)

//WriteMemory
//extern BOOL WriteMemory(DWORD dwAddress, const void* cpvPatch, DWORD dwSize);
//void WriteMemory(unsigned long ulAddress, unsigned long ulAmount, ...);

#pragma warning (disable: 4005)



//Definitions
#define GetPointer(Base, Off) ReadPointer((ULONG_PTR*)Base, Off);
DOUBLE ReadDoublePointer(DWORD ulBase, INT iOffset);
#define NewThread(lol) CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&lol, NULL, NULL, NULL);
//#define SendKey(KeyPress) PostMessage(FindWindow("MapleStoryClass", 0), WM_KEYDOWN, KeyPress, (MapVirtualKey(KeyPress, 0) << 16) + 1);
//#define SendKey(Key) PostMessage(FindWindow(L"MapleStoryClass", 0), WM_KEYDOWN, Key, (MapVirtualKey(Key, 0) << 16) + 1)
//auto att
bool bAttackEnabled = false;                                                            //false/true
DWORD dwAttackKey = 0xA2;                                                                //left controwl key



//extern void SendKey(DWORD dwKeyPress);




/**
* Contains updated adresses for MapleStory v103.1
* Updated using Waty's Automated AOB scanner
*/
#define CUserLocalPtr = 0x15A8688; //TSingleton<CUserLocal>
#define AttackCountOffset = 0x9950; //CUserLocal::AttackCount
#define BuffCountOffset = 0x9960; //CUserLocal::BuffCount
#define BreathOffset = 0x668; //CUserLocal::BreathValue
#define ItemIdOffset = 0x8C3D; //CUserLocal::nHoveredItem
#define ComboOffset = 0x0!; //CUserLocal::ComboCount
#define PetOffset = 0x7710; //CUserLocal::Pet
#define PetFullnessOffset = 0x0!; //CUserLocal::Pet::Fullnes
#define TeleportToggleOffset = 0x970C; //CUserLocal::bShouldTeleport
#define LocationPointOffset = 0xA738; //CUserLocal::ptCurPos
#define TeleportPointOffset = 0x9724; //CUserLocal::ptTeleportCoords
#define TryDoingTeleportAddy = 0xF70BC0; //CUserLocal::TryDoingTeleport
#define KamiFloatAddy = 0xF70D8F; //Change push 0 to push 1 to keep floating
#define StaticChatLogAddAddy = 0x4D4A10; //CHATLOG_ADD

#define ChatLogAddAddy = 0xD86C30; //CUIStatusBar::ChatLogAdd
#define SetNumberValueAddy = 0xDBC890; //CUIStatusBar::SetNumberValue
#define SetStatusValueAddy = 0xDB0190; //CUIStatusBar::SetStatusValue
#define FlashHPBarAddy = 0xDAD0F0; //CUIStatusBar::FlashHPBar
#define FlashMPBarAddy = 0xDAD2C0; //CUIStatusBar::FlashMPBar
#define MouseBasePtr = 0x15A8694;
#define MouseLocOffset = 0x978;
#define MouseXOffset = 0x98;
#define MouseAniOffset = 0xA2C;


#define TubiOffset = 0x214C; //CWvsContext::bExclRequestSent
#define LastLootTimeOffset = 0x2150; //CWvsContext::tExclRequestSent
#define ShowMiniMapOffset = 0x6940; //CWvsContext::bMiniMapOnOff
#define GetChannelNameAddy = 0x64A890; //CWvsContext::GetChannelName

#define GetItemCountAddy = 0x10BC760; //CWvsContext::GetItemCount
#define OnPacketAddy = 0x10B2A40; //CWvsContext::OnPacket
#define OnDropPickupAddy = 0x7A7B10; //CWvsContext::OnDropPickupMessage
#define SendPickUpRequestAddy = 0x1098140; //CWvsContext::SendDropPickUpRequest
#define MigratoToCashShopAddy = 0x10976B0; //CWvsContext::SendMigrateToShopRequest
#define WallBasePtr = 0x15ACB1C;
#define CUserPoolPtr = 0x15ACB10; //TSingleton<CUserPool> aka UserBasePtr

#define OnUserEnterFieldAddy = 0xF9E3A0; //CUserPool::OnUserEnterField


#define MobDeathOffset = 0x0!; //CMob::nDeathAnimation Wrong?
#define OnMobDieAddy = 0x881250; //CMob::OnDie
#define CDropPoolPtr = 0x15AD28C; //TSingleton<CDropPool>

#define TryPickUpDropAddy = 0x612FC0; //CDropPool::TryPickUpDrop
#define OnDropEnterFieldAddy = 0x619640; //CDropPool::OnDropEnterField
#define AddDropAddy = 0x6145D0; //CDropPool::Add
#define RemoveDropAddy = 0x6125D0; //CDropPool::Remove
#define DropPoolDestructor = 0x612690; //CDropPool::~CDropPool
#define CReactorPoolPtr = 0x15B3D20; //TSingleton<CReactorPool>
#define  ReactorCountOffset = 0xC; //CReactorPool::nReactorCount
#define AddReactorAddy = 0x954A70; //CReactorPool::AddReactor
#define RemoveReactorAddy = 0x94F780; //CReactorPool::RemoveReactor
#define ReactorPoolDestructor = 0x1071210; //CReactorPool::~CReactorPool

#define SendPacketClassAddy = 0x57A970; //CClientSocket::SendPacket
#define CClientSocketFlushAddy = 0x57A5A0; //CClientSocket::Flush
#define SendPacketAddy = 0x0!; //#1 XRef in IDA for SendPacketClass
#define CCAddy = 0x64ACD0; //CField::SendTransferChannelRequest
#define HideMissesAddy = 0x59D6E0; //CAnimationDisplayer::Effect_Miss
#define HideDamageAddy = 0x4B6730; //CAnimationDisplayer::Effect_HP
#define HideSkillsAddy = 0x4D2D00; //CAnimationDisplayer::Effect_SkillUse
#define SetDataAddy = 0x453BA0; //TSecType<long>::SetData
#define GetDataAddy  0x455B80 //TSecType<long>::GetData
#define GetUpdateTimeAddy = 0xFC2EB0; //get_update_time
#define CItemInfoPtr = 0x15A8568; //TSingleton<CItemInfo>
#define GetItemNameAddy = 0x7767D0; //CItemInfo::GetItemName
#define GetItemPriceAddy = 0x7629A0; //CItemInfo::GetItemPrice
#define GetItemString = 0x771B30; //CItemInfo::GetItemString
#define GetItemCRCAddy = 0x79B1B0; //CItemInfo::GetItemCRC
#define CSkillInfoPtr = 0x15A4C00; //TSingleton<CSkillInfo>
#define GetSkillAddy = 0x0!; //CSkillInfo::GetSkill
#define GetSkillLevelAddy = 0x9DE470; //CSkillInfo::GetSkillLevel
#define InitOutPacketAddy = 0x8F6440; //COutPacket::Init
#define COutPacketConstructor = 0x8F65E0; //COutPacket::COutPacket(long)
#define Encode1Addy = 0x0!; //COutPacket::Encode1
#define Encode2Addy = 0x477250; //COutPacket::Encode2
#define Encode4Addy = 0x0!; //COutPacket::Encode4
#define Encode8Addy = 0x4D6740; //COutPacket::Encode8
#define EncodeBufferAddy = 0x5312C0; //COutPacket::EncodeBuffer
#define EncodeStrAddy = 0x4D74C0; //COutPacket::EncodeStr
#define MakeBufferListAddy = 0x8F6650; //COutPacket::MakeBufferList
#define Decode1Addy = 0x0!; //CInPacket::Decode1
#define Decode2Addy = 0x0!; //CInPacket::Decode2
#define Decode4Addy = 0x0!; //CInPacket::Decode4
#define Decode8Addy = 0x408C80; //CInPacket::Decode8
#define DecodeBufferAddy = 0x0!; //CInPacket::DecodeBuffer
#define DecodeStrAddy = 0x48F630; //CInPacket::DecodeStr
#define GetFieldAddy = 0xEFC420; //get_field
#define SendWhisperAddy = 0x0!; //CField::SendChatMsgWhisper
#define CConfigPtr = 0x15ACBE4; //TSingleton<CConfig> aka SettingsBasePtr
#define FMAAddy = 0x8555D0;
#define FullGodmodeAddy1 = 0xF6D820;
#define FullGodmodeAddy2 = 0x885430;
#define IFSReturnAddy1 = 0xF97686;
#define IFSReturnAddy2 = 0xF9285C;
#define SemiBreathAddy = 0x504B1A;
#define NoDelayAddy = 0xF3C2AB;
#define NoMpUsageAddy = 0xF29312; //(85 F6 7D 06 33 F6) + 3
#define MobFreezeAddy = 0x88A332;
#define CNpcPoolPtr = 0x15B3D28; //TSingleton<CNpcPool>
#define OnNpcEnterFieldAddy = 0x8DD190; //CNpcPool::OnNpcEnterField
#define OnNpcLeaveFieldAddy = 0x8DD010; //CNpcPool::OnNpcLeaveField
#define CNpcPoolDestructor = 0x8DCCC0; //CNpcPool::~CNpcPool
#define ReactorMineOpcode = 0x208;
#define JDAAddy1 = 0xF0A346;
#define JDAAddy2 = 0x85F38A;
#define JDAAddy3 = 0xF0A3A1;
#define PinTyperAddy1 = 0x7EA316;
#define PinTyperAddy2 = 0x7EB877;
#define PicTyperAddy1 = 0x9EE576; //CSoftKeyboardDlg::OnKey
#define PicTyperAddy2 = 0x9ED516; //CSoftKeyboardDlg::OnCreate
#define PicTyperAddy3 = 0x9ED532; //CSoftKeyboardDlg::OnCreate
#define PicTyperCall = 0x5C3840; //CCtrlEdit::CCtrlEdit
#define DojangGodmodeCallAddy = 0xE95E60;
#define DojangGodmodeRetAddy = 0xFC29BA;
#define NoFadeStagesAddy1 = 0x52FAE0;
#define NoFadeStagesAddy2 = 0x9F1DC0;
#define HideBackgroundAddy = 0x81F130;
#define HideCloudsAddy = 0x81BA80;
#define NoAttackLimitAddy = 0xEF98C0;
#define DecodeMoneyAddy = 0x5E83A0; //GW_CharacterStat::DecodeMoney
#define DecodeChangeStatAddy = 0x5F21F0; //GW_CharacterStat::DecodeChangeStat
#define MoneyHookRetAddy = 0x5F24C8;
#define GetItemAddy = 0x0!; //CharacterData::GetItem
#define GetItemSlotCountAddy = 0x475A10; //CharacterData::GetItemSlotCount
#define GetEmptySlotCountAddy = 0x5E6380; //CharacterData::GetEmptySlotCount
#define FindEmptySlotAddy = 0x52C660; //CharacterData::FindEmptySlotPosition
#define SetActiveAddy = 0x1013F20; //CVecCtrl::SetActive
#define SPControlRetAddy = 0xF33D00;
#define CUIScreenMsgPtr = 0x15B46C4; //TSingleton<CUIScreenMsg>
#define ScrMsg_AddAddy = 0xD25910; //CUIScreenMsg::ScrMsg_Add
#define NoMagnusBallsAddy = 0x699BF0;
#define PerfectMercedesAddy1 = 0x60E292;
#define PerfectMercedesAddy2 = 0xF5F896;
#define SitHackAddy = 0xF0357B;
#define NoMobKbAddy = 0x872DF8;
#define NoKBAddy = 0xA350F5;
#define FLACCAddy = 0x4FE2FF;
#define FatalSectionLockAddy = 0x401020; //ZFatalSection::Lock
#define MSLockAddy = 0x408400; //ZSynchronizedHelper<ZFatalSection>()
#define MSUnlockAddy = 0x4013F0; //~ZSynchronizedHelper<ZFatalSection>
#define innoHashAddy = 0x1106500; //CIGCipher::innoHash
#define CUIMiniMapPtr = 0x15B3D40; //TSingleton<CUIMiniMap>

#define GetStringPoolAddy = 0xA30370; //StringPool::GetInstance
#define GetBSTRAddy = 0x4503D0; //StringPool::GetBSTR
#define TeleportAddy1 = 0xEFB3E0;
#define TeleportAddy2 = 0x1015590;
#define GetMacAddressAddy = 0x7B86A0; //CLogin::GetLocalMacAddressWithHDDSerialNo
#define SystemInfoInitAddy = 0x1106D60; //CSystemInfo::Init
#define SkillInjectionAddy1 = 0xF8BB7C; //Checks if we can do final attack
#define SkillInjectionAddy2 = 0x0!;
#define SkillInjectionAddy3 = 0xF8BCA0;
#define SkillInjectionAddy4 = 0xF8BCB4;
#define SkillInjectionAddy5 = 0xF8BCBA;
#define SkillInjectionAddy6 = 0xF8BD55;
#define SkillInjectionAddy7 = 0xF8BD62;
#define SkillInjectionAddy8 = 0xF3C29D;
#define SkillInjectionAddy9 = 0xF29308;
#define PerfectLootAddy1 = 0x55EC07; //Tubi
#define PerfectLootAddy2 = 0x611EE5; //InstantDrop
#define PerfectLootAddy3 = 0x4A5969; //NoLootAnimation
#define OnMobEnterFieldAddy = 0x88F170; //CMobPool::OnMobEnterField
#define OnMobLeaveFieldAddy = 0x88ECD0; //CMobPool::OnMobLeaveField
#define OnMobCrcKeyChangedAddy = 0x88C160; //CMobPool::OnMobCrcKeyChanged
#define OnMobPacketAddy = 0x88BAB0; //CMobPool::OnMobPacket
#define GetMobAddy = 0x47E790; //CMobPool::GetMob
#define GetNearestMobAddy = 0x88E080; //CMobPool::GetNearestMob
#define MobPoolDestructorAddy = 0x88B5C0; //CMobPool::~CMobPool
#define TryDoingFinalAttackAddy = 0xF8BB10; //CUserLocal::TryDoingFinalAttack
                      
#define CClientSocketPtr = 0x15A8690; //TSingleton<CClientSocket>

#define PeopleBasePtr 0x015ACB10
#define PeopleCountOffset 0x18 //CUserPool::nPeopleCount

#define PeopleAddy 0x164ED1B0

#define MobAddy 0x15ACB14 //TSingleton<CMobPool> aka MobBasePtr
#define MobCountOffset 0x10 //CMobPool::nMoubCount


#define ServerPtr 0x15A856C //TSingleton<CWvsContext> aka ServerBasePtr  
#define WorldOffset 0x20D0  //CWvsContext::nWorldId
#define ChannelOffset 0x20D8 

//8b ? ? ? ? ? e8 ? ? ? ? 39 ? ? ? ? ? 74 ? 8b ? ? ? 8b
#define CharMapInfoAddy 0x015B3D40
#define CharXOffset 0xE30
#define CharYOffset 0xE34
#define MapIdOffset  0xF7C //CUIMiniMap::nMapId

#define GetCharacterDataAddy 0x5E9700 //CWvsContext::GetCharacterData
#define ItemIdOffset 0xA43D //CUserLocal::nHoveredItem

//8B 0D ? ? ? ? 6A ? 50 E8 ? ? ? ? 8B 44 24 ? 3B C6
//89 0D ? ? ? ? EB 06 89 3D ? ? ? ? 8D 4E ? C7 06
#define ItemBaseAddy 0x015AD28C //TSingleton<CDropPool>
#define  ItemsCountOffset  0x24 //CDropPool::nItemCount
//8b ? ? ? ? ? e8 ? ? ? ? 85 c0 74 ? 8b ? ? ? ? ? 8b ?
#define CharBasePtr 0x015A8688// 0x015A868C TSingleton<CUserLocal>
//89 8E ? ? ? ? 8B 50 ? 8B 06 89 96 ? ? ? ? 8B 50
#define XOffset 0xA738
#define YOffset 0xA73C
//89 ? ? ? 0 0 c7 ? ? ? 0 0 ? 0 0 0 8d
#define AttackCountOffset 0x989C
//83 B8 ? ? ? ? 00 7E ? 6A 00 6A 00 6A 00 6A 00
#define BreathOffset 0x668 

#define StatsBase 0x015A868C
#define EXP 0x00001E10 

#define CUIStatusBarPtr  0x15A868C //TSingleton<CUIStatusBar>
#define EXPOffset  0x1E24 // 2nd result: 8B 86 ?? ?? ?? ?? C6 44 24 ?? ?? 3B C3 74 ?? 83 C0 ?? 50 E8 ?? ?? ?? ?? 83 C4 ?? 8D 8E ?? ?? ?? ?? C6 44 24 ?? ?? E8 ?? ?? ?? ?? 8D 8E ?? ?? ?? ?? C6 44 24 ?? ?? C7 01 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8D 8E ?? ?? ?? ?? C6 44 24 ?? ?? C7 01 ?? ?? ?? ?? E8 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A ?? 6A ?? 8D 86 ?? ?? ?? ?? 50 C6 44 24 ?? ?? E8 ?? ?? ?? ?? 8D 8E ?? ?? ?? ?? C6 44 24 ?? ?? C7 01 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 86 ?? ?? ?? ?? C6 44 24 ?? ?? 3B C3 74 ?? 83 C0 ?? 50 E8 ?? ?? ?? ?? 83 C4 ?? 8B 86 ?? ?? ?? ?? C6 44 24 ?? ?? 3B C3 74 ?? 83 C0 ?? 50 E8 ?? ?? ?? ?? 83 C4 ?? 8B CE

#define CUIStatusBar__SetNumberValueAdr 0x15A868C

#define jmp(frm, to) (int)(((int)to - (int)frm) - 5);

void AutoCCPeople();
void AutoCCDelay();
bool AutoCCPeopleEnabled = false;
bool AutoCCDelayEnabled = false;
bool AutoSkill1Enabled = false;
bool AutoSkill2Enabled = false;
bool AutoSkill3Enabled = false;
bool AutoSkill4Enabled = false;
bool AutoSkill5Enabled = false;
bool expTimerbool = false;
int CCPeople;
int Channel;
int CCDelay;
int KillCount;
int SkillDelay1, SkillDelay2, SkillDelay3, SkillDelay4, SkillDelay5;
double GetCurrentEXP();

