// Copyright 2021 NNTU-CS

int cbinsearch(int arr[], int len, int value, int l) {
  int left = l, right = len - 1; 
  int cnt = 0;
  while (left <= right) { 
    int mid = l + (left + right) / 2;
    if (arr[mid] == value) {
      cnt++;
      int i = mid - 1;
      while (i >= left && arr[i] == value) {
        cnt++;
        i--;
      }
      i = mid + 1;
      while (i <= right && arr[i] == value) {
        cnt++;
        i++;
      }
      return cnt;
    } else {
        if (arr[mid] < value) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
    }
  return 0;
}

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
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  for (int i = 0; i < right; i++) {
    counter += cbinsearch(arr, len, value - arr[i], i);
	}
	return counter;
  return 0;
}
