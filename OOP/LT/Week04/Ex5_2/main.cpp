#include "lib.h"

int main() {
    Client client1("Alice", 101);
    SavingAccount savingAcc(client1, "SA12345", 1000.0, 5.0);
    savingAcc.display();
    savingAcc.applyInterest();
    savingAcc.display();

    system("pause");
    return 0;
}