#include <iostream>
#include"Pleyer.h"
#include"Legendary_Character.h"
#include"Epic_Character.h"





int main() {

    Epic_Character ofek("ofek", "gan ner", Anemo, Sword, "Death bringer");
    Epic_Character rony("rony", "ramat gan",Anemo, Bow, "a toy");
    Epic_Character yuval("yuval", "hell", Geo,Catalyst, "A shitty book");
    Legendary_Character Ofek("m16", "Ofek", "gan ner", Hydro, Polearm, "pointy");

    Character** list = new Character * [4];

    list[0] = &ofek;
    list[1] = &rony;
    list[2] = &yuval;
    list[3] = &Ofek;

    Player player(list, 4, "player");
    player.print_data();


    Player p("p");
    int choice;
    for (;;) {

        cout << "1.Add character\n"
            << "2.Edit weapon to character\n"
            << "3.Edit active team\n"
            << "4.Evaluate team\n";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            string name,location, weapon_name ,signature_weapon;
            int elem,weapon,stars;
           
            cout << "Enter chararcter name: ";
            cin >> name;
            cout << "Enter chatacter location: ";
            cin >> location;
            cout << "Choose element: \n"
                << "1.Anemo\n"
                << "2.Pyro\n"
                << "3.Cyro\n"
                << "4.Hydro\n"
                << "5.Electro\n"
                << "6.Geo\n"
                << "7.Dendro\n";
            cin >> elem;
            while (elem < 1 || elem > 7) {
                cout << "Invalid element,\n try again: ";
                cin  >>elem;
            }
            elem--;

            cout << "Choose weapon: \n"
                << "1.Sword\n"
                << "2.Polearm\n"
                << "3.Catalyst\n"
                << "4.Claymore\n"
                << "5.Bow\n";
            cin >> weapon;
            while (weapon < 1 || weapon > 7) {
                cout << "Invalid weapon,\n try again: ";
                cin >> weapon;
            }
            weapon--;

            cout << "Choose weapon's name: ";
            cin >> weapon_name;

            cout << "Choose character type: \n"
                << "4.Epic\n"
                << "5.Legendary\n";
            cin >> stars;
            while (stars != 4 || stars != 5) {
                cout << "invalid type,\n try again: ";
                cin >> stars;
            }

            if (stars == 4) {
                Epic_Character new_character(name, location, (Elements)elem,(Weapon) weapon, weapon_name);
                player.add_character_to_data(&new_character);
                break;
            }
            if (stars == 5) {
                cout << "Choose signature weapon: ";
                cin >> signature_weapon;
                Legendary_Character new_character(signature_weapon,name, location, (Elements)elem, (Weapon)weapon, weapon_name);
                player.add_character_to_data(&new_character);
                player.print_data();
                break;

            }
        }
        case 2: {
            int choice1;
            string weapon;
            cout << "Choose character: \n";
            player.print_active();
            cout << "=>>  ";
            cin >> choice1;
            cout << "Enter weapon: ";
            cin >> weapon;
            player.change_weapon(choice1-1, weapon);
            player.print_active();
            break;
        }
        case 3: {
            int data_character,active_character;
            cout << "Choose character to switch: \n";
            player.print_active();
            cout << "=>>  ";
            cin >> active_character;
            cout << "Choose character form data: \n";
            player.print_data();
            cout << "=>> ";
            cin >> data_character;
            player.switch_character(data_character-1, active_character-1);
            player.print_active();
            break;
        }
        case 4: {
            player.Evaluate();
            break;
        }
        default:
            break;
        }
    }
    
    return 0;
}
