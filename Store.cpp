#include "pch.h"
#include "Store.h"

CStore::CStore()
	: m_pPlayer(nullptr)
	, m_pInven(nullptr)
{
	// �����ۺ��� ���� ũ�� �̸� �Ҵ�
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].reserve(3);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].reserve(3);
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize()
{
	// ��� ������ ��ü ���� ����

	//�����
	CItem* pItem = new CItem("�ʱް�", 10, 0, 1);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(1000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);

	pItem = new CItem("�߱ް�", 20, 0, 2);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(2000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);

	pItem = new CItem("��ް�", 30, 0, 3);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(3000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);
	
	// ��
	pItem = new CItem("�ʱ޿�", 0, 10, 1);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_ARMOR);
	pItem->Set_Price(1000);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].push_back(pItem);
	
	pItem = new CItem("�߱޿�", 0, 20, 2);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_ARMOR);
	pItem->Set_Price(2000);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].push_back(pItem);
	
	pItem = new CItem("�ʱ޿�", 0, 30, 3);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_ARMOR);
	pItem->Set_Price(3000);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].push_back(pItem);
}

void CStore::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. �������  2. �� ����  3. �Ǹ�  4. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(ITEM_TYPE::ITEM_WEAPON);
			break;
			
		case 2:
			Render(ITEM_TYPE::ITEM_ARMOR);
			break;
			
		case 3:
			Sell_Item();
			break;
			
		case 4:
			return;

		default:
			continue;
		}
	}
}

void CStore::Render(ITEM_TYPE _eItemType)
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		int i = 1;
		// ������ Ÿ�� ���� ��� �����۵��� ���
		for (const auto& iter : m_vecItem[(int)_eItemType])
		{
			cout << i << ". �� : " << endl;
			iter->Render();
			++i;
		}
		cout << "������ ������ ��ȣ ���� (4�� : �� �ܰ�) : ";
		cin >> iInput;
		if (4 == iInput)
			return;

		// ������ ����
		Buy_Item(m_vecItem[(int)_eItemType][iInput - 1]);
	}
}

void CStore::Release()
{
	for (int i = 0; i < (int)ITEM_TYPE::ITEM_END; ++i)
	{
		for_each(m_vecItem[i].begin(), m_vecItem[i].end(), CDeleteObj());
		m_vecItem[i].clear();
		vector<CObj*>().swap(m_vecItem[i]);
	}
}

void CStore::Buy_Item(CObj* _pItem)
{
	// �� �� �ִ��� Ȯ�� && �κ� ���� Ȯ��
	if (m_pPlayer->Get_Info().iMoney >= _pItem->Get_Info().iMoney
		&& m_pInven->Buy_Item(_pItem))
	{
		dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Item(*_pItem);
		cout << "���ż���" << endl;
	}
	else
	{
		cout << "�κ��丮 ĭ�� ���� á�ų� �Ǵ� �ܾ��� �����մϴ�." << endl;
	}
	system("pause");
}

void CStore::Sell_Item(void)
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pInven->Render_Selective(false);

		cout << "0. ������ : " << endl;
		cin >> iInput;

		--iInput;

		if (0 > iInput)
			return;
		if (5 <= iInput)
			continue;
		int iGetMoney = 0;

		if (m_pInven->Is_SellItem(iInput, iGetMoney))
		{
			dynamic_cast<CPlayer*>(m_pPlayer)->Plus_Money(iGetMoney);
			cout << "�Ǹ� ����!" << endl;
		}
		else
		{
			cout << "[�Ǹ� ����] �Ǹ��� �������� �����ϴ�." << endl;
		}
		system("pause");
	}
}
