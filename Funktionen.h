#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

#include "Spielfeldfunktionen.h"
#include <iostream>
#include <string>

using namespace std;

const string dateiname = "spielstand.txt";

int highscoreAbrufen();                     /** Funktion ruft bisherigen highscore aus der Textdatei
                                            "highscore.txt" ab. (F)**/

int highscoreVergleichen(int untilscore);   /** Funktion vergleicht bisherigen highscore mit dem
                                            gerade erspielten und gibt höheren zurück (F)**/

void highscoreEintragen(int nhighscore);    /** Funktion trägt neuen highscore in die Textdatei
                                            "highscore.txt" ein. (F)**/

void ColorCout(int color, string text);     /** gibt Text in bestimmter Farbe wieder**/

void clearConsole();                        /** löscht Text auf der Konsole **/

/**
* @brief Löscht alle Inhalte aus der gewünschten Datei (Aven)
**/
void clearFile();

/**
* @brief startet einen neuen Spielstand (Aven)
* @param[in] &spieler1 Name des 1. Spielers als Referenz
* @param[in] &spieler2 Name des 2. Spielers als Referenz
**/
void NeuesSpiel(string &spieler1, string &spieler2);

/**
* @brief Der Spielstand wird in einer .txt-Datei gespeichert (Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus ja/nein ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran ja/nein ob Spieler 1 dran ist
**/
void SpielstandSpeichern(const string& spieler1, const string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief Der Spielstand wird aus einer .txt-Datei gelesen (Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus ja/nein ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran ja/nein ob Spieler 1 dran ist
**/
void SpielstandLaden(string& spieler1, string& spieler2, string spielfeldarray[fg][fg], bool& checksiegStatus, int& winstreak, bool& Spieler1istDran);

/**
* @brief prüfen, ob Eingabe vom Benutzer entsprechend des Datentyps stimmt (Laura)
* @param[in] spielername der vom Benutzer eingegeben wird
* @param[in] position Feld das vom Benutzer ausgewählt wird
* // alle folgenden Parameter sind ausschlielich für SpielstandSpeichern relevant (bearbeitet Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus ja/nein ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran ja/nein ob Spieler 1 dran ist
**/
void checkEingabe(string& spielername);
void checkEingabeSpielzug(string &position, string& spieler1, string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief prüfen ob Spielzug vom Benutzer möglich ist (Laura)
* @param [in] feld das vom Benutzer ausgewählt wird
**/
bool checkSpielzug(const string& spielfeld, int positiony, int positionx); //const weil es nur Spielfeld liest

// funny modus

#endif //FUNKTIONEN_H
