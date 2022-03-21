#pragma once
#include "Obj.h"
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
	void	SelectJob(void);

};

