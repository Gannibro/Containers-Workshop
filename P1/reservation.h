#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

namespace seneca {
    class Reservation {
    private:
        char m_reservationId[11];  // Ensure space for the null terminator
        std::string m_name;
        std::string m_email;
        int m_partySize;
        int m_day;
        int m_hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // RESERVATION_H
