// SaveDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DNDPproject.h"
#include "SaveDialog.h"
#include "afxdialogex.h"
#include <fstream>
#include "DNDPprojectDlg.h"


// SaveDialog dialog

IMPLEMENT_DYNAMIC(SaveDialog, CDialogEx)

SaveDialog::SaveDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(SaveDialog::IDD, pParent)
{
	me=NULL;
	Location=NULL;
	SaveDialog::ClassType=0;
}

SaveDialog::SaveDialog(int classtype,Character * me,CPoint * Location,CWnd* pParent)
	: CDialogEx(SaveDialog::IDD, pParent)
{
	SaveDialog::me=me;
	SaveDialog::Location=Location;
	SaveDialog::ClassType=classtype;
}

SaveDialog::~SaveDialog()
{
}

void SaveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, CSaveName);
	DDX_Control(pDX, IDC_EDIT2, CSavePass);
}


BEGIN_MESSAGE_MAP(SaveDialog, CDialogEx)
	ON_BN_CLICKED(IDCANCELSAVE, &SaveDialog::OnBnClickedCancelsave)
	ON_BN_CLICKED(ID_SAVEGAME, &SaveDialog::OnBnClickedSavegame)
END_MESSAGE_MAP()


// SaveDialog message handlers


void SaveDialog::OnBnClickedCancelsave()
{
EndDialog( 0 );
}


void SaveDialog::OnBnClickedSavegame()
{
CString CharacterName=CString(_T(""));
CString password=CString(_T(""));

CSaveName.GetWindowText(CharacterName);
CharacterName += ".gam";

CSavePass.GetWindowText(password);

std::ofstream WriteStuff;
WriteStuff.open(CharacterName);

if(!WriteStuff) 
{ 
	MessageBox(L"Your character could not be saved, for some reason.",
L"Error! Character Could Not Be Saved."); 
;
} //close if

else 
{
//NOTE: We need to convert the CStrings to strings to write the data.
char PASSWORD[100] = " ";
for(int y = 0; y < password.GetLength(); y++)
{ PASSWORD[y] = password[y]; }

CString CHARACTERNAME = me->getName();
char CHARNAME[100] = " ";
for(int z = 0; z < CHARACTERNAME.GetLength(); z++)
{ CHARNAME[z] = CHARACTERNAME[z]; }

//Simple serialization of Character class 
WriteStuff << PASSWORD << "\n"; 
WriteStuff << CHARNAME << "\n";
WriteStuff << me->getHP() << "\n";
WriteStuff << me->getDef() << "\n"; 
WriteStuff << me->getInt() << "\n";
WriteStuff << me->getStr() << "\n";
WriteStuff << me->getDex() << "\n";

WriteStuff << Location->x << "\n";
WriteStuff << Location->y << "\n"; 

WriteStuff<<ClassType<<"\n";

//WriteStuff << CurrentPlayer->getDagger() << "\n";
//WriteStuff << CurrentPlayer->getSword() << "\n";
//WriteStuff << CurrentPlayer->getLongBow() << "\n"; 
//WriteStuff << CurrentPlayer->getChainMail() << "\n"; 
//WriteStuff << CurrentPlayer->getFullBodyArmor() << "\n";
//WriteStuff << CurrentPlayer->getHealingPotion() << "\n";
//WriteStuff << CurrentPlayer->getFishKey() << "\n";

//WriteStuff << W1GiantAlive << "\n";
//WriteStuff << E1DragonAlive << "\n"; 
//WriteStuff << S2MotleyCrewAlive << "\n"; 
//WriteStuff << FirstTimeInShamanHut << "\n";
//WriteStuff << CENTERFirstTime << "\n";
//WriteStuff << UNDERDragonPairAlive << "\n";
//WriteStuff << FoundHP_West2 << "\n";
//WriteStuff << FoundHP_Shaman << "\n"; 
//WriteStuff << ConqueredDragons << "\n";
//WriteStuff << ConqueredGiants << "\n";

WriteStuff.close();

MessageBox(L"Your character was saved successfully!",
L"Character Saved Successfully!"); 
EndDialog( 0 );
}//close else





}