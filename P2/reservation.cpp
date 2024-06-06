#include <iomanip>
#include <algorithm>
#include "Reservation.h"

namespace seneca {
    Reservation::Reservation() {}

    Reservation::Reservation(const std::string& res) {
        size_t start = 0, end = 0;

        // Extract reservation ID
        end = res.find(':');
        m_reservationId = res.substr(start, end);
        m_reservationId.erase(0, m_reservationId.find_first_not_of(" "));
        m_reservationId.erase(m_reservationId.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extract name
        end = res.find(',', start);
        m_name = res.substr(start, end - start);
        m_name.erase(0, m_name.find_first_not_of(" "));
        m_name.erase(m_name.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extract email
        end = res.find(',', start);
        m_email = res.substr(start, end - start);
        m_email.erase(0, m_email.find_first_not_of(" "));
        m_email.erase(m_email.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extract number of people
        end = res.find(',', start);
        m_numOfPeople = std::stoi(res.substr(start, end - start));
        start = end + 1;

        // Extract day
        end = res.find(',', start);
        m_day = std::stoi(res.substr(start, end - start));
        start = end + 1;

        // Extract hour
        m_hour = std::stoi(res.substr(start));
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::setw(10) << std::right << res.m_reservationId << ": "
           << std::setw(20) << std::right << res.m_name << "  "
           << std::left << std::setw(20) << "<" + res.m_email + ">"
           << "    ";

        if (res.m_hour >= 6 && res.m_hour <= 9) {
            os << "Breakfast";
        } else if (res.m_hour >= 11 && res.m_hour <= 15) {
            os << "Lunch";
        } else if (res.m_hour >= 17 && res.m_hour <= 21) {
            os << "Dinner";
        } else {
            os << "Drinks";
        }

        os << " on day " << res.m_day << " @ " << res.m_hour << ":00"
           << " for " << res.m_numOfPeople << " people." << std::endl;

        return os;
    }
}