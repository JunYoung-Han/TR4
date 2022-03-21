#pragma once
#include "Obj.h"
class CMonster :
    public CObj
{
public:
    CMonster();
    CMonster(const char* _szName, int _iAttack, int _iMaxHp, int _iLevel);
    virtual ~CMonster();

public:
    void Initialize(void) override;
    void Render(void) override;
    void Release(void) override;
};

