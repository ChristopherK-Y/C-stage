/**
* 功能：对一个整形数组排序，从小到大
* 返回值：无
* 参数：int* arr(数组指针)为目标数组
*		int left为排序时选则的最左边标
*		int right为排序时选择的最右边下标志
*/
void quickSort(int* arr, int left, int right) {
	if (left < right) {
		//Swap(s[left], s[(left + right) / 2]); //将中间的这个数和第一个数交换(可以换一种思路，很简单)
		int l = left; int r = right; int X = arr[l];
		while (l < r) {
			while (l < r && arr[r] >= X) {//从右往左挑出一个比X大小的数
				r--;
			}

			if (l < r) {
				arr[l++] = arr[r];
			}

			while (l < r && arr[l] < X) {//从左往右挑出一个大于等于X的数
				l++;
			}

			if (l < r) {
				arr[r--] = arr[l];
			}
		}
		arr[l] = X;//最后执行到这一步，一定是l=r，所以用i和r的下标都是一样的
		quickSort(arr, left, l - 1);//递归执行前半段
		quickSort(arr, l + 1, right);//递归执行后半段
	}
}