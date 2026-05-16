#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <Sequence.hpp>
#include <ListSequence.hpp>
#include <ImmutableListSequence.hpp>
#include <LinkedList.hpp>

TEST(ImmutableListSequenceOperations, Append) {
    ImmutableListSequence<int> seq;
    Sequence<int>* new_seq = seq.Append(42);
    
    ASSERT_NE(new_seq, nullptr);
    EXPECT_NE(new_seq, &seq);
    EXPECT_EQ(new_seq->GetLength(), 1);
    EXPECT_EQ(new_seq->Get(0), 42);
    EXPECT_EQ(seq.GetLength(), 0);
    
    delete new_seq;
}

TEST(ImmutableListSequenceOperations, Prepend) {
    int arr[] = {2, 3};
    ImmutableListSequence<int> seq(arr, 2);
    
    Sequence<int>* new_seq = seq.Prepend(1);
    EXPECT_EQ(new_seq->GetLength(), 3);
    EXPECT_EQ(new_seq->Get(0), 1);
    EXPECT_EQ(new_seq->Get(1), 2);
    EXPECT_EQ(seq.GetLength(), 2);
    
    delete new_seq;
}

TEST(ImmutableListSequenceOperations, InsertAt) {
    int arr[] = {10, 30};
    ImmutableListSequence<int> seq(arr, 2);
    
    Sequence<int>* new_seq = seq.InsertAt(20, 1);
    EXPECT_EQ(new_seq->GetLength(), 3);
    EXPECT_EQ(new_seq->Get(0), 10);
    EXPECT_EQ(new_seq->Get(1), 20);
    EXPECT_EQ(new_seq->Get(2), 30);
    EXPECT_EQ(seq.GetLength(), 2);
    
    delete new_seq;
    
    EXPECT_THROW(seq.InsertAt(99, -1), IndexOutOfRangeException);
    EXPECT_THROW(seq.InsertAt(99, 3), IndexOutOfRangeException);
}

TEST(ImmutableListSequenceOperations, Concat) {
    int a1[] = {1, 2};
    int a2[] = {3, 4, 5};
    ImmutableListSequence<int> seq1(a1, 2);
    ImmutableListSequence<int> seq2(a2, 3);
    
    Sequence<int>* concat = seq1.Concat(&seq2);
    EXPECT_EQ(concat->GetLength(), 5);
    EXPECT_EQ(concat->Get(0), 1);
    EXPECT_EQ(concat->GetLast(), 5);
    
    EXPECT_EQ(seq1.GetLength(), 2);
    EXPECT_EQ(seq2.GetLength(), 3);
    EXPECT_NE(concat, &seq1);
    EXPECT_NE(concat, &seq2);
    delete concat;
}

TEST(ImmutableListSequenceOperations, Concat_WithEmpty) {
    int arr[] = {10, 20};
    ImmutableListSequence<int> seq(arr, 2);
    ImmutableListSequence<int> empty;
    
    Sequence<int>* res1 = seq.Concat(&empty);
    EXPECT_EQ(res1->GetLength(), 2);
    delete res1;
    
    Sequence<int>* res2 = empty.Concat(&seq);
    EXPECT_EQ(res2->GetLength(), 2);
    delete res2;
}

TEST(ImmutableListSequenceOperations, GetSubsequence) {
    int arr[] = {10, 20, 30, 40, 50};
    ImmutableListSequence<int> seq(arr, 5);
    
    Sequence<int>* sub = seq.GetSubsequence(1, 3);
    ASSERT_NE(sub, nullptr);
    EXPECT_EQ(sub->GetLength(), 3);
    EXPECT_EQ(sub->Get(0), 20);
    EXPECT_EQ(sub->GetLast(), 40);
    EXPECT_EQ(seq.GetLength(), 5);
    EXPECT_NE(sub, &seq);
    delete sub;
    
    EXPECT_THROW(seq.GetSubsequence(-1, 2), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(0, 5), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(3, 1), IndexOutOfRangeException);
}

TEST(ImmutableListSequenceChaining, Operations) {
    ImmutableListSequence<int> seq;
    
    Sequence<int>* s1 = seq.Append(1);
    Sequence<int>* s2 = s1->Prepend(0);
    Sequence<int>* s3 = s2->InsertAt(5, 1);
    
    EXPECT_EQ(seq.GetLength(), 0);
    EXPECT_EQ(s1->GetLength(), 1);
    EXPECT_EQ(s2->GetLength(), 2);
    EXPECT_EQ(s3->GetLength(), 3);
    
    EXPECT_EQ(s3->Get(0), 0);
    EXPECT_EQ(s3->Get(1), 5);
    EXPECT_EQ(s3->Get(2), 1);
    
    delete s2;
    delete s3;
    delete s1;
    
    EXPECT_NO_THROW(seq.GetLength());
    EXPECT_EQ(seq.GetLength(), 0);
}

TEST(ImmutableListSequenceMemory, DeepCopy) {
    int a[] = {1, 2};
    ImmutableListSequence<int> seq(a, 2);
    seq.Append(1);

    int b[] = {3};
    ImmutableListSequence<int> other(b, 1);

    Sequence<int>* res = seq.Concat(&other);

    EXPECT_EQ(res->GetLength(), 3);
    EXPECT_EQ(seq.GetLength(), 2);
    EXPECT_EQ(other.GetLength(), 1);

    EXPECT_EQ(res->Get(0), 1);
    EXPECT_EQ(res->Get(1), 2);
    EXPECT_EQ(res->Get(2), 3);

    delete res;
}

TEST(ImmutableListSequenceExceptions, IndexOutOfRange) {
    ImmutableListSequence<int> seq;
    seq.Append(1); seq.Append(2);
    
    EXPECT_THROW(seq.Get(-1), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(-1, 1), IndexOutOfRangeException);
    
    EXPECT_THROW(seq.Get(2), IndexOutOfRangeException);
    EXPECT_THROW(seq.GetSubsequence(0, 2), IndexOutOfRangeException);
    
    ImmutableListSequence<int> empty;
    EXPECT_THROW(empty.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(empty.GetLast(), IndexOutOfRangeException);
    EXPECT_THROW(empty.Get(0), IndexOutOfRangeException);
}

TEST(ImmutableListSequenceTemplates, StringSequence_Immutable) {
    ImmutableListSequence<std::string> seq;
    Sequence<std::string>* s1 = seq.Append("Alpha");
    Sequence<std::string>* s2 = s1->Append("Beta");
    
    EXPECT_EQ(seq.GetLength(), 0);
    EXPECT_EQ(s2->GetLength(), 2);
    EXPECT_EQ(s2->Get(1), "Beta");
    EXPECT_EQ(s1->Get(0), "Alpha");
    EXPECT_NE(s1, s2);
    
    delete s1; delete s2;
}

TEST(ImmutableListSequenceTemplates, CustomStruct_Immutable) {
    struct Point { int x, y; };
    Point arr[] = {{1, 2}, {3, 4}};
    ImmutableListSequence<Point> seq(arr, 2);
    
    Sequence<Point>* s1 = seq.InsertAt({99, 99}, 1);
    EXPECT_EQ(s1->Get(1).x, 99);
    EXPECT_EQ(seq.Get(1).x, 3);
    
    delete s1;
}