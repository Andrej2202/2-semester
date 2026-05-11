#include <iostream>
#include <string>
#include <exception>
#include <LinearForm.hpp>
#include <MutableArraySequence.hpp>

template<typename T>
Sequence<T>* readSequence(const std::string& label) {
    size_t count;
    std::cout << "Введите количество элементов для '" << label << "': ";
    std::cin >> count;
    Sequence<T>* seq = new MutableArraySequence<T>();
    for (size_t i = 0; i < count; ++i) {
        T val;
        std::cout << "  Элемент [" << i << "]: ";
        std::cin >> val;
        seq->Append(val);
    }
    return seq;
}

int main() {
    LinearForm<double>* currentForm = nullptr;

    int choice = -1;
    while (true) {
        try {
            std::cout << "\n========================================\n";
            std::cout << "       Тестирование LinearForm<T>       \n";
            std::cout << "========================================\n";
            std::cout << "1. Создать новую линейную форму\n";
            std::cout << "2. Вывести текущую форму\n";
            std::cout << "3. Сложить с другой формой (F = F + G)\n";
            std::cout << "4. Вычесть другую форму (F = F - G)\n";
            std::cout << "5. Умножить на скаляр (F = F * c)\n";
            std::cout << "6. Вычислить значение F(x1, ..., xn)\n";
            std::cout << "0. Выход\n";
            std::cout << "========================================\n";
            std::cout << "Ваш выбор: ";
            std::cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "Завершение работы.\n";
                    goto cleanup;

                case 1: {
                    std::cout << "\n--- Создание формы ---\n";
                    Sequence<double>* coeffs = readSequence<double>("Коэффициенты [a0, a1, ..., an]");
                    delete currentForm;
                    currentForm = new LinearForm<double>(coeffs);
                    std::cout << "Успешно создана: " << *currentForm << "\n";
                    break;
                }

                case 2: {
                    if (!currentForm) {
                        std::cout << "Форма ещё не создана. Выберите пункт 1.\n";
                        break;
                    }
                    std::cout << "Текущая форма: " << *currentForm << "\n";
                    std::cout << "Арность (число переменных): " << currentForm->GetArity() << "\n";
                    break;
                }

                case 3: {
                    if (!currentForm) { 
                        std::cout << "Форма ещё не создана. Выберите пункт 1.\n"; 
                        break; 
                    }
                    std::cout << "\n--- Сложение ---\n";
                    Sequence<double>* otherCoeffs = readSequence<double>("Коэффициенты второй формы G");
                    LinearForm<double> other(otherCoeffs);
                    *currentForm = *currentForm + other;
                    std::cout << "Результат сложения: " << *currentForm << "\n";
                    break;
                }

                case 4: {
                    if (!currentForm) { std::cout << "Сначала создайте форму.\n"; break; }
                    std::cout << "\n--- Вычитание ---\n";
                    Sequence<double>* otherCoeffs = readSequence<double>("Коэффициенты формы G");
                    LinearForm<double> other(otherCoeffs);
                    *currentForm = *currentForm - other;
                    std::cout << "Результат вычитания: " << *currentForm << "\n";
                    break;
                }

                case 5: {
                    if (!currentForm) { 
                        std::cout << "Форма ещё не создана. Выберите пункт 1.\n"; 
                        break; 
                    }
                    std::cout << "\n--- Умножение на скаляр ---\n";
                    double scalar;
                    std::cout << "Введите скаляр c: ";
                    std::cin >> scalar;
                    *currentForm = *currentForm * scalar;
                    std::cout << "Результат: " << *currentForm << "\n";
                    break;
                }

                case 6: {
                    if (!currentForm) { 
                        std::cout << "Форма ещё не создана. Выберите пункт 1.\n"; 
                        break; 
                    }
                    size_t arity = currentForm->GetArity();
                    if (arity == 0) {
                        std::cout << "Форма не имеет переменных (только свободный член).\n";
                        break;
                    }
                    std::cout << "\n--- Вычисление значения ---\n";
                    std::cout << "Форма имеет " << arity << " переменных.\n";
                    Sequence<double>* args = new MutableArraySequence<double>();
                    for (size_t i = 0; i < arity; ++i) {
                        double val;
                        std::cout << "  x" << (i + 1) << " = ";
                        std::cin >> val;
                        args->Append(val);
                    }
                    double result = currentForm->Evaluate(*args);
                    std::cout << "Результат F(x1..xn) = " << result << "\n";
                    delete args;
                    break;
                }

                default:
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        } catch (...) {
            std::cout << "\nПроизошла неизвестная ошибка.\n";
        }

        std::cin.clear(); //сброс флагов ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

cleanup:
    delete currentForm;
    return 0;
}