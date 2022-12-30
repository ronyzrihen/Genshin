//
// Created by Rony Zrihen on 28/12/2022.
//
#include <iostream>
#include <string>
typedef enum {Anemo, Pyro, Cyro, Hydro, Electro, Geo, Dendro}Elements;
typedef enum {Sword, Polearm, Catalyst, Claymore, Bow}Weapon;
using namespace std;


class Character{

public:
Character();
Character(Character&);
Character(const string& name,int star,const string& location,Elements element,Weapon weapon,const string& equipped_weapon);
~Character();

protected:
    std::string m_name;
    std::string m_location;
    Elements m_element;
    Weapon  m_weapon;
    std :: string equipped_weapon;
    int m_stars;

};