#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {  // Changed from sdds to seneca
    class Reservation {
        std::string m_reservationId;
        std::string m_name;
        std::string m_email;
        int m_numOfPeople;
        int m_day;
        int m_hour;

    public:
        Reservation();
        Reservation(const std::string& res);

        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // SDDS_RESERVATION_H