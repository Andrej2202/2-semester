# 🧪 Справочник макросов Google Test (C++)

## ⚖️ EXPECT vs ASSERT
| Префикс | Поведение при провале | Когда использовать |
|:--------|:----------------------|:-------------------|
| `EXPECT_*` | Тест **продолжается**, помечается как ❌ | Несколько независимых проверок в одном тесте |
| `ASSERT_*` | Тест **прерывается немедленно** | Дальнейшие проверки бессмысленны (объект не создался, `nullptr`) |

---

##  Логика и сравнение
| Макрос | Что проверяет | Пример для `DynamicArray` |
|:-------|:--------------|:--------------------------|
| `EXPECT_TRUE(cond)` | Условие истинно | `EXPECT_TRUE(arr.Size() >= 0);` |
| `EXPECT_FALSE(cond)` | Условие ложно | `EXPECT_FALSE(arr.IsEmpty());` |
| `EXPECT_EQ(a, b)` | Равно (`a == b`) | `EXPECT_EQ(arr.Size(), 5);` |
| `EXPECT_NE(a, b)` | Не равно (`a != b`) | `EXPECT_NE(arr.GetData(), nullptr);` |
| `EXPECT_LT(a, b)` | Меньше (`a < b`) | `EXPECT_LT(index, arr.Size());` |
| `EXPECT_LE(a, b)` | Меньше или равно (`≤`) | `EXPECT_LE(arr.Size(), MAX_ARR_SIZE);` |
| `EXPECT_GT(a, b)` | Больше (`a > b`) | `EXPECT_GT(arr.Capacity(), 0);` |
| `EXPECT_GE(a, b)` | Больше или равно (`≥`) | `EXPECT_GE(arr.Size(), 0);` |

---

## 🔤 Строки и числа с плавающей точкой
| Макрос | Что проверяет | ️ Важное примечание |
|:-------|:--------------|:---------------------|
| `EXPECT_FLOAT_EQ(a, b)` | `float` с учётом точности IEEE 754 | Для `T=float` |
| `EXPECT_DOUBLE_EQ(a, b)` | `double` с учётом точности | Для `T=double` |
| `EXPECT_NEAR(a, b, delta)` | `\|a - b\| ≤ delta` | Универсальный допуск: `EXPECT_NEAR(val, 3.14, 0.001);` |
| `EXPECT_STREQ(s1, s2)` | C-строки совпадают | Только для `const char*` |
| `EXPECT_STRNE(s1, s2)` | C-строки разные | Только для `const char*` |
> 💡 Для `std::string` всегда используйте обычные `EXPECT_EQ` / `EXPECT_NE`.

---

## 🚨 Исключения и аварийное завершение
| Макрос | Что проверяет | Пример для `DynamicArray` |
|:-------|:--------------|:--------------------------|
| `EXPECT_THROW(expr, type)` | Выбрасывает исключение `type` | `EXPECT_THROW(arr.Get(100), std::out_of_range);` |
| `EXPECT_NO_THROW(expr)` | Не выбрасывает исключений | `EXPECT_NO_THROW(arr.PushBack(42));` |
| `EXPECT_ANY_THROW(expr)` | Любое исключение | `EXPECT_ANY_THROW(arr.Set(-1, 0));` |
| `EXPECT_DEATH(expr, regex)` | Программа завершается (`assert`/`abort`) | `EXPECT_DEATH(arr.ForceCrash(), ".*");` |

---

## 💡 Продвинутые приёмы
| Приём | Синтаксис | Пример использования |
|:------|:----------|:---------------------|
| Кастомное сообщение | `<< "текст"` | `EXPECT_EQ(arr.Size(), 5) << "Failed at step " << i;` |
| Проверка указателей | `EXPECT_EQ(ptr1, ptr2)` | `EXPECT_NE(&arr1, &arr2);` (глубокое копирование) |
| Контекст отладки | `SCOPED_TRACE("msg")` | Добавляет `"msg"` ко всем `EXPECT` внутри блока `{}` |
| Временные ассерты | `::testing::Test::RecordProperty("key", "val")` | Логирует метаданные в XML-отчёт `ctest` |

---

## 🛠 Быстрые команды запуска (PowerShell)
| Задача | Команда |
|:-------|:-------|
| Запустить все тесты | `.\build\Lab2Tests.exe` |
| Только один тест | `.\build\Lab2Tests.exe --gtest_filter=DynamicArrayTest.ConstructorBySize` |
| Несколько тестов (wildcard) | `.\build\Lab2Tests.exe --gtest_filter=*Constructor*:*GetSet*` |
| Исключить тесты | `.\build\Lab2Tests.exe --gtest_filter=-*Slow*` |
| Остановиться на первой ошибке | `.\build\Lab2Tests.exe --gtest_break_on_failure` |
| Запустить через CTest | `ctest --test-dir build --output-on-failure` |

---

## 📌 Чек-лист для TDD в лабе
1. **Сначала тест** → `EXPECT_EQ(arr.Size(), 0);` (должен упасть)
2. **Минимальный код** → добавьте поле `size_` и конструктор
3. **Зелёный тест** → `cmake --build build && .\build\Lab2Tests.exe`
4. **Рефакторинг** → уберите дублирование, проверьте `const`-корректность
5. **Граничные случаи** → `0`, `-1`, `nullptr`, выход за границы, копирование самого себя
6. **Утечки памяти** → проверьте через `delete[]` в деструкторе и тесты на копирование

ctrl + shift + v предпросмотр