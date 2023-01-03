//
// Created by Rony Zrihen on 30/12/2022.
//

#include "Legendary_Character.h"

Legendary_Character::Legendary_Character(const string& Signature_Weapon, const string &name, const string &location,
                                         Elements element, Weapon weapon ,const string& weapon_name)
                                         :
                        Character(name,5,location, element,weapon, weapon_name),
                        m_Signature_Weapon(Signature_Weapon)
                                         {}

Legendary_Character::Legendary_Character(Legendary_Character& source) :
Character(source),
m_Signature_Weapon(source.m_Signature_Weapon)
{

}