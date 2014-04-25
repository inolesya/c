#include <stdio.h>

main()
{
    int arr[8]={0,1,2,3,4,5,6,7};
    int i;
    printf("base\tposition\n");
    for (i = 0; i<10; i++)
        printf("%d\t%d\n",i,binSearch(i,arr,sizeof(arr)));

}

int binSearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while ( low <= high && x != v[(mid=(low+high)/2)] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
    }
    if ( x == v[mid] )
        return mid;
    else
        return -1; 
}
