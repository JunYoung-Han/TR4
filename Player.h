#pragma once
#include "Obj.h"
#include "Item.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	CPlayer(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel);
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Render(void) override;
	virtual void Release(void) override;

private:
	void	Load_Data(void);
	
public:
	void	Combat_Win(const CObj& _pMonster);
	void	Combat_Lose(void);
	void	Combat_Run(void);
	
public:
	void	Buy_Item(const CObj& _pItem) { m_tInfo.iMoney -= _pItem.Get_Info().iMoney; }
	void	Plus_Money(int _iPrice) { m_tInfo.iMoney += _iPrice; }
	void	Equip_Item(CObj* _pItem);
	void	Unequip_Item(CObj* _pItem);
	void    Adjust_ItemAbility(CObj* _pItem, bool _bEquipStatus);


public:
	void	SelectJob(void);

private:
	// ITEM_TYPE에 따른 장비 슬롯
	CObj* m_pEquipSlot[(int)ITEM_TYPE::ITEM_END];

};

