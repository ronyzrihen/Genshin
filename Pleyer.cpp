//
// Created by Rony Zrihen on 28/12/2022.
//

#include "Pleyer.h"
using namespace std;

Player::Player(const string &name) :
m_data_characters(new Character*),
m_name(name)
{
    std::memset(m_active_characters, NULL,4*sizeof(Character*));



}

Player::Player(Character **c_list, int size):
m_data_characters(new Character * [size])
{
    for (int i;i<size;i++){
        m_data_characters[i]=new Character (*(c_list[i]));
    }


}