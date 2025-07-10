#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    int maxElement = 0;
    printf("Enter %d digits: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    int *hash = (int *)malloc((maxElement + 1) * sizeof(int));

    for (int i = 0; i <= maxElement; i++)
    {
        hash[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int highestFrequency = 0;
    int lowestFrequency = INT_MAX;
    int numberWithHighestFrequency = -1;
    int numberWithLowestFrequency = -1;
    for (int i = 0; i <= maxElement; i++)
    {
        if (hash[i] > 0)
        {
            if (hash[i] > highestFrequency)
            {
                highestFrequency = hash[i];
                numberWithHighestFrequency = i;
            }
            if (hash[i] < lowestFrequency)
            {
                lowestFrequency = hash[i];
                numberWithLowestFrequency = i;
            }
            
        }
        
    }

    printf("Number with highest frequency: %d (appeared %d times)\n", numberWithHighestFrequency, highestFrequency);
    printf("Number with lowest frequency: %d (appeared %d times)\n", numberWithLowestFrequency, lowestFrequency);

    int q;
    printf("Enter the no. of digits for which the frequency is required: ");
    scanf("%d", &q);
    
    while (q-- !=0)
    {
        int number;
        printf("Enter number: ");
        scanf("%d", &number);
        
        if (number <= maxElement)
        {
            printf("Frequency for %d is %d\n", number, hash[number]);
        } else{
            printf("Number not present");
        }
        
    }
    free(arr);
    free(hash);
}