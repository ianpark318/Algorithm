#include "timebomb.h"    // 0. 반드시 포함 

int searchMaxIndex(int low, int high) {
    int mid = (low + high) / 2;
    if (low == high)
        return low;
    else {
        int leftMaxIndex = searchMaxIndex(low, mid);
        int rightMaxIndex = searchMaxIndex(mid + 1, high);
        int result = box_comp(leftMaxIndex, rightMaxIndex);

        if(result == 1)
            return leftMaxIndex;
        else
            return rightMaxIndex;
    }
}

int main() {
    int N, result, index;

    box_ready();
    N = box_size();
    int mid = N / 2;
    searchMaxIndex(0, N-1);

    box_report(index);
}