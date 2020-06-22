#include "common_types.h"

#include "navy_t.h"
#include "controller_t.h"

using namespace std;


// Para que funcione, corre el codigo, COPIA el .out del directorio dentro de out
//el programa esperara hasta que haya un .out en el la carpeta out, leera lo que esta dentro y dps eliminara el out





int main() {
    //handshakeIn("dinamita team");
    //statement_t st = waitIn();
    //statement_t* pst = &st;
    //cout << st.token << endl;
    //string type = "A";
    //out(placeFleet(pst, type));
    //board_t b = board_t('J', 10);
    //navy_t n1 = navy_t(2,3,'A', 'H', b);
    //navy_t n2 = navy_t(4,6,'S', 'V', b);
    //navy_t n3 = navy_t(1,8,'B', 'H', b);
    //b.print();
    string name = "BattleBot";
    controller_t ctr(name);
    ctr.execute();
    return 0;
}