#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <ArraySequence.hpp>
#include "SuperUnicPointer.hpp"
#include <MutableArraySequence.hpp>

TEST(MutableArraySequenceTest, AppendPrependInsertAt) {
    MutableArraySequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "0";
    seq.Append(10);
    seq.Append(20);
    seq.Prepend(0);
    seq.InsertAt(99, 2);
    EXPECT_EQ(seq.GetLength(), 4)
        << "input:" << "seq.GetLength() after ops"
        << "\nexpected:" << "4";
    EXPECT_EQ(seq.Get(0), 0)
        << "input:" << "seq.Get(0)"
        << "\nexpected:" << "0";
    EXPECT_EQ(seq.Get(1), 10)
        << "input:" << "seq.Get(1)"
        << "\nexpected:" << "10";
    EXPECT_EQ(seq.Get(2), 99)
        << "input:" << "seq.Get(2)"
        << "\nexpected:" << "99";
    EXPECT_EQ(seq.Get(3), 20)
        << "input:" << "seq.Get(3)"
        << "\nexpected:" << "20";
}

TEST(MutableArraySequenceTest, ReturnsThis) {
    MutableArraySequence<int> seq;
    Sequence<int>* res = seq.Append(42);
    EXPECT_EQ(res, &seq)
        << "input:" << "res vs &seq"
        << "\nexpected:" << "res == &seq (mutable returns self)";
    EXPECT_EQ(seq.GetLength(), 1)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "1";
}

TEST(MutableArraySequenceTest, InsertAt_Invalid) {
    MutableArraySequence<int> seq;
    seq.Append(10);
    seq.Append(20);
    EXPECT_NO_THROW(seq.InsertAt(99, 1))
        << "input:" << "seq.InsertAt(99, 1)"
        << "\nexpected:" << "no throw";
    EXPECT_EQ(seq.GetLength(), 3)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(seq.Get(0), 10)
        << "input:" << "seq.Get(0)"
        << "\nexpected:" << "10";
    EXPECT_EQ(seq.Get(1), 99)
        << "input:" << "seq.Get(1)"
        << "\nexpected:" << "99";
    EXPECT_NO_THROW(seq.InsertAt(55, 2))
        << "input:" << "seq.InsertAt(55, 2)"
        << "\nexpected:" << "no throw";
    EXPECT_EQ(seq.GetLength(), 4)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "4";
    EXPECT_EQ(seq.Get(2), 55)
        << "input:" << "seq.Get(2)"
        << "\nexpected:" << "55";
    EXPECT_EQ(seq.Get(3), 20)
        << "input:" << "seq.Get(3)"
        << "\nexpected:" << "20";
    EXPECT_THROW(seq.InsertAt(10, -1), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(10, -1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.InsertAt(10, 4), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(10, 4)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.InsertAt(10, 100), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(10, 100)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
}

TEST(SequenceOpsTest, GetSubsequence_ValidRange) {
    int arr[] = {1, 2, 3, 4, 5};
    MutableArraySequence<int> seq(arr, 5);
    Sequence<int>* sub = seq.GetSubsequence(1, 3);
    ASSERT_NE(sub, nullptr)
        << "input:" << "seq.GetSubsequence(1, 3)"
        << "\nexpected:" << "sub != nullptr";
    EXPECT_EQ(sub->GetLength(), 3)
        << "input:" << "sub->GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(sub->Get(0), 2)
        << "input:" << "sub->Get(0)"
        << "\nexpected:" << "2";
    EXPECT_EQ(sub->Get(1), 3)
        << "input:" << "sub->Get(1)"
        << "\nexpected:" << "3";
    EXPECT_EQ(sub->Get(2), 4)
        << "input:" << "sub->Get(2)"
        << "\nexpected:" << "4";
    delete sub;
}

TEST(SequenceOpsTest, GetSubsequence_BoundaryAndSingleElement) {
    MutableArraySequence<int> seq;
    seq.Append(10);
    seq.Append(20);
    seq.Append(30);
    
    SuperUnicPointer<Sequence<int>> sub(seq.GetSubsequence(0, 0));
    EXPECT_EQ(sub->GetLength(), 1)
        << "input:" << "sub->GetLength()"
        << "\nexpected:" << "1";
    EXPECT_EQ(sub->Get(0), 10)
        << "input:" << "sub->Get(0)"
        << "\nexpected:" << "10";
        
    sub = SuperUnicPointer<Sequence<int>>(seq.GetSubsequence(2, 2));
    EXPECT_EQ(sub->Get(0), 30)
        << "input:" << "sub->Get(0)"
        << "\nexpected:" << "30";
}

TEST(SequenceOpsTest, GetSubsequence_InvalidThrows) {
    int arr[] = {1, 2, 3};
    MutableArraySequence<int> seq(arr, 3);
    EXPECT_THROW(seq.GetSubsequence(-1, 2), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(-1, 2)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.GetSubsequence(0, 3), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(0, 3)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.GetSubsequence(2, 1), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(2, 1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
}

TEST(SequenceOpsTest, Concat_BasicAndEmpty) {
    int a1[] = {1, 2};
    int a2[] = {3, 4, 5};
    MutableArraySequence<int> seq1(a1, 2);
    MutableArraySequence<int> seq2(a2, 3);
    MutableArraySequence<int> empty;
    
    Sequence<int>* concat = seq1.Concat(&seq2);
    EXPECT_EQ(concat->GetLength(), 5)
        << "input:" << "concat->GetLength()"
        << "\nexpected:" << "5";
    EXPECT_EQ(concat->Get(0), 1)
        << "input:" << "concat->Get(0)"
        << "\nexpected:" << "1";
    EXPECT_EQ(concat->GetLast(), 5)
        << "input:" << "concat->GetLast()"
        << "\nexpected:" << "5";
    delete concat;
    
    concat = seq1.Concat(&empty);
    EXPECT_EQ(concat->GetLength(), 2)
        << "input:" << "concat->GetLength()"
        << "\nexpected:" << "2";
    delete concat;
    
    concat = empty.Concat(&seq1);
    EXPECT_EQ(concat->GetLength(), 2)
        << "input:" << "concat->GetLength()"
        << "\nexpected:" << "2";
    delete concat;
}

TEST(SequenceOpsTest, Concat_NullPtr) {
    MutableArraySequence<int> seq;
    seq.Append(1);
    EXPECT_THROW(seq.Concat(nullptr), InvalidArgumentException)
        << "input:" << "seq.Concat(nullptr)"
        << "\nexpected:" << "throws InvalidArgumentException";
}

TEST(SequenceExceptionsTest, EmptyOrOutOfRange) {
    MutableArraySequence<int> seq;
    seq.Append(42);
    EXPECT_THROW(seq.Get(-1), IndexOutOfRangeException)
        << "input:" << "seq.Get(-1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.Get(1), IndexOutOfRangeException)
        << "input:" << "seq.Get(1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.InsertAt(10, 5), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(10, 5)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
        
    Sequence<int>* empty = new MutableArraySequence<int>();
    EXPECT_THROW(empty->GetFirst(), IndexOutOfRangeException)
        << "input:" << "empty->GetFirst()"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(empty->GetLast(), IndexOutOfRangeException)
        << "input:" << "empty->GetLast()"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(empty->Get(0), IndexOutOfRangeException)
        << "input:" << "empty->Get(0)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    delete empty;
}

TEST(MutableArraySequenceTemplates, PointSequence) {
    struct Point { int x, y; };
    Point raw[] = {{1, 2}, {3, 4}};
    MutableArraySequence<Point> s1(raw, 2);
    EXPECT_EQ(s1.Get(0).x, 1)
        << "input:" << "s1.Get(0).x"
        << "\nexpected:" << "1";
    EXPECT_EQ(s1.Get(1).y, 4)
        << "input:" << "s1.Get(1).y"
        << "\nexpected:" << "4";
}