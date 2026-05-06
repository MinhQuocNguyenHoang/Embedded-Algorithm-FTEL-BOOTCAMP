// Cách thức giải: Là ta lấy tổng asciII của s trừ với tổng asciII t thì cái mã asciII sau khi trừ sẽ đại diện cho chữ thêm vào


char findTheDifference(char* s, char* t) {
    int sum = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
        sum -= s[i];
    
    for (int i = 0; t[i] != '\0'; i++)
        sum += t[i];
    
    return (char)sum;
}