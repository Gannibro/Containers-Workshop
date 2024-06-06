#include "ConfirmationSender.h"

namespace seneca {
    ConfirmationSender::ConfirmationSender() {}

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) {
        *this = other;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] m_reservations;

            m_reservations = new const Reservation*[other.m_count];
            for (size_t i = 0; i < other.m_count; ++i) {
                m_reservations[i] = other.m_reservations[i];
            }
            m_count = other.m_count;
        }
        return *this;
    }

    // Added move constructor
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept {
        m_reservations = other.m_reservations;
        m_count = other.m_count;
        other.m_reservations = nullptr;
        other.m_count = 0;
    }

    // Added move assignment
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            delete[] m_reservations;
            m_reservations = other.m_reservations;
            m_count = other.m_count;
            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_reservations[i] == &res) {
                return *this;
            }
        }

        const Reservation** temp = new const Reservation*[m_count + 1];
        for (size_t i = 0; i < m_count; ++i) {
            temp[i] = m_reservations[i];
        }
        temp[m_count] = &res;

        delete[] m_reservations;
        m_reservations = temp;
        ++m_count;

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_reservations[i] == &res) {
                m_reservations[i] = nullptr;
                break;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";

        if (sender.m_count == 0) {
            os << "There are no confirmations to send!\n";
        } else {
            for (size_t i = 0; i < sender.m_count; ++i) {
                if (sender.m_reservations[i]) {
                    os << *sender.m_reservations[i];
                }
            }
        }

        os << "--------------------------\n";
        return os;
    }
}