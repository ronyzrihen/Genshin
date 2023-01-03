//
// Created by Rony Zrihen on 28/12/2022.
//
#pragma once
#include <iostream>
#include <string>
typedef enum {Anemo, Pyro, Cyro, Hydro, Electro, Geo, Dendro}Elements;
typedef enum {Sword, Polearm, Catalyst, Claymore, Bow}Weapon;

using namespace std;



class Character{

public:
Character(){};
Character(Character&source);
Character(const string& name,int star,const string& location,Elements element,Weapon weapon, const string& equiped_weapon);
~Character(){};

public:
    void print(ostream& out);
    virtual void print_child(ostream& out){};
    int get_star() { return m_stars; };
    void set_weapon(const string& name) { m_equipped_weapon = name; };
    Elements get_element() { return m_element; };
    string get_location() { return m_location; };
    string get_name() { return m_name; };
    Weapon get_weapon() { return m_weapon; };
    
protected:
    std::string m_name;
    std::string m_location;
    Elements m_element;
    Weapon  m_weapon;
    std :: string m_equipped_weapon;
    int m_stars;

};




ostream& operator <<(ostream& out, Character& source);
