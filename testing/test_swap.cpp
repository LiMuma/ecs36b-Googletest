#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 1, b = 2;
    swap(&a,&b);
    EXPECT_EQ(a,2);
    EXPECT_EQ(b,1);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
    int arr[5] = {2, 1, 3, 6, 5};
    swap(&arr[0],&arr[1]);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],3);
    EXPECT_EQ(arr[3],6);
    EXPECT_EQ(arr[4],5);
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = a_start, b = b_start;
    swap(&a,&b);
    RC_ASSERT(a == b_start);
    RC_ASSERT(b == a_start);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
    std::vector<int> arr = values;
    int len = values.size();

    int i = *rc::gen::inRange<int>(0, len);
    int j = *rc::gen::inRange<int>(0, len);
    RC_PRE(i != j);
    int i_before = arr[i];
    int j_before = arr[j];
    swap(&i_before,&j_before);
    RC_ASSERT(arr[i] == j_before);
    RC_ASSERT(arr[j] == i_before);
}
