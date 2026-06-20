#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>

class Compartment {
public:
    virtual ~Compartment() = default;
    virtual std::string notice() = 0;
};

class FirstClass : public Compartment {
public:
    std::string notice() override {
        return "FirstClass compartment: Comfortable seating and premium service ahead.";
    }
};

class Ladies : public Compartment {
public:
    std::string notice() override {
        return "Ladies compartment: Reserved for ladies only.";
    }
};

class General : public Compartment {
public:
    std::string notice() override {
        return "General compartment: Open to all passengers with valid ticket.";
    }
};

class Luggage : public Compartment {
public:
    std::string notice() override {
        return "Luggage compartment: For luggage and parcels only.";
    }
};

class TestCompartment {
public:
    static void main() {
        std::array<std::unique_ptr<Compartment>, 10> compartments;

        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::uniform_int_distribution<int> distribution(1, 4);

        for (std::size_t index = 0; index < compartments.size(); ++index) {
            int compartmentType = distribution(generator);

            switch (compartmentType) {
            case 1:
                compartments[index] = std::make_unique<FirstClass>();
                break;
            case 2:
                compartments[index] = std::make_unique<Ladies>();
                break;
            case 3:
                compartments[index] = std::make_unique<General>();
                break;
            case 4:
            default:
                compartments[index] = std::make_unique<Luggage>();
                break;
            }
        }

        for (std::size_t index = 0; index < compartments.size(); ++index) {
            std::cout << "Compartment " << (index + 1) << ": "
                      << compartments[index]->notice() << std::endl;
        }
    }
};

int main() {
    TestCompartment::main();
    return 0;
}