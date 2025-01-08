#include "Spielfeldfunktionen.h"
#include "Funktionen.h"

#include <string>
#include <iostream>

using namespace std;

void spielfelderstellen(string spielfeld[fg][fg]){
    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
                if (spielfeld[i][j] == to_string(i)+ to_string(j)){
                    ColorCout(8, spielfeld[i][j]);
                }
                if (spielfeld[i][j] == "XX"){
                    ColorCout(12,spielfeld[i][j]);
                }
                if (spielfeld[i][j] == "=="){
                    ColorCout(1,spielfeld[i][j]);
                } cout <<' ';
        } cout << endl;
    } cout << endl;
}

void spielfeldrotierenUhr(string spielfeld[fg][fg]){

    cout << "Spielfeld rotiert im Uhrzeigersinn." << endl;

    string temparray[fg][fg];

    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           temparray[i][j] = spielfeld[i][j];
        }
    }

    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           if (temparray[i][j] == "XX" || temparray[i][j] == "=="){
            spielfeld[i][j] = "  ";
           }
        }
    }

    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
            if (temparray[i][j] == "XX" || temparray[i][j] == "=="){
                if (i == 0 && j < fg - 1){              // außen oben nach rechts
                    spielfeld[i][j + 1] = temparray[i][j];
                } else if (j == fg - 1 && i < fg - 1){    // außen rechts nach unten
                    spielfeld[i + 1][j] = temparray[i][j];
                } else if (i == fg - 1 && j > 0){         // außen unten nach links
                    spielfeld[i][j - 1] = temparray[i][j];
                } else if (j == 0 && i > 0){              // außen links nach oben
                    spielfeld[i - 1][j] = temparray[i][j];
                } else if (i == 1 && j == 1){    // innen oben nach rechts
                    spielfeld[i][j + 1] = temparray[i][j];
                } else if (i == 2 && j == 2){    // innen unten nach links
                    spielfeld[i][(j - 1)] = temparray[i][j];
                } else if (j == 1 && i == 2){    // innen links nach oben
                    spielfeld[i-1][j] = temparray[i][j];
                } else if (j == 2 && i == 1){    // innen rechts nach unten
                    spielfeld[i + 1][j] = temparray[i][j];
                }
                temparray[i][j]= " ";
                temparray[i][j] = to_string(i) + to_string(j);
            }
        }
    }
    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           if (spielfeld[i][j] == "  "){
            spielfeld[i][j] = temparray[i][j];
           }
        }
    }
    spielfelderstellen(spielfeld);
}

void spielfeldrotierenGegenUhr(string spielfeld[fg][fg]){

    cout << "Spielfeld rotiert gegen den Uhrzeigersinn." << endl;

    string temparray[fg][fg];


    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           temparray[i][j] = spielfeld[i][j];
        }
    }

    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           if (temparray[i][j] == "XX" || temparray[i][j] == "=="){
            spielfeld[i][j] = "  ";
           }
        }
    }

    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
            if (temparray[i][j] == "XX" || temparray[i][j] == "=="){
                if (i == 0 && j < fg && j > 0){              // außen oben nach links
                    spielfeld[i][j - 1] = temparray[i][j];
                } else if (j == fg - 1 && i < fg && i > 0){    // außen rechts nach oben
                    spielfeld[i - 1][j] = temparray[i][j];
                } else if (i == fg - 1 && j >= 0 && j < fg - 1){         // außen unten nach rechts
                    spielfeld[i][j + 1] = temparray[i][j];
                } else if (j == 0 && i >= 0 && i < fg - 1){              // außen links nach unten
                    spielfeld[i + 1][j] = temparray[i][j];
                } else if (i == 1 && j == 2){    // innen oben nach links
                    spielfeld[i][j - 1] = temparray[i][j];
                } else if (i == 2 && j == 1){    // innen unten nach rechts
                    spielfeld[i][j + 1] = temparray[i][j];
                } else if (j == 1 && i == 1){    // innen links nach unten
                    spielfeld[i + 1][j] = temparray[i][j];
                } else if (j == 2 && i == 2){    // innen rechts nach oben
                    spielfeld[i - 1][j] = temparray[i][j];
                }
                temparray[i][j] = to_string(i) + to_string(j);
            }
        }
    }
    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
           if (spielfeld[i][j] == "  "){
            spielfeld[i][j] = temparray[i][j];
           }
        }
    }
    spielfelderstellen(spielfeld);
}

int checkSiegquer(const string spielfeld[fg][fg]){
    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
            if (spielfeld[fg][fg] == "==" && spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j + 2] == spielfeld[i][j + 3] && spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j] == "XX"){
                return 1;
                } else if (spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j + 2] == spielfeld[i][j + 3] && spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j] == "XX"){
                return 1;
                } else if (spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j + 2] == spielfeld[i][j + 3] && spielfeld[i][j] == spielfeld[i][j + 1] && spielfeld[i][j] == "=="){
                return 2;
                }
            }
        }
}

int checkSiegvert(const string spielfeld[fg][fg]){

}

int checkSiegdiagonal(const string spielfeld[fg][fg]){

}

bool checksieg(const string spielfeld[fg][fg]){
    if (checkSiegquer(spielfeld) == 3 || checkSiegdiagonal(spielfeld) == 3 || checkSiegvert(spielfeld) == 3){
        cout << "Das Spiel endet unentschieden." << endl;
        cout << endl;
        return true;
    }

    else if (checkSiegquer(spielfeld) == 1){
        cout << "Spieler 1 hat gewonnen" << endl;
        cout << endl;
        return true;
    }
    else if (checkSiegquer(spielfeld) == 2){
        cout << "Spieler 2 hat gewonnen" << endl;
        cout << endl;
        return true;
    }
}

void spielzug1(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    string positiony; // strings, da in checkEingabeSpielzug auf "save" kontrolliert und anschließend via stoi() zu int umgewandelt wird
    string positionx;

    cout << spieler1 << " (XX) ist am Zug. Zeile [space] Spalte eingeben." << endl;
    checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran); // Funktion wird aufgerufen
    checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

    spielfeld[stoi(positiony)][stoi(positionx)] = "XX";
}

void spielzug2(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    if (spieler2 == "computer" || spieler2 == "Computer") { // lowercase
        cout << spieler2 << " (==) ist am Zug." << endl;
        SpielzugComputer(spielfeld);
    }
    else if (spieler2 != "computer" && spieler2 != "Computer") { // lowercase
        string positiony; // string begründung siehe spielzug1
        string positionx;

        cout << spieler2 << " (==) ist am Zug. Zeile [space] Spalte eingeben." << endl;
        checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran); // Funktion wird aufgerufen
        checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

        spielfeld[stoi(positiony)][stoi(positionx)] = "==";
    }
}

void SpielzugComputer(string spielfeld[fg][fg]){
    int i;
    int j;
    bool freiesFeld;

    freiesFeld = false;

    while (!freiesFeld){
        i = rand() % fg;
        j = rand() % fg;
        if (spielfeld[i][j] == to_string(i) + to_string(j)){
            spielfeld[i][j] = "==";
            freiesFeld = true;
        }
    }
    cout << "Computer waehlt Feld " << i << j << endl;
}

void SpielzugComputerL(string spielfeld[fg][fg]){
// Siegzug
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            if (spielfeld[i][j] == to_string(i) + to_string(j)) {
                spielfeld[i][j] = "==";
                /*if (checkSieg(spielfeld)) {
                    cout << "Computer waehlt Feld " << i << j << endl;
                    return;
                    }*/
                spielfeld[i][j] = to_string(i) + to_string(j);
                }
            }
        }
// Blockzug
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            if (spielfeld[i][j] == to_string(i) + to_string(j)) {
                spielfeld[i][j] = "XX";
                /*if (checkSieg(spielfeld)) {
                    cout << "Computer waehlt Feld " << i << j << endl;
                    return;
                    }*/
                spielfeld[i][j] = to_string(i) + to_string(j);
                }
            }
        }
// Zufälliger Spielzug
    int i;
    int j;
    bool freiesFeld;

    freiesFeld = false;

    while (!freiesFeld){
        i = rand() % fg;
        j = rand() % fg;
        if (spielfeld[i][j] == to_string(i) + to_string(j)){
            spielfeld[i][j] = "==";
            freiesFeld = true;
            cout << "Computer waehlt Feld " << i << j << endl;
            return;
        }
    }
}

