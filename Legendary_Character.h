//
// Created by Rony Zrihen on 28/12/2022.
//
#include <iostream>
#include <string>
#include "Character.h"


using namespace std;
class Legendary_Character: public Character{

public:
    Legendary_Character(Legendary_Character& source);
    Legendary_Character(string Signature_Weapon,const string& name,int star,const string& location,Elements element,Weapon weapon,const string& equipped_weapon);


private:

string m_Signature_Weapon;

};