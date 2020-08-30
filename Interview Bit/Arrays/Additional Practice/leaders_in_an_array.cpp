int maximumElement(vector<int> arr)
{
    int mx = INT_MIN;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        mx = max(mx, arr[i]);
    }
    return mx;
}

vector<int> Solution::solve(vector<int> &A) {
    vector<int> arr;
    arr.push_back(A[A.size()-1]);
    for(int i = A.size()-2 ; i >= 0 ; i--)
    {
        int maxuntil = maximumElement(arr);
        if(A[i] > maxuntil)
            arr.push_back(A[i]);
    }
    return arr;
}
