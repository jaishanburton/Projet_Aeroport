#include "headers.h"

/** Liste personnes avec qui nous avons fais des TP
Arouna Drame
Ilias Maafa
Marc-Antoine Grabey
Ivan Hyvaek
**/

using namespace std;

int main()
{

    srand(time(NULL));
    BITMAP* doublebuffer=NULL;

    Map MAP;
    MAP.initialisationAllegro();
    MAP.affichage(doublebuffer);

    return 0;
}END_OF_MAIN();
