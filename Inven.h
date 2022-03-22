#pragma once
#include "Player.h"

class CInven
{
public:
	CInven();
	~CInven();

public:
	void	Initialize();
	void	Update();
private:
	void	Release();

public:
	void	Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }

public:
	void	Equip_Item();
	void	Unequip_Item();
	void	Render_All();
	void	Render_Selective(bool _isEquipped);
	bool	Buy_Item(CObj* _pItem);
	bool	Is_SellItem(int _iSelect, int& _iMoney);

private:
	CObj* m_pPlayer;
	// 인벤토리 역할을 하는 벡터
	vector<CObj*> m_vecInven;
	const size_t m_iInvenSize;
};