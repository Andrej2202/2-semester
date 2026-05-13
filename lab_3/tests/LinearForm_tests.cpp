#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <Exceptions.hpp>
#include <DynamicArray.hpp>

TEST(DynamicArrayConstructors, FromRawArray) {
    int raw[] = {10, 20, 30, 40};
    DynamicArray<int> arr(raw, 4);
    
    EXPECT_EQ(arr.GetSize(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(arr.Get(i), raw[i])
            << "input:" << "int raw[] = {10, 20, 30, 40} -> DynamicArray<int> arr(raw, 4) ->  seq["<<i<<"]"
            << "\nexpected:" << i;
    }
}