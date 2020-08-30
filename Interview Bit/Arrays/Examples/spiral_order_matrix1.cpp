vector<int> Solution::spiralOrder(const vector<vector<int> > &mat) {
    int M = mat.size();
    int N = mat[0].size();
    vector<int> add;
    
    int top = 0, bottom = M - 1;
    int left = 0, right = N - 1;

    while (1)
    {
        if (left > right)
            break;
        // print top row
        for (int i = left; i <= right; i++)
            add.push_back(mat[top][i]);
        top++;

        if (top > bottom)
            break;
        // print right column
        for (int i = top; i <= bottom; i++)
            add.push_back(mat[i][right]);
        right--;

        if (left > right)
            break;
        // print bottom row
        for (int i = right; i >= left; i--)
            add.push_back(mat[bottom][i]);
        bottom--;

        if (top > bottom)
            break;
        // print left column
        for (int i = bottom; i >= top; i--)
            add.push_back(mat[i][left]);
        left++;
    }
    return add;
}
