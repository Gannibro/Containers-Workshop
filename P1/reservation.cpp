#include "Reservation.h"
#include <sstream>
#include <cstring>
#include <algorithm>

namespace seneca {

    // Default constructor
    Reservation::Reservation() : m_reservationId{""}, m_name{""}, m_email{""}, m_partySize{0}, m_day{0}, m_hour{0} {}

    // Constructor that parses the reservation string
    Reservation::Reservation(const std::string& res) {
        std::istringstream ss(res);
        std::string token;

        // Extract and trim reservation ID
        std::getline(ss, token, ':');
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        strncpy(m_reservationId, token.c_str(), sizeof(m_reservationId) - 1);
        m_reservationId[sizeof(m_reservationId) - 1] = '\0';

        // Extract and trim name
        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        m_name = token;

        // Extract and trim email
        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        m_email = token;

        // Extract party size
        std::getline(ss, token, ',');
        m_partySize = std::stoi(token);

        // Extract day
        std::getline(ss, token, ',');
        m_day = std::stoi(token);

        // Extract hour
        std::getline(ss, token);
        m_hour = std::stoi(token);
    }

    // Update the reservation with a new day and time
    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    // Overload the insertion operator
    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::setw(10) << std::right << res.m_reservationId << ":  "
           << std::setw(20) << std::right << res.m_name << "  "
           << std::setw(20) << std::left << "<" + res.m_email + ">";
        std::string mealType;
        if (res.m_hour >= 6 && res.m_hour <= 9)
            mealType = "Breakfast";
        else if (res.m_hour >= 11 && res.m_hour <= 15)
            mealType = "Lunch";
        else if (res.m_hour >= 17 && res.m_hour <= 21)
            mealType = "Dinner";
        else
            mealType = "Drinks";
            os << std::setfill(' ') << std::right << std::setw(11) << ""
           << mealType << " on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partySize
           << (res.m_partySize == 1 ? " person." : " people.") << std::endl;

        return os;
    }
}
