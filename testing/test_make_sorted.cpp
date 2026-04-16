#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1, 2, 3, 4, 5};
    make_sorted(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {5, 4, 3, 2, 1};
    make_sorted(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {2, 1, 5, 3, 4};
    make_sorted(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {2, 1, 4, 1, 5, 3, 4};
    make_sorted(arr, 7);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 4);
    EXPECT_EQ(arr[5], 4);
    EXPECT_EQ(arr[6], 5);
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    make_sorted(arr, len);
    for (int i = 0; i + 1 < len; i++) {
        RC_ASSERT(arr[i] <= arr[i+1]);
    }
    free(arr);
}
