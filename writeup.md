# Google Test And Debugging Writeup

## Things I Thought To Test
1. See if we can find the index of the minimum value in an array.
2. See if we can swap two values and see if the swap was successful.
3. See if we can sort an array into ascending order.

## Bugs

### Bug 1

### Location

sorting.cpp Line 13.

```c++
make_sorted(ar, len);
```

### How the bug was located

Joanna and I worked together, and we made a mistake in the order of my task. I checked for errors by using the command "./SortInts 25 83 17 24", then manually fixed all the bugs and wrote the Google Test.

### Description

We need to sort the sorted_ar instead of the original one. Otherwise, the returned array will never be sorted.

### Fix 

I change the parameter in make_sorted from ar to sorted_ar so that the function will return the sorted array.

```c++
make_sorted(sorted_ar, len);
```

### Bug 2

### Location

Sorting.cpp Line 55.

```c++
if (ar[i] > ar[min_index]) {
```

### How the bug was located

Joanna and I worked together, and we made a mistake in the order of my task. I checked for errors by using the command "./SortInts 25 83 17 24", then manually fixed all the bugs and wrote the Google Test.

### Description

The purpose of this function is to find the minimum value. The judgment condition should be "less than"

### Fix

Change the sign "greater than" to "less than".

```c++
if (ar[i] < ar[min_index]) {
```

### Bug 3

### Location

sorting.cpp Line 59.

```c++
return ar[min_index];
```

### How the bug was located

Joanna and I worked together, and we made a mistake in the order of my task. I checked for errors by using the command "./SortInts 25 83 17 24", then manually fixed all the bugs and wrote the Google Test.

### Description

This function return the min value, instead of the min index of the array.

### Fix

Just return the min_index of the array.

```c++
return min_index;
```