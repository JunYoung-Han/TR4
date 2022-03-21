#pragma once
#include "Player.h"
#include "Field.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Initialize(void);
	void	Update(void);

private:
	void	Release(void);

private:
	void	Save_Data(void);

private:
	CObj* m_pPlayer;
	CField* m_pField;

};