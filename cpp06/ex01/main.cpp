#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data originalData;
    originalData.number = 42;
    originalData.str = "Hello, C++98!";

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized std::uintptr_t: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "The deserialized pointer matches the original pointer." << std::endl;
        std::cout << "Data content: number = " << deserializedData->number
                  << ", text = \"" << deserializedData->str << "\"" << std::endl;
    }
	else {
        std::cout << "The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}