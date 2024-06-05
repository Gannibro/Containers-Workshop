#include "Reservation.h"
#include <iomanip>
#include <iostream>
#include <algorithm> // for std::find_if
#include <sstream>   // for std::stringstream

namespace seneca {

    // Utility function to trim leading and trailing whitespace
    std::string trim(const std::string& str) {
        auto front = std::find_if_not(str.begin(), str.end(), ::isspace);
        auto back = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
        return (front < back ? std::string(front, back) : std::string());
    }

    Reservation::Reservation() : m_partySize(0), m_day(0), m_hour(0) {}

    Reservation::Reservation(const std::string& res) {
        // Debug: Print the input string
        std::cout << "Parsing reservation: " << res << std::endl;

        try {
            // Split the string using the delimiters
            size_t start = 0;
            size_t end = res.find(':');
            m_reservationID = trim(res.substr(start, end - start));

            start = end + 1;
            end = res.find(',', start);
            m_name = trim(res.substr(start, end - start));

            start = end + 1;
            end = res.find(',', start);
            m_email = trim(res.substr(start, end - start));

            start = end + 1;
            end = res.find(',', start);
            std::string partySizeStr = trim(res.substr(start, end - start));

            start = end + 1;
            end = res.find(',', start);
            std::string dayStr = trim(res.substr(start, end - start));

            std::string hourStr = trim(res.substr(end + 1));

            // Debug: Print each extracted substring
            std::cout << "  Reservation ID: " << m_reservationID << std::endl;
            std::cout << "  Name: " << m_name << std::endl;
            std::cout << "  Email: " << m_email << std::endl;
            std::cout << "  Party Size (str): " << partySizeStr << std::endl;
            std::cout << "  Day (str): " << dayStr << std::endl;
            std::cout << "  Hour (str): " << hourStr << std::endl;

            m_partySize = std::stoul(partySizeStr);
            m_day = std::stoul(dayStr);
            m_hour = std::stoul(hourStr);
        } catch (const std::exception& e) {
            // Debug: Print the error and the input string
            std::cerr << "Error parsing reservation: " << res << "\nException: " << e.what() << std::endl;
            throw;
        }
    }

    void Reservation::update(size_t day, size_t hour) {
        m_day = day;
        m_hour = hour;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::setw(10) << res.m_reservationID << ": "
           << std::setw(20) << res.m_name << "  "
           << std::setw(20) << res.m_email << "    "
           << "Party Size: " << std::setw(2) << res.m_partySize << "    "
           << "Day: " << std::setw(2) << res.m_day << "    "
           << "Hour: " << std::setw(2) << res.m_hour << "\n";
        return os;
    }
}
