/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例 :

输入: [0, 1, 0, 3, 12]
输出 : [1, 3, 12, 0, 0]
说明 :

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/move-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include"public.h"
//———————————    方法1    —————————————————————————    方法1    —————————————— 
/**
* 功能：交换一个数组内的部分元素
* 返回值：无（在原数组上进行交换）
* 参数：要进行操作的数组nums，从哪开始交换（俩俩交换）tail，数组的大小numsSize
* 思路：就是简单的俩俩交换
*/
void exchange(int* nums, int tail, int numsSize) {
	while (tail < numsSize - 1 && nums[tail + 1] != 0) {
		nums[tail] ^= nums[tail + 1];
		nums[tail + 1] ^= nums[tail];
		nums[tail] ^= nums[tail + 1];
		tail++;
	}
}

/**
* 功能：给定一个数组,编写一个函数将所有0移动到数组的末尾,同时保持非零元素的相对顺序
* 返回值：无
* 参数：要进行操作的数组nums，数组的大小numsSize
* 
* 思路：
* ①定义一个tail指向数组的最后一个元素
* ②给一个while循环，条件为：tail不能后移到越界
* 进入循环：
* ①如果tail指向的元素不是0，就一直后移
* ②如果tail指向0了，就将它所指的元素及其后面的所有元素，两两互换
*/
void moveZeroes_mine(int* nums, int numsSize) {
	int tail = numsSize - 1;
	while (tail >= 0) {
		if (nums[tail]) {
			tail--;
		}
		else {
			exchange(nums, tail, numsSize);
			tail--;
		}
	}
}
//———————————    方法2    —————————————————————————    方法2    —————————————— 




/**
* 功能：交换两个数
*/
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}


/**
* 功能：给定一个数组,编写一个函数将所有0移动到数组的末尾,同时保持非零元素的相对顺序
* 返回值：无
* 参数：要进行操作的数组nums，数组的大小numsSize
* 
* 思路：
* ①定义两个指针同时指向数组的首元素
* ②进入while循环，循环条件为：右指针不能大于数组的大小（最多走到最后一个元素）
* ③如果右指针遇到了非0元素，那么就把左指针和右指针的数进行交换，且把左指针+1.否则右指针+1
* 
* 注意：
* 如果开始几个元素全部都是非0的数字，那么就会一直自己和自己换，
* 直到遇到一个0，那么左指针右指针刚好都指向0，再过一次循环右指针就不指这个0了，剩下的就可以理解了
*/
void moveZeroes(int* nums, int numsSize) {
	int left = 0;
	int right = 0;
	while (right < numsSize) {
		if (nums[right] != 0) {
			swap(&nums[left], &nums[right]);//注意此处不能用异或交换，nums[left] ^= nums[right],当他们同时指向一个元素的时候，\
											一旦修改了就回不去了，所以用第三方变量进行交换
			left++;
		}
		right++;
	}
}



/*int main() {//测试代码块
	int nums[] = { 1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	moveZeroes(nums, numsSize);
	return 0;
}*/