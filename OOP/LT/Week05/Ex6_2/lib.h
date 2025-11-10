#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen {
protected:
    int screenNumber;
    double standardPrice;
    std::vector<bool> seatStatus;
    int totalSeats;
    int seatsBooked;
public:
    Screen(int number, int seats, double price);
    bool isSeatAvailable(int seatNumber) const;
    bool bookSeat(int seatNumber) const;
    double calculateTicketPrice() const;
    void displayDetails() const;
    void printInfo() const;
    int getTotalSeats() const;
    double calculateTotalRevenue() const;
    ~Screen();
};

class VIPScreen : public Screen {
private:
    double vipSurcharge;
    vector<string> extraServices;
public:
    VIPScreen(int number, int seats, double price, double rate, const vector<string>& services);
    void displayDetails() const;
    double calculatePrice() const;
    void printInfo() const;
};

class Cinema {
private:
    string name;
    string location;
    vector<Screen*> screens;
public:
    Cinema(const string& cinemaName, const string& cinemaLocation);
    void addScreen(int seats, double price);
    void addVIPScreen(int seats, double price, double rate, const vector<string>& services);
    Screen* getScreen(int screenNumber) const;
    void printCinemaDetails() const;
    ~Cinema();
};