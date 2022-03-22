#pragma once
// Store Ŭ����.
// �÷��̾ �������� ��� ��.
// ���ο��� �÷��̾�� �κ��丮�� �ּҸ� �޾ƿ�.

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
	// ������ Item Type (�迭) �ε������� vector �� ����.
	// �������� �����۵��� �������� �����Ϸ��� �뵵.
	vector<CObj*> m_vecItem[(int)ITEM_TYPE::ITEM_END];
};

