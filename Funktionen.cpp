#include "Funktionen.h"
#include "Spielfeldfunktionen.h"

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

void clearFile() {

    ofstream speichern(dateiname, ios::trunc); // in truncate mode öffnen (heißt: alle inhalte werden gelöscht), kommt aus dem input/output stream deshalb ios

    if (!speichern) { // datei konnte nicht geöffnet werden
        cerr << "Fehler beim Öffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    } else {
        cout << "Die Datei \"" << dateiname << "\" wurde geleert.\n\n\n";
    }
    speichern.close();
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
    cin >> spieler1;
    cout << "Name von Spieler 2 eingeben: ";
    cin >> spieler2;
    if (spieler2 == "Computer" || spieler2 == "computer"){
        cout << "test" << endl;
    }

    //Spielfeld:
    cout << "Startspielfeld:" << endl;
    spielfelderstellen(spielfeldarray);
}

void SpielstandSpeichern(string& spieler1, string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) { // & referenz nur bei spielernamen, da a) strings relativ groß sind (vgl. int) und b) da arrays automatisch wie eine referenz behandelt werden

    char OE = 153;
    char ue = 129;
    char ae = 132;

    ofstream speichern;

    speichern.open(dateiname);
    
    if (!speichern) { // spielstand.txt konnte nicht geöffnet werden
        cerr << "Fehler beim " << OE << "ffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    }

    // spielernamen speichern, hier noch mit manueller eingabe der namen
    speichern << "Spieler 1: " << spieler1 << endl;
    speichern << "Spieler 2: " << spieler2 << endl;
    cout << "\n\nSpielernamen wurden gespeichert!\n";

    // spielfeldarray speichern
    speichern << "Spielfeld:\n";
    for (int i = 0; i < 4; i++) { // äußere schleife für reihen
        for (int j = 0; j < 4; j++) { // innere schleife für zeilen
            speichern << spielfeldarray[fg][fg];
            if (j < 3) speichern << " "; // fügt ein leerzeichen nach jedem index ein (außer die ganz rechts)
        }
        speichern << endl; // fügt einen zeilenumbruch nach jeder zeile ein
    }
    cout << "Spielfeld wurde gespeichert!\n";

    // bool checksiegStatus speichern
    checksiegStatus = checksieg(spielfeldarray);
    speichern << "Wurde das Spiel schon gewonnen?" << (checksiegStatus ? true : false) << endl; // sieg wird als ja oder nein gespeichert

    cout << "\(Eventueller\) Sieg wurde gespeichert!\n";

    // int winstreak speichern
    winstreak = 0;
    if (checksiegStatus == true) {
        winstreak++;
    }
    speichern << "Winstreak: " << winstreak << endl;

    cout << "Winstreak wurde gespeichert!\n";


    // bool Spieler1istDran speichernn
    speichern << "Ist Spieler 1 dran?: " << (Spieler1istDran ? true : false) << endl; // Spieler1istDran wird als ja oder nein gespeichert

    cout << "Nächster Spieler wurde gespeichernt!\n";

    speichern.close();
}

void SpielstandLaden(const string& dateiname, string& spieler1, string& spieler2, string spielfeldarray[fg][fg], bool& checksiegStatus, int& winstreak, bool& Spieler1istDran) {

    string dummy, temp;
    char OE = 153;
    char ue = 129;

    ifstream laden;

    laden.open(dateiname);
    
    if (!laden) { // spielstand.txt konnte nicht geöffnet werden
        cerr << "Fehler beim " << OE << "ffnen der Datei \"" << dateiname << "\".\n\n"; // sends data to the standart error stream, heißt der text wird nicht verarbeitet wie ein standart output, sondern direkt auf die konsole geschrieben
    }
// laden funktion in überarbeitung
    /* 
    getline(laden, dummy); // "Spieler 1: " überspringen
    getline(laden, spieler1);

    getline(laden, dummy); // "Spieler 2: " überspringen
    getline(laden, spieler2);

    getline(laden, dummy); // "Spielfeld:\n" überspringen
    for (int i = 0; i < 4; i++) { // äußere schleife für reihen
        for (int j = 0; j < 4; j++) { // innere schleife für zeilen
            laden >> spielfeldarray[fg][fg];
        }
    }

    getline(laden, dummy); // "Wurde das Spiel schon gewonnen?: " überspringen
    laden >> temp; // "ja" und "nein" zurück zu bool konvertieren
     if (temp == "ja") {
        checksiegStatus = true;
    } else if (temp == "nein") {
        checksiegStatus = false;
    } else {
        cerr << "Fehler: Ung" << ue << "ltiger Wert für 'Wurde das Spiel schon gewonnen?'.\n";
    }
    laden.ignore(); // zeilenumbruch überspringen

    getline(laden, dummy); // "Winstreeak: " überspringen
    laden >> winstreak;

    getline(laden, dummy); // "Ist Spieler 1 dran? " überspringen
    laden >> temp; // "ja" und "nein" zurück zu bool konvertieren
     if (temp == "ja") {
        Spieler1istDran = true;
    } else if (temp == "nein") {
        Spieler1istDran = false;
    } else {
        cerr << "Fehler: Ung" << ue << "ltiger Wert für 'Ist Spieler 1 dran?'.\n";
    }
    laden.ignore(); // zeilenumbruch überspringen

    // Zur Kontrolle alle Werte ausgeben
    cout << "Spieler 1: " << spieler1 << endl;
    cout << "Spieler 2: " << spieler2 << "\n\n";
    cout << "Spielfeld:\n";
    for (int i = 0; i < fg; ++i) {
        for (int j = 0; j < fg; ++j) {
            cout << spielfeldarray[fg][fg] << " ";
        }
        cout << endl;
    }
    cout << "Wurde das Spiel schon gewonnen?" << (checksieg ? "ja" : "nein") << endl;
    cout << "Winstreak: " << winstreak << endl;
    cout << "Ist Spieler 1 dran?: " << (Spieler1istDran ? "ja" : "nein") << endl;
    */ 
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
            break; // gültige Eingabe, Schleife verlassen
        }
    }
}

void checkEingabeSpielzug(string &position, string& spieler1, string& spieler2, const string spielfeldarray[fg][fg], bool checksiegStatus, int winstreak, bool Spieler1istDran) {
    
    char ue = 129;
    
    while (true){
        cin >> position; // für string position und stoi ist aven verantwortlich
        if (position == "save" || position == "Save" || position == "SAVE") { // eingabe zu lowercase machen
        SpielstandSpeichern(spieler1, spieler2, spielfeldarray[fg][fg], checksieg, winstreak, Spieler1istDran);
        } else if (cin.fail() || stoi(position) < 0 || stoi(position) > 3) { // prüft ob Benutzer einen Wert eingegeben hat, der nicht zum Datentyp von variable passt // stoi - konvertiert string zu integer, hier mit der basis 10 (und fehler wenn kein int input) (aven)
            cout << "Ung" << ue << "ltige Eingabe, bitte erneut versuchen." << endl;
            cin.clear();   // löscht Fehlerinformation
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoriert ungütige Eingabe
        } else {
            break; // gültige Eingabe, Schleife verlassen
        }
    }
}

bool checkSpielzug(const string& spielfeld[fg][fg], int positiony, int positionx){
    
    char oe = 148;
    
    if ( spielfeld[positiony][positionx] == "XX" || spielfeld[positiony][positionx] == "--" ){
        cout << "Spielzug nicht m" << oe << "glich, bitte erneut versuchen." << endl;
       return false;
    } else {
        return true;
    }
}

void FunnyModus() {

    cout << "Name von Spieler 1 eingeben: ";
    cin >> spieler1;
    cout << "Name von Spieler 2 eingeben: ";
    cin >> spieler2;
    if (spieler2 == "Computer" || spieler2 == "computer"){
        cout << "test" << endl;
    }

    //Spielfeld:
    cout << "Startspielfeld:" << endl;
    spielfelderstellen(spielfeldarray);

    cout << "_____________________________________________________________________________\n\n";
    cout << "In diesem Modus ist speichern nicht m" << oe << "glich. Vielen Dank f" << ue << "r Ihr Verst" << ae << "ndnis.\n\n";
    cout << "_____________________________________________________________________________\n\n";
    
    // Spielablauf
    
    // Interruptions beliebig 
}
