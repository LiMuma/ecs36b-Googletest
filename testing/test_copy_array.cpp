#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[5]={1,2,3,4,5};
    int* copy_arr=copy_array(arr, 5);
    EXPECT_EQ(1, copy_arr[0]);
    EXPECT_EQ(2, copy_arr[1]);
    EXPECT_EQ(3, copy_arr[2]);
    EXPECT_EQ(4, copy_arr[3]);
    EXPECT_EQ(5, copy_arr[4]);
    free(copy_arr);
}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[5]={1,2,3,4,5};
    int* copy_arr=copy_array(arr, 5);
    copy_arr[2]=5;//check if the origional arry will be changed if change the copy.
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    free(copy_arr);
}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[5]={1,2,3,4,5};
    int* copy_arr=copy_array(arr, 5);
    EXPECT_NE(copy_arr, arr);
    for (int i = 0; i < 5; ++i) {
        EXPECT_NE(copy_arr+i, arr+i);
    }
    free(copy_arr);
}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = values.size();

    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    int* copy_arr = copy_array(arr, len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(copy_arr[i] == arr[i]);
    }
    free(copy_arr);
    free(arr);
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = values[i];
    }
    int* copy_arr = copy_array(arr, len);
    int random_index = *rc::gen::inRange<int>(0, len);
    copy_arr[random_index] = *rc::gen::inRange<int>(0, 999);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(arr[i] == values[i]);
    }

    free(copy_arr);
    free(arr);
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */
    int len = values.size();
    int* arr = (int*)malloc(len * sizeof(int));
    for (int i= 0; i< len; i++) {
        arr[i] = values[i];
    }
    int* copy_arr = copy_array(arr, len);
    for (int i = 0; i < len; i++) {
        RC_ASSERT(copy_arr+i != arr+i);
    }
    free(copy_arr);
    free(arr);
}