#include "pch.h"
#include "Obj.h"

CObj::CObj()
{
}

CObj::CObj(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel)
	: m_tInfo(_szName, _iAttack, _iMaxHp, _iLevel)
{
}

CObj::CObj(CObj& _rCObj)
	: m_tInfo(_rCObj.m_tInfo)
{
}

CObj::~CObj()
{
}