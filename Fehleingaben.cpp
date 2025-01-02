#include <iostream>
#include <limits>
#include <cctype>
#include "Fehleingaben.h"

using namespace std;

void checkEingabe(string& spielername) {
    while (true) {
        cin >> spielername;
        bool valid = true;
        for (char c : spielername) {
            if (!isalpha(c)) { // prüft ob jedes Zeichen ein Buchstabe ist
                valid = false;
                break;
            }
        }
        if (!valid || spielername.empty() || cin.fail()) {
            cout << "Ungültige Eingabe, bitte erneut versuchen." << endl;
            cin.clear();   // löscht Fehlerinformation
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ungültige Eingabe
        } else {
            break; // gtige Eingabe, Schleife verlassen
        }
    }
}

void checkEingabeSpielzug(int& nummer) {
    while (true){
        cin >> nummer;
        if(cin.fail() || nummer<0 || nummer>3){ // prüft ob Benutzer einen Wert eingegeben hat, der nicht zum Datentyp von variable passt
            cout << "Ungültige Eingabe, bitte erneut versuchen." << endl;
            cin.clear();   // löscht Fehlerinformation
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ung黮tige Eingabe
        } else {
            break; // g黮tige Eingabe, Schleife verlassen
        }
    }
}
