#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <ArraySequence.hpp>
#include <MutableArraySequence.hpp>
#include <ImmutableArraySequence.hpp>
#include <LinkedList.hpp>

TEST(ArraySequenceBasics, ConstructFromRawArray) {
    int arr[] = {10, 20, 30, 40};
    MutableArraySequence<int> seq(arr, 4);
    
    EXPECT_EQ(seq.GetLength(), 4);
    EXPECT_EQ(seq.Get(0), 10);
    EXPECT_EQ(seq.Get(3), 40);
}

TEST(ArraySequenceBasics, ConstructEmpty) {
    MutableArraySequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0);
    
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetLast(), IndexOutOfRangeException);
    EXPECT_THROW(seq.Get(0), IndexOutOfRangeException);
}

TEST(ArraySequenceBasics, ConstructFromLinkedList) {
    int arr[] = {5, 10, 15};
    LinkedList<int> list(arr, 3);
    MutableArraySequence<int> seq(list);
    
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.Get(1), 10);
    EXPECT_EQ(seq.GetFirst(), 5);
    EXPECT_EQ(seq.GetLast(), 15);
}