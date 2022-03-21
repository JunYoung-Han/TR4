#include "pch.h"
#include "MainGame.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	dynamic_cast<CPlayer*>(m_pPlayer)->SelectJob();
}

void CMainGame::Update(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. 사냥터  2. 상점  3. 인벤토리  4. 저장  5. 종료 : " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if(nullptr == m_pField)
			{
				m_pField = new CField;
				m_pField->Initialize();
				m_pField->Set_Player(m_pPlayer);
			}
			m_pField->Update();
			break;
			
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			Save_Data();
			break;
			
		case 5:
			return;

		default:
			continue;
		}
	}
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);
}

void CMainGame::Save_Data(void)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/Player.dat", "wb");

	if (0 == err)
	{
		fwrite(&(m_pPlayer->Get_Info()), sizeof(INFO), 1, fp);

		cout << "캐릭터 정보 저장 성공" << endl;
		fclose(fp);
	}
	else
		cout << "캐릭터 저장 실패" << endl;
	system("pause");
}
