#include "Funktionen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>
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

