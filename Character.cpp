//
// Created by Rony Zrihen on 28/12/2022.
//
#include "Character.h"


string elem_str[7] = { "Anemo", "Pyro", "Cryo", "Hydro", "Electro", "Geo", "Dendro" };
string weapon_str[5] = { "Sword", "Polearm", "Catalyst", "Claymore", "Bow" };

Character:: Character(const string& name,int star,const string& location,Elements element,Weapon weapon, const string& equiped_weapon)
:
m_name(name),
m_stars(star),
m_location(location),
m_element(element),
m_weapon(weapon),
m_equipped_weapon(equiped_weapon)
{

}


Character::Character(Character& source):
m_name(source.m_name),
m_location(source.m_location),
m_element(source.m_element),
m_weapon(source.m_weapon),
m_equipped_weapon(source.m_equipped_weapon),
m_stars(source.m_stars)
{



}

void Character::print(ostream& out) {

	out << m_name << " - " << m_stars << " " <<elem_str[m_element] << " "<< m_location << " " << weapon_str[m_weapon] << " " << m_equipped_weapon << " ";
	print_child(out);
	out << endl;
}




ostream& operator <<(ostream& out, Character& source) {

	source.print(out);

	return out;

}



























