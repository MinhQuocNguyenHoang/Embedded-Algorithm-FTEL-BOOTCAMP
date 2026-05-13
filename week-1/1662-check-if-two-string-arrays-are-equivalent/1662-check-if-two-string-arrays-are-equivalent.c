bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0, j = 0;
    int p1 = 0, p2 = 0; 

    while (i < word1Size && j < word2Size) {
        if (word1[i][p1] != word2[j][p2]) return false;

        p1++;
        p2++;

        if (word1[i][p1] == '\0') {
            i++;
            p1 = 0;
        }

        if (word2[j][p2] == '\0') {
            j++;
            p2 = 0;
        }
    }

    return i == word1Size && j == word2Size;
}