#pragma once

#define PURE	= 0

typedef struct tagInfo
{
	char szName[32];
	int iAttack;
	int iHp;
	int iMaxHp;
	int iExp;
	int iMaxExp;
	int iMoney;
	int iLevel;

	tagInfo(void)
	{
		memset(this, 0, sizeof(tagInfo));
	}
	tagInfo(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel = 1)
		: iAttack(_iAttack), iMaxHp(_iMaxHp), iHp(_iMaxHp), iLevel(_iLevel), iExp(0), iMaxExp(100), iMoney(0)
	{
		strcpy_s(szName, 32, _szName);
	}
}INFO;

template<typename T>
void Safe_Delete(T& Temp)
{
	if (nullptr != Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

class CDeleteObj
{
public:
	template<typename T>
	void operator()(T& Temp)
	{
		if (nullptr != Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

enum class COMBAT
{
	COMBAT_WIN,
	COMBAT_LOSE,
	COMBAT_RUN,
	COMBAT_END,
};

enum class ITEM_TYPE
{
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_END,
};