//
// Created by Rony Zrihen on 28/12/2022.
//
#include "Epic_Character.h"

Epic_Character::Epic_Character(const string &name, const string &location, Elements element, Weapon weapon, const string& weapon_name)
                               :
                               Character(name,4,location, element,weapon, weapon_name)
                               {}


Epic_Character::Epic_Character(Epic_Character& source):
Character(source)
{


}