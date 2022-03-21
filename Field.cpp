#include "pch.h"
#include "Field.h"

CField::CField()
	: m_pPlayer(nullptr)
{
}

CField::~CField()
{
	Release();
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. �ʱ�  2. �߱�  3. ���  4. �� �ܰ� : " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("�ʱ�", 10, 50, 1);
			m_pMonster->Initialize();
			break;

		case 2:
			m_pMonster = new CMonster("�߱�", 20, 100, 2);
			m_pMonster->Initialize();
			break;

		case 3:
			m_pMonster = new CMonster("���", 30, 150, 3);
			m_pMonster->Initialize();
			break;

		case 4:
			return;

		default:
			continue;
		}

		switch (Fight())
		{
		case COMBAT::COMBAT_WIN:
			dynamic_cast<CPlayer*>(m_pPlayer)->Combat_Win(*m_pMonster);
			break;

		case COMBAT::COMBAT_LOSE:
			dynamic_cast<CPlayer*>(m_pPlayer)->Combat_Lose();
			break;

		case COMBAT::COMBAT_RUN:
			dynamic_cast<CPlayer*>(m_pPlayer)->Combat_Run();
			break;

		default:
			break;
		}
		Release();
	}
}

void CField::Release()
{
	Safe_Delete<CObj*>(m_pMonster);
}

COMBAT CField::Fight()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1. ����  2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);
			m_pMonster->Set_Damage(m_pPlayer->Get_Info().iAttack);
			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return COMBAT::COMBAT_LOSE;
			}
			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "�÷��̾� �¸�!" << endl;
				system("pause");
				return COMBAT::COMBAT_WIN;
			}
			break;

		case 2:
			return COMBAT::COMBAT_RUN;
			break;

		default:
			continue;
		}
	}
}
