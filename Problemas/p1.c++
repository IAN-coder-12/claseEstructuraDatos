//Ian Hernández Hernández
//A01276755
#include <vector>
#include <iostream>
using namespace std;

// 75. Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1]) {
				int aux = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = aux;
			}
		}
	}
    }
};