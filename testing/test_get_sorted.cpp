#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {1, 2, 3, 4, 5, 6};
    int* sorted_arr = get_sorted(arr,6);
    EXPECT_EQ(sorted_arr[0],1);
    EXPECT_EQ(sorted_arr[1],2);
    EXPECT_EQ(sorted_arr[2],3);
    EXPECT_EQ(sorted_arr[3],4);
    EXPECT_EQ(sorted_arr[4],5);
    EXPECT_EQ(sorted_arr[5],6);
    free(sorted_arr);
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {6, 5, 4, 3, 2, 1};
    int* sorted_arr = get_sorted(arr,6);
    EXPECT_EQ(sorted_arr[0],1);
    EXPECT_EQ(sorted_arr[1],2);
    EXPECT_EQ(sorted_arr[2],3);
    EXPECT_EQ(sorted_arr[3],4);
    EXPECT_EQ(sorted_arr[4],5);
    EXPECT_EQ(sorted_arr[5],6);
    free(sorted_arr);
}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {2, 1, 4, 3, 6, 5};
    int* sorted_arr = get_sorted(arr,6);
    EXPECT_EQ(sorted_arr[0],1);
    EXPECT_EQ(sorted_arr[1],2);
    EXPECT_EQ(sorted_arr[2],3);
    EXPECT_EQ(sorted_arr[3],4);
    EXPECT_EQ(sorted_arr[4],5);
    EXPECT_EQ(sorted_arr[5],6);
    free(sorted_arr);
}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {2, 1, 4, 3, 6, 5, 1, 3};
    int* sorted_arr = get_sorted(arr,8);
    EXPECT_EQ(sorted_arr[0],1);
    EXPECT_EQ(sorted_arr[1],1);
    EXPECT_EQ(sorted_arr[2],2);
    EXPECT_EQ(sorted_arr[3],3);
    EXPECT_EQ(sorted_arr[4],3);
    EXPECT_EQ(sorted_arr[5],4);
    EXPECT_EQ(sorted_arr[6],5);
    EXPECT_EQ(sorted_arr[7],6);
    free(sorted_arr);
}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {2, 1, 4, 3, 6, 5, 1, 3};
    int* sorted_arr = get_sorted(arr,8);
    EXPECT_EQ(arr[0],2);
    EXPECT_EQ(arr[1],1);
    EXPECT_EQ(arr[2],4);
    EXPECT_EQ(arr[3],3);
    EXPECT_EQ(arr[4],6);
    EXPECT_EQ(arr[5],5);
    EXPECT_EQ(arr[6],1);
    EXPECT_EQ(arr[7],3);
    free(sorted_arr);
}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] =  {1, 2, 3};
    int* sorted_arr = get_sorted(arr,3);
    for (int i = 0; i < 3; i++) {
        EXPECT_NE(arr+i, sorted_arr+i);
    }
    free(sorted_arr);
}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    int* sorted_arr = get_sorted(arr,len);
    for (int i = 0; i + 1 < len; i++) {
        RC_ASSERT(sorted_arr[i] <= sorted_arr[i + 1]);
    }
    free(sorted_arr);
    free(arr);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];

    }
    int* sorted_arr = get_sorted(arr,len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(values[i] == arr[i]);
    }
    free(arr);
    free(sorted_arr);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    int* sorted_arr = get_sorted(arr,len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(sorted_arr + i != arr + i);
    }
    free(arr);
    free(sorted_arr);
}