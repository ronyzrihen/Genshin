//
// Created by Rony Zrihen on 28/12/2022.
//
#include <iostream>
#include <string>
#include "Character.h"


using namespace std;

class Epic_Character : public Character{

public:
    Epic_Character(const string& name,int star,const string& location,Elements element,Weapon weapon,const string& equipped_weapon);
    void Attack(){};

};