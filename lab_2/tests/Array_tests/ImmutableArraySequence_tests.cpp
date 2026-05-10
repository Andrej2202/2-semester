#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <ArraySequence.hpp>
#include <ImmutableArraySequence.hpp>

TEST(ImmutableArraySequenceBasics, ConstructEmpty) {
    ImmutableArraySequence<int> seq;
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "ImmutableArraySequence<int> seq -> Length"
        << "\nexpected:" << "0";
    EXPECT_THROW(seq.GetFirst(), IndexOutOfRangeException)
        << "input:" << "ImmutableArraySequence<int> seq -> seq[0]"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.GetLast(), IndexOutOfRangeException)
        << "input:" << "ImmutableArraySequence<int> seq -> seq[0]"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.Get(0), IndexOutOfRangeException)
        << "input:" << "ImmutableArraySequence<int> seq -> seq[0]"
        << "\nexpected:" << "throws IndexOutOfRangeException";
}

TEST(ImmutableArraySequenceBasics, ConstructFromArray) {
    int arr[] = {10, 20, 30};
    ImmutableArraySequence<int> seq(arr, 3);
    EXPECT_EQ(seq.GetLength(), 3)
        << "input:" << "int arr[] = {10, 20, 30} -> ImmutableArraySequence<int> seq(arr, 3) -> Length"
        << "\nexpected:" << "3";
    EXPECT_EQ(seq.GetFirst(), 10)
        << "input:" << "int arr[] = {10, 20, 30} -> ImmutableArraySequence<int> seq(arr, 3) -> seq[0]"
        << "\nexpected:" << "3";
    EXPECT_EQ(seq.GetLast(), 30)
        << "input:" << "int arr[] = {10, 20, 30} -> ImmutableArraySequence<int> seq(arr, 3) -> seq[2]"
        << "\nexpected:" << "3";
    EXPECT_NO_THROW(seq.Get(1))
        << "input:" << "int arr[] = {10, 20, 30} -> ImmutableArraySequence<int> seq(arr, 3) -> seq[1]"
        << "\nexpected:" << "3";
}

TEST(ImmutableArraySequenceOps, Append) {
    ImmutableArraySequence<int> seq;
    Sequence<int>* new_seq = seq.Append(42);
    ASSERT_NE(new_seq, nullptr)
        << "input:" << "ImmutableArraySequence<int> seq -> Sequence<int>* new_seq = seq.Append(42) -> pointer to new_seq"
        << "\nexpected:" << "new_seq != nullptr";
    EXPECT_NE(new_seq, &seq)
        << "input:" << "ImmutableArraySequence<int> seq -> Sequence<int>* new_seq = seq.Append(42) -> pointer to new_seq"
        << "\nexpected:" << "new_seq == &seq";
    EXPECT_EQ(new_seq->GetLength(), 1)
        << "input:" << "ImmutableArraySequence<int> seq -> Sequence<int>* new_seq = seq.Append(42) -> new_seq length"
        << "\nexpected:" << "1";
    EXPECT_EQ(new_seq->Get(0), 42)
        << "input:" << "ImmutableArraySequence<int> seq -> Sequence<int>* new_seq = seq.Append(42) -> seq[0]"
        << "\nexpected:" << "42";
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "ImmutableArraySequence<int> seq -> Sequence<int>* new_seq = seq.Append(42) -> seq length"
        << "\nexpected:" << "0";
    delete new_seq;
}

TEST(ImmutableArraySequenceOps, Prepend) {
    int arr[] = {2, 3};
    ImmutableArraySequence<int> seq(arr, 2);
    Sequence<int>* new_seq = seq.Prepend(1);
    EXPECT_EQ(new_seq->GetLength(), 3)
        << "input:" << "int arr[] = {2, 3} -> ImmutableArraySequence<int> seq(arr, 2) -> Sequence<int>* new_seq = seq.Prepend(1) -> new length"
        << "\nexpected:" << "3";
    EXPECT_EQ(new_seq->Get(0), 1)
        << "input:" << "int arr[] = {2, 3} -> ImmutableArraySequence<int> seq(arr, 2) -> Sequence<int>* new_seq = seq.Prepend(1) -> new seq[0]"
        << "\nexpected:" << "1";
    EXPECT_EQ(new_seq->Get(1), 2)
        << "input:" << "int arr[] = {2, 3} -> ImmutableArraySequence<int> seq(arr, 2) -> Sequence<int>* new_seq = seq.Prepend(1) -> new seq[1]"
        << "\nexpected:" << "2";
    EXPECT_EQ(seq.GetLength(), 2)
        << "input:" << "int arr[] = {2, 3} -> ImmutableArraySequence<int> seq(arr, 2) -> Sequence<int>* new_seq = seq.Prepend(1) -> seq length"
        << "\nexpected:" << "2";
    delete new_seq;
}

TEST(ImmutableArraySequenceOps, InsertAt) {
    int arr[] = {10, 30};
    ImmutableArraySequence<int> seq(arr, 2);
    Sequence<int>* new_seq = seq.InsertAt(20, 1);
    EXPECT_EQ(new_seq->GetLength(), 3)
        << "input:" << "new_seq->GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(new_seq->Get(0), 10)
        << "input:" << "new_seq->Get(0)"
        << "\nexpected:" << "10";
    EXPECT_EQ(new_seq->Get(1), 20)
        << "input:" << "new_seq->Get(1)"
        << "\nexpected:" << "20";
    EXPECT_EQ(new_seq->Get(2), 30)
        << "input:" << "new_seq->Get(2)"
        << "\nexpected:" << "30";
    EXPECT_EQ(seq.GetLength(), 2)
        << "input:" << "seq.GetLength() after InsertAt"
        << "\nexpected:" << "2 (original unchanged)";
    delete new_seq;
    EXPECT_THROW(seq.InsertAt(99, -1), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(99, -1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.InsertAt(99, 2), IndexOutOfRangeException)
        << "input:" << "seq.InsertAt(99, 2)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
}

TEST(ImmutableArraySequenceOps, Concat) {
    int a1[] = {1, 2};
    int a2[] = {3, 4, 5};
    ImmutableArraySequence<int> seq1(a1, 2);
    ImmutableArraySequence<int> seq2(a2, 3);
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
    EXPECT_EQ(seq1.GetLength(), 2)
        << "input:" << "seq1.GetLength() after Concat"
        << "\nexpected:" << "2";
    EXPECT_EQ(seq2.GetLength(), 3)
        << "input:" << "seq2.GetLength() after Concat"
        << "\nexpected:" << "3";
    EXPECT_NE(concat, &seq1)
        << "input:" << "concat vs &seq1"
        << "\nexpected:" << "concat != &seq1";
    EXPECT_NE(concat, &seq2)
        << "input:" << "concat vs &seq2"
        << "\nexpected:" << "concat != &seq2";
    delete concat;
}

TEST(ImmutableArraySequenceOps, GetSubsequence) {
    int arr[] = {10, 20, 30, 40, 50};
    ImmutableArraySequence<int> seq(arr, 5);
    Sequence<int>* sub = seq.GetSubsequence(1, 3);
    EXPECT_EQ(sub->GetLength(), 3)
        << "input:" << "sub->GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(sub->Get(0), 20)
        << "input:" << "sub->Get(0)"
        << "\nexpected:" << "20";
    EXPECT_EQ(sub->GetLast(), 40)
        << "input:" << "sub->GetLast()"
        << "\nexpected:" << "40";
    EXPECT_EQ(seq.GetLength(), 5)
        << "input:" << "seq.GetLength() after GetSubsequence"
        << "\nexpected:" << "5 (original unchanged)";
    EXPECT_NE(sub, &seq)
        << "input:" << "sub vs &seq"
        << "\nexpected:" << "sub != &seq";
    delete sub;
    EXPECT_THROW(seq.GetSubsequence(-1, 2), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(-1, 2)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.GetSubsequence(0, 5), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(0, 5)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
    EXPECT_THROW(seq.GetSubsequence(3, 1), IndexOutOfRangeException)
        << "input:" << "seq.GetSubsequence(3, 1)"
        << "\nexpected:" << "throws IndexOutOfRangeException";
}

TEST(ImmutableArraySequenceMemory, DeepCopyIndependence) {
    ImmutableArraySequence<int> original;
    Sequence<int>* step1 = original.Append(10);
    Sequence<int>* step2 = step1->Append(20);
    Sequence<int>* step3 = step2->Append(30);
    EXPECT_EQ(original.GetLength(), 0)
        << "input:" << "original.GetLength()"
        << "\nexpected:" << "0";
    EXPECT_EQ(step1->GetLength(), 1)
        << "input:" << "step1->GetLength()"
        << "\nexpected:" << "1";
    EXPECT_EQ(step2->GetLength(), 2)
        << "input:" << "step2->GetLength()"
        << "\nexpected:" << "2";
    EXPECT_EQ(step3->GetLength(), 3)
        << "input:" << "step3->GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(step3->Get(0), 10)
        << "input:" << "step3->Get(0)"
        << "\nexpected:" << "10";
    EXPECT_EQ(step3->Get(1), 20)
        << "input:" << "step3->Get(1)"
        << "\nexpected:" << "20";
    EXPECT_EQ(step3->Get(2), 30)
        << "input:" << "step3->Get(2)"
        << "\nexpected:" << "30";
    delete step2;
    delete step3;
    delete step1;
    EXPECT_NO_THROW(original.GetLength())
        << "input:" << "original.GetLength() after deletes"
        << "\nexpected:" << "no throw";
    EXPECT_EQ(original.GetLength(), 0)
        << "input:" << "original.GetLength() final"
        << "\nexpected:" << "0";
}

TEST(ImmutableArraySequenceOps, ChainingOperations) {
    ImmutableArraySequence<int> seq;
    Sequence<int>* s1 = seq.Append(1);
    Sequence<int>* s2 = s1->Prepend(0);
    Sequence<int>* s3 = s2->InsertAt(5, 1);
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "0";
    EXPECT_EQ(s1->GetLength(), 1)
        << "input:" << "s1->GetLength()"
        << "\nexpected:" << "1";
    EXPECT_EQ(s2->GetLength(), 2)
        << "input:" << "s2->GetLength()"
        << "\nexpected:" << "2";
    EXPECT_EQ(s3->GetLength(), 3)
        << "input:" << "s3->GetLength()"
        << "\nexpected:" << "3";
    EXPECT_EQ(s3->Get(0), 0)
        << "input:" << "s3->Get(0)"
        << "\nexpected:" << "0";
    EXPECT_EQ(s3->Get(1), 5)
        << "input:" << "s3->Get(1)"
        << "\nexpected:" << "5";
    EXPECT_EQ(s3->Get(2), 1)
        << "input:" << "s3->Get(2)"
        << "\nexpected:" << "1";
    delete s1;
    delete s2;
    delete s3;
}

TEST(ImmutableArraySequenceTemplates, StringSequence) {
    ImmutableArraySequence<std::string> seq;
    Sequence<std::string>* s1 = seq.Append("Alpha");
    Sequence<std::string>* s2 = s1->Append("Beta");
    EXPECT_EQ(seq.GetLength(), 0)
        << "input:" << "seq.GetLength()"
        << "\nexpected:" << "0";
    EXPECT_EQ(s2->GetLength(), 2)
        << "input:" << "s2->GetLength()"
        << "\nexpected:" << "2";
    EXPECT_EQ(s2->Get(1), "Beta")
        << "input:" << "s2->Get(1)"
        << "\nexpected:" << "\"Beta\"";
    EXPECT_EQ(s1->Get(0), "Alpha")
        << "input:" << "s1->Get(0)"
        << "\nexpected:" << "\"Alpha\"";
    delete s1;
    delete s2;
}

TEST(ImmutableArraySequenceTemplates, PointSequence) {
    struct Point { int x, y; };
    Point raw[] = {{1, 2}, {3, 4}};
    ImmutableArraySequence<Point> s1(raw, 2);
    EXPECT_EQ(s1.Get(0).x, 1)
        << "input:" << "s1.Get(0).x"
        << "\nexpected:" << "1";
    EXPECT_EQ(s1.Get(1).y, 4)
        << "input:" << "s1.Get(1).y"
        << "\nexpected:" << "4";
}