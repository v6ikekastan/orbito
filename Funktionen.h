#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H


#include <iostream>
#include <string>

using namespace std;

int highscoreAbrufen();                     /** Funktion ruft bisherigen highscore aus der Textdatei
                                            "highscore.txt" ab. (F)**/

int highscoreVergleichen(int untilscore);   /** Funktion vergleicht bisherigen highscore mit dem
                                            gerade erspielten und gibt höheren zurück (F)**/

void highscoreEintragen(int nhighscore);    /** Funktion trägt neuen highscore in die Textdatei
                                            "highscore.txt" ein. (F)**/

void ColorCout(int color, string text);     /** gibt Text in bestimmter Farbe wieder**/

void clearConsole();                        /** löscht text auf der Konsole **/

/**
* @brief prüfen ob Eingabe vom Benutzer entsprechend des Datentyps stimmt
* @param [in] spielername der vom Benutzer eingegeben wird
* @param [in] position Feld das vom Benutzer ausgewählt wird
**/
void checkEingabe(string& spielername);
void checkEingabeSpielzug(int& position);

/**
* @brief prüfen ob Spielzug vom Benutzer möglich ist
* @param [in] feld das vom Benutzer ausgewählt wird
**/
void checkSpielzug(char& feld) 

#endif //FUNKTIONEN_H
