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

Player::Player(Character **c_list, int size,const string&name):
m_data_characters(new Character * [size]),
m_name(name),
m_size(size)
{
    for (int i=0;i<size;i++){
        if(c_list[i]->get_star()==5)
            m_data_characters[i] = new Legendary_Character(*(Legendary_Character* )(c_list[i]));
        if (c_list[i]->get_star() == 4)
            m_data_characters[i] = new Epic_Character(*(Epic_Character*)(c_list[i]));
     }
}



void Player::print_data() {
    for (int i = 0; i < m_size; i++)
    {
        cout << *(m_data_characters[i]) << endl;
    }
}


bool Player::add_character_to_data(Character* character) {
    Epic_Character* new_epic=NULL;
    Legendary_Character* new_lagend=NULL;
    if ((character->get_star() != 5) && (character->get_star() != 4))
        return false;
    if (character->get_star() == 5)
         new_lagend = new Legendary_Character(*(Legendary_Character*)character); 
    if (character->get_star() == 4)
         new_epic = new Epic_Character(*(Epic_Character*)character);

    if (m_size == 0) {
        if(new_epic==NULL)
            m_data_characters[0] = new_epic;
        else
            m_data_characters[0] = new_lagend;
        m_size++;
        return true;
    }
    Character** new_list=new Character*[m_size];
    memcpy(new_list, m_data_characters,sizeof (Character*)* m_size);
    if (new_epic != NULL)
        m_data_characters[m_size] = new_epic;
    else
        m_data_characters[m_size] = new_lagend;
    delete[] m_data_characters;
    m_data_characters = new_list;
    m_size++;
    return true;
}

Player::~Player() {
    delete[]m_active_characters;
    for (int i = 0; i < m_size; i++)
    {
        delete m_data_characters[i];
    }
    delete m_data_characters;
}
