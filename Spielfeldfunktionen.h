#ifndef SPIELFELDFUNKTIONEN_H
#define SPIELFELDFUNKTIONEN_H

#include <string>

using namespace std;

const int fg = 4;
/**
* @brief Ein neues Spielfeld wird auf die Konsole geschrieben mit unterschiedlichen Farben (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void spielfelderstellen(string spielfeld[fg][fg]); /**zeichnet das neuste Spielfeld auf die Konsole (F)**/

/**
* @brief Das Spielfeld wird im Uhrzeigersinn rotiert (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void spielfeldrotierenUhr(string spielfeld[fg][fg]);

/**
* @brief Das Spielfeld wird gegen den Uhrzeigersinn rotiert (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void spielfeldrotierenGegenUhr(string spielfeld[fg][fg]);

int checkSiegquer(const string spielfeld[fg][fg]);        /**�berpr�ft, ob ein Spieler horizontal gewonnen hat (F)**/

int checkSiegvert(const string spielfeld[fg][fg]);        /**�berpr�ft, ob ein Spieler vertikal gewonnen hat (F)**/

int checkSiegdiagonal(const string spielfeld[fg][fg]);    /**�berpr�ft, ob ein Spieler diagonal gewonnen hat (F)**/

bool checksieg(const string spielfeld[fg][fg]);   /**kombiniert checkSiegquer(), checkSiegdiagonal() & checkSiegvert()
                                            und gibt so letzendlich den Sieger aus(F)**/
/**
* @brief Der optionale Spielzug wird nach Auswahl ausgeführt (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
* @param[in] spieler Spielername
* @param[in] spielernummer Spieler 1 oder 2, um XX und YY zu unterscheiden
**/
void steinVerschieben(string spielfeld[fg][fg], string spieler, int spielernummer);

void spielzug1(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);  /** spielt den ausgew�hlten Spielzug von spieler 1**/

void spielzug2(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);  /** spielt den Spielzug von spieler 2, wenn Name von Spieler 2
                                                            computer ist, spielt der computer - SpielzugComputer()**/

/**
* @brief Der Spielzug des Computers wird per Zufall ausgeführt (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void SpielzugComputer(string spielfeld[fg][fg]);

/**
* @brief Der Spielzug des Computers wird einen Schritt vorausschauend ausgeführt (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void SpielzugComputerL(string spielfeld[fg][fg]);

/**
* @brief Ein neues Spielfeld horizontal auf die Konsole geschrieben (Florian)
* @param[in] spielfeld[fg][fg] zweidimensionales 4x4 Array
**/
void funny_spielfelderstellen(string spielfeld[fg][fg]);

void funny_spielfeldrotierenUhr(string spielfeld[fg][fg]);
void funny_spielzug2(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);
void funny_spielzug1(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);


#endif //SPIELFELDFUNKTIONEN_H
