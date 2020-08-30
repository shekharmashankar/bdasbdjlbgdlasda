string multiplyWithDigit(string num, char dig)
{
    string mul;
    int carry = 0;
    for(int i=num.length()-1;i>=0;i--)
    {
        carry = (num[i]-'0')*(dig-'0') + carry;
        mul = to_string(carry%10) + mul;
        carry/=10;
    }
    if(carry)
        mul = to_string(carry) + mul;
    if(!mul.length()) mul = to_string(0);
    return mul;
}

string add(string a, string b)
{
    string sum;
    int carry = 0;
    
    for(int i = 0; i < max(a.length(),b.length()); i++)
    {
        int diga = 0, digb = 0;
        if(i<a.length())
            diga = a.at(a.length()-1-i) - '0';
        if(i<b.length())
            digb = b.at(b.length()-1-i) - '0';
        carry = diga+digb+carry;
        sum = to_string(carry%10) + sum;
        carry/=10;
    }
    if(carry)
        sum = to_string(carry)+sum;
    if(!sum.length()) sum = to_string(0);
    return sum;
}

string multiplyWith10(string num, int times)
{
    string mul(num);
    for(int i=0;i<times;i++)
        mul+="0";
    if(!mul.length()) mul = to_string(0);
    return mul;
}

string clearLeadingZeros(string num)
{
    string clr;
    bool flag = true;
    for(char c : num)
    {
        if(c!='0' || !flag)
        {
            flag = false;
            clr+=c;
        }
    }
    if(!clr.length()) clr = to_string(0);
    return clr;
}

string multiply(string a, string b)
{
    string mul;
    for(int i=0; i<min(a.length(),b.length());i++)
    {
        string prod;
        if(a.length()<b.length())
            prod = multiplyWithDigit(b,a.at(a.length()-1-i));
        else
            prod = multiplyWithDigit(a,b.at(b.length()-1-i));
        mul = add(mul,multiplyWith10(prod,i));
    }
    
    if(!mul.length()) mul = to_string(0);
    mul = clearLeadingZeros(mul);
    return mul;
}

string Solution::solve(int A)
{
    string fact = to_string(1);
    for(int i=2;i<=A;i++)
        fact = multiply(fact,to_string(i));
    return fact;
}