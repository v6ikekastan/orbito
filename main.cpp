#include "Funktionen.h"
#include "Spielfeldfunktionen.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <limits> //Zeile 51 - mac Variante

using namespace std;

/** Spiel Orbito **/

string spielfeldarray[fg][fg]{
    {"00", "01", "02", "03"},
    {"10", "11", "12", "13"},
    {"20", "21", "22", "23"},
    {"30", "31", "32", "33"}
};
string spieler1, spieler2;
bool checksiegStatus, Spieler1istDran;
int winstreak;

int main(){

    srand(time(0));
    cout << highscoreAbrufen() << endl;
    highscoreEintragen(highscoreAbrufen() + 1);

    char neuesLetztesSpiel;
    bool korrekteEingabeSpielstart = false; // überprüft, ob eine valide Eingabe zum Spielstart getätigt wurde

    while (!korrekteEingabeSpielstart) { // wiederholt solange, bis eine valide Eingabe getätigt wurde
        cout << "Wollen Sie ein neues Spiel starten (N), den letzten Spielstand (L) laden oder im Funny-Modus (F) spielen? " << endl;
        cout << endl;
        cout << "Der Funny-Modus kann mit (F) gestartet werden. (Computergegner hier nicht moeglich)" << endl;
        cin >> neuesLetztesSpiel;
        cout << endl;
        neuesLetztesSpiel = tolower(neuesLetztesSpiel);

        if (neuesLetztesSpiel == 'l') {
            SpielstandLaden(spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
            korrekteEingabeSpielstart = true;
        } else if (neuesLetztesSpiel == 'n') {
            NeuesSpiel(spieler1, spieler2);
            korrekteEingabeSpielstart = true;
        } else if (neuesLetztesSpiel == 'f') {
            FunnyModus(spieler1, spieler2, spielfeldarray);
        } else {
            cout << "Ung" << ue << "ltige Eingabe, bitte erneut versuchen.\n"; // Fehlermeldung bei invalider Eingabe
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "_________________________________________________________________________________________________\n\n";
    cout << "Sie k" << oe << "nnen jederzeit Ihren Spielstand speichern und das Spiel beenden, indem Sie \"save\" eingeben.\n\n";
    cout << "_________________________________________________________________________________________________\n\n";

    bool Spieler1istDran = false; // notwendig zum den Spielstand zu speichern, logisch eigentlich inkorrekt da spieler1 ja zuerst zieht aber egal
    string richtung;

    for (int i = 0; i < 8; i++){

        spielzug1(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        spielfelderstellen(spielfeldarray);

        cout << "Rotationsrichtung waehlen. (rechts/uhr oder links/gegenUhr)" << endl;
        cin >> richtung ;
        if (richtung == "r" || richtung == "R" || richtung == "U" || richtung == "u" || richtung == "rechts" || richtung == "Rechts" || richtung == "Uhr" || richtung == "uhr" ){
            spielfeldrotierenUhr(spielfeldarray);
        }
        else{
            spielfeldrotierenGegenUhr(spielfeldarray);
        }
        cin.clear();
        spielzug2(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        spielfelderstellen(spielfeldarray);

        cout << "Rotationsrichtung waehlen. (rechts/uhr oder links/gegenUhr)" << endl;
        cin >> richtung;
        if (richtung == "r" || richtung == "R" || richtung == "U" || richtung == "u" || richtung == "rechts" || richtung == "Rechts" || richtung == "Uhr" || richtung == "uhr" ){
            spielfeldrotierenUhr(spielfeldarray);
        }
        else{
            spielfeldrotierenGegenUhr(spielfeldarray);
        }
        cin.clear();
        Spieler1istDran = true; // nachdem spieler2 seinen zug getätigt hat, ist spieler1 dran

        if (checkTotalSieg(spielfeldarray, pattern1, pattern2) == true) {
            break;
        }
    }

    return 0;
}
