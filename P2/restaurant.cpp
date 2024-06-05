#include "Restaurant.h"
#include <utility> // for std::move

namespace seneca {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_cnt(cnt) {
        m_reservations = new Reservation*[cnt];
        for (size_t i = 0; i < cnt; ++i) {
            m_reservations[i] = new Reservation(*reservations[i]);
        }
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_cnt; ++i) {
            delete m_reservations[i];
        }
        delete[] m_reservations;
    }

    Restaurant::Restaurant(const Restaurant& other) : m_cnt(other.m_cnt) {
        m_reservations = new Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; ++i) {
            m_reservations[i] = new Reservation(*other.m_reservations[i]);
        }
    }

    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_cnt; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_cnt = other.m_cnt;
            m_reservations = new Reservation*[m_cnt];
            for (size_t i = 0; i < m_cnt; ++i) {
                m_reservations[i] = new Reservation(*other.m_reservations[i]);
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& other) noexcept : m_reservations(other.m_reservations), m_cnt(other.m_cnt) {
        other.m_reservations = nullptr;
        other.m_cnt = 0;
    }

    Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_cnt; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_cnt = other.m_cnt;

            other.m_reservations = nullptr;
            other.m_cnt = 0;
        }
        return *this;
    }

    size_t Restaurant::size() const {
        return m_cnt;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
        static int call_cnt = 0;
        ++call_cnt;

        os << "--------------------------\n";
        os << "Fancy Restaurant (" << call_cnt << ")\n";
        os << "--------------------------\n";

        if (res.m_cnt == 0) {
            os << "This restaurant is empty!\n";
        } else {
            for (size_t i = 0; i < res.m_cnt; ++i) {
                os << *res.m_reservations[i];
            }
        }

        os << "--------------------------\n";
        return os;
    }
}
