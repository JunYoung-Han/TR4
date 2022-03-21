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

		cout << "1. �����  2. ����  3. �κ��丮  4. ����  5. ���� : " << endl;
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

		cout << "ĳ���� ���� ���� ����" << endl;
		fclose(fp);
	}
	else
		cout << "ĳ���� ���� ����" << endl;
	system("pause");
}
