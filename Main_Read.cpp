#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

void readMemory(double memsize) {
    // Вычисляем количество элементов int для чтения из памяти
    size_t num_elements = static_cast<size_t>(memsize * 1024 * 1024 * 1024 * sizeof(int));

    // Выделяем память
   int* memory = new int[num_elements];

    // Размер шага в байтах для чтения из памяти (4 килобайта)
    size_t step = 4 * 1024;

    // Читаем данные из памяти
    for (size_t i = 0; i < num_elements; i += step / sizeof(int)) {
        int value = const_cast<const volatile int*>(memory)[i]; // Читаем значение из памяти
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Задержка 1 миллисекунда
    }

    // Освобождаем память
    delete[] memory;;
    memory = nullptr;
}

int main() {
    double memsize_in_gb = 1.0; // Размер памяти в гигабайтах
    readMemory(memsize_in_gb);

    return 0;
}
