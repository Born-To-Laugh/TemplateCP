vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
/*
Trong blog này, chúng ta sẽ tìm hiểu về hàm Z (Z-function) của một chuỗi S và
những ứng dụng của nó. Cho một chuỗi S độ dài n, ký hiệu là S[0…n−1], ta có hàm
Z tương ứng là một mảng z[0…n−1], với z[i] là độ dài tiền tố chung lớn nhất của
chuỗi S[0…n−1] và S[i…n−1]. Ở đây, ta sẽ quy ước hai điều: một là chuỗi và mảng
sẽ mặc định bắt đầu từ 0, hai là z[0]=0, ta có thể hiểu quy ước này nghĩa là chuỗi
con xét ở đây phải là chuỗi con nghiêm ngặt (tức không tính chính nó).
*/
