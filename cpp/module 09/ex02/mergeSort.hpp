#include "PmergeMe.hpp"

template <typename T>
void merge(T& left, T& right, T& result)
{
    u_int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            result[k++] = left[i++];
        else
            result[k++] = right[j++];
    }
    while (i < left.size())
        result[k++] = left[i++];
    while (j < right.size())
        result[k++] = right[j++];
}

template <typename T>
void mergeSort(T& sequence)
{
    if (sequence.size() <= 1)
        return;
    u_int mid = sequence.size() / 2;
    T left(sequence.begin(), sequence.begin() + mid);
    T right(sequence.begin() + mid, sequence.end());
    
    mergeSort(left);
    mergeSort(right);
    merge(left, right, sequence);
}