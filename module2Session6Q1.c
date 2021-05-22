#define MAX 25
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void fillArray(int nums[], int total);
void sortArray(int nums[], int total);
int findMean(int nums[], int total);
int findMedian(int nums[], int total);
int findMode(int nums[], int total);
void printResults(int mean, int median, int mode);

int main() {
    int nums[MAX];
    int total, cnt=0;
    int mean, median, mode;
    fillArray(nums,25);
    sortArray(nums, 25);
    mean = findMean(nums, 25);
    median = findMedian(nums, 25);
    mode = findMode(nums, 25);
    printResults(mean, median, mode);
    return 0;
}

void fillArray(int nums[], int total) {
    int i;
    for (i = 0; i < total; i++) {
        scanf("\n%i", &nums[i]);
    }
}

void sortArray(int nums[], int total) {
    int x;
    int y;
    for (x = 0; x < total; x++) {
        for (y = 0; y < total - 1; y++) {
            if (nums[y] > nums[y + 1]) {
                int temp = nums[y + 1];
                nums[y + 1] = nums[y];
                nums[y] = temp;
            }
        }
    }
}

int findMean(int nums[], int total) {
    int sum = 0;
    int mv;
    for (int i = 0; i < total; i++) {
        sum = sum + nums[i];
    }
    mv = sum / total;
    return (mv);
}

int findMedian(int nums[], int total) {
    int temp = total / 2;
    return nums[temp];
}

int findMode(int nums[], int total) {
    int freq[25][2], count = 0, max_freq, max_num[25], cnt = 0, mode=0;
    for (int j = 0; j < total; j++)
    {
        count = 0;
        for (int i = j; i < total; i++)
        {
            if (nums[j] == nums[i])
                count++;
            else
                break;
        }
        freq[j][0] = nums[j];
        freq[j][1] = count;   
    }
    max_freq = freq[0][1];
    for (int k = 1; k < total; k++)
    {
        
        if (freq[k][1] > max_freq)
            max_freq = freq[k][1];
        
    }
    for (int k = 0; k < total; k++)
    {
        if (freq[k][1] == max_freq)
        {
            max_num[cnt] = freq[k][0];
            cnt++;
        }
    }
    if (cnt == 1)
    {
        mode = max_num[cnt - 1];
    }
    else if (cnt > 1)
    {
        mode = max_num[0];
        for (int d = 1; d < cnt; d++)
        {
            if (max_num[d] > mode)
                mode = max_num[d];
        }
    }
    return mode;
}

void printResults(int mean, int median, int mode) {
    printf("%d\n%d\n%d", mean, median, mode);
}