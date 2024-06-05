#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {
    class ConfirmationSender {
    private:
        const Reservation** m_reservations;
        size_t m_cnt;

    public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other) noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // CONFIRMATIONSENDER_H
