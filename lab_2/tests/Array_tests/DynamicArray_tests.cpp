#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <Exceptions.hpp>
#include <DynamicArray.hpp>

TEST(DynamicArrayConstructors, FromRawArray) {
    int raw[] = {10, 20, 30, 40};
    DynamicArray<int> arr(raw, 4);
    
    EXPECT_EQ(arr.GetSize(), 4);
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(arr.Get(i), raw[i]);
    }
}

TEST(DynamicArrayConstructors, FromSize) {
    DynamicArray<int> arr(5);
    ASSERT_EQ(arr.GetSize(), 5);
    EXPECT_NO_THROW(arr.Get(0));
    EXPECT_NO_THROW(arr.Get(4));
    arr.Set(0, 0);
    arr.Set(4, 0);
    EXPECT_EQ(arr.Get(0), 0);
    EXPECT_EQ(arr.Get(4), 0);
}

TEST(DynamicArrayConstructors, CopyConstructor_DeepCopy) {
    int raw[] = {1, 2, 3};
    DynamicArray<int> original(raw, 3);
    DynamicArray<int> copy(original);
    
    EXPECT_EQ(copy.GetSize(), 3);
    EXPECT_EQ(copy.Get(0), 1);
    EXPECT_EQ(copy.Get(2), 3);
}

TEST(DynamicArrayConstructors, ZeroSizeArray) {
    DynamicArray<int> empty(0);
    EXPECT_EQ(empty.GetSize(), 0);
    EXPECT_THROW(empty.Get(0), IndexOutOfRangeException);
}

TEST(DynamicArrayAccess, GetValidAndBoundaryIndices) {
    int raw[] = {5, 10, 15};
    DynamicArray<int> arr(raw, 3);
    
    EXPECT_EQ(arr.Get(0), 5);
    EXPECT_EQ(arr.Get(1), 10);
    EXPECT_EQ(arr.Get(2), 15);
    EXPECT_EQ(arr.GetSize(), 3);
}

TEST(DynamicArrayAccess, GetThrowsOnInvalidIndices) {
    DynamicArray<int> arr(3);
    
    EXPECT_THROW(arr.Get(-1), IndexOutOfRangeException);
    EXPECT_THROW(arr.Get(3), IndexOutOfRangeException);
    EXPECT_THROW(arr.Get(100), IndexOutOfRangeException);
}

TEST(DynamicArrayModification, SetValidIndices) {
    DynamicArray<int> arr(4);
    
    arr.Set(0, 100);
    arr.Set(2, 300);
    arr.Set(3, 400);
    
    EXPECT_EQ(arr.Get(0), 100);
    EXPECT_EQ(arr.Get(2), 300);
    EXPECT_EQ(arr.Get(3), 400);
}

TEST(DynamicArrayModification, SetThrowsOnInvalidIndices) {
    DynamicArray<int> arr(2);
    EXPECT_THROW(arr.Set(-1, 10), IndexOutOfRangeException);
    EXPECT_THROW(arr.Set(2, 10), IndexOutOfRangeException);
}

TEST(DynamicArrayResize, IncreaseSize_PreservesData) {
    int raw[] = {1, 2, 3};
    DynamicArray<int> arr(raw, 3);
    
    arr.Resize(6);
    EXPECT_EQ(arr.GetSize(), 6);
    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Get(1), 2);
    EXPECT_EQ(arr.Get(2), 3);
    EXPECT_EQ(arr.Get(5), 0); 
}

TEST(DynamicArrayResize, DecreaseSize_TruncatesCorrectly) {
    int raw[] = {10, 20, 30, 40, 50};
    DynamicArray<int> arr(raw, 5);
    
    arr.Resize(3);
    EXPECT_EQ(arr.GetSize(), 3);
    EXPECT_EQ(arr.Get(0), 10);
    EXPECT_EQ(arr.Get(1), 20);
    EXPECT_EQ(arr.Get(2), 30);
    EXPECT_THROW(arr.Get(3), IndexOutOfRangeException);
    EXPECT_THROW(arr.Get(4), IndexOutOfRangeException);
}

TEST(DynamicArrayResize, ResizeToZero) {
    int raw[] = {1, 2};
    DynamicArray<int> arr(raw, 2);
    
    arr.Resize(0);
    EXPECT_EQ(arr.GetSize(), 0);
    EXPECT_THROW(arr.Get(0), IndexOutOfRangeException);
}

TEST(DynamicArrayResize, ResizeToSameSize) {
    int raw[] = {7, 8, 9};
    DynamicArray<int> arr(raw, 3);
    
    arr.Resize(3);
    EXPECT_EQ(arr.GetSize(), 3);
    EXPECT_EQ(arr.Get(1), 8);
}

TEST(DynamicArrayResize, NegativeSizeThrows) {
    DynamicArray<int> arr(5);
    EXPECT_THROW(arr.Resize(-1), InvalidArgumentException);
}

TEST(DynamicArrayMemory, CopyIndependence) {
    int raw[] = {1, 2, 3};
    DynamicArray<int> original(raw, 3);
    DynamicArray<int> copy(original);
    
    copy.Set(1, 999);
    EXPECT_EQ(original.Get(0), 1);
    EXPECT_EQ(original.Get(1), 2);
    EXPECT_EQ(original.Get(2), 3);
}

TEST(DynamicArrayTemplates, StringArray) {
    std::string raw[] = {"Alpha", "Beta", "Gamma"};
    DynamicArray<std::string> arr(raw, 3);
    
    EXPECT_EQ(arr.Get(0), "Alpha");
    EXPECT_EQ(arr.Get(2), "Gamma");
    EXPECT_EQ(arr.GetSize(), 3);
    
    arr.Resize(2);
    EXPECT_EQ(arr.GetSize(), 2);
    EXPECT_EQ(arr.Get(1), "Beta");
    
    arr.Set(1, "Modified");
    EXPECT_EQ(arr.Get(1), "Modified");
}

TEST(DynamicArrayTemplates, CustomStruct) {
    struct Point { int x, y; };
    Point raw[] = {{1, 2}, {3, 4}};
    DynamicArray<Point> arr(raw, 2);
    
    EXPECT_EQ(arr.Get(0).x, 1);
    EXPECT_EQ(arr.Get(1).y, 4);
    
    arr.Set(0, {10, 20});
    EXPECT_EQ(arr.Get(0).x, 10);
    EXPECT_EQ(arr.Get(0).y, 20);
}