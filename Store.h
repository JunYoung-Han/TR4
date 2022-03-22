#pragma once
// Store 클래스.
// 플레이어가 아이템을 사는 씬.
// 메인에서 플레이어와 인벤토리의 주소를 받아옴.

#include "Player.h"
#include "Inven.h"

class CStore
{
public:
	CStore();
	~CStore();

public:
	void	Initialize();
	void	Update();
private:
	void	Render(ITEM_TYPE _eItemType);
	void	Release();

public:
	void	Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	void	Set_Inven(CInven* _pInven) { m_pInven = _pInven; }
private:
	void	Buy_Item(CObj* _pItem);
	void	Sell_Item(void);



private:
	CObj* m_pPlayer;
	CInven* m_pInven;
	// 각각의 Item Type (배열) 인덱스마다 vector 가 존재.
	// 상점들의 아이템들을 종류별로 저장하려는 용도.
	vector<CObj*> m_vecItem[(int)ITEM_TYPE::ITEM_END];
};

