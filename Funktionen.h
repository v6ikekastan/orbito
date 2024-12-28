#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H


#include <iostream>
#include <string>

using namespace std;

int highscoreAbrufen();                     /** Funktion ruft bisherigen highscore aus der Textdatei
                                            "highscore.txt" ab. (F)**/

int highscoreVergleichen(int untilscore);   /** Funktion vergleicht bisherigen highscore mit dem
                                            gerade erspielten und gibt h�heren zur�ck (F)**/

void highscoreEintragen(int nhighscore);    /** Funktion tr�gt neuen highscore in die Textdatei
                                            "highscore.txt" ein. (F)**/

void ColorCout(int color, string text);     /** gibt Text in bestimmter Farbe wieder**/

void clearConsole();                        /** l�scht text auf der Konsole **/

#endif //FUNKTIONEN_H
