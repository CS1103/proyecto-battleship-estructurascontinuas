#include "common_types.h"
#include "navy_t.h"
#include "controller_t.h"

using namespace std;

int main() {
    string name = "BattleBot";
    controller_t ctr(name);
    ctr.execute();
    return 0;
}