#ifndef FEHLEINGABEN_H
#define FEHLEINGABEN_H

#include <string>

using namespace std;

/**
* @brief prüftt ob Eingabe vom Benutzer entsprechend des Datentyps stimmt
* @param [in] spielername der vom Benutzer eingegeben wird
* @param [in] position die vom Benutzer eingegeben wird
**/

void checkEingabe(string& spielername);
void checkEingabeSpielzug(int& position);

#endif // FEHLEINGABEN_H
