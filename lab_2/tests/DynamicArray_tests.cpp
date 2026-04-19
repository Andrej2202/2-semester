#include <gtest/gtest.h>
#include "DynamicArray.hpp"


TEST(DynamicArrayTest, CreationFromRawArray) {
    int raw[] = {10, 20, 30};
    DynamicArray<int> arr(raw, 3);
    
    EXPECT_EQ(arr.GetSize(), 3);
    EXPECT_EQ(arr.Get(1), 20);
}