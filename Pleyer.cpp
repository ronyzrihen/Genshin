//
// Created by Rony Zrihen on 28/12/2022.
//

#include "Pleyer.h"
using namespace std;






Player::Player(const string &name) :
m_data_characters(new Character*),
m_name(name),
m_size(0)
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
        cout <<i+1<<". " << *(m_data_characters[i]) ;
       
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
        if(new_epic!=NULL)
            m_data_characters[0] = new_epic;
        else
            m_data_characters[0] = new_lagend;
        m_size++;
        return true;
    }
    Character** new_list=new Character*[m_size+1];
    memcpy(new_list, m_data_characters,sizeof (Character*)* m_size);
    if (new_epic != NULL)
        new_list[m_size] = new_epic;
    else
        new_list[m_size] = new_lagend;
    m_size++;
    delete m_data_characters;
    m_data_characters = new_list;
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



void Player::change_weapon(int num, const string& name) {

    if (num > 4 || num < 0||name==" ")
        return ;
    if (m_active_characters[num] == NULL) {
        cout << "Error\n";
        return;
    }
    m_active_characters[num]->set_weapon(name);
}



void Player::print_active() {
    
    for (int i = 0; i < 4; i++)
    {
        if (m_active_characters[i] == NULL) {
            cout<<i+1 << ".     NULL      \n";
            continue;
        }
        cout <<i + 1 << ". " << *(m_active_characters[i]) ;

    }
}



void Player::switch_character(int num1, int num2) {
    if (num1 < 0 || num1 >= m_size || num2 >= 4 || num2 < 0)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (m_active_characters[i] == m_data_characters[num1]) {
            cout << "Character was not added to active charaters\n";
            return;
        }
    }
    m_active_characters[num2] = m_data_characters[num1];
}



void Player::Evaluate() {

    string elem_str[7] = { "Anemo", "Pyro", "Cryo", "Hydro", "Electro", "Geo", "Dendro" };
    int elem[7];
    memset(elem, 0, 7 * sizeof(int));
    int loc[4];
    memset(loc, 0, 4 * sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        if(m_active_characters[i])
            elem[m_active_characters[i]->get_element()]++;
        for ( int j = i+1;  j < 4;  j++)
        {
            if (m_active_characters[j]) {

            if (m_active_characters[i]->get_location() == m_active_characters[j]->get_location())
                loc[i]++;
            }
        }

    }

    for (int i = 0; i < 4; i++) {
        if (!m_active_characters[i])
            continue;
        cout << m_active_characters[i]->get_name();
        switch (m_active_characters[i]->get_weapon()) {

        case Sword: {
            cout << "  swing swiftly the sword\n";
            break;
        }
                  case Polearm: {
                      cout << " agile with polearm\n";
            break;
        }
                  case Catalyst: {
                      cout << " cast spells with catalyst\n";
            break;
        }
                  case Claymore: {
                      cout << " swing the heavy claymore\n";
            break;
        }
                  case Bow:{
                      cout << " shot from afar with the bow\n";
            break;
        }
      
        }//END OF SWITCH
    }

    cout << endl<< endl;

    cout << "Passable Elements Reactions:\n";
    if (elem[Cyro] && elem[Anemo])
        cout << "Blizzard\n";
    if (elem[Dendro] && elem[Pyro])
        cout << "Burn\n";
    if (elem[Geo] && (elem[Cyro] || elem[Electro] || elem[Hydro] || elem[Pyro]))
        cout << "Crystalize\n";
    if (elem[Geo] && elem[Anemo])
        cout << "Dust\n";
    if (elem[Electro] && elem[Hydro])
        cout << "Electro-charged\n";
    if (elem[Hydro] && elem[Cyro])
        cout << "Frozen\n";
    if (elem[Geo] && elem[Pyro])
        cout << "Magma\n";
    if (elem[Pyro] && elem[Cyro])
        cout << "Melt\n";
     if (elem[Geo] && elem[Hydro])
        cout << "Mud\n";
     if (elem[Pyro] && elem[Electro])
        cout << "Overloaded\n";
     if (elem[Dendro] && elem[Hydro])
        cout << "poison\n";
     if (elem[Geo] && elem[Cyro])
        cout << "Shatter\n";
     if (elem[Electro] && elem[Cyro])
        cout << "Superconduct\n";
     if (elem[Anemo] && (elem[Cyro]|| elem[Electro] || elem[Hydro] || elem[Pyro]))
        cout << "Swirl\n";
     if (elem[Geo] && elem[Dendro])
        cout << "Thorn\n";
     if (elem[Hydro] && elem[Pyro])
        cout << "Vaporize\n";


     
    for (int i = 0; i < 7; i++)
    {
        if (elem[i] > 1) {
            
            cout << elem[i] << " characters are " <<elem_str[i] << " elements:" << endl
            << "adding " << elem[i] << "0% " << elem_str[i] << " power\n";
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (loc[i] > 0) {
            cout << loc[i] + 1 << " characteers from the same location: " << endl
                << "adding " << loc[i] + 1 << "0% coordination\n ";
        }

    }
}

