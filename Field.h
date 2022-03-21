#pragma once
#include "Player.h"
#include "Monster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }

public:
	void	Initialize();
	void	Update();
	void	Release();

private:
	COMBAT Fight();

private:
	CObj* m_pPlayer;
	CObj* m_pMonster;
};