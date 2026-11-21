vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
/*
Tiền tố chuẩn. Cho một xâu s. Một tiền tố của s được gọi là một tiền tố chuẩn
nếu nó không là cả xâu s. Hàm tiền tố. Cho một xâu s có độ dài n. Hàm tiền tố 
của s được định nghĩa là một mảng π có độ dài n, trong đó π[i] là độ dài của 
tiền tố chuẩn dài nhất của xâu con s[0…i] mà cũng là hậu tố của xâu con này. 
Từ định nghĩa này ta có π[0]=0.
*/
