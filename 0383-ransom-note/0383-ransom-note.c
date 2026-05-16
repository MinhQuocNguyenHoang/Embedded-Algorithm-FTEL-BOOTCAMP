bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};

    for(int i=0;i<strlen(magazine);i++){
        count[magazine[i]-'a']++;
    }

    for(int i=0;i<strlen(ransomNote);i++){
        count[ransomNote[i]-'a']--;
        if(count[ransomNote[i]-'a']<0) return false;
    }
    return true;
}