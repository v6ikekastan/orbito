#include "Funktionen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>
#include <limits>
#include <cctype>

using namespace std;

int highscoreAbrufen(){
    ifstream dateiScore("highscore.txt");
    int zahl;

    if(dateiScore.is_open()){
            dateiScore >> zahl;
            dateiScore.close();
        }

    else {
        cout << "Fehler beim öffnen der Datei 'highscore.txt'." << endl;
    }

    return zahl;

}


int highscoreVergleichen(int untilscore, int scorenow){
    cout << "highscore Vergleich" << endl;
    int ahighscore = fmax(untilscore, scorenow);

    return ahighscore;

}


void highscoreEintragen(int nhighscore){
    ofstream dateiScore("highscore.txt");

    if (dateiScore.is_open()){
        dateiScore << nhighscore;
        dateiScore.close();
        cout << "Neuer Anzahl Durchlaeufe (" << nhighscore << ") gespeichert." << endl;
    }

    else {
        cout << "Fehler beim speichern des highscores in 'highscore.txt .'" << endl;
    }
}


void ColorCout(int color, string text){
   HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(handle, color);
   cout << text;
   SetConsoleTextAttribute(handle, 7);
}


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


void checkEingabeSpielzug(int& position) {
    while (true){
        cin >> position;
        if (position == "save" || position == "Save" || position == "SAVE") {
        SpielstandSpeichern(spieler1, spieler2, spielfeldarray[fg][fg], checksieg, winstreak, Spieler1istDran);
        } else if (cin.fail() || position<0 || position>3) { // prüft ob Benutzer einen Wert eingegeben hat, der nicht zum Datentyp von variable passt
            cout << "Ungültige Eingabe, bitte erneut versuchen." << endl;
            cin.clear();   // löscht Fehlerinformation
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ung黮tige Eingabe
        } else {
            break; // g黮tige Eingabe, Schleife verlassen
    }
}


bool checkSpielzug(const string& spielfeld, int positiony, int positionx){
    if ( spielfeld[positiony][positionx] == "XX" || spielfeld[positiony][positionx] == "--" ){
        cout << "Spielzug nicht moeglich, bitte erneut versuchen." << endl;
       return false;
    } else {
        return true;
    }
}

