//
// Created by Rony Zrihen on 28/12/2022.
//
#pragma once
#include <iostream>
#include <string>
#include "Character.h"


using namespace std;
class Legendary_Character: public Character{

public:
    Legendary_Character(Legendary_Character& source);
    Legendary_Character(const string& Signature_Weapon,const string& name,const string& location,Elements element,Weapon weapon);
   virtual void print_child(ostream& out) { out << m_Signature_Weapon; };
   ~Legendary_Character() {};
private:

string m_Signature_Weapon;

};