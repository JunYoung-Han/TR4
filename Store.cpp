#include "pch.h"
#include "Store.h"

CStore::CStore()
	: m_pPlayer(nullptr)
	, m_pInven(nullptr)
{
	// 아이템별로 벡터 크기 미리 할당
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].reserve(3);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].reserve(3);
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize()
{
	// 모든 아이템 객체 정보 생성

	//무기류
	CItem* pItem = new CItem("초급검", 10, 0, 1);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(1000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);

	pItem = new CItem("중급검", 20, 0, 2);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(2000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);

	pItem = new CItem("고급검", 30, 0, 3);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_WEAPON);
	pItem->Set_Price(3000);
	m_vecItem[(int)ITEM_TYPE::ITEM_WEAPON].push_back(pItem);
	
	// 방어구
	pItem = new CItem("초급옷", 0, 10, 1);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_ARMOR);
	pItem->Set_Price(1000);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].push_back(pItem);
	
	pItem = new CItem("중급옷", 0, 20, 2);
	pItem->Set_ItemType(ITEM_TYPE::ITEM_ARMOR);
	pItem->Set_Price(2000);
	m_vecItem[(int)ITEM_TYPE::ITEM_ARMOR].push_back(pItem);
	
	pItem = new CItem("초급옷", 0, 30, 3);
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

		cout << "1. 무기상점  2. 방어구 상점  3. 판매  4. 전 단계 : ";
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
		// 아이템 타입 안의 모든 아이템들을 출력
		for (const auto& iter : m_vecItem[(int)_eItemType])
		{
			cout << i << ". 번 : " << endl;
			iter->Render();
			++i;
		}
		cout << "구매할 아이템 번호 선택 (4번 : 전 단계) : ";
		cin >> iInput;
		if (4 == iInput)
			return;

		// 아이템 구매
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
	// 살 돈 있는지 확인 && 인벤 공간 확인
	if (m_pPlayer->Get_Info().iMoney >= _pItem->Get_Info().iMoney
		&& m_pInven->Buy_Item(_pItem))
	{
		dynamic_cast<CPlayer*>(m_pPlayer)->Buy_Item(*_pItem);
		cout << "구매성공" << endl;
	}
	else
	{
		cout << "인벤토리 칸이 가득 찼거나 또는 잔액이 부족합니다." << endl;
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

		cout << "0. 나가기 : " << endl;
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
			cout << "판매 성공!" << endl;
		}
		else
		{
			cout << "[판매 실패] 판매할 아이템이 없습니다." << endl;
		}
		system("pause");
	}
}
