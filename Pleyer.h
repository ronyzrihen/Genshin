//
// Created by Rony Zrihen on 28/12/2022.
//
#pragma once
#include "Character.h"
#include"Legendary_Character.h"
#include"Epic_Character.h"
#include <iostream>
#include <string>


class Player {

public:
    Player(const string &name);
    Player(Character**c_list,int size,const string&name);
    ~Player();
public:
    void print_data();
    bool add_character_to_data(Character* character);
private:

std::string m_name;
Character *m_active_characters[4];
Character **m_data_characters;
int m_size;

};