#include "lib.h"

int main(){
    Address addr1("123 Le Loi", "Ho Chi Minh City", "Vietnam");
    Student student1("Nguyen Van A", "S12345", 3.8, addr1);
    cout << "Student Information:" << endl;
    student1.display();
    cout << "Grade: " << student1.getGrade() << endl << endl;
    Address addr2("456 Nguyen Trai", "Hanoi", "Vietnam");
    ExchangeStudent exchStudent("Tran Thi B", "E54321", 3.2, addr2, "USA", 6);
    cout << "Exchange Student Information:" << endl;
    exchStudent.display();
    exchStudent.updateDuration(12);
    cout << endl;
    cout << "Updated Exchange Student Information:" << endl;
    exchStudent.display();

    system("pause");
    return 0;
}