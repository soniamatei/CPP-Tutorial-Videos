#ifndef A8_9_914_MATEI_SONIA_VALIDATORS_H
#define A8_9_914_MATEI_SONIA_VALIDATORS_H

#include <iostream>

class Validator {

public:
    /// Verifies if a string contains only digits.
    /// \param string string
    /// \return 1 -> true; 0 -> false
    static int validateIsNumber(std::string string) {

        for(char i : string)

            if (i > '9' || i < '0')
                return 0;

        return 1;
    }

    /// Verifies if a string is a valid link.
    /// \param string string
    /// \return 1 -> true; 0 -> false
    static int validateIsLink(std::string string) {

        for(char i : string)

            if (i == ' ')
                return 0;

        return 1;
    }

    /// Verifies if a string is not empty.
    /// \param string string
    /// \return 1 -> true; 0 -> false
    static int validateNotEmpty(std::string string) {

        if (string.empty())
            return 0;
        return 1;
    }
};

#endif //A8_9_914_MATEI_SONIA_VALIDATORS_H
