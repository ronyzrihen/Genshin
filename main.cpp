#include <iostream>
#include"Pleyer.h"
#include"Legendary_Character.h"
#include"Epic_Character.h"





int main() {

    Epic_Character ofek("ofek", "gan ner", Electro, Sword);
    Epic_Character rony("rony", "ramat gan",Anemo, Bow);
    Epic_Character yuval("yuval", "hell", Geo,Catalyst);
    Legendary_Character Ofek("m16", "Ofek", "gan ner", Hydro, Polearm);

    Character** list = new Character * [4];

    list[0] = &ofek;
    list[1] = &rony;
    list[2] = &yuval;
    list[3] = &Ofek;

    Player player(list, 4, "player");
    player.print_data();

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
            string name,location, signature_weapon;
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

            cout << "Choose weapon: \n"
                << "1.Sword\n"
                << "2.Polearm\n"
                << "3.Catalyst\n"
                << "4.Claymore\n"
                << "5.Bow\n";
            cin >> weapon;

            cout << "Choose character type: \n"
                << "4.Epic\n"
                << "5.Legendary\n";
            cin >> stars;

            if (stars == 4) {
                Epic_Character new_character(name, location, (Elements)elem,(Weapon) weapon);
                player.add_character_to_data(&new_character);
                break;
            }
            if (stars == 5) {
                cout << "Choose signature weapon: ";
                cin >> signature_weapon;
                Legendary_Character new_character(signature_weapon,name, location, (Elements)elem, (Weapon)weapon);
                player.add_character_to_data(&new_character);
                break;

            }
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        default:
            break;
        }
    }
    
    return 0;
}
