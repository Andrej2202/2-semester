#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <ListSequence.hpp>
#include <MutableListSequence.hpp>
#include <ImmutableListSequence.hpp>
#include <LinkedList.hpp>


TEST(MutableListSequenceConstructors, Default_Empty) {
    MutableListSequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0);
    
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetLast(), IndexOutOfRangeException);
    EXPECT_THROW(seq.Get(0), IndexOutOfRangeException);
}

TEST(MutableListSequenceConstructors, FromRawArray) {
    int arr[] = {10, 20, 30, 40};
    MutableListSequence<int> seq(arr, 4);
    
    EXPECT_EQ(seq.GetLength(), 4);
    EXPECT_EQ(seq.Get(0), 10);
    EXPECT_EQ(seq.Get(1), 20);
    EXPECT_EQ(seq.GetLast(), 40);
}

TEST(MutableListSequenceConstructors, FromRawArray_ZeroSize) {
    int* empty_arr = nullptr;
    MutableListSequence<int> seq(empty_arr, 0);
    EXPECT_EQ(seq.GetLength(), 0);
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException);
}

TEST(MutableListSequenceConstructors, FromLinkedList) {
    int arr[] = {5, 10, 15};
    LinkedList<int> list(arr, 3);
    MutableListSequence<int> seq(list); 
    
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.GetFirst(), 5);
    EXPECT_EQ(seq.Get(1), 10);
    EXPECT_EQ(seq.GetLast(), 15);
}

TEST(ImmutableListSequenceConstructors, Default_Empty) {
    ImmutableListSequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0);
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetLast(), IndexOutOfRangeException);
}

TEST(ImmutableListSequenceConstructors, FromRawArray) {
    int arr[] = {100, 200, 300};
    ImmutableListSequence<int> seq(arr, 3);
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.Get(0), 100);
    EXPECT_EQ(seq.Get(2), 300);
}

TEST(ImmutableListSequenceConstructors, FromLinkedList) {
    int arr[] = {1, 2, 3, 4};
    LinkedList<int> list(arr, 4);
    ImmutableListSequence<int> seq(list);
    EXPECT_EQ(seq.GetLength(), 4);
    EXPECT_EQ(seq.GetFirst(), 1);
    EXPECT_EQ(seq.GetLast(), 4);
}

TEST(ListSequenceConstructors, DeepCopyIndependence_FromLinkedList) {
    int arr[] = {1, 2, 3};
    LinkedList<int> source(arr, 3);
    
    MutableListSequence<int> seq1(source);
    ImmutableListSequence<int> seq2(source);
    
    source.Append(99);
    source.Prepend(0);
    
    EXPECT_EQ(seq1.GetLength(), 3);
    EXPECT_EQ(seq2.GetLength(), 3);
    EXPECT_EQ(seq1.Get(0), 1);
    EXPECT_EQ(seq2.GetLast(), 3);
}

TEST(ListSequenceConstructors, Templates_WorkWithStrings) {
    std::string arr[] = {"Alpha", "Beta", "Gamma"};
    
    MutableListSequence<std::string> m_seq(arr, 3);
    ImmutableListSequence<std::string> i_seq(arr, 3);
    
    EXPECT_EQ(m_seq.GetLength(), 3);
    EXPECT_EQ(m_seq.Get(1), "Beta");
    
    EXPECT_EQ(i_seq.GetLength(), 3);
    EXPECT_EQ(i_seq.GetFirst(), "Alpha");
    EXPECT_EQ(i_seq.GetLast(), "Gamma");
}

TEST(ListSequenceConstructors, Templates_WorkWithCustomStruct) {
    struct Point { int x, y; };
    Point arr[] = {{1, 2}, {3, 4}};
    
    MutableListSequence<Point> m_seq(arr, 2);
    EXPECT_EQ(m_seq.Get(0).x, 1);
    EXPECT_EQ(m_seq.GetLast().y, 4);
    
    ImmutableListSequence<Point> i_seq(arr, 2);
    EXPECT_EQ(i_seq.GetLength(), 2);
}