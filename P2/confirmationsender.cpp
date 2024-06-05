#include "ConfirmationSender.h"
#include <algorithm> // for std::find

namespace seneca {
    ConfirmationSender::ConfirmationSender() : m_reservations(nullptr), m_cnt(0) {}

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) : m_cnt(other.m_cnt) {
        m_reservations = new const Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; ++i) {
            m_reservations[i] = other.m_reservations[i];
        }
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] m_reservations;

            m_cnt = other.m_cnt;
            m_reservations = new const Reservation*[m_cnt];
            for (size_t i = 0; i < m_cnt; ++i) {
                m_reservations[i] = other.m_reservations[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept : m_reservations(other.m_reservations), m_cnt(other.m_cnt) {
        other.m_reservations = nullptr;
        other.m_cnt = 0;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_cnt = other.m_cnt;

            other.m_reservations = nullptr;
            other.m_cnt = 0;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        if (std::find(m_reservations, m_reservations + m_cnt, &res) == m_reservations + m_cnt) {
            const Reservation** temp = new const Reservation*[m_cnt + 1];
            for (size_t i = 0; i < m_cnt; ++i) {
                temp[i] = m_reservations[i];
            }
            temp[m_cnt] = &res;
            delete[] m_reservations;
            m_reservations = temp;
            ++m_cnt;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        auto it = std::find(m_reservations, m_reservations + m_cnt, &res);
        if (it != m_reservations + m_cnt) {
            *it = m_reservations[--m_cnt];
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";

        if (sender.m_cnt == 0) {
            os << "There are no confirmations to send!\n";
        } else {
            for (size_t i = 0; i < sender.m_cnt; ++i) {
                os << *sender.m_reservations[i];
            }
        }

        os << "--------------------------\n";
        return os;
    }
}
