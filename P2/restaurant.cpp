#include "Restaurant.h"

namespace seneca {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
        m_reservations = new Reservation*[cnt];
        for (size_t i = 0; i < cnt; ++i) {
            if (reservations[i] != nullptr) {
                m_reservations[i] = new Reservation(*reservations[i]);
            } else {
                m_reservations[i] = nullptr;
            }
        }
        m_count = cnt;
    }

    Restaurant::Restaurant(const Restaurant& other) {
        m_reservations = new Reservation*[other.m_count];
        for (size_t i = 0; i < other.m_count; ++i) {
            m_reservations[i] = new Reservation(*other.m_reservations[i]);
        }
        m_count = other.m_count;
    }

    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_reservations = new Reservation*[other.m_count];
            for (size_t i = 0; i < other.m_count; ++i) {
                m_reservations[i] = new Reservation(*other.m_reservations[i]);
            }
            m_count = other.m_count;
        }
        return *this;
    }

    // Move constructor
    Restaurant::Restaurant(Restaurant&& other) noexcept {
        m_count = other.m_count;
        m_reservations = other.m_reservations;
        other.m_reservations = nullptr;
        other.m_count = 0;
    }

// Move assignment operator
    Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
        if (this != &other) {
            // Deallocate existing resources
            for (size_t i = 0; i < m_count; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            // Transfer ownership from other
            m_count = other.m_count;
            m_reservations = other.m_reservations;

            // Reset other to a valid state
            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_count; ++i) {
            delete m_reservations[i];
        }
        delete[] m_reservations;
    }

    size_t Restaurant::size() const {
        return m_count;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
    static size_t CALL_CNT = 0;
    os << "--------------------------\n";
    os << "Fancy Restaurant (" << ++CALL_CNT << ")\n";
    os << "--------------------------\n";

    if (restaurant.size() == 0) {
        os << "This restaurant is empty!\n";
    } else {
        for (size_t i = 0; i < restaurant.size(); ++i) {
            if (restaurant.m_reservations[i] != nullptr) {
                os << *restaurant.m_reservations[i];
            }
        }
    }

    os << "--------------------------\n";
    return os;
}
}