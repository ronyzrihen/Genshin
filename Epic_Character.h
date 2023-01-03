//
// Created by Rony Zrihen on 28/12/2022.
//
#pragma once
#include <iostream>
#include <string>
#include "Character.h"


using namespace std;

class Epic_Character : public Character{

public:
    Epic_Character(const string& name,const string& location,Elements element,Weapon weapon, const string& weapon_name);
    Epic_Character(Epic_Character& source);
    ~Epic_Character() {};
    void Attack(){};

};