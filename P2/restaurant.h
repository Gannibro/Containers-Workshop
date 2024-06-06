#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace seneca {  // Changed from sdds to seneca
    class Restaurant {
        Reservation** m_reservations{nullptr};
        size_t m_count{0};

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;  // Added move constructor
        Restaurant& operator=(Restaurant&& other) noexcept;  // Added move assignment
        ~Restaurant();

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
    };
}

#endif // SDDS_RESTAURANT_H