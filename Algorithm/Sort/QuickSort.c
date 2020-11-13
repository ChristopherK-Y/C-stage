/**
* ���ܣ���һ�������������򣬴�С����
* ����ֵ����
* ������int* arr(����ָ��)ΪĿ������
*		int leftΪ����ʱѡ�������߱�
*		int rightΪ����ʱѡ������ұ��±�־
*/
void quickSort(int* arr, int left, int right) {
	if (left < right) {
		//Swap(s[left], s[(left + right) / 2]); //���м��������͵�һ��������(���Ի�һ��˼·���ܼ�)
		int l = left; int r = right; int X = arr[l];
		while (l < r) {
			while (l < r && arr[r] >= X) {//������������һ����X��С����
				r--;
			}

			if (l < r) {
				arr[l++] = arr[r];
			}

			while (l < r && arr[l] < X) {//������������һ�����ڵ���X����
				l++;
			}

			if (l < r) {
				arr[r--] = arr[l];
			}
		}
		arr[l] = X;//���ִ�е���һ����һ����l=r��������i��r���±궼��һ����
		quickSort(arr, left, l - 1);//�ݹ�ִ��ǰ���
		quickSort(arr, l + 1, right);//�ݹ�ִ�к���
	}
}