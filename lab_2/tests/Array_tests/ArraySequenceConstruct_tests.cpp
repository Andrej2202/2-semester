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
    
    EXPECT_EQ(seq.GetLength(), 4)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> MutableArraySequence<int> seq(arr, 4) -> seq length"
        << "\nexpected:" << "4";
    EXPECT_EQ(seq.Get(0), 10)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> MutableArraySequence<int> seq(arr, 4) -> seq[0]"
        << "\nexpected:" << "10";
    EXPECT_EQ(seq.Get(3), 40)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> MutableArraySequence<int> seq(arr, 4) -> seq[3]"
        << "\nexpected:" << "40";
}

TEST(ArraySequenceBasics, ConstructEmpty) {
    MutableArraySequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "MutableArraySequence<int> seq -> seq length()"
        << "\nexpected:" << "0";
    
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException)
        << "input:" << "MutableArraySequence<int> seq -> seq[0]"
        << "\nexpected:" << "throw IndexOutOfRangeException";
}

TEST(ArraySequenceBasics, ConstructFromLinkedList) {
    int arr[] = {5, 10, 15};
    LinkedList<int> list(arr, 3);
    MutableArraySequence<int> seq(list);
    
    EXPECT_EQ(seq.GetLength(), 3)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> LinkedList<int> list(arr, 3) -> MutableArraySequence<int> seq(list) -> length"
        << "\nexpected:" << "3";
    EXPECT_EQ(seq.Get(1), 10)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> LinkedList<int> list(arr, 3) -> MutableArraySequence<int> seq(list) -> seq[1]"
        << "\nexpected:" << "10";
    EXPECT_EQ(seq.GetFirst(), 5)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> LinkedList<int> list(arr, 3) -> MutableArraySequence<int> seq(list) -> seq[0]"
        << "\nexpected:" << "5";
    EXPECT_EQ(seq.GetLast(), 15)
        << "input:" << "int arr[] = {10, 20, 30, 40} -> LinkedList<int> list(arr, 3) -> MutableArraySequence<int> seq(list) -> seq[2]"
        << "\nexpected:" << "15";
}