vector<int> Solution::maxset(vector<int> &arr) {
    long sum = -1;
    int start = 0;
    int end = 0;
    long sum_seg = 0;
    vector<int> final;
    vector<int> seg;
    for(int i = 0 ; i < arr.size() ; i++)
    {   
        if(arr[i] >= 0)
        {
            sum_seg += arr[i];
            seg.push_back(arr[i]);
            
            if(sum_seg > sum)
            {
                sum = sum_seg;
                final = seg;
            }
            else if(sum_seg == sum)
            {
                if(seg.size() > final.size())
                    final = seg;
            }
        }
        else
        {
            seg.clear();
            sum_seg = 0;
        }
    }
    return final;
}

