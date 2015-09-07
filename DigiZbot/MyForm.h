#include <windows.h>




#pragma once

namespace DigiZbot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  JDA;
	private: System::Windows::Forms::CheckBox^  MobFreeze;
	private: System::Windows::Forms::CheckBox^  GnD;
	private: System::Windows::Forms::CheckBox^  NDS;
	private: System::Windows::Forms::CheckBox^  NFS;

	private: System::Windows::Forms::CheckBox^  NB;
	private: System::Windows::Forms::CheckBox^  PL;
	private: System::Windows::Forms::CheckBox^  UA;
	private: System::Windows::Forms::CheckBox^  UMP;


	private: System::Windows::Forms::CheckBox^  NMR;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;






	private: System::Windows::Forms::CheckBox^  FGM;
	private: System::Windows::Forms::CheckBox^  NMB;
	private: System::Windows::Forms::CheckBox^  NSE;

	private: System::Windows::Forms::CheckBox^  SM;
	private: System::Windows::Forms::CheckBox^  CPU;
	private: System::Windows::Forms::CheckBox^  NoBreath;
	private: System::Windows::Forms::CheckBox^  NoMobKB;
	private: System::Windows::Forms::CheckBox^  NoKB;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckBox^  AS1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  FMD;
	private: System::Windows::Forms::CheckBox^  FA;
	private: System::Windows::Forms::CheckBox^  NBD;
	private: System::Windows::Forms::Button^  bEmbedMS;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lPeople;
	private: System::Windows::Forms::Label^  lWorld;

	private: System::Windows::Forms::Timer^  tInfo;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  lChannel;
	private: System::Windows::Forms::NumericUpDown^  nudCCPeople;
	private: System::Windows::Forms::CheckBox^  cbAutoCCPeople;

	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::CheckBox^  As5;

	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::CheckBox^  As4;

	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::CheckBox^  As3;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::CheckBox^  As2;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::NumericUpDown^  nudCCDelay;
	private: System::Windows::Forms::CheckBox^  cbAutoCCDelay;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TextBox^  SkillinjectDelay;
	private: System::Windows::Forms::TextBox^  skillID;
	private: System::Windows::Forms::CheckBox^  skillinject;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  lMonsters;
private: System::Windows::Forms::Label^  MapID;
private: System::Windows::Forms::Label^  CharXY;



private: System::Windows::Forms::Label^  lKillCount;






private: System::Windows::Forms::NumericUpDown^  nudSkillDelay1;
private: System::Windows::Forms::NumericUpDown^  nudSkillDelay5;

private: System::Windows::Forms::NumericUpDown^  nudSkillDelay4;

private: System::Windows::Forms::NumericUpDown^  nudSkillDelay3;

private: System::Windows::Forms::NumericUpDown^  nudSkillDelay2;
private: System::Windows::Forms::CheckBox^  VR;
private: System::Windows::Forms::CheckBox^  MSU;
private: System::Windows::Forms::CheckBox^  HWID;
private: System::Windows::Forms::GroupBox^  gbTimer;
private: System::Windows::Forms::Label^  lHoursToLevelUp;
private: System::Windows::Forms::Label^  lHoursToLevelUpLabel;
private: System::Windows::Forms::CheckBox^  cbTopMost;
private: System::Windows::Forms::Label^  lCurrentEXP;
private: System::Windows::Forms::Label^  lCurrentEXPLabel;
private: System::Windows::Forms::Label^  lMinutesTillLevelUpLabel;
private: System::Windows::Forms::Label^  lEXPTillLevelUpLabel;
private: System::Windows::Forms::Label^  lEXPHourLabel;
private: System::Windows::Forms::Label^  lEXPMinuteLabel;
private: System::Windows::Forms::Label^  lMinutesTillLevelUp;
private: System::Windows::Forms::Label^  lEXPTillLevelUp;
private: System::Windows::Forms::Label^  lEXPHour;
private: System::Windows::Forms::Label^  lEXPMinute;
private: System::Windows::Forms::Timer^  tEXP;
public: System::Windows::Forms::Timer^  tFirst;
private:
public: System::Windows::Forms::Timer^  tSecond;
public: System::Windows::Forms::CheckBox^  cbFirst;
private: System::Windows::Forms::CheckBox^  cbSecond;
private: System::Windows::Forms::Label^  ZCurrentEXP;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::CheckBox^  MC;
private: System::Windows::Forms::CheckBox^  HookStats;

private:










public:



	private: System::ComponentModel::IContainer^  components;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->JDA = (gcnew System::Windows::Forms::CheckBox());
			this->MobFreeze = (gcnew System::Windows::Forms::CheckBox());
			this->GnD = (gcnew System::Windows::Forms::CheckBox());
			this->NDS = (gcnew System::Windows::Forms::CheckBox());
			this->NFS = (gcnew System::Windows::Forms::CheckBox());
			this->NB = (gcnew System::Windows::Forms::CheckBox());
			this->PL = (gcnew System::Windows::Forms::CheckBox());
			this->UA = (gcnew System::Windows::Forms::CheckBox());
			this->UMP = (gcnew System::Windows::Forms::CheckBox());
			this->NMR = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->HookStats = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->NMB = (gcnew System::Windows::Forms::CheckBox());
			this->NoBreath = (gcnew System::Windows::Forms::CheckBox());
			this->CPU = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->MSU = (gcnew System::Windows::Forms::CheckBox());
			this->VR = (gcnew System::Windows::Forms::CheckBox());
			this->FMD = (gcnew System::Windows::Forms::CheckBox());
			this->NoKB = (gcnew System::Windows::Forms::CheckBox());
			this->SM = (gcnew System::Windows::Forms::CheckBox());
			this->NoMobKB = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->NBD = (gcnew System::Windows::Forms::CheckBox());
			this->FA = (gcnew System::Windows::Forms::CheckBox());
			this->FGM = (gcnew System::Windows::Forms::CheckBox());
			this->NSE = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->nudSkillDelay5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSkillDelay4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSkillDelay3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSkillDelay2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSkillDelay1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->As2 = (gcnew System::Windows::Forms::CheckBox());
			this->AS1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->As5 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->As3 = (gcnew System::Windows::Forms::CheckBox());
			this->As4 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->cbAutoCCPeople = (gcnew System::Windows::Forms::CheckBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->cbAutoCCDelay = (gcnew System::Windows::Forms::CheckBox());
			this->nudCCDelay = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudCCPeople = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->gbTimer = (gcnew System::Windows::Forms::GroupBox());
			this->lHoursToLevelUp = (gcnew System::Windows::Forms::Label());
			this->lHoursToLevelUpLabel = (gcnew System::Windows::Forms::Label());
			this->cbTopMost = (gcnew System::Windows::Forms::CheckBox());
			this->cbSecond = (gcnew System::Windows::Forms::CheckBox());
			this->lCurrentEXP = (gcnew System::Windows::Forms::Label());
			this->lCurrentEXPLabel = (gcnew System::Windows::Forms::Label());
			this->lMinutesTillLevelUpLabel = (gcnew System::Windows::Forms::Label());
			this->lEXPTillLevelUpLabel = (gcnew System::Windows::Forms::Label());
			this->lEXPHourLabel = (gcnew System::Windows::Forms::Label());
			this->lEXPMinuteLabel = (gcnew System::Windows::Forms::Label());
			this->lMinutesTillLevelUp = (gcnew System::Windows::Forms::Label());
			this->lEXPTillLevelUp = (gcnew System::Windows::Forms::Label());
			this->lEXPHour = (gcnew System::Windows::Forms::Label());
			this->lEXPMinute = (gcnew System::Windows::Forms::Label());
			this->cbFirst = (gcnew System::Windows::Forms::CheckBox());
			this->HWID = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->MC = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SkillinjectDelay = (gcnew System::Windows::Forms::TextBox());
			this->skillID = (gcnew System::Windows::Forms::TextBox());
			this->skillinject = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->ZCurrentEXP = (gcnew System::Windows::Forms::Label());
			this->lKillCount = (gcnew System::Windows::Forms::Label());
			this->CharXY = (gcnew System::Windows::Forms::Label());
			this->MapID = (gcnew System::Windows::Forms::Label());
			this->lMonsters = (gcnew System::Windows::Forms::Label());
			this->lChannel = (gcnew System::Windows::Forms::Label());
			this->lWorld = (gcnew System::Windows::Forms::Label());
			this->bEmbedMS = (gcnew System::Windows::Forms::Button());
			this->lPeople = (gcnew System::Windows::Forms::Label());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->tInfo = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tEXP = (gcnew System::Windows::Forms::Timer(this->components));
			this->tFirst = (gcnew System::Windows::Forms::Timer(this->components));
			this->tSecond = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay1))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCCDelay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCCPeople))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->gbTimer->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// JDA
			// 
			this->JDA->AutoSize = true;
			this->JDA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->JDA->ForeColor = System::Drawing::Color::Wheat;
			this->JDA->Location = System::Drawing::Point(6, 19);
			this->JDA->Name = L"JDA";
			this->JDA->Size = System::Drawing::Size(46, 17);
			this->JDA->TabIndex = 0;
			this->JDA->Text = L"JDA";
			this->toolTip1->SetToolTip(this->JDA, L"JumpDownAnywhere");
			this->JDA->UseVisualStyleBackColor = true;
			this->JDA->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MobFreeze
			// 
			this->MobFreeze->ForeColor = System::Drawing::Color::Wheat;
			this->MobFreeze->Location = System::Drawing::Point(5, 19);
			this->MobFreeze->Name = L"MobFreeze";
			this->MobFreeze->Size = System::Drawing::Size(82, 17);
			this->MobFreeze->TabIndex = 1;
			this->MobFreeze->Text = L"Mob Freeze";
			this->toolTip1->SetToolTip(this->MobFreeze, L"Freezes all mobs on the map");
			this->MobFreeze->UseVisualStyleBackColor = true;
			this->MobFreeze->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// GnD
			// 
			this->GnD->AutoSize = true;
			this->GnD->ForeColor = System::Drawing::Color::Wheat;
			this->GnD->Location = System::Drawing::Point(90, 19);
			this->GnD->Name = L"GnD";
			this->GnD->Size = System::Drawing::Size(50, 17);
			this->GnD->TabIndex = 2;
			this->GnD->Text = L"GND";
			this->toolTip1->SetToolTip(this->GnD, L"GenericNoDelay");
			this->GnD->UseVisualStyleBackColor = true;
			this->GnD->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_2);
			// 
			// NDS
			// 
			this->NDS->ForeColor = System::Drawing::Color::Wheat;
			this->NDS->Location = System::Drawing::Point(5, 86);
			this->NDS->Name = L"NDS";
			this->NDS->Size = System::Drawing::Size(113, 17);
			this->NDS->TabIndex = 3;
			this->NDS->Text = L"NoDamageShown";
			this->toolTip1->SetToolTip(this->NDS, L"Won\'t show any damage");
			this->NDS->UseVisualStyleBackColor = true;
			this->NDS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_3);
			// 
			// NFS
			// 
			this->NFS->ForeColor = System::Drawing::Color::Wheat;
			this->NFS->Location = System::Drawing::Point(6, 63);
			this->NFS->Name = L"NFS";
			this->NFS->Size = System::Drawing::Size(100, 17);
			this->NFS->TabIndex = 4;
			this->NFS->Text = L"NoFadeStages";
			this->toolTip1->SetToolTip(this->NFS, L"No delay between changing maps");
			this->NFS->UseVisualStyleBackColor = true;
			this->NFS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_4);
			// 
			// NB
			// 
			this->NB->AutoSize = true;
			this->NB->ForeColor = System::Drawing::Color::Wheat;
			this->NB->Location = System::Drawing::Point(105, 63);
			this->NB->Name = L"NB";
			this->NB->Size = System::Drawing::Size(98, 17);
			this->NB->TabIndex = 6;
			this->NB->Text = L"NoBackground";
			this->toolTip1->SetToolTip(this->NB, L"Removes the background");
			this->NB->UseVisualStyleBackColor = true;
			this->NB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_5);
			// 
			// PL
			// 
			this->PL->AutoSize = true;
			this->PL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PL->ForeColor = System::Drawing::Color::Wheat;
			this->PL->Location = System::Drawing::Point(6, 65);
			this->PL->Name = L"PL";
			this->PL->Size = System::Drawing::Size(81, 17);
			this->PL->TabIndex = 7;
			this->PL->Text = L"PerfectLoot";
			this->toolTip1->SetToolTip(this->PL, L"No loot drop animation+instant loot");
			this->PL->UseVisualStyleBackColor = true;
			this->PL->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_6);
			// 
			// UA
			// 
			this->UA->ForeColor = System::Drawing::Color::Wheat;
			this->UA->Location = System::Drawing::Point(6, 40);
			this->UA->Name = L"UA";
			this->UA->Size = System::Drawing::Size(100, 17);
			this->UA->TabIndex = 8;
			this->UA->Text = L"UnlimitedAttack";
			this->toolTip1->SetToolTip(this->UA, L"Allows you to attack unlimited times at the same spot");
			this->UA->UseVisualStyleBackColor = true;
			this->UA->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_7);
			// 
			// UMP
			// 
			this->UMP->AutoSize = true;
			this->UMP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UMP->ForeColor = System::Drawing::Color::Wheat;
			this->UMP->Location = System::Drawing::Point(6, 42);
			this->UMP->Name = L"UMP";
			this->UMP->Size = System::Drawing::Size(85, 17);
			this->UMP->TabIndex = 9;
			this->UMP->Text = L"UnlimitedMP";
			this->toolTip1->SetToolTip(this->UMP, L"Gives you unlimited mp");
			this->UMP->UseVisualStyleBackColor = true;
			this->UMP->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_8);
			// 
			// NMR
			// 
			this->NMR->ForeColor = System::Drawing::Color::Wheat;
			this->NMR->Location = System::Drawing::Point(89, 42);
			this->NMR->Name = L"NMR";
			this->NMR->Size = System::Drawing::Size(104, 17);
			this->NMR->TabIndex = 11;
			this->NMR->Text = L"NoMobReaction";
			this->toolTip1->SetToolTip(this->NMR, L"Mobs won\'t show any reaction");
			this->NMR->UseVisualStyleBackColor = true;
			this->NMR->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_10);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(3, 102);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(332, 440);
			this->tabControl1->TabIndex = 12;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage1.BackgroundImage")));
			this->tabPage1->Controls->Add(this->HookStats);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(324, 414);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Hacks";
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// HookStats
			// 
			this->HookStats->AutoSize = true;
			this->HookStats->Location = System::Drawing::Point(218, 25);
			this->HookStats->Name = L"HookStats";
			this->HookStats->Size = System::Drawing::Size(50, 17);
			this->HookStats->TabIndex = 24;
			this->HookStats->Text = L"hook";
			this->HookStats->UseVisualStyleBackColor = true;
			this->HookStats->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_28);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->NDS);
			this->groupBox3->Controls->Add(this->UA);
			this->groupBox3->Controls->Add(this->NMB);
			this->groupBox3->Controls->Add(this->NB);
			this->groupBox3->Controls->Add(this->NFS);
			this->groupBox3->Controls->Add(this->NoBreath);
			this->groupBox3->Controls->Add(this->CPU);
			this->groupBox3->ForeColor = System::Drawing::Color::Cornsilk;
			this->groupBox3->Location = System::Drawing::Point(12, 273);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 135);
			this->groupBox3->TabIndex = 23;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Etc";
			// 
			// NMB
			// 
			this->NMB->ForeColor = System::Drawing::Color::Wheat;
			this->NMB->Location = System::Drawing::Point(6, 17);
			this->NMB->Name = L"NMB";
			this->NMB->Size = System::Drawing::Size(100, 17);
			this->NMB->TabIndex = 13;
			this->NMB->Text = L"NoMagnusBalls";
			this->toolTip1->SetToolTip(this->NMB, L"Will remove the falling balls at magnus");
			this->NMB->UseVisualStyleBackColor = true;
			this->NMB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_13);
			// 
			// NoBreath
			// 
			this->NoBreath->ForeColor = System::Drawing::Color::Wheat;
			this->NoBreath->Location = System::Drawing::Point(105, 40);
			this->NoBreath->Name = L"NoBreath";
			this->NoBreath->Size = System::Drawing::Size(100, 17);
			this->NoBreath->TabIndex = 18;
			this->NoBreath->Text = L"NoBreath";
			this->toolTip1->SetToolTip(this->NoBreath, L"Removes the breath after attacking/falling");
			this->NoBreath->UseVisualStyleBackColor = true;
			this->NoBreath->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_18);
			// 
			// CPU
			// 
			this->CPU->ForeColor = System::Drawing::Color::Wheat;
			this->CPU->Location = System::Drawing::Point(105, 17);
			this->CPU->Name = L"CPU";
			this->CPU->Size = System::Drawing::Size(100, 17);
			this->CPU->TabIndex = 17;
			this->CPU->Text = L"CPUhack";
			this->toolTip1->SetToolTip(this->CPU, L"no background + no tiles + no map objects + no clouds");
			this->CPU->UseVisualStyleBackColor = true;
			this->CPU->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_17);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->MSU);
			this->groupBox2->Controls->Add(this->VR);
			this->groupBox2->Controls->Add(this->FMD);
			this->groupBox2->Controls->Add(this->MobFreeze);
			this->groupBox2->Controls->Add(this->NMR);
			this->groupBox2->Controls->Add(this->NoKB);
			this->groupBox2->Controls->Add(this->SM);
			this->groupBox2->Controls->Add(this->NoMobKB);
			this->groupBox2->ForeColor = System::Drawing::Color::Cornsilk;
			this->groupBox2->Location = System::Drawing::Point(12, 143);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 113);
			this->groupBox2->TabIndex = 22;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Mob Related";
			// 
			// MSU
			// 
			this->MSU->AutoSize = true;
			this->MSU->ForeColor = System::Drawing::Color::Wheat;
			this->MSU->Location = System::Drawing::Point(89, 88);
			this->MSU->Name = L"MSU";
			this->MSU->Size = System::Drawing::Size(92, 17);
			this->MSU->TabIndex = 23;
			this->MSU->Text = L"MobSpeedUp";
			this->toolTip1->SetToolTip(this->MSU, L"Mobs will move faster");
			this->MSU->UseVisualStyleBackColor = true;
			this->MSU->CheckedChanged += gcnew System::EventHandler(this, &MyForm::MSU_CheckedChanged);
			// 
			// VR
			// 
			this->VR->AutoSize = true;
			this->VR->ForeColor = System::Drawing::Color::Wheat;
			this->VR->Location = System::Drawing::Point(5, 88);
			this->VR->Name = L"VR";
			this->VR->Size = System::Drawing::Size(70, 17);
			this->VR->TabIndex = 22;
			this->VR->Text = L"VacRight";
			this->VR->UseVisualStyleBackColor = true;
			this->VR->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_31);
			// 
			// FMD
			// 
			this->FMD->AutoSize = true;
			this->FMD->ForeColor = System::Drawing::Color::Wheat;
			this->FMD->Location = System::Drawing::Point(89, 65);
			this->FMD->Name = L"FMD";
			this->FMD->Size = System::Drawing::Size(95, 17);
			this->FMD->TabIndex = 21;
			this->FMD->Text = L"FullMobDisarm";
			this->toolTip1->SetToolTip(this->FMD, L"Stops mob from casting spells");
			this->FMD->UseVisualStyleBackColor = true;
			this->FMD->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_21);
			// 
			// NoKB
			// 
			this->NoKB->ForeColor = System::Drawing::Color::Wheat;
			this->NoKB->Location = System::Drawing::Point(89, 19);
			this->NoKB->Name = L"NoKB";
			this->NoKB->Size = System::Drawing::Size(81, 17);
			this->NoKB->TabIndex = 20;
			this->NoKB->Text = L"NoKB";
			this->toolTip1->SetToolTip(this->NoKB, L"Character won\'t get knockbacked");
			this->NoKB->UseVisualStyleBackColor = true;
			this->NoKB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_20);
			// 
			// SM
			// 
			this->SM->ForeColor = System::Drawing::Color::Wheat;
			this->SM->Location = System::Drawing::Point(4, 42);
			this->SM->Name = L"SM";
			this->SM->Size = System::Drawing::Size(80, 17);
			this->SM->TabIndex = 16;
			this->SM->Text = L"ScareMobs";
			this->toolTip1->SetToolTip(this->SM, L"Variant of mob freeze");
			this->SM->UseVisualStyleBackColor = true;
			this->SM->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_16);
			// 
			// NoMobKB
			// 
			this->NoMobKB->ForeColor = System::Drawing::Color::Wheat;
			this->NoMobKB->Location = System::Drawing::Point(4, 65);
			this->NoMobKB->Name = L"NoMobKB";
			this->NoMobKB->Size = System::Drawing::Size(75, 17);
			this->NoMobKB->TabIndex = 19;
			this->NoMobKB->Text = L"NoMobKB";
			this->toolTip1->SetToolTip(this->NoMobKB, L"Mobs won\'t got knockbacked");
			this->NoMobKB->UseVisualStyleBackColor = true;
			this->NoMobKB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_19);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->NBD);
			this->groupBox1->Controls->Add(this->FA);
			this->groupBox1->Controls->Add(this->JDA);
			this->groupBox1->Controls->Add(this->UMP);
			this->groupBox1->Controls->Add(this->PL);
			this->groupBox1->Controls->Add(this->GnD);
			this->groupBox1->Controls->Add(this->FGM);
			this->groupBox1->Controls->Add(this->NSE);
			this->groupBox1->ForeColor = System::Drawing::Color::Cornsilk;
			this->groupBox1->Location = System::Drawing::Point(12, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 131);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Char Related";
			// 
			// NBD
			// 
			this->NBD->AutoSize = true;
			this->NBD->ForeColor = System::Drawing::Color::Wheat;
			this->NBD->Location = System::Drawing::Point(91, 66);
			this->NBD->Name = L"NBD";
			this->NBD->Size = System::Drawing::Size(86, 17);
			this->NBD->TabIndex = 16;
			this->NBD->Text = L"NoBuffDelay";
			this->toolTip1->SetToolTip(this->NBD, L"Buff spells will cast faster");
			this->NBD->UseVisualStyleBackColor = true;
			this->NBD->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_23);
			// 
			// FA
			// 
			this->FA->AutoSize = true;
			this->FA->ForeColor = System::Drawing::Color::Wheat;
			this->FA->Location = System::Drawing::Point(91, 42);
			this->FA->Name = L"FA";
			this->FA->Size = System::Drawing::Size(88, 17);
			this->FA->TabIndex = 15;
			this->FA->Text = L"FusionAttack";
			this->toolTip1->SetToolTip(this->FA, L"All attacks will be focused on 1 enemy");
			this->FA->UseVisualStyleBackColor = true;
			this->FA->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_22);
			// 
			// FGM
			// 
			this->FGM->AutoSize = true;
			this->FGM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FGM->ForeColor = System::Drawing::Color::Wheat;
			this->FGM->Location = System::Drawing::Point(6, 85);
			this->FGM->Name = L"FGM";
			this->FGM->Size = System::Drawing::Size(89, 17);
			this->FGM->TabIndex = 12;
			this->FGM->Text = L"FullGodMode";
			this->toolTip1->SetToolTip(this->FGM, L"Gives you full god mode");
			this->FGM->UseVisualStyleBackColor = true;
			this->FGM->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_12);
			// 
			// NSE
			// 
			this->NSE->AutoSize = true;
			this->NSE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NSE->ForeColor = System::Drawing::Color::Wheat;
			this->NSE->Location = System::Drawing::Point(6, 108);
			this->NSE->Name = L"NSE";
			this->NSE->Size = System::Drawing::Size(87, 17);
			this->NSE->TabIndex = 14;
			this->NSE->Text = L"NoSkillEffect";
			this->toolTip1->SetToolTip(this->NSE, L"No skill animation will be shown");
			this->NSE->UseVisualStyleBackColor = true;
			this->NSE->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_14);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage2.BackgroundImage")));
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(324, 414);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Bot";
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->nudSkillDelay5);
			this->groupBox6->Controls->Add(this->nudSkillDelay4);
			this->groupBox6->Controls->Add(this->nudSkillDelay3);
			this->groupBox6->Controls->Add(this->nudSkillDelay2);
			this->groupBox6->Controls->Add(this->nudSkillDelay1);
			this->groupBox6->Controls->Add(this->As2);
			this->groupBox6->Controls->Add(this->AS1);
			this->groupBox6->Controls->Add(this->label5);
			this->groupBox6->Controls->Add(this->comboBox1);
			this->groupBox6->Controls->Add(this->comboBox5);
			this->groupBox6->Controls->Add(this->label1);
			this->groupBox6->Controls->Add(this->As5);
			this->groupBox6->Controls->Add(this->comboBox2);
			this->groupBox6->Controls->Add(this->label4);
			this->groupBox6->Controls->Add(this->label2);
			this->groupBox6->Controls->Add(this->comboBox4);
			this->groupBox6->Controls->Add(this->As3);
			this->groupBox6->Controls->Add(this->As4);
			this->groupBox6->Controls->Add(this->comboBox3);
			this->groupBox6->Controls->Add(this->label3);
			this->groupBox6->ForeColor = System::Drawing::Color::Cornsilk;
			this->groupBox6->Location = System::Drawing::Point(13, 17);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(293, 161);
			this->groupBox6->TabIndex = 75;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"AutoSkills";
			// 
			// nudSkillDelay5
			// 
			this->nudSkillDelay5->Location = System::Drawing::Point(187, 130);
			this->nudSkillDelay5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudSkillDelay5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSkillDelay5->Name = L"nudSkillDelay5";
			this->nudSkillDelay5->Size = System::Drawing::Size(54, 20);
			this->nudSkillDelay5->TabIndex = 80;
			this->nudSkillDelay5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudSkillDelay5->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudSkillDelay5_ValueChanged);
			// 
			// nudSkillDelay4
			// 
			this->nudSkillDelay4->Location = System::Drawing::Point(187, 102);
			this->nudSkillDelay4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudSkillDelay4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSkillDelay4->Name = L"nudSkillDelay4";
			this->nudSkillDelay4->Size = System::Drawing::Size(54, 20);
			this->nudSkillDelay4->TabIndex = 79;
			this->nudSkillDelay4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudSkillDelay4->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudSkillDelay4_ValueChanged);
			// 
			// nudSkillDelay3
			// 
			this->nudSkillDelay3->Location = System::Drawing::Point(187, 75);
			this->nudSkillDelay3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudSkillDelay3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSkillDelay3->Name = L"nudSkillDelay3";
			this->nudSkillDelay3->Size = System::Drawing::Size(54, 20);
			this->nudSkillDelay3->TabIndex = 78;
			this->nudSkillDelay3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudSkillDelay3->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudSkillDelay3_ValueChanged);
			// 
			// nudSkillDelay2
			// 
			this->nudSkillDelay2->Location = System::Drawing::Point(187, 48);
			this->nudSkillDelay2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudSkillDelay2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSkillDelay2->Name = L"nudSkillDelay2";
			this->nudSkillDelay2->Size = System::Drawing::Size(54, 20);
			this->nudSkillDelay2->TabIndex = 77;
			this->nudSkillDelay2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudSkillDelay2->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudSkillDelay2_ValueChanged);
			// 
			// nudSkillDelay1
			// 
			this->nudSkillDelay1->Location = System::Drawing::Point(187, 21);
			this->nudSkillDelay1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudSkillDelay1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudSkillDelay1->Name = L"nudSkillDelay1";
			this->nudSkillDelay1->Size = System::Drawing::Size(54, 20);
			this->nudSkillDelay1->TabIndex = 76;
			this->nudSkillDelay1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudSkillDelay1->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudSkillDelay1_ValueChanged);
			// 
			// As2
			// 
			this->As2->AutoSize = true;
			this->As2->ForeColor = System::Drawing::Color::Wheat;
			this->As2->Location = System::Drawing::Point(6, 51);
			this->As2->Name = L"As2";
			this->As2->Size = System::Drawing::Size(79, 17);
			this->As2->TabIndex = 55;
			this->As2->Text = L"Auto Skill 2";
			this->As2->UseVisualStyleBackColor = true;
			this->As2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_24);
			// 
			// AS1
			// 
			this->AS1->AutoSize = true;
			this->AS1->ForeColor = System::Drawing::Color::Wheat;
			this->AS1->Location = System::Drawing::Point(6, 24);
			this->AS1->Name = L"AS1";
			this->AS1->Size = System::Drawing::Size(79, 17);
			this->AS1->TabIndex = 0;
			this->AS1->Text = L"Auto Skill 1";
			this->AS1->UseVisualStyleBackColor = true;
			this->AS1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_11);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::Color::Wheat;
			this->label5->Location = System::Drawing::Point(247, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 70;
			this->label5->Text = L"seconds";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H",
					L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Shift", L"Control",
					L"Page Up", L"Page Down", L"End", L"Home", L"Delete"
			});
			this->comboBox1->Location = System::Drawing::Point(91, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(73, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H",
					L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Shift", L"Control",
					L"Page Up", L"Page Down", L"End", L"Home", L"Delete"
			});
			this->comboBox5->Location = System::Drawing::Point(91, 129);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(73, 21);
			this->comboBox5->TabIndex = 68;
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox5_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::Wheat;
			this->label1->Location = System::Drawing::Point(247, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"seconds";
			// 
			// As5
			// 
			this->As5->AutoSize = true;
			this->As5->ForeColor = System::Drawing::Color::Wheat;
			this->As5->Location = System::Drawing::Point(6, 132);
			this->As5->Name = L"As5";
			this->As5->Size = System::Drawing::Size(79, 17);
			this->As5->TabIndex = 67;
			this->As5->Text = L"Auto Skill 5";
			this->As5->UseVisualStyleBackColor = true;
			this->As5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_27);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H",
					L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Shift", L"Control",
					L"Page Up", L"Page Down", L"End", L"Home", L"Delete"
			});
			this->comboBox2->Location = System::Drawing::Point(91, 47);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(73, 21);
			this->comboBox2->TabIndex = 56;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::Color::Wheat;
			this->label4->Location = System::Drawing::Point(247, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 66;
			this->label4->Text = L"seconds";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Wheat;
			this->label2->Location = System::Drawing::Point(247, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 58;
			this->label2->Text = L"seconds";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H",
					L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Shift", L"Control",
					L"Page Up", L"Page Down", L"End", L"Home", L"Delete"
			});
			this->comboBox4->Location = System::Drawing::Point(91, 101);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(73, 21);
			this->comboBox4->TabIndex = 64;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox4_SelectedIndexChanged);
			// 
			// As3
			// 
			this->As3->AutoSize = true;
			this->As3->ForeColor = System::Drawing::Color::Wheat;
			this->As3->Location = System::Drawing::Point(6, 78);
			this->As3->Name = L"As3";
			this->As3->Size = System::Drawing::Size(79, 17);
			this->As3->TabIndex = 59;
			this->As3->Text = L"Auto Skill 3";
			this->As3->UseVisualStyleBackColor = true;
			this->As3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_25);
			// 
			// As4
			// 
			this->As4->AutoSize = true;
			this->As4->ForeColor = System::Drawing::Color::Wheat;
			this->As4->Location = System::Drawing::Point(6, 105);
			this->As4->Name = L"As4";
			this->As4->Size = System::Drawing::Size(79, 17);
			this->As4->TabIndex = 63;
			this->As4->Text = L"Auto Skill 4";
			this->As4->UseVisualStyleBackColor = true;
			this->As4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_26);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H",
					L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Shift", L"Control",
					L"Page Up", L"Page Down", L"End", L"Home", L"Delete"
			});
			this->comboBox3->Location = System::Drawing::Point(91, 74);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(73, 21);
			this->comboBox3->TabIndex = 60;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::Color::Wheat;
			this->label3->Location = System::Drawing::Point(247, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 62;
			this->label3->Text = L"seconds";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->cbAutoCCPeople);
			this->groupBox5->Controls->Add(this->label25);
			this->groupBox5->Controls->Add(this->cbAutoCCDelay);
			this->groupBox5->Controls->Add(this->nudCCDelay);
			this->groupBox5->Controls->Add(this->nudCCPeople);
			this->groupBox5->ForeColor = System::Drawing::Color::Cornsilk;
			this->groupBox5->Location = System::Drawing::Point(13, 194);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(200, 100);
			this->groupBox5->TabIndex = 74;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"AutoCC";
			// 
			// cbAutoCCPeople
			// 
			this->cbAutoCCPeople->AutoSize = true;
			this->cbAutoCCPeople->ForeColor = System::Drawing::Color::Wheat;
			this->cbAutoCCPeople->Location = System::Drawing::Point(5, 19);
			this->cbAutoCCPeople->Name = L"cbAutoCCPeople";
			this->cbAutoCCPeople->Size = System::Drawing::Size(49, 17);
			this->cbAutoCCPeople->TabIndex = 53;
			this->cbAutoCCPeople->Text = L"PPL:";
			this->cbAutoCCPeople->UseVisualStyleBackColor = true;
			this->cbAutoCCPeople->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbAutoCCPeople_CheckedChanged);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->ForeColor = System::Drawing::Color::Wheat;
			this->label25->Location = System::Drawing::Point(139, 53);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(42, 13);
			this->label25->TabIndex = 73;
			this->label25->Text = L"second";
			// 
			// cbAutoCCDelay
			// 
			this->cbAutoCCDelay->AutoSize = true;
			this->cbAutoCCDelay->ForeColor = System::Drawing::Color::Wheat;
			this->cbAutoCCDelay->Location = System::Drawing::Point(5, 51);
			this->cbAutoCCDelay->Name = L"cbAutoCCDelay";
			this->cbAutoCCDelay->Size = System::Drawing::Size(56, 17);
			this->cbAutoCCDelay->TabIndex = 71;
			this->cbAutoCCDelay->Text = L"Delay:";
			this->cbAutoCCDelay->UseVisualStyleBackColor = true;
			this->cbAutoCCDelay->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_32);
			// 
			// nudCCDelay
			// 
			this->nudCCDelay->Location = System::Drawing::Point(79, 51);
			this->nudCCDelay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudCCDelay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCCDelay->Name = L"nudCCDelay";
			this->nudCCDelay->Size = System::Drawing::Size(54, 20);
			this->nudCCDelay->TabIndex = 72;
			this->nudCCDelay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->nudCCDelay->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudCCPeople_ValueChanged);
			// 
			// nudCCPeople
			// 
			this->nudCCPeople->Location = System::Drawing::Point(79, 16);
			this->nudCCPeople->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCCPeople->Name = L"nudCCPeople";
			this->nudCCPeople->Size = System::Drawing::Size(54, 20);
			this->nudCCPeople->TabIndex = 54;
			this->nudCCPeople->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCCPeople->ValueChanged += gcnew System::EventHandler(this, &MyForm::nudCCPeople_ValueChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage3.BackgroundImage")));
			this->tabPage3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label9);
			this->tabPage3->Controls->Add(this->gbTimer);
			this->tabPage3->Controls->Add(this->HWID);
			this->tabPage3->Controls->Add(this->label8);
			this->tabPage3->Controls->Add(this->MC);
			this->tabPage3->Controls->Add(this->label7);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->SkillinjectDelay);
			this->tabPage3->Controls->Add(this->skillID);
			this->tabPage3->Controls->Add(this->skillinject);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(324, 414);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Other hacks";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Wheat;
			this->label11->Location = System::Drawing::Point(34, 253);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 59;
			this->label11->Text = L"label11";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Wheat;
			this->label10->Location = System::Drawing::Point(34, 227);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 58;
			this->label10->Text = L"label10";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::Wheat;
			this->label9->Location = System::Drawing::Point(34, 204);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 57;
			this->label9->Text = L"label9";
			// 
			// gbTimer
			// 
			this->gbTimer->Controls->Add(this->lHoursToLevelUp);
			this->gbTimer->Controls->Add(this->lHoursToLevelUpLabel);
			this->gbTimer->Controls->Add(this->cbTopMost);
			this->gbTimer->Controls->Add(this->cbSecond);
			this->gbTimer->Controls->Add(this->lCurrentEXP);
			this->gbTimer->Controls->Add(this->lCurrentEXPLabel);
			this->gbTimer->Controls->Add(this->lMinutesTillLevelUpLabel);
			this->gbTimer->Controls->Add(this->lEXPTillLevelUpLabel);
			this->gbTimer->Controls->Add(this->lEXPHourLabel);
			this->gbTimer->Controls->Add(this->lEXPMinuteLabel);
			this->gbTimer->Controls->Add(this->lMinutesTillLevelUp);
			this->gbTimer->Controls->Add(this->lEXPTillLevelUp);
			this->gbTimer->Controls->Add(this->lEXPHour);
			this->gbTimer->Controls->Add(this->lEXPMinute);
			this->gbTimer->Controls->Add(this->cbFirst);
			this->gbTimer->ForeColor = System::Drawing::Color::Wheat;
			this->gbTimer->Location = System::Drawing::Point(13, 290);
			this->gbTimer->Name = L"gbTimer";
			this->gbTimer->Size = System::Drawing::Size(202, 97);
			this->gbTimer->TabIndex = 54;
			this->gbTimer->TabStop = false;
			this->gbTimer->Text = L"EXP Timer";
			// 
			// lHoursToLevelUp
			// 
			this->lHoursToLevelUp->AutoSize = true;
			this->lHoursToLevelUp->Location = System::Drawing::Point(151, 80);
			this->lHoursToLevelUp->Name = L"lHoursToLevelUp";
			this->lHoursToLevelUp->Size = System::Drawing::Size(13, 13);
			this->lHoursToLevelUp->TabIndex = 39;
			this->lHoursToLevelUp->Text = L"0";
			// 
			// lHoursToLevelUpLabel
			// 
			this->lHoursToLevelUpLabel->AutoSize = true;
			this->lHoursToLevelUpLabel->Location = System::Drawing::Point(6, 80);
			this->lHoursToLevelUpLabel->Name = L"lHoursToLevelUpLabel";
			this->lHoursToLevelUpLabel->Size = System::Drawing::Size(90, 13);
			this->lHoursToLevelUpLabel->TabIndex = 38;
			this->lHoursToLevelUpLabel->Text = L"Hours to level up:";
			// 
			// cbTopMost
			// 
			this->cbTopMost->AutoSize = true;
			this->cbTopMost->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->cbTopMost->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->cbTopMost->Location = System::Drawing::Point(122, 0);
			this->cbTopMost->Name = L"cbTopMost";
			this->cbTopMost->Size = System::Drawing::Size(74, 17);
			this->cbTopMost->TabIndex = 37;
			this->cbTopMost->Text = L"Top Most";
			this->cbTopMost->UseVisualStyleBackColor = true;
			// 
			// cbSecond
			// 
			this->cbSecond->AutoSize = true;
			this->cbSecond->Location = System::Drawing::Point(114, 15);
			this->cbSecond->Name = L"cbSecond";
			this->cbSecond->Size = System::Drawing::Size(15, 14);
			this->cbSecond->TabIndex = 56;
			this->cbSecond->UseVisualStyleBackColor = true;
			// 
			// lCurrentEXP
			// 
			this->lCurrentEXP->AutoSize = true;
			this->lCurrentEXP->Location = System::Drawing::Point(151, 15);
			this->lCurrentEXP->Name = L"lCurrentEXP";
			this->lCurrentEXP->Size = System::Drawing::Size(13, 13);
			this->lCurrentEXP->TabIndex = 36;
			this->lCurrentEXP->Text = L"0";
			// 
			// lCurrentEXPLabel
			// 
			this->lCurrentEXPLabel->AutoSize = true;
			this->lCurrentEXPLabel->Location = System::Drawing::Point(6, 15);
			this->lCurrentEXPLabel->Name = L"lCurrentEXPLabel";
			this->lCurrentEXPLabel->Size = System::Drawing::Size(68, 13);
			this->lCurrentEXPLabel->TabIndex = 35;
			this->lCurrentEXPLabel->Text = L"Current EXP:";
			// 
			// lMinutesTillLevelUpLabel
			// 
			this->lMinutesTillLevelUpLabel->AutoSize = true;
			this->lMinutesTillLevelUpLabel->Location = System::Drawing::Point(6, 67);
			this->lMinutesTillLevelUpLabel->Name = L"lMinutesTillLevelUpLabel";
			this->lMinutesTillLevelUpLabel->Size = System::Drawing::Size(99, 13);
			this->lMinutesTillLevelUpLabel->TabIndex = 34;
			this->lMinutesTillLevelUpLabel->Text = L"Minutes till level up:";
			// 
			// lEXPTillLevelUpLabel
			// 
			this->lEXPTillLevelUpLabel->AutoSize = true;
			this->lEXPTillLevelUpLabel->Location = System::Drawing::Point(6, 28);
			this->lEXPTillLevelUpLabel->Name = L"lEXPTillLevelUpLabel";
			this->lEXPTillLevelUpLabel->Size = System::Drawing::Size(83, 13);
			this->lEXPTillLevelUpLabel->TabIndex = 33;
			this->lEXPTillLevelUpLabel->Text = L"EXP till level up:";
			// 
			// lEXPHourLabel
			// 
			this->lEXPHourLabel->AutoSize = true;
			this->lEXPHourLabel->Location = System::Drawing::Point(6, 54);
			this->lEXPHourLabel->Name = L"lEXPHourLabel";
			this->lEXPHourLabel->Size = System::Drawing::Size(62, 13);
			this->lEXPHourLabel->TabIndex = 32;
			this->lEXPHourLabel->Text = L"EXP / Hour";
			// 
			// lEXPMinuteLabel
			// 
			this->lEXPMinuteLabel->AutoSize = true;
			this->lEXPMinuteLabel->Location = System::Drawing::Point(6, 41);
			this->lEXPMinuteLabel->Name = L"lEXPMinuteLabel";
			this->lEXPMinuteLabel->Size = System::Drawing::Size(71, 13);
			this->lEXPMinuteLabel->TabIndex = 31;
			this->lEXPMinuteLabel->Text = L"EXP / Minute";
			// 
			// lMinutesTillLevelUp
			// 
			this->lMinutesTillLevelUp->AutoSize = true;
			this->lMinutesTillLevelUp->Location = System::Drawing::Point(151, 67);
			this->lMinutesTillLevelUp->Name = L"lMinutesTillLevelUp";
			this->lMinutesTillLevelUp->Size = System::Drawing::Size(13, 13);
			this->lMinutesTillLevelUp->TabIndex = 30;
			this->lMinutesTillLevelUp->Text = L"0";
			// 
			// lEXPTillLevelUp
			// 
			this->lEXPTillLevelUp->AutoSize = true;
			this->lEXPTillLevelUp->Location = System::Drawing::Point(151, 28);
			this->lEXPTillLevelUp->Name = L"lEXPTillLevelUp";
			this->lEXPTillLevelUp->Size = System::Drawing::Size(13, 13);
			this->lEXPTillLevelUp->TabIndex = 28;
			this->lEXPTillLevelUp->Text = L"0";
			// 
			// lEXPHour
			// 
			this->lEXPHour->AutoSize = true;
			this->lEXPHour->Location = System::Drawing::Point(151, 54);
			this->lEXPHour->Name = L"lEXPHour";
			this->lEXPHour->Size = System::Drawing::Size(13, 13);
			this->lEXPHour->TabIndex = 27;
			this->lEXPHour->Text = L"0";
			// 
			// lEXPMinute
			// 
			this->lEXPMinute->AutoSize = true;
			this->lEXPMinute->Location = System::Drawing::Point(151, 41);
			this->lEXPMinute->Name = L"lEXPMinute";
			this->lEXPMinute->Size = System::Drawing::Size(13, 13);
			this->lEXPMinute->TabIndex = 26;
			this->lEXPMinute->Text = L"0";
			// 
			// cbFirst
			// 
			this->cbFirst->AutoSize = true;
			this->cbFirst->Location = System::Drawing::Point(81, 15);
			this->cbFirst->Name = L"cbFirst";
			this->cbFirst->Size = System::Drawing::Size(15, 14);
			this->cbFirst->TabIndex = 54;
			this->cbFirst->UseVisualStyleBackColor = true;
			// 
			// HWID
			// 
			this->HWID->AutoSize = true;
			this->HWID->ForeColor = System::Drawing::Color::Wheat;
			this->HWID->Location = System::Drawing::Point(13, 102);
			this->HWID->Name = L"HWID";
			this->HWID->Size = System::Drawing::Size(56, 17);
			this->HWID->TabIndex = 34;
			this->HWID->Text = L"HWID";
			this->HWID->UseVisualStyleBackColor = true;
			this->HWID->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_33);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Wheat;
			this->label8->Location = System::Drawing::Point(34, 178);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 33;
			this->label8->Text = L"label8";
			// 
			// MC
			// 
			this->MC->AutoSize = true;
			this->MC->ForeColor = System::Drawing::Color::Wheat;
			this->MC->Location = System::Drawing::Point(13, 149);
			this->MC->Name = L"MC";
			this->MC->Size = System::Drawing::Size(80, 17);
			this->MC->TabIndex = 32;
			this->MC->Text = L"MesoCount";
			this->MC->UseVisualStyleBackColor = true;
			this->MC->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_30);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->ForeColor = System::Drawing::Color::Wheat;
			this->label7->Location = System::Drawing::Point(10, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Delay:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->ForeColor = System::Drawing::Color::Wheat;
			this->label6->Location = System::Drawing::Point(10, 43);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Skill ID:";
			// 
			// SkillinjectDelay
			// 
			this->SkillinjectDelay->Location = System::Drawing::Point(76, 66);
			this->SkillinjectDelay->Name = L"SkillinjectDelay";
			this->SkillinjectDelay->Size = System::Drawing::Size(39, 20);
			this->SkillinjectDelay->TabIndex = 29;
			this->SkillinjectDelay->Text = L"Delay";
			// 
			// skillID
			// 
			this->skillID->Location = System::Drawing::Point(76, 40);
			this->skillID->Name = L"skillID";
			this->skillID->Size = System::Drawing::Size(82, 20);
			this->skillID->TabIndex = 28;
			this->skillID->Text = L"Skill ID";
			this->skillID->TextChanged += gcnew System::EventHandler(this, &MyForm::skillID_TextChanged_1);
			// 
			// skillinject
			// 
			this->skillinject->AutoSize = true;
			this->skillinject->Enabled = false;
			this->skillinject->ForeColor = System::Drawing::Color::Wheat;
			this->skillinject->Location = System::Drawing::Point(13, 17);
			this->skillinject->Name = L"skillinject";
			this->skillinject->Size = System::Drawing::Size(73, 17);
			this->skillinject->TabIndex = 27;
			this->skillinject->Text = L"Skill inject";
			this->skillinject->UseVisualStyleBackColor = true;
			this->skillinject->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_29);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox4);
			this->panel1->Controls->Add(this->tabControl1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(337, 545);
			this->panel1->TabIndex = 25;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox4->Controls->Add(this->ZCurrentEXP);
			this->groupBox4->Controls->Add(this->lKillCount);
			this->groupBox4->Controls->Add(this->CharXY);
			this->groupBox4->Controls->Add(this->MapID);
			this->groupBox4->Controls->Add(this->lMonsters);
			this->groupBox4->Controls->Add(this->lChannel);
			this->groupBox4->Controls->Add(this->lWorld);
			this->groupBox4->Controls->Add(this->bEmbedMS);
			this->groupBox4->Controls->Add(this->lPeople);
			this->groupBox4->Location = System::Drawing::Point(8, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(327, 100);
			this->groupBox4->TabIndex = 27;
			this->groupBox4->TabStop = false;
			// 
			// ZCurrentEXP
			// 
			this->ZCurrentEXP->AutoSize = true;
			this->ZCurrentEXP->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ZCurrentEXP->Location = System::Drawing::Point(97, 17);
			this->ZCurrentEXP->Name = L"ZCurrentEXP";
			this->ZCurrentEXP->Size = System::Drawing::Size(81, 15);
			this->ZCurrentEXP->TabIndex = 33;
			this->ZCurrentEXP->Text = L"Current EXP:0";
			// 
			// lKillCount
			// 
			this->lKillCount->AutoSize = true;
			this->lKillCount->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lKillCount->Location = System::Drawing::Point(87, 65);
			this->lKillCount->Name = L"lKillCount";
			this->lKillCount->Size = System::Drawing::Size(72, 15);
			this->lKillCount->TabIndex = 32;
			this->lKillCount->Text = L"Kill Count: 0";
			// 
			// CharXY
			// 
			this->CharXY->AutoSize = true;
			this->CharXY->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CharXY->Location = System::Drawing::Point(192, 65);
			this->CharXY->Name = L"CharXY";
			this->CharXY->Size = System::Drawing::Size(73, 15);
			this->CharXY->TabIndex = 30;
			this->CharXY->Text = L"Char XY: 0,0";
			// 
			// MapID
			// 
			this->MapID->AutoSize = true;
			this->MapID->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MapID->Location = System::Drawing::Point(192, 41);
			this->MapID->Name = L"MapID";
			this->MapID->Size = System::Drawing::Size(56, 15);
			this->MapID->TabIndex = 29;
			this->MapID->Text = L"Map ID: 0";
			// 
			// lMonsters
			// 
			this->lMonsters->AutoSize = true;
			this->lMonsters->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lMonsters->Location = System::Drawing::Point(87, 41);
			this->lMonsters->Name = L"lMonsters";
			this->lMonsters->Size = System::Drawing::Size(49, 15);
			this->lMonsters->TabIndex = 28;
			this->lMonsters->Text = L"Mobs: 0";
			// 
			// lChannel
			// 
			this->lChannel->AutoSize = true;
			this->lChannel->Location = System::Drawing::Point(9, 65);
			this->lChannel->Name = L"lChannel";
			this->lChannel->Size = System::Drawing::Size(61, 13);
			this->lChannel->TabIndex = 27;
			this->lChannel->Text = L"Channel: -1";
			// 
			// lWorld
			// 
			this->lWorld->AutoSize = true;
			this->lWorld->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lWorld->Location = System::Drawing::Point(9, 17);
			this->lWorld->Name = L"lWorld";
			this->lWorld->Size = System::Drawing::Size(78, 15);
			this->lWorld->TabIndex = 25;
			this->lWorld->Text = L"World: Kradia";
			// 
			// bEmbedMS
			// 
			this->bEmbedMS->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bEmbedMS->ForeColor = System::Drawing::Color::Black;
			this->bEmbedMS->Location = System::Drawing::Point(181, 9);
			this->bEmbedMS->Name = L"bEmbedMS";
			this->bEmbedMS->Size = System::Drawing::Size(138, 23);
			this->bEmbedMS->TabIndex = 24;
			this->bEmbedMS->Text = L"Embed MS";
			this->bEmbedMS->UseVisualStyleBackColor = true;
			this->bEmbedMS->Click += gcnew System::EventHandler(this, &MyForm::bEmbedMS_Click);
			// 
			// lPeople
			// 
			this->lPeople->AutoSize = true;
			this->lPeople->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lPeople->Location = System::Drawing::Point(9, 41);
			this->lPeople->Name = L"lPeople";
			this->lPeople->Size = System::Drawing::Size(55, 15);
			this->lPeople->TabIndex = 26;
			this->lPeople->Text = L"People: 0";
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Visible = true;
			// 
			// tInfo
			// 
			this->tInfo->Enabled = true;
			this->tInfo->Tick += gcnew System::EventHandler(this, &MyForm::tInfo_Tick);
			// 
			// tEXP
			// 
			this->tEXP->Enabled = true;
			this->tEXP->Interval = 1;
			this->tEXP->Tick += gcnew System::EventHandler(this, &MyForm::tEXP_Tick);
			// 
			// tFirst
			// 
			this->tFirst->Interval = 1;
			this->tFirst->Tick += gcnew System::EventHandler(this, &MyForm::tFirst_Tick);
			// 
			// tSecond
			// 
			this->tSecond->Interval = 1;
			this->tSecond->Tick += gcnew System::EventHandler(this, &MyForm::tSecond_Tick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 541);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"DigiZbot - EMS V104";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSkillDelay1))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCCDelay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCCPeople))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->gbTimer->ResumeLayout(false);
			this->gbTimer->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_2(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_3(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_4(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_5(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_6(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_7(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_8(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_9(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_10(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_11(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_12(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_13(System::Object^  sender, System::EventArgs^  e);
    private: System::Void checkBox1_CheckedChanged_14(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_15(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_16(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_17(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_18(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_19(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_20(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_21(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_22(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_23(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_24(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_25(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_26(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_27(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_28(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_29(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_30(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_31(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_32(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged_33(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbAutoCCPeople_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tInfo_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bEmbedMS_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void comboBox5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void skillID_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nudCCPeople_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nudCCDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void nudSkillDelay1_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void nudSkillDelay2_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nudSkillDelay3_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nudSkillDelay4_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void nudSkillDelay5_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void MSU_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void cbTopMost_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tEXP_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tFirst_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tSecond_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		e->Cancel = true;
		this->Visible = false;
	}
	private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e); //MyForm::PPtyper->Checked;
 private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }

private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void skillID_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);






};
}
	