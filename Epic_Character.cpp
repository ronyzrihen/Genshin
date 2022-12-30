//
// Created by Rony Zrihen on 28/12/2022.
//
#include "Epic_Character.h"

Epic_Character::Epic_Character(const string &name, int star, const string &location, Elements element, Weapon weapon,
                               const string &equipped_weapon)
                               :
                               Character(name, star,location, element,weapon,equipped_weapon)
                               {}