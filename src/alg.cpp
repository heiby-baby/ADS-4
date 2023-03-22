// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int i = 0; i < right; i++) {
    for (int j = right; j > i; j--) {
      if ((arr[i] + arr[j]) == value) {
        counter++;
      }
    }
	}
  return counter;
}

int countPairs3(int* arr, int len, int value) {
	int counter = 0;
	int right = len;
	for (int i = 0; i < right; i++) {
		int left = i;
		int val = value - arr[i];
		while (right - 1 > left) {
			int mid = (left + right) / 2;
			if (arr[mid] == val) {
				counter++;
				int middle = mid + 1;
				while (arr[middle] == val && middle < right) {
					counter++;
					middle++;
				}
				middle = mid - 1;
				while (arr[middle] == val && middle > left) {
					counter++;
					middle--;
				}
				break;
			}
			if (arr[mid] > val) {
				right = mid;
			} else {
        left = mid;
			}
		}
	}
	return counter;
}
