#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
	: CObj()
{
}

CMonster::CMonster(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel)
	: CObj(_szName, _iAttack, _iMaxHp, _iLevel)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	// 돈과 경험치 랜덤초기화
	m_tInfo.iExp = rand() % 50 + ((m_tInfo.iLevel - 1) * 50);
	m_tInfo.iMoney = rand() % 5000 + ((m_tInfo.iLevel - 1) * 50);
	m_tInfo.iMaxExp = m_tInfo.iExp;
}

void CMonster::Render(void)
{
	cout << "=============================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "공격력 : " << m_tInfo.iAttack << endl;
	cout << "체력 : " << m_tInfo.iHp << endl;
	cout << "경험치 : " << m_tInfo.iExp << endl;
	cout << "소지금 : " << m_tInfo.iMoney << endl;
}

void CMonster::Release(void)
{
}
