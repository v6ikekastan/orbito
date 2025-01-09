#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H

#include "Spielfeldfunktionen.h"
#include <iostream>
#include <string>

using namespace std;

const string dateiname = "spielstand.txt";
const char ue = 129;
const char ae = 132;
const char oe = 148;
const char OE = 153;

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
* @brief prüft, ob Eingabe vom Benutzer entsprechend des Datentyps stimmt (Laura)
* @param[in] spielername der vom Benutzer eingegeben wird
**/
void checkEingabe(string& spielername);

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
* @param[in] checksiegStatus true/false ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran true/false ob Spieler 1 dran ist
**/
void SpielstandSpeichern(const string &spieler1, const string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief Der Spielstand wird aus einer .txt-Datei gelesen (Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus true/false ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran true/false ob Spieler 1 dran ist
**/
void SpielstandLaden(string &spieler1, string &spieler2, string spielfeldarray[fg][fg], bool& checksiegStatus, int& winstreak, bool& Spieler1istDran);

/**
* @brief Formatiert die Eingabe zu einem string und sucht nach "save" (Aven)
* @param[in] position Eingabe des Spielers: Feld oder save
// alle folgenden Parameter sind ausschlielich für SpielstandSpeichern relevant
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus true/false ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran true/false ob Spieler 1 dran ist
**/
void checkSave(string position, string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief prüft, ob Eingabe vom Benutzer entsprechend des Datentyps stimmt (Laura)
* @param[in] position Feld das vom Benutzer ausgewählt wird
* // alle folgenden Parameter sind ausschlielich für SpielstandSpeichern relevant (bearbeitet Aven)
* @param[in] spieler1 Name des ersten Spielers
* @param[in] spieler2 Name des zweiten Spielers
* @param[in] spielfeldarray Spielfeld, zweidimensionales 4x4 Array
* @param[in] checksiegStatus true/false ob das Spiel schon gewonnen wurde
* @param[in] winstreak Wieviele Spiele gewonnen wurden
* @param[in] Spieler1istDran true/false ob Spieler 1 dran ist
**/
void checkEingabeSpielzug(int &position, string& spieler1, string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran);

/**
* @brief prüfen ob Spielzug vom Benutzer möglich ist (Laura)
* @param [in] feld das vom Benutzer ausgewählt wird
**/
bool checkSpielzug(const string spielfeld[fg][fg], int positiony, int positionx); 

/**
* @brief Die Buchstaben des Namen werden untereinander vertauscht (Florian)
* @param[in] name Name des Spielers
* @param[out] name vermischter Name des Spielers
**/
string namensmisch(string name); // (Flo)

/**
* @brief platziert einen Stein OO zufällig im Feld (Laura)
* @param [out] zugCounter
**/
void extraStein(string spielfeld[fg][fg], int &zugCounter); //Laura (Flo Zeile

#endif //FUNKTIONEN_H
