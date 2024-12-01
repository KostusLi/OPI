#include <iostream>
#include <string>

// Функция для кодирования символа в UTF-8
std::string encodeToUTF8(uint32_t unicodeChar) {
    char utf8Str[5] = { 0 };  // Массив на 5 элементов для хранения результата (4 байта для UTF-8 + null-терминатор)
    int length = 0;  // Переменная для отслеживания количества байтов в UTF-8

    if (unicodeChar <= 0x7F) {  // 1 байт для символов ASCII
        utf8Str[0] = static_cast<char>(unicodeChar);
        length = 1;
    }
    else if (unicodeChar <= 0x7FF) {  // 2 байта
        utf8Str[0] = static_cast<char>(0xC0 | ((unicodeChar >> 6) & 0x1F));
        utf8Str[1] = static_cast<char>(0x80 | (unicodeChar & 0x3F));
        length = 2;
    }
    else if (unicodeChar <= 0xFFFF) {  // 3 байта
        utf8Str[0] = static_cast<char>(0xE0 | ((unicodeChar >> 12) & 0x0F));
        utf8Str[1] = static_cast<char>(0x80 | ((unicodeChar >> 6) & 0x3F));
        utf8Str[2] = static_cast<char>(0x80 | (unicodeChar & 0x3F));
        length = 3;
    }
    else if (unicodeChar <= 0x10FFFF) {  // 4 байта
        utf8Str[0] = static_cast<char>(0xF0 | ((unicodeChar >> 18) & 0x07));
        utf8Str[1] = static_cast<char>(0x80 | ((unicodeChar >> 12) & 0x3F));
        utf8Str[2] = static_cast<char>(0x80 | ((unicodeChar >> 6) & 0x3F));
        utf8Str[3] = static_cast<char>(0x80 | (unicodeChar & 0x3F));
        length = 4;
    }
    else {
        throw std::out_of_range("Недопустимый символ Unicode");
    }

    return std::string(utf8Str, length);  // Преобразуем массив в строку с учетом длины
}

int main() {
    setlocale(LC_ALL, "ru");
    uint32_t unicodeChar;
    std::cout << "Введите Unicode-значение символа (например, 0x41 для 'A'): ";
    std::cin >> std::hex >> unicodeChar;

    try {
        std::string utf8Char = encodeToUTF8(unicodeChar);
        std::cout << "Символ в UTF-8: ";
        for (unsigned char c : utf8Char) {
            std::cout << std::hex << static_cast<int>(c & 0xFF) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
