/*给定一个无重复元素的有序整数数组 nums 。
返回恰好覆盖数组中所有数字的最小有序区间范围列表。也就是说，nums的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于nums的数字x 。
列表中的每个区间范围[a, b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b


示例 1：

输入：nums = [0, 1, 2, 4, 5, 7]
输出：["0->2", "4->5", "7"]
解释：区间范围是：
[0, 2] -- > "0->2"
[4, 5] -- > "4->5"
[7, 7] -- > "7"
示例 2：

输入：nums = [0, 2, 3, 4, 6, 8, 9]
输出：["0", "2->4", "6", "8->9"]
解释：区间范围是：
[0, 0] -- > "0"
[2, 4] -- > "2->4"
[6, 6] -- > "6"
[8, 9] -- > "8->9"
示例 3：

输入：nums = []
输出：[]
示例 4：

输入：nums = [-1]
输出：["-1"]
示例 5：

输入：nums = [0]
输出：["0"]


提示：

0 <= nums.length <= 20
- 231 <= nums[i] <= 231 - 1
nums 中的所有值都 互不相同

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/summary-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


#include"public.h"

//———————————    方法1    —————————————————————————    方法1    —————————————————————————    方法1    ——————————————

void write(int* nums, int l, int r, char** ret, int now) {//写入函数
	if (l != r) {
		ret[now] = (char*)malloc(sizeof(char) * 5);
		ret[now][0] = '0' + nums[l];
		ret[now][1] = '-';
		ret[now][2] = '>';
		ret[now][3] = '0' + nums[r];
		ret[now][4] = '\0';
		return;
	}
	else {
		ret[now] = (char*)malloc(sizeof(char) * 2);
		ret[now][0] = '0' + nums[l];
		ret[now][1] = '\0';
		return;
	}
}


/**
 * 功能，返回值，参数见方法2
 * 
 * 思路：（谨以此纪念我的思路）
 * 功能并未实现，方法太过暴力且啰嗦，添加过多的if
 * 在调用write函数（自己实现）的时候，只能写入一位的十进制数字
 */
char** summaryRanges_mine(int* nums, int numsSize, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * numsSize);
	int l = 0, r = 1, now = 0;

	if (numsSize == 1) {
		*returnSize = 1;
		write(nums, 0, 0, ret, now);
		return realloc(ret, sizeof(char*) * 1);
	}

	if (numsSize == 0) {
		return NULL;
	}


	while (r < numsSize) {
		if (nums[r] == (nums[r - 1] + 1) && r != numsSize - 1) {
			r++;
		}
		else{
			write(nums, l, r - 1, ret, now);
			now++, r++;
			l = r - 1;
		}
		if (r == numsSize - 1) {
			if (nums[r] == (nums[r - 1] + 1)) {
				write(nums, l, r, ret, now);
				now++;
			}
			else {
				write(nums, l, r - 1, ret, now);
				now++;
				write(nums, r, r, ret, now);
			}
		}
	}
	*returnSize = now;
	return realloc(ret, sizeof(char*) * now);
}


//———————————    方法2    —————————————————————————    方法2    —————————————————————————    方法2    ——————————————

/**
* 功能：输入：nums = [0, 2, 3, 4, 6, 8, 9]；输出：["0", "2->4", "6", "8->9"]
* 返回值：一个char**（内部元素为char*指向一个字符串）
* 参数：nums：输入的整形数组
*		numsSize：数组的元素个数
*		returnSize：返回的数组的元素个数（char*的个数或者是字符串的个数）
* 
* 思路：
* ①首先开辟一个元素个数和整形数组一样大小的char*数组（假设每一个元素都是单独的不连续的）
* ②定义：left左指针，right右指针，now现在有多少个字符串；
* 思想：
* 定义一个循环，第一步：让左指针和右指针指向一样的单元，然后一直往后找一个元素，该元素的下一元素和该元素不连续，直到找到一个符合要求的元素
* 第二步：如果左右指针指向同一个元素，那么就开辟空间，然后使用sprintf写入，否则就写入另外一种格式%d->%d
* 最后给*returnSize赋值,然后返回新开辟的指针
*/
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * numsSize);
	int left = 0;
	int right = 0;
	int now = 0;

	for (; right < numsSize; right++) {
		left = right;
		while (right < numsSize - 1 && (nums[right] + 1) == nums[right + 1]) {
			right++;
		}

		if (left == right) {
			ret[now] = (char*)calloc(30, sizeof(char));
			sprintf(ret[now++], "%d", nums[left]);
		}
		else {
			ret[now] = (char*)calloc(30, sizeof(char));
			sprintf(ret[now++], "%d->%d", nums[left], nums[right]);
		}
	}
	*returnSize = now ;
	return ret;
}





//int main() {//测试代码模块
//	int nums[] = { 0, 1, 2, 4, 5, 7 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int returnSize = 0;
//	char** sss = summaryRanges(nums, numsSize, &returnSize);
//
//	return 0;
//}


