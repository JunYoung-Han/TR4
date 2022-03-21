#pragma once
class CObj
{
public:
	CObj();
	CObj(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	CObj(CObj& _rCObj);
	virtual ~CObj();

public:
	virtual void	Initialize(void) PURE;
	virtual void	Render(void) PURE;
	virtual void	Release(void) PURE;

public:
	const INFO& Get_Info(void) const { return m_tInfo; }
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }

protected:
	INFO m_tInfo;
};