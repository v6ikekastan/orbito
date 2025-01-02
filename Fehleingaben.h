#ifndef FEHLEINGABEN_H
#define FEHLEINGABEN_H

#include <string>

using namespace std;

/**
* @brief prüfen ob Eingabe vom Benutzer entsprechend des Datentyps stimmt
* @param [in] spielername der vom Benutzer eingegeben wird
* @param [in] position Feld das vom Benutzer ausgewählt wird
**/

void checkEingabe(string& spielername);
void checkEingabeSpielzug(int& position);

#endif // FEHLEINGABEN_H
