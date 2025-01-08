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

    char ae, ue, oe, OE;
    ae = 132;
    ue = 129;
    oe = 148;
    OE = 153;

    srand(time(0));
    cout << highscoreAbrufen() << endl;
    highscoreEintragen(highscoreAbrufen() + 1);

    char neuesLetztesSpiel;
    bool korrekteEingabeSpielstart = false; // überprüft, ob eine valide Eingabe zum Spielstart getätigt wurde

    while (!korrekteEingabeSpielstart) { // wiederholt solange, bis eine valide Eingabe getätigt wurde
        cout << "Wollen Sie ein neues Spiel starten (n/N) oder den letzten Spielstand (l/L) laden? ";
        cin >> neuesLetztesSpiel;
        cout << endl;
        // eingabe zu lowercase

        if (neuesLetztesSpiel == 'l' || neuesLetztesSpiel =='L') {
            SpielstandLaden(spieler1, spieler2, spielfeldarray, checksiegStatus, winstreak, Spieler1istDran);
            korrekteEingabeSpielstart = true;
        } else if (neuesLetztesSpiel == 'n' || neuesLetztesSpiel =='N') {
            NeuesSpiel(spieler1, spieler2);
            korrekteEingabeSpielstart = true;
        } else if (neuesLetztesSpiel == 'f') { 
            // platzhalter funny modus
        } else {
            cout << "\nUng" << ue << "ltige Eingabe.\nBitte treffen Sie eine Auswahl.\n\n"; // Fehlermeldung bei invalider Eingabe
        }
    }

    cout << "___________________________________________________________________________\n\n";
    cout << "Sie k" << oe << "nnen Ihren Spielstand jederzeit speichern, indem Sie \"save\" eingeben.\n\n";
    cout << "___________________________________________________________________________\n\n";

    bool Spieler1istDran = false; // notwendig zum den Spielstand zu speichern, logisch eigentlich inkorrekt da spieler1 ja zuerst zieht aber egal

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
