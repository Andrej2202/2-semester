
---
### `BUG-2026-087`: `[ListSequence] Поле X нулевого элемента некорректно инициализируется при создании из массива структур Point`

| Поле               | Значение                                                                 |
|--------------------|--------------------------------------------------------------------------|
| **Component**      | `core/sequences/ListSequence`                                            |
| **Severity**       | `High` (Потеря/искажение данных в индексе 0, ломает дальнейшую логику)   |
| **Priority**       | `P1` (Блокирующий для релиза)                                            |
| **Environment**    | `Windows 11 Домашняя 25H2, C++23, GTest, Release version`                |
| **Assignee**       | `@Olkhovi4`                                                              |
| **Reporter**       | `@olkhovi4`                                                              |
| **Status**         | `NEW`                                                                    |

---
#### Шаги воспроизведения
1. Определить пользовательскую структуру:
   ```cpp
   struct Point { int x, y; };
   ```
2. Создать массив точек и инициализировать `ListSequence`:
   ```cpp
       Point arr[] = { {0, 20}, {30, 40}, {50, 60} };
       MutableListSequence<Point> m_seq(arr, 3);
       
       EXPECT_EQ(seq.Get(0).x, 0); //Ожидается 0
   ```
3. Собрать и запустить тест: `.\build\Lab2Tests.exe --gtest_color=yes`

#### Ожидаемый результат
`seq.Get(0).x == 100`. Нулевой элемент полностью соответствует исходным данным из переданного массива.

#### Фактический результат
`seq.Get(0).x` содержит `0`. Остальные элементы (`seq.Get(1)`, `seq.Get(2)`) и поле `y` нулевого элемента инициализируются корректно. Ошибка воспроизводится стабильно.

####  Вывод GTest
```text
[ RUN      ] ListSequenceConstructors.Templates_CustomStruct
D:\2_semester\lab_2\tests\List_tests\ListSequenceConstructors_tests.cpp:106: Failure
Expected equality of these values:
  m_seq.Get(0).x
    Which is: 10
  100

[  FAILED  ] ListSequenceConstructors.Templates_CustomStruct (10 ms)
```

#### Предполагаемая причина
В конструкторе `ListSequence<T>(const T* arr, size_t len)` цикл копирования начинается с `i = 1` вместо `i = 0`, либо первый узел создаётся дефолтным конструктором, а поле `x` не перезаписывается.

#### Вложения
- `gtest_listsequence_point.xml` (полный отчёт запуска)

#### Метки
`listsequence` `initialization-bug` `index-0` `struct-copy` `memory-unsafe` `gtest-fail`

---