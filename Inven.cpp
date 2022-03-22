#include "pch.h"
#include "Inven.h"

CInven::CInven()
	: m_pPlayer(nullptr)
	, m_iInvenSize(5)
{
}

CInven::~CInven()
{
	Release();
}

void CInven::Initialize()
{
	m_vecInven.reserve(5);
}

void CInven::Update()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. ����  2. ����  3. �� �ܰ� : " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Equip_Item();
			break;

		case 2:
			Unequip_Item();
			break;

		case 3:
			return;

		default:
			continue;
		}
	}
}

void CInven::Release()
{
	for_each(m_vecInven.begin(), m_vecInven.end(), CDeleteObj());
	m_vecInven.clear();
	vector<CObj*>().swap(m_vecInven);
}

void CInven::Equip_Item()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render_All();

		cout << "0. ������ : " << endl;
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;
		if ((size_t)iInput >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Equip_Item(m_vecInven[iInput]);

	}
}

void CInven::Unequip_Item()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render_Selective(true);

		cout << "0. ������ : " << endl;
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;
		if ((size_t)iInput >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Unequip_Item(m_vecInven[iInput]);

	}
}

void CInven::Render_All()
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		cout << i + 1 << ". ";
		m_vecInven[i]->Render();
	}
}

void CInven::Render_Selective(bool _isEquipped)
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		if (_isEquipped ? dynamic_cast<CItem*>(m_vecInven[i])->Get_Equip() :
			!dynamic_cast<CItem*>(m_vecInven[i])->Get_Equip())
		{
			cout << i + 1 << ". ";
			m_vecInven[i]->Render();
		}
	}
}

bool CInven::Buy_Item(CObj* _pItem)
{
	// �κ��丮 ���� Ȯ��
	if (m_iInvenSize <= m_vecInven.size())
		return false;

	// �κ��丮�� ������ ���� ����� �ֱ�
	// �ȱ׷��� ������ �Ҵ�� �������� �ּҸ� �״�� �������� �ȴ�.
	CObj* pObj = new CItem(*dynamic_cast<CItem*>(_pItem));

	// �ش� �������� �κ��� �ְ� true ��ȯ
	m_vecInven.push_back(pObj);
	return true;
}

bool CInven::Is_SellItem(int _iSelect, int& _iMoney)
{
	auto iter = m_vecInven.begin();
	iter += _iSelect;

	_iMoney = (*iter)->Get_Info().iMoney >> 1; // �ݰ����� �Ǵ�

	Safe_Delete<CObj*>(*iter);
	m_vecInven.erase(iter);

	return true;
}
