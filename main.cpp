#include "Funktionen.h"
#include "Spielfeldfunktionen.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

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
        cout << "Wollen Sie ein neues Spiel starten (N) oder den letzten Spielstand (L) laden? "; // anpassen für funny modus
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
            // platzhalter funny modus.
        } else {
            cout << "\nUng" << ue << "ltige Eingabe.\nBitte treffen Sie eine Auswahl.\n\n"; // Fehlermeldung bei invalider Eingabe
        }
    }

    cout << "_________________________________________________________________________________________________\n\n";
    cout << "Sie k" << oe << "nnen jederzeit Ihren Spielstand speichern und das Spiel beenden, indem Sie \"save\" eingeben.\n\n";
    cout << "_________________________________________________________________________________________________\n\n";

    bool Spieler1istDran = false; // notwendig zum den Spielstand zu speichern, logisch eigentlich inkorrekt da spieler1 ja zuerst zieht aber egal

    cout << "HIER WIRD GESPEICHERT!!\n";
    SpielstandSpeichern(spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);

    for (int i = 0; i < 8; i++){

        spielzug1(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        spielfelderstellen(spielfeldarray);
        spielfeldrotierenUhr(spielfeldarray);
        spielzug2(spielfeldarray, spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
        spielfelderstellen(spielfeldarray);
        spielfeldrotierenUhr(spielfeldarray);

        Spieler1istDran = true; // nachdem spieler2 seinen zug getätigt hat, ist spieler1 dran

        if (checksieg(spielfeldarray) == true) {
            break;
        }
    }

    return 0;
}
