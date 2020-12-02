/*给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums[i] = nums[j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:
输入: nums = [1, 2, 3, 1], k = 3
输出 : true

示例 2 :
输入 : nums = [1, 0, 1, 1], k = 1
输出 : true

示例 3 :
输入 : nums = [1, 2, 3, 1, 2, 3], k = 2
输出 : false

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include"public.h"

typedef enum{false,true}bool;


//———————————    方法1    —————————————————————————    方法1    —————————————————————————    方法1    ——————————————
/**
* 功能：给定整数数组和一个整数k,判断是否存在两个不同的索引i和j,使得nums[i]=nums[j],并且i和j的差的绝对值至多为k
* 返回值：bool类型的ture或者false
* 参数：原整形数组，数组的元素个数，和一个k值
* 
* 思路：
* 两层for循环：
* ①第一层：first指针从0开始到倒数第二个元素
* ②第二层：second指针从first的下一个开始到first以后的k个或者倒数第一个元素即停止
* 如果找到，则返回true
* 最后返回false
*/
bool containsNearbyDuplicate_one(int* nums, int numsSize, int k) {
	for (int first = 0; first < numsSize - 1; first++) {
		for (int second = first + 1; second < numsSize && second <= first + k; second++) {
			if (nums[first] == nums[second]) {
				return true;
			}
		}
	}
	return false;
}

//———————————    方法2    —————————————————————————    方法2    —————————————————————————    方法2    ——————————————
typedef struct node {//结构体定义
	int value;//值
	int index;//下标
}node;

int compare(const void* xp, const void* yp) {//qosrt中，对于结构体的排序
	node* x = (node*)xp;
	node* y = (node*)yp;
	if (x->value > y->value) {
		return 1;
	}
	else if (x->value < y->value) {
		return -1;
	}
	else {
		return 0;
	}
}


/**
* 功能：给定整数数组和一个整数k,判断是否存在两个不同的索引i和j,使得nums[i]=nums[j],并且i和j的差的绝对值至多为k
* 返回值：bool类型的ture或者false
* 参数：原整形数组，数组的元素个数，和一个k值
* 
* 思路：
* ①首先把整个数组存入结构体,然后使用qsort进行排序（相同的元素就会被扎堆放在一起）
* ②单层for循环：
*	从下标0开始，在结构体数组中查找有没有挨着的两个元素的value一样
*	如果一样就看下标的差值是否在k值内，如果在就直接返回true
*	否则就继续循环，直到循环截止，就返回false
*/
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	node* numss = (node*)malloc(sizeof(node) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		numss[i].index = i;
		numss[i].value = nums[i];
	}
	qsort(numss, numsSize, sizeof(node), compare);
	for (int i = 0; i < numsSize - 1; i++) {
		if (numss[i].value != numss[i + 1].value) {
			continue;
		}
		else {
			if (abs(numss[i + 1].index - numss[i].index) <= k) {
				free(numss);
				return true;
			}
		}
	}
	free(numss);
	return false;
}