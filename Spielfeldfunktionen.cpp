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
                 }
                if (spielfeld[i][j] == "OO"){
                    ColorCout(14,spielfeld[i][j]);
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

void steinVerschieben(string spielfeld[fg][fg], string spieler, int spielernummer) {
    int x = 0;
    int y = 0;
    string richtung;
    bool w = true;
    string temparray[fg][fg];
    char ausfuehrung;
    int begrenzung;
    begrenzung = 0;

    cout << "Optionaler Spielzug: orthogonale Verschiebung eines gegnerischen Steins." << endl;
    cout << "Fuer Ausfuehrung beliebigen Buchstaben eingeben. Bei abbruch beliebige Zahl." << endl;
    cin >> ausfuehrung;
    if (!isalpha(ausfuehrung)){
        cout << "Das Spiel wird ohne optionalen Spielzug fortgesetzt." << endl;
        return;
    }

    // Kopiere das Spielfeld ins temporäre Array
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            temparray[i][j] = spielfeld[i][j];
        }
    }

    // Position und Richtung des Steins einlesen
    while (w == true) {
        begrenzung = begrenzung + 1;
        if (begrenzung == 7){
            cout << "Das Spiel wird ohne optionalem Spielzug fortgesetzt. (zu viele Fehlversuche)" << endl;
            return;
        }
        cout << "Gib die aktuelle Position des zu verschiebenden Steins (x y) an: ";
        cin >> x >> y;

        // Überprüfen, ob die aktuelle Position gültig ist
        if (x < 0 || x >= fg || y < 0 || y >= fg || temparray[x][y] == to_string(x) + to_string(y)) {
            cout << "Ungueltige Position!" << endl;
            continue; // Neustart der Schleife
        }

        if (spielernummer == 1 && temparray[x][y] == "XX"){
            cout << "Es duerfen nur gegnerische Steine verschoben werden." << endl;
            continue;
        }

        if (spielernummer == 2 && temparray[x][y] == "=="){
            cout << "Es duerfen nur gegnerische Steine verschoben werden." << endl;
            continue;
        }

        cout << "Gib die Verschieberichtung an (oben, unten, links, rechts): ";
        cin >> richtung;

        // Bestimmen der neuen Position basierend auf der Richtung
        int newX = x, newY = y;
        if (richtung == "oben" || richtung == "Oben" || richtung == "o" || richtung == "O" || richtung == "w") {
            newX = x - 1;
        } else if (richtung == "unten" || richtung == "Unten" || richtung == "u" || richtung == "U" || richtung == "s") {
            newX = x + 1;
        } else if (richtung == "links" || richtung == "Links" || richtung == "L" || richtung == "l" || richtung == "a") {
            newY = y - 1;
        } else if (richtung == "rechts" || richtung == "Rechts" || richtung == "r" || richtung == "R" || richtung == "d") {
            newY = y + 1;
        } else {
            cout << "Ungueltige Richtung!" << endl;
            continue; // Neustart der Schleife
        }
        // Überprüfen, ob die neue Position gültig ist
        if (newX < 0 || newX >= fg || newY < 0 || newY >= fg || spielfeld[newX][newY] != to_string(newX) + to_string(newY)) {
            cout << "Ungueltige Verschiebung!" << endl;
            continue; // Neustart der Schleife
        }
        // Stein verschieben
        temparray[newX][newY] = temparray[x][y];
        temparray[x][y] = to_string(x) + to_string(y); // Leeren Platz markieren

        // Schleife beenden
        w = false;
    }

    // Spielfeld aktualisieren
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            spielfeld[i][j] = temparray[i][j];
        }
    }
    spielfelderstellen(spielfeld);
}

void spielzug1(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    int positiony, positionx;

    cout << spieler1 << " (XX) ist am Zug." << endl;
    steinVerschieben(spielfeld, spieler1, 1);
    cout << "Zeile [space] Spalte eingeben." << endl;

    do { // Wiederholen, bis der Spieler einen gültigen Zug tätigt
        checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

    if (!checkSpielzug(spielfeld, positiony, positionx)) {} // Überprüfe, ob der Zug gültig ist
        
    } while (!checkSpielzug(spielfeld, positiony, positionx)); // Solange der Zug ungültig ist, wiederhole die Eingabeaufforderung

    spielfeld[positiony][positionx] = "XX";// Wenn der Spielzug gültig ist, aktualisiere das Spielfeld

}

void spielzug2(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    if (spieler2 == "computer" || spieler2 == "Computer") {
        cout << spieler2 << " (==) ist am Zug." << endl;
        SpielzugComputerL(spielfeld);
        }
    else if (spieler2 != "computer" && spieler2 != "Computer") {
        int positiony;
        int positionx;


    cout << spieler2 << " (==) ist am Zug." << endl;
    steinVerschieben(spielfeld, spieler2, 2);
    cout <<"Zeile [space] Spalte eingeben." << endl;

    do { // Wiederholen, bis der Spieler einen gültigen Zug tätigt
        checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

        if (!checkSpielzug(spielfeld, positiony, positionx)) {} // Überprüfe, ob der Zug gültig ist
             
    } while (!checkSpielzug(spielfeld, positiony, positionx)); // Solange der Zug ungültig ist, wiederhole die Eingabeaufforderung

        spielfeld[positiony][positionx] = "==";
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
    string temparray[fg][fg];
    string temparray2[fg][fg];
    int positionx;
    int positiony;
    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
            temparray[i][j] = spielfeld[i][j];
            }
        }


    for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
            temparray2[i][j] = to_string(i) + to_string(j);
            }
        }
// Siegzug oder Blockzug 1
    spielfeldrotierenUhr(temparray);
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            if (temparray[i][j] == to_string(i) + to_string(j)) {
                temparray[i][j] = "==";
                temparray2[i][j] = "==";
                if (checkTotalSieg(temparray, pattern1, pattern2)) {
                    spielfeldrotierenGegenUhr(temparray2);

                    for (int f = 0; f < fg; f++) {
                        for (int g = 0; g < fg; g++) {
                                if (temparray2[f][g] == "=="){
                                    spielfeld[f][g] = temparray2[f][g];
                                    positionx = f;
                                    positiony = g;
                                    }
                                }
                            }
                    cout << "Computer w" << ae << "hlt Feld " << positionx << positiony << endl;
                    cout << "und rotiert mit dem Uhrzeigersinn." << endl;

                    return;
                    }
                temparray[i][j] = to_string(i) + to_string(j);
                temparray2[i][j] = to_string(i) + to_string(j);
                }
            }
        }
// Siegzug oder Blockzug 2
    spielfeldrotierenGegenUhr(temparray);
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            if (temparray[i][j] == to_string(i) + to_string(j)) {
                temparray[i][j] = "==";
                temparray2[i][j] = "==";
                if (checkTotalSieg(temparray, pattern1, pattern2)) {
                    spielfeldrotierenUhr(temparray2);

                    for (int f = 0; f < fg; f++) {
                        for (int g = 0; g < fg; g++) {
                                if (temparray2[f][g] == "=="){
                                    spielfeld[f][g] = temparray2[f][g];
                                    positionx = f;
                                    positiony = g;
                                    }
                                }
                            }
                    cout << "Computer w" << ae << "hlt Feld " << positionx << positiony << endl;
                    cout << "und rotiert gegen den Uhrzeigersinn." << endl;

                    return;
                    }
                temparray[i][j] = to_string(i) + to_string(j);
                temparray2[i][j] = to_string(i) + to_string(j);
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
            int rotation;
            rotation = rand() % 2 + 1;
            if (rotation == 1){
                cout << "Computer w" << ae << "hlt Feld " << i << j << endl;
                cout << "und rotiert gegen den Uhrzeigersinn." << endl;
                spielfeldrotierenGegenUhr(spielfeld);
                return;
            }
            else {
                cout << "Computer w" << ae << "hlt Feld " << i << j << endl;
                cout << "und rotiert im Uhrzeigersinn." << endl;
                spielfeldrotierenUhr(spielfeld);
                return;
            }
        }
   }
}


void funny_spielfelderstellen(string spielfeld[fg][fg]){
      for (int i = 0; i < fg; i++){
        for (int j = 0; j < fg; j++){
                if (spielfeld[i][j] == to_string(i)+ to_string(j)){
                    ColorCout(8, spielfeld[i][j]);
                    cout <<' ';
                }
                if (spielfeld[i][j] == "XX"){
                    ColorCout(12,spielfeld[i][j]);
                    cout << ' ';
                }
                if (spielfeld[i][j] == "=="){
                    ColorCout(1,spielfeld[i][j]);
                    cout << ' ';
                }

        }
    } cout << endl;
}

void funny_spielfeldrotierenUhr(string spielfeld[fg][fg]){

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
    funny_spielfelderstellen(spielfeld);
}

void funny_spielzug1(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    int positiony, positionx;

    cout << spieler1 << " (XX) ist am Zug." << endl;
    cout << "Zeile [space] Spalte eingeben." << endl;

    do { // Wiederholen, bis der Spieler einen gültigen Zug tätigt
        checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

    if (!checkSpielzug(spielfeld, positiony, positionx)) {} // Überprüfe, ob der Zug gültig ist
         cout << "Spielzug nicht m" << oe << "glich, bitte erneut versuchen." << endl;
    } while (!checkSpielzug(spielfeld, positiony, positionx)); // Solange der Zug ungültig ist, wiederhole die Eingabeaufforderung

    spielfeld[positiony][positionx] = "XX";// Wenn der Spielzug gültig ist, aktualisiere das Spielfeld

}

void funny_spielzug2(string spielfeld[fg][fg], string &spieler1, string &spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {

        int positiony;
        int positionx;


    cout << spieler2 << " (==) ist am Zug." << endl;

    cout <<"Zeile [space] Spalte eingeben." << endl;

    do { // Wiederholen, bis der Spieler einen gültigen Zug tätigt
        checkEingabeSpielzug(positiony, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        checkEingabeSpielzug(positionx, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

        if (!checkSpielzug(spielfeld, positiony, positionx)) {} // Überprüfe, ob der Zug gültig ist
             cout << "Spielzug nicht m" << oe << "glich, bitte erneut versuchen." << endl;
    } while (!checkSpielzug(spielfeld, positiony, positionx)); // Solange der Zug ungültig ist, wiederhole die Eingabeaufforderung

        spielfeld[positiony][positionx] = "==";
    }

