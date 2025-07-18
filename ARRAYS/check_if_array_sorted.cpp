bool isSorted(int arr[], int n) {
    // Code Here
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        return false;
        
        
        
    }
    return true;
}


