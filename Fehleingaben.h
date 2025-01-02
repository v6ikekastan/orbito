#ifndef FEHLEINGABEN_H
#define FEHLEINGABEN_H

#include <string>

using namespace std;

/**
* @brief prüftt ob Eingabe vom Benutzer entsprechend des Datentyps stimmt
* @param [in] spielername der vom Benutzer eingegeben wird
* @param [in] nummer die vom Benutzer eingegeben wird
**/

void checkEingabe(string& spielername);
void checkEingabeSpielzug(int& nummer);

#endif // FEHLEINGABEN_H
