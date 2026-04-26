#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <Sequence.hpp>
#include <ListSequence.hpp>
#include <MutableListSequence.hpp>
#include <LinkedList.hpp>

TEST(MutableListSequenceModification, Append_Prepend_ModifyInPlace) {
    MutableListSequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0);
    
    seq.Append(1);
    seq.Append(2);
    seq.Prepend(0);
    
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.Get(0), 0);
    EXPECT_EQ(seq.Get(1), 1);
    EXPECT_EQ(seq.Get(2), 2);
}

TEST(MutableListSequenceModification, InsertAt_ValidIndices) {
    MutableListSequence<int> seq;
    seq.Append(10); seq.Append(30);
    
    EXPECT_NO_THROW(seq.InsertAt(20, 1));
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.Get(0), 10);
    EXPECT_EQ(seq.Get(1), 20);
    EXPECT_EQ(seq.Get(2), 30);
}

TEST(MutableListSequenceModification, ReturnsThis_NoDeleteNeeded) {
    MutableListSequence<int> seq;
    Sequence<int>* resAppend = seq.Append(42);
    Sequence<int>* resPrepend = seq.Prepend(0);
    Sequence<int>* resInsert = seq.InsertAt(99, 1);
    
    EXPECT_EQ(resAppend, &seq);
    EXPECT_EQ(resPrepend, &seq);
    EXPECT_EQ(resInsert, &seq);
    
    EXPECT_EQ(seq.GetLength(), 3);
}

TEST(MutableListSequenceAccessors, Get_GetFirst_GetLast_Correctness) {
    int arr[] = {1, 2, 3, 4, 5};
    MutableListSequence<int> seq(arr, 5);
    
    EXPECT_EQ(seq.GetFirst(), 1);
    EXPECT_EQ(seq.GetLast(), 5);
    EXPECT_EQ(seq.Get(2), 3);
    EXPECT_EQ(seq.GetLength(), 5);
}

TEST(MutableListSequenceAccessors, EmptySequence_Throws) {
    MutableListSequence<int> seq;
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetLast(), IndexOutOfRangeException);
    EXPECT_THROW(seq.Get(0), IndexOutOfRangeException);
}

TEST(MutableListSequenceOperations, GetSubsequence_ReturnsNewCopy) {
    int arr[] = {10, 20, 30, 40, 50};
    MutableListSequence<int> seq(arr, 5);
    
    Sequence<int>* sub = seq.GetSubsequence(1, 3); 
    ASSERT_NE(sub, nullptr);
    EXPECT_EQ(sub->GetLength(), 3);
    EXPECT_EQ(sub->Get(0), 20);
    EXPECT_EQ(sub->GetLast(), 40);
    EXPECT_EQ(seq.GetLength(), 5);
    EXPECT_NE(sub, &seq);
    
    delete sub;
}

TEST(MutableListSequenceOperations, GetSubsequence_BoundaryAndInvalid) {
    MutableListSequence<int> seq;
    seq.Append(1); seq.Append(2); seq.Append(3);
    
    Sequence<int>* single = seq.GetSubsequence(0, 0);
    EXPECT_EQ(single->GetLength(), 1);
    delete single;
    
    single = seq.GetSubsequence(2, 2);
    EXPECT_EQ(single->Get(0), 3);
    delete single;
    
    EXPECT_THROW(seq.GetSubsequence(-1, 2), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(0, 3), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(2, 1), IndexOutOfRangeException);
}

TEST(MutableListSequenceOperations, Concat_ReturnsNewCopy) {
    int a1[] = {1, 2};
    int a2[] = {3, 4, 5};
    MutableListSequence<int> seq1(a1, 2);
    MutableListSequence<int> seq2(a2, 3);
    
    Sequence<int>* concat = seq1.Concat(&seq2);
    ASSERT_NE(concat, nullptr);
    EXPECT_EQ(concat->GetLength(), 5);
    EXPECT_EQ(concat->Get(0), 1);
    EXPECT_EQ(concat->GetLast(), 5);
    
    EXPECT_EQ(seq1.GetLength(), 2);
    EXPECT_EQ(seq2.GetLength(), 3);
    EXPECT_NE(concat, &seq1);
    EXPECT_NE(concat, &seq2);
    delete concat;
}

TEST(MutableListSequenceOperations, Concat_WithEmpty) {
    int arr[] = {10, 20};
    MutableListSequence<int> seq(arr, 2);
    MutableListSequence<int> empty;
    
    Sequence<int>* res1 = seq.Concat(&empty);
    EXPECT_EQ(res1->GetLength(), 2);
    delete res1;
    
    Sequence<int>* res2 = empty.Concat(&seq);
    EXPECT_EQ(res2->GetLength(), 2);
    delete res2;
}

TEST(MutableListSequenceExceptions, IndexOutOfRange_StrictContract) {
    MutableListSequence<int> seq;
    seq.Append(1); seq.Append(2);
    
    EXPECT_THROW(seq.Get(-1), IndexOutOfRangeException);
    EXPECT_THROW(seq.InsertAt(10, -1), IndexOutOfRangeException);
    
    EXPECT_THROW(seq.Get(2), IndexOutOfRangeException);
    EXPECT_THROW(seq.InsertAt(10, 2), IndexOutOfRangeException);
    EXPECT_THROW(seq.InsertAt(10, 5), IndexOutOfRangeException);
}

TEST(MutableListSequenceTemplates, StringSequence) {
    std::string arr[] = {"Alpha", "Beta", "Gamma"};
    MutableListSequence<std::string> seq(arr, 3);
    
    EXPECT_EQ(seq.GetLength(), 3);
    seq.Prepend("Zero");
    EXPECT_EQ(seq.GetFirst(), "Zero");
    EXPECT_EQ(seq.GetLast(), "Gamma");
    
    EXPECT_NO_THROW(seq.InsertAt("Mid", 2));
    EXPECT_EQ(seq.Get(2), "Mid");
}

TEST(MutableListSequenceTemplates, CustomStruct) {
    struct Point { int x, y; };
    Point arr[] = {{1, 2}, {3, 4}};
    MutableListSequence<Point> seq(arr, 2);
    
    EXPECT_EQ(seq.Get(0).x, 1);
    seq.Append({5, 5});
    EXPECT_EQ(seq.GetLength(), 3);
    EXPECT_EQ(seq.GetLast().y, 5);
}