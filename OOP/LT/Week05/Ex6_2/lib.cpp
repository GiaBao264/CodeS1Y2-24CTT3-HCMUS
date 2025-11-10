#include "lib.h"

Screen::Screen(int number, int seats, double price)
    : screenNumber(number), totalSeats(seats), standardPrice(price), seatsBooked(0) {
    seatStatus.resize(seats, false);
}

bool Screen::isSeatAvailable(int seatNumber) const {
    if (seatNumber < 0 || seatNumber >= totalSeats) {
        return false;
    }
    return !seatStatus[seatNumber];
}

bool Screen::bookSeat(int seatNumber) const {
    if (isSeatAvailable(seatNumber)) {
        seatStatus[seatNumber] = true;
        seatsBooked++;
        return true;
    }
    return false;
}

double Screen::calculateTotalRevenue() const {
    return seatsBooked * standardPrice;
}

Screen::~Screen() {
    // Destructor implementation
}
