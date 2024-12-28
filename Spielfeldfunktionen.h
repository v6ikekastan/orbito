#ifndef SPIELFELDFUNKTIONEN_H
#define SPIELFELDFUNKTIONEN_H

#include <string>

using namespace std;

const int fg = 4;

void spielfelderstellen(string spielfeld[fg][fg]); /**zeichnet das neuste Spielfeld auf die Konsole (F)**/


void spielfeldrotierenUhr(string spielfeld[fg][fg]);        /**rotiert die Platten auf dem Spielfeld im Uhrzeigersinn,
                                                            jedoch ohne die Positionskoordinaten zu ver�ndern (F)**/

void spielfeldrotierenGegenUhr(string spielfeld[fg][fg]);   /**rotiert die Steine auf dem Spielfeld gegen den Uhrzeigerssinn,
                                                            jedoch ohne die Positionskoordinaten zu ver�ndern (F)**/

bool checkSpielzug(string spielfeld[fg][fg], string eingabe[fg][fg]); /**�berpr�ft ob der Spielzug g�ltig ist (F)**/

int checkSiegquer(string spielfeld[fg][fg]);        /**�berpr�ft, ob ein Spieler horizontal gewonnen hat (F)**/
int checkSiegvert(string spielfeld[fg][fg]);        /**�berpr�ft, ob ein Spieler vertikal gewonnen hat (F)**/
int checkSiegdiagonal(string spielfeld[fg][fg]);    /**�berpr�ft, ob ein Spieler diagonal gewonnen hat (F)**/

bool checksieg(string spielfeld[fg][fg]);   /**combiniert checkSiegquer(), checkSiegdiagonal() & checkSiegvert()
                                            und gibt so letzendlich den Sieger aus(F)**/

void spielzug1(string spielfeld[fg][fg], string spieler1);  /** spielt den ausgew�hlten Spielzug von spieler 1**/
void spielzug2(string spielfeld[fg][fg], string spieler2);  /** spielt den Spielzug von spieler 2, wenn Name von Spieler 2
                                                            computer ist, spielt der computer - SpielzugComputer()**/

void SpielzugComputer(string spielfeld[fg][fg]);      /** f�hrt (zuf�lligen) Spielzug von Computer aus **/

void SpielzugComputerL(string spielfeld[fg][fg]);      /** f�hrt (logischen) Spielzug von Computer aus **/





#endif //SPIELFELDFUNKTIONEN_H
