#include "pch.h"
#include "Item.h"

CItem::CItem()
	: CObj()
{
}

CItem::CItem(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel)
	: CObj(_szName, _iAttack, _iMaxHp, _iLevel)
{
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Render()
{
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "���ݷ� : " << m_tInfo.iAttack << endl;
	cout << "ü�� : " << m_tInfo.iHp << endl;
	cout << "���� : " << m_tInfo.iMoney << endl;
	cout << "==============================" << endl;
}

void CItem::Release()
{
}
