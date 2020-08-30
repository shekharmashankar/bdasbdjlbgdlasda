vector<int> Solution::wave(vector<int> &A) {
    vector<int> add;
    sort(A.begin(), A.end());
    for(int i = 0 ; i < A.size()-1 ; i+=2)
    {
        add.push_back(A[i+1]);
        add.push_back(A[i]);
    }
    if(A.size()%2 == 1)
        add.push_back(A[A.size()-1]);
    return add;
}
