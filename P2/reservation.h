#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

namespace seneca {
    class Reservation {
    private:
        std::string m_reservationID;
        std::string m_name;
        std::string m_email;
        size_t m_partySize;
        size_t m_day;
        size_t m_hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void update(size_t day, size_t hour);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // RESERVATION_H
