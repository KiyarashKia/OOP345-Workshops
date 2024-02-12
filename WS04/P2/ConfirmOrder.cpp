#include "ConfirmOrder.h"

namespace seneca {

    ConfirmOrder::ConfirmOrder() : toys(nullptr), numToys(0) {}

    ConfirmOrder::~ConfirmOrder() { delete[] toys; }
    
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) : toys(nullptr), numToys(other.numToys) {
        if (other.numToys > 0) {
            toys = new const Toy * [other.numToys];
            for (size_t i = 0; i < other.numToys; ++i) {
                toys[i] = other.toys[i];
            }
        }
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept
        : toys(other.toys), numToys(other.numToys) {
        other.toys = nullptr;
        other.numToys = 0;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept {
        if (this != &other) {
            delete[] toys;
            toys = other.toys;
            numToys = other.numToys;
            other.toys = nullptr;
            other.numToys = 0;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
        if (this != &other) {
            delete[] toys;
            numToys = other.numToys;
            toys = new const Toy * [other.numToys];
            for (size_t i = 0; i < other.numToys; ++i) {
                toys[i] = other.toys[i];
            }
        }
        return *this;
    }

    void ConfirmOrder::resize(size_t newSize) {
        const Toy** newToys = new const Toy * [newSize];
        for (size_t i = 0; i < numToys && i < newSize; ++i) {
            newToys[i] = toys[i];
        }
        delete[] toys;
        toys = newToys;
        numToys = newSize;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        for (size_t i = 0; i < numToys; ++i) {
            if (toys[i] == &toy) return *this;
        }
        resize(numToys + 1);
        toys[numToys - 1] = &toy;
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        for (size_t i = 0; i < numToys; ++i) {
            if (toys[i] == &toy) {
                for (size_t j = i; j < numToys - 1; ++j) {
                    toys[j] = toys[j + 1];
                }
                numToys--;
                return *this;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order) {
        os << "--------------------------\nConfirmations to Send\n--------------------------\n";
        if (order.numToys == 0) {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < order.numToys; ++i) {
                os << *(order.toys[i]) << "\n";
            }
        }
        os << "--------------------------\n";
        return os;
    }


}
