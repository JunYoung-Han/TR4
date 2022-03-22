#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	CItem();
	CItem(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CItem();

public:
	virtual void    Initialize() override;
	virtual void    Render() override;
	virtual void    Release() override;

public:
	const ITEM_TYPE&	Get_ItemType(void) const { return m_eItemType; }
	void				Set_ItemType(ITEM_TYPE _eItemType) { m_eItemType = _eItemType; }
	void				Set_Price(int _iPrice) { m_tInfo.iMoney = _iPrice; }
	
	void				Set_Equip(bool _bEquip) { m_bEquip = _bEquip; }
	bool				Get_Equip() { return m_bEquip; }


private:
	ITEM_TYPE   m_eItemType = ITEM_TYPE::ITEM_END;
	bool        m_bEquip = false;
};

