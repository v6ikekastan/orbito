#include "Funktionen.h"
#include "Spielfeldfunktionen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>
#include <limits>
#include <cctype>
#include <ctime>
#include <cstring>

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

int checkSiegRow(string spielfeldarray[fg][fg], string pattern) {
    for (int row = 0; row <=3; ++row) {
        if ((spielfeldarray[row][0]).compare(pattern) == 0) {
            for (int match = 0; (spielfeldarray[row][match].compare(pattern) == 0); ++match) {
                if (match == 3) {
                    cout << "test win"; // set bool oder so
                    return 1; // ausmachen oder so
                }
            }
        }
    }
}

int checkSiegCol(string spielfeldarray[fg][fg], string pattern) {
    for (int col = 0; col <=3; ++col) {
        if ((spielfeldarray[0][col]).compare(pattern) == 0) {
            for (int match = 0; (spielfeldarray[match][col].compare(pattern) == 0); ++match) {
                if (match == 3) {
                    cout << "test win 2"; // set bool oder so
                    return 1;    // ausmachen oder so
                }
            }
        }
    }
}

int checkSiegDiagonal1(string spielfeldarray[fg][fg], string pattern) {
    for (int i = 0; i <=3; ++i) {
        if ((spielfeldarray[i][i]).compare(pattern) == 0) {
            for (int match = 0; (spielfeldarray[i][match].compare(pattern) == 0); ++match) {
                if (match == 3) {
                    cout << "test win 3"; // set bool oder so
                    return 1; // ausmachen oder so
                }
            }
        }
    }
}

int checkSiegDiagonal2(string spielfeldarray[fg][fg], string pattern) {
    for (int j = 0; j <=3; ++j) {
        if ((spielfeldarray[0][j]).compare(pattern) == 0) {
            for (int match = 0; (spielfeldarray[match][j].compare(pattern) == 0); ++match) {
                if (match == 3) {
                    cout << "test win 4"; // set bool oder so
                    return 1;    // ausmachen oder so
                }
            }
        }
    }
}

bool checkTotalSieg(string arr[fg][fg], string pattern1, string pattern2) {
    if (checkSiegCol(arr, pattern1) || checkSiegRow(arr, pattern1) || checkSiegDiagonal1(arr, pattern1) || checkSiegDiagonal2(arr, pattern1) || checkSiegCol(arr, pattern2) || checkSiegRow(arr, pattern2) || checkSiegDiagonal1(arr, pattern2) || checkSiegDiagonal2(arr, pattern2)) {
        return true;
    }
}


void clearFile() {

    ofstream speichern(dateiname, ios::trunc); // in truncate mode öffnen (heißt: alle inhalte werden gelöscht), kommt aus dem input/output stream deshalb ios

    if (!speichern) { // datei konnte nicht geöffnet werden
        cerr << "Fehler beim " << OE << "ffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    } else {
        cout << "Die Datei \"" << dateiname << "\" wurde geleert.\n\n\n";
    }
    speichern.close();
}

void checkEingabe(string &spielername) {
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
            cout << "Ung" << ue << "ltige Eingabe, bitte erneut versuchen." << endl;
            cin.clear();   // löscht Fehlerinformation
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ungültige Eingabe
        } else {
            break; // gültige Eingabe, Schleife verlassen
        }
    }
}

void NeuesSpiel(string &spieler1, string &spieler2) { // Spielernamen als Referenz, sodass Änderungen aus der Funktion auch ins main übernommen werden

    string spielfeldarray[fg][fg]{
    {"00", "01", "02", "03"},
    {"10", "11", "12", "13"},
    {"20", "21", "22", "23"},
    {"30", "31", "32", "33"}
    };

    clearFile();

    cout << "Name von Spieler 1 eingeben: ";
    checkEingabe(spieler1);
    cout << "Name von Spieler 2 eingeben: ";
    checkEingabe(spieler2);
    if (spieler2 == "Computer" || spieler2 == "computer"){
        cout << "test" << endl;
    }

    //Spielfeld:
    cout << "Startspielfeld:" << endl;
    spielfelderstellen(spielfeldarray);
}

void SpielstandSpeichern(const string &spieler1, const string &spieler2, string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) { // & referenz nur bei spielernamen, da a) strings relativ groß sind (vgl. int) und b) da arrays automatisch wie eine referenz behandelt werden

    ofstream speichern;

    speichern.open(dateiname);

    if (!speichern) { // spielstand.txt konnte nicht geöffnet werden
        cerr << "Fehler beim " << OE << "ffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    }

    // spielernamen speichern, hier noch mit manueller eingabe der namen
    speichern << "Spieler 1:\n" << spieler1 << endl;
    speichern << "Spieler 2:\n" << spieler2 << endl;
    cout << "\n\n Spielernamen wurden gespeichert!\n";

    // spielfeldarray speichern
    speichern << "Spielfeld:\n";
    for (int i = 0; i < 4; i++) { // äußere schleife für reihen
        for (int j = 0; j < 4; j++) { // innere schleife für zeilen
            speichern << spielfeldarray[i][j];
            if (j < 3) speichern << " "; // fügt ein leerzeichen nach jedem index ein (außer die ganz rechts)
        }
        speichern << endl; // fügt einen zeilenumbruch nach jeder zeile ein
    }
    Sleep(150);
    cout << " Spielfeld wurde gespeichert!\n";

    // bool checksiegStatus speichern
    checksiegStatus = checksieg(spielfeldarray);
    speichern << "Wurde das Spiel schon gewonnen?\n" << (checksiegStatus ? true : false) << endl; // sieg wird als ja oder nein gespeichert

    Sleep(150);
    cout << "\(Eventueller\) Sieg wurde gespeichert!\n";

    // int winstreak speichern
    winstreak = 0;
    if (checksiegStatus == true) {
        winstreak++;
    }
    speichern << "Winstreak:\n" << winstreak << endl;
    Sleep(150);
    cout << " Winstreak wurde gespeichert!\n";

    // bool Spieler1istDran speichernn
    speichern << "Ist Spieler 1 dran?:\n" << (Spieler1istDran ? true : false) << endl; // Spieler1istDran wird als ja oder nein gespeichert
    Sleep(150);
    cout << " N" << ae << "chster Spieler wurde gespeichernt!\n\n";

    speichern.close();
    Sleep(500);
    cout << "_________________________________________________________________________________________________\n\n";
    cout << "Vielen Dank f" << ue <<"r\'s Spielen! Bis zum n" << ae << "chsten Mal!!\n\n";
    cout << "_________________________________________________________________________________________________\n\n";

    exit(0);
}

void SpielstandLaden(string &spieler1, string &spieler2, string spielfeldarray[fg][fg], bool& checksiegStatus, int& winstreak, bool& Spieler1istDran) {

    string dummy, temp;

    ifstream laden;

    laden.open(dateiname);

    if (!laden) { // spielstand.txt konnte nicht geöffnet werden
        cerr << "Fehler beim " << OE << "ffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    }

    getline(laden, dummy); // "Spieler 1:\n" überspringen
    getline(laden, spieler1);

    getline(laden, dummy); // "Spieler 2:\n" überspringen
    getline(laden, spieler2);

    getline(laden, dummy); // "Spielfeld:\n" überspringen
    for (int i = 0; i < 4; i++) { // äußere schleife für reihen
        for (int j = 0; j < 4; j++) { // innere schleife für zeilen
            laden >> spielfeldarray[i][j];
        }
    }

    getline(laden, dummy); // "Wurde das Spiel schon gewonnen?: " überspringen
    laden >> checksiegStatus;
    laden.ignore(); // zeilenumbruch überspringen

    getline(laden, dummy); // "Winstreeak: " überspringen
    laden >> winstreak;

    getline(laden, dummy); // "Ist Spieler 1 dran? " überspringen
    laden >> Spieler1istDran;
    laden.ignore(); // zeilenumbruch überspringen

    // Zur Kontrolle alle Werte ausgeben
    cout << "Zuletzt gespeichert:\n";
    cout << "_________________________________________________________________________________________________\n\n";

    cout << "Spieler 1: " << spieler1 << endl;
    cout << "Spieler 2: " << spieler2 << "\n\n";

    cout << "Spielfeld:\n";
    for (int i = 0; i < fg; ++i) {
        for (int j = 0; j < fg; ++j) {
            cout << spielfeldarray[i][j] << " ";
        }
        cout << endl;
    } cout << endl;

    cout << "Wurde das Spiel schon gewonnen? " << (checksieg ? "ja" : "nein") << "\n\n";
    cout << "Winstreak: " << winstreak << "\n\n";
    cout << "Ist Spieler 1 dran? " << (Spieler1istDran ? "ja" : "nein") << endl;
}

void checkSave(string position, string &spieler1, string &spieler2, string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {

    int strLaenge = position.length(); // transformiert string zu lowercase
    for (int i = 0; i < strLaenge; i++) {
        position[i] = tolower(position[i]); // geht jeden char des strings bis zum ende durch
    }

    if (position == "save") {
        SpielstandSpeichern(spieler1, spieler2, spielfeldarray, checksieg, winstreak, Spieler1istDran);
        exit(0);
    } else;
}

void checkEingabeSpielzug(int &position, string& spieler1, string& spieler2, string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {

    while (true) {
        if (!(cin >> position)) { // Input was successfully read as an int
            cin.clear(); // Clear the error flag
            string checkInput;
            cin >> checkInput; // Read the failed input as a string

            // überprüft ob die eingabe "save" ist
            checkSave(checkInput, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

            // wenn input nicht "save" ist, dann ungültig
            cout << "Ung" << ue << "ltige Eingabe, bitte erneut versuchen.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the remaining invalid input
        } else {
            if(cin.fail() || position < 0 || position > 3){ // prüft ob Benutzer einen Wert eingegeben hat, der nicht zum Datentyp von variable passt
                cout << "Ung" << ue << "ltige Eingabe, bitte erneut versuchen." << endl;
                cin.clear();   // löscht Fehlerinformation
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ungütige Eingabe
            } else {
                break; // gültige Eingabe, Schleife verlassen
            }
        }
    }
}

bool checkSpielzug(string spielfeld[fg][fg], int positiony, int positionx){

    if (spielfeld[positiony][positionx] == "XX" || spielfeld[positiony][positionx] == "==" ){
    cout << "Spielzug nicht m" << oe << "glich, bitte erneut versuchen." << endl;
       return false; //ungültiger Spielzug
    } else {
    return true; //gültiger Spielzug
    }
}

void extraStein(string spielfeld[4][4], int &zugCounter){

    string temparray [fg][fg]; //FLO Zeile 279-284
    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            temparray[i][j] = spielfeld[i][j];
        }
    }

    zugCounter++; // Erhöhe den Zähler für die Anzahl der Züge
    if(zugCounter == 1){
        bool placed = false;  // Flag, um zu überprüfen, ob der Stein platziert wurde

        while (!placed) {
            int randY = rand() % fg;  // Zufällige Zeile
            int randX = rand() % fg;  // Zufällige Spalte

            if (temparray[randY][randX] != "XX" && temparray[randY][randX] != "OO" && temparray[randY][randX] != "==") { // Überprüfen, ob das Feld leer ist
                temparray[randY][randX] = "OO"; // setzt den Stein "OO"
                cout << "Zus" << ae << "tzlicher Stein (OO) wurde an zuf" << ae << "lliger Stelle (" << randY << ", " << randX << ") gesetzt!" << endl;
                placed = true;  // Stein wurde erfolgreich platziert
            }
        }
        zugCounter = 0; // Setze den Zähler zurück, um nach dem nächsten vierten Zug erneut einen Stein hinzuzufügen
    }

    for (int i = 0; i < fg; i++) {
        for (int j = 0; j < fg; j++) {
            spielfeld[i][j] = temparray[i][j];
        }
    }

}


void FunnyModus(string &spieler1, string &spieler2, string spielfeldarray[fg][fg]) {
    string richtung;
    string spieler11;
    string spieler22;

    cout << "Name von Spieler 1 eingeben: ";
    checkEingabe(spieler1);
    spieler11 = namensmisch(spieler1);
    cout << "Name von Spieler 2 eingeben: ";
    checkEingabe(spieler2);
    spieler22 = namensmisch(spieler2);

    cout << "Startspielfeld:" << endl;
    spielfelderstellen(spielfeldarray);

    cout << "_____________________________________________________________________________\n\n";
    cout << "In diesem Modus ist speichern nicht m" << oe << "glich. Vielen Dank f" << ue << "r Ihr Verst" << ae << "ndnis.\n\n";
    cout << "_____________________________________________________________________________\n\n";

    bool checksiegStatus, Spieler1istDran;
    int winstreak;
    int zugCounter = 0;
    string spielfeld[fg][fg]; //für Zeile 309

    for (int i = 0; i < 8; i++){
        funny_spielzug1(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        funny_spielfelderstellen(spielfeldarray);


        funny_spielfeldrotierenUhr(spielfeldarray);

        funny_spielzug2(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        funny_spielfelderstellen(spielfeldarray);

        funny_spielfeldrotierenUhr(spielfeldarray);

        Spieler1istDran = true; // nachdem spieler2 seinen zug getätigt hat, ist spieler1 dran

        extraStein(spielfeldarray, i);

        if (checksieg(spielfeldarray) == true) {
            break;
        }



    }
}

string namensmisch(string name) {
    size_t len = name.length();
    size_t index1, index2;
    char temp;

    for (int i = 0; i < len * 2; ++i){
            index1 = rand() % len;
            index2 = rand() % len;
            temp = name[index1];
            name[index1] = name[index2];
            name[index2] = temp;
                    }
            return name;
}
