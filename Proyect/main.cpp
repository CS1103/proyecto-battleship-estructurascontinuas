#include "common_types.h"

#include "navy_t.h"
#include "controller_t.h"

using namespace std;

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
    //ctr.getBoard().set_path();
    //cout << ctr.getBoard().get_path();
    //cout << filesystem::current_path();
    ctr.execute();
    return 0;
}