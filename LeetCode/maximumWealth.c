/*给你一个mxn的整数网格 accounts,其中accounts[i][j]是第i​​​​​​​​​​​​位客户在第j家银行托管的资产数量。返回最富有客户所拥有的资产总量 。
客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。

示例 1：

输入：accounts = [[1, 2, 3], [3, 2, 1]]
输出：6
解释：
第 1 位客户的资产总量 = 1 + 2 + 3 = 6
第 2 位客户的资产总量 = 3 + 2 + 1 = 6
两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
示例 2：

输入：accounts = [[1, 5], [7, 3], [3, 5]] 
输出：10
解释：
第 1 位客户的资产总量 = 6
第 2 位客户的资产总量 = 10
第 3 位客户的资产总量 = 8
第 2 位客户是最富有的，资产总量是 10
示例 3：

输入：accounts = [[2, 8, 7], [7, 1, 3], [1, 9, 5]]
输出：17


提示：

m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/richest-customer-wealth
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include"public.h"

/**
* 功能：给一个mxn的整数网格,其中[i][j]是第i​​​​​​​​​​​​位客户在第j家银行托管的资产数量，返回最富有客户所拥有的资产总量 。
* 返回值：一个整形数（最富有客户所拥有的资产总量）
* 参数：accounts原数据的二级指针，accountsSize二维数组的行个数，accountsColSize（int*类型）每一行的元素个数（列数）
* 
* 思路：
* 二层循环，第一层循环是行数，第二层每一行的列数
* 统计一行的和，然后和最大值比，然后更新最大值
* 最后返回最大值
*/
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
	int max = 0;
	for (int i = 0; i < accountsSize; i++) {
		int sum = 0;
		for (int j = 0; j < accountsColSize[i]; j++) {
			sum += accounts[i][j];
		}
		max = sum > max ? sum : max;
	}
	return max;
}