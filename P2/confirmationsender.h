#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {  // Changed from sdds to seneca
    class ConfirmationSender {
        const Reservation** m_reservations{nullptr};
        size_t m_count{0};

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other) noexcept;  // Added move constructor
        ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;  // Added move assignment
        ~ConfirmationSender();

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // SDDS_CONFIRMATIONSENDER_H