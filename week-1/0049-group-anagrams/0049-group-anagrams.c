/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpChar(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

char *makeKey(char *s)
{
    int len = strlen(s);

    char *key = (char *)malloc((len + 1) * sizeof(char));
    strcpy(key, s);

    qsort(key, len, sizeof(char), cmpChar);

    return key;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    char **keys = (char **)malloc(strsSize * sizeof(char *));
    int *colSizes = (int *)malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++)
    {
        char *key = makeKey(strs[i]);

        int found = -1;

        for (int j = 0; j < groupCount; j++)
        {
            if (strcmp(keys[j], key) == 0)
            {
                found = j;
                break;
            }
        }

        if (found == -1)
        {
            keys[groupCount] = key;

            result[groupCount] = (char **)malloc(strsSize * sizeof(char *));
            result[groupCount][0] = strs[i];

            colSizes[groupCount] = 1;
            groupCount++;
        }
        else
        {
            result[found][colSizes[found]] = strs[i];
            colSizes[found]++;

            free(key);
        }
    }

    *returnSize = groupCount;
    *returnColumnSizes = colSizes;

    for (int i = 0; i < groupCount; i++)
    {
        free(keys[i]);
    }

    free(keys);

    return result;
}