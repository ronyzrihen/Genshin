//
// Created by Rony Zrihen on 30/12/2022.
//

#include "Legendary_Character.h"

Legendary_Character::Legendary_Character(string Signature_Weapon, const string &name, int star, const string &location,
                                         Elements element, Weapon weapon, const string &equipped_weapon)
                                         :
                        Character(name, star,location, element,weapon,equipped_weapon),
                        m_Signature_Weapon(Signature_Weapon)
                                         {}

Legendary_Character::Legendary_Character(Legendary_Character& source) :
Character(source)
{






}