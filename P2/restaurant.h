#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace seneca {
    class Restaurant {
    private:
        Reservation** m_reservations;
        size_t m_cnt;

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        ~Restaurant();
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        Restaurant& operator=(Restaurant&& other) noexcept;

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
    };
}

#endif // RESTAURANT_H
