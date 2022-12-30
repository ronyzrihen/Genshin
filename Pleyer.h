//
// Created by Rony Zrihen on 28/12/2022.
//
#include "Character.h"
#include <iostream>
#include <string>


class Player {

public:
    Player(const string &name);
    Player(Character**c_list,int size);
private:

std::string m_name;
Character *m_active_characters[4];
Character **m_data_characters;


};