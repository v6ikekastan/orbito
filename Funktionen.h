#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

#include "Spielfeldfunktionen.h"
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

void clearConsole();                        /** löscht Text auf der Konsole **/

/**
* @brief prüfen, ob Eingabe vom Benutzer entsprechend des Datentyps stimmt (Laura)
* @param [in] spielername der vom Benutzer eingegeben wird
* @param [in] position Feld das vom Benutzer ausgewählt wird
**/
void checkEingabe(string& spielername);
void checkEingabeSpielzug(int& position);

/**
* @brief prüfen ob Spielzug vom Benutzer möglich ist (Laura)
* @param [in] feld das vom Benutzer ausgewählt wird
**/
bool checkSpielzug(const string& spielfeld, int positiony, int positionx); //const weil es nur Spielfeld liest

/**
* @brief Der Spielstand wird in einer .txt-Datei gespeichert (Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksieg ja/nein ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran ja/nein ob Spieler 1 dran ist
**/
void SpielstandSpeichern(const string& spieler1, const string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief Der Spielstand wird aus einer .txt-Datei gelesen (Aven)
* @param[in] dateiname Die .txt-Datei mit dem gespeicherten Spielstand
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksieg ja/nein ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran ja/nein ob Spieler 1 dran ist
**/
void SpielstandLaden(const string& dateiname, string& spieler1, string& spieler2, string spielfeldarray[fg][fg], bool& checksiegStatus, int& winstreak, bool& Spieler1istDran);

/**
* @brief Löscht alle Inhalte aus der gewünschten Datei (Aven)
* @param[in] dateiname Name der gewünschten Datei
**/
void clearFile(const string& dateiname);

/**
* @brief startet einen neuen Spielstand (Aven)
* @param[in] &spieler1 Name des 1. Spielers als Referenz
* @param[in] &spieler2 Name des 2. Spielers als Referenz
**/
void NeuesSpiel(string &spieler1, string &spieler2);

#endif //FUNKTIONEN_H
