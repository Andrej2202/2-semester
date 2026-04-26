#include <gtest/gtest.h>
#include <string>
#include <Exceptions.hpp>
#include <LinkedList.hpp>

TEST(LinkedListConstructors, FromRawArray) {
    int arr[] = {10, 20, 30, 40};
    LinkedList<int> list(arr, 4);
    
    EXPECT_EQ(list.GetLength(), 4);
    EXPECT_EQ(list.Get(0), 10);
    EXPECT_EQ(list.Get(3), 40);
}

TEST(LinkedListConstructors, EmptyList) {
    LinkedList<int> list;
    EXPECT_EQ(list.GetLength(), 0);
    
    EXPECT_THROW(list.GetFirst(), IndexOutOfRangeException);
    EXPECT_THROW(list.GetLast(), IndexOutOfRangeException);
}

TEST(LinkedListConstructors, CopyConstructor_DeepCopy) {
    int arr[] = {1, 2, 3};
    LinkedList<int> original(arr, 3);
    LinkedList<int> copy(original);
    
    EXPECT_EQ(copy.GetLength(), 3);
    EXPECT_EQ(copy.Get(0), 1);
    EXPECT_EQ(copy.Get(2), 3);
}

TEST(LinkedListAccessors, GetFirst_GetLast_GetValid) {
    LinkedList<int> list;
    list.Prepend(20); list.Prepend(10); list.Append(30);
    
    EXPECT_EQ(list.GetLength(), 3);
    EXPECT_EQ(list.GetFirst(), 10);
    EXPECT_EQ(list.GetLast(), 30);
    EXPECT_EQ(list.Get(1), 20);
}

TEST(LinkedListAccessors, Get_InvalidIndices_Throw) {
    int arr[] = {1, 2};
    LinkedList<int> list(arr, 2);
    
    EXPECT_THROW(list.Get(-1), IndexOutOfRangeException);
    EXPECT_THROW(list.Get(2), IndexOutOfRangeException);
    EXPECT_THROW(list.Get(100), IndexOutOfRangeException);
}

TEST(LinkedListMutators, AppendAndPrepend_Order) {
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Prepend(0);
    
    EXPECT_EQ(list.GetLength(), 3);
    EXPECT_EQ(list.Get(0), 0);
    EXPECT_EQ(list.Get(1), 1);
    EXPECT_EQ(list.Get(2), 2);
}

TEST(LinkedListMutators, InsertAt_ValidIndices) {
    LinkedList<int> list;
    list.Append(10); list.Append(30);
    
    EXPECT_NO_THROW(list.InsertAt(15, 1));
    EXPECT_EQ(list.GetLength(), 3);
    EXPECT_EQ(list.Get(0), 10);
    EXPECT_EQ(list.Get(1), 15);
    EXPECT_EQ(list.Get(2), 30);
}

TEST(LinkedListMutators, InsertAt_InvalidThrows) {
    LinkedList<int> list;
    list.Append(1); list.Append(2);
    
    EXPECT_THROW(list.InsertAt(99, -1), IndexOutOfRangeException);
    EXPECT_THROW(list.InsertAt(99, 2), IndexOutOfRangeException);
    EXPECT_THROW(list.InsertAt(99, 5), IndexOutOfRangeException);
}

TEST(LinkedListOperations, GetSubList_ValidRange) {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList<int> list(arr, 5);
    
    LinkedList<int>* sub = list.GetSubList(1, 3);
    ASSERT_NE(sub, nullptr);
    EXPECT_EQ(sub->GetLength(), 3);
    EXPECT_EQ(sub->Get(0), 2);
    EXPECT_EQ(sub->Get(1), 3);
    EXPECT_EQ(sub->GetLast(), 4);
    
    delete sub;
}

TEST(LinkedListOperations, GetSubList_BoundaryAndSingle) {
    LinkedList<int> list;
    list.Append(10); list.Append(20); list.Append(30);
    
    LinkedList<int>* single = list.GetSubList(0, 0);
    EXPECT_EQ(single->GetLength(), 1);
    EXPECT_EQ(single->Get(0), 10);
    delete single;
    
    single = list.GetSubList(2, 2);
    EXPECT_EQ(single->Get(0), 30);
    delete single;
}

TEST(LinkedListOperations, GetSubList_InvalidThrows) {
    int arr[] = {1, 2, 3};
    LinkedList<int> list(arr, 3);
    
    EXPECT_THROW(list.GetSubList(-1, 2), IndexOutOfRangeException);
    EXPECT_THROW(list.GetSubList(0, 3), IndexOutOfRangeException);
    EXPECT_THROW(list.GetSubList(2, 1), IndexOutOfRangeException);
}

TEST(LinkedListOperations, Concat_BasicAndEmpty) {
    int a1[] = {1, 2};
    int a2[] = {3, 4, 5};
    LinkedList<int> list1(a1, 2);
    LinkedList<int> list2(a2, 3);
    LinkedList<int> empty;
    
    LinkedList<int>* concat = list1.Concat(&list2);
    ASSERT_NE(concat, nullptr);
    EXPECT_EQ(concat->GetLength(), 5);
    EXPECT_EQ(concat->Get(0), 1);
    EXPECT_EQ(concat->GetLast(), 5);
    delete concat;
    
    concat = list1.Concat(&empty);
    EXPECT_EQ(concat->GetLength(), 2);
    delete concat;
    
    concat = empty.Concat(&list1);
    EXPECT_EQ(concat->GetLength(), 2);
    delete concat;
}

TEST(LinkedListOperations, Concat_OriginalsIntact) {
    int a[] = {10, 20};
    LinkedList<int> list(a, 2);
    
    LinkedList<int>* res = list.Concat(&list);
    EXPECT_EQ(list.GetLength(), 2);
    EXPECT_EQ(res->GetLength(), 4);
    delete res;
}

TEST(LinkedListMemory, DeepCopyIndependence) {
    int arr[] = {1, 2, 3};
    LinkedList<int> original(arr, 3);
    LinkedList<int> copy(original);
    
    copy.Append(99);
    copy.Prepend(0);
    
    EXPECT_EQ(original.GetLength(), 3); 
    EXPECT_EQ(original.GetFirst(), 1);
    EXPECT_EQ(original.GetLast(), 3);
    
    EXPECT_EQ(copy.GetLength(), 5);
    EXPECT_EQ(copy.GetFirst(), 0);
    EXPECT_EQ(copy.GetLast(), 99);
}

TEST(LinkedListTemplates, StringSequence) {
    std::string arr[] = {"Alpha", "Beta", "Gamma"};
    LinkedList<std::string> list(arr, 3);
    
    EXPECT_EQ(list.GetFirst(), "Alpha");
    EXPECT_EQ(list.GetLast(), "Gamma");
    EXPECT_EQ(list.GetLength(), 3);
    
    list.Prepend("Zero");
    EXPECT_EQ(list.GetFirst(), "Zero");
    EXPECT_EQ(list.GetLength(), 4);
}

TEST(LinkedListTemplates, CustomStruct) {
    struct Point { int x, y; };
    Point arr[] = {{1, 2}, {3, 4}};
    LinkedList<Point> list(arr, 2);
    
    EXPECT_EQ(list.Get(0).x, 1);
    EXPECT_EQ(list.Get(1).y, 4);
    
    list.InsertAt({5, 5}, 1);
    EXPECT_EQ(list.Get(1).x, 5);
}