#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int arr[] = {1, 2, 3, 4, 5};
    int min_index = min_index_of_array(arr, 5);
    EXPECT_EQ(0, min_index);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int arr[] = {5, 2, 3, 4, 1};
    int min_index = min_index_of_array(arr, 5);
    EXPECT_EQ(4, min_index);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int arr[] = {2, 1, 3, 4, 5};
    int min_index = min_index_of_array(arr, 5);
    EXPECT_EQ(1, min_index);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int arr[] = {2, 1, 1, 3, 4, 5};
    int min_index = min_index_of_array(arr, 6);
    EXPECT_EQ(1, min_index);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int arr[] = {2, 1, 3, 4, 5, 1};
    int min_index = min_index_of_array(arr, 6);
    EXPECT_EQ(1, min_index);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
    EXPECT_EQ(arr[5], 1);
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ( std::vector<int> values)) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    int min_index = min_index_of_array(arr, len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(arr[min_index] <= arr[i]);
    }
    free(arr);
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ( std::vector<int> values)) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    int* original = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
        original[i] = values[i];
    }
    min_index_of_array(arr, len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(arr[i] == original[i]);
    }
    free(arr);
    free(original);
}
