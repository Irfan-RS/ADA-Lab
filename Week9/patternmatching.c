#include<stdio.h>
void patternMatching(char text[], char pattern[]) { 
    int i, j; int n = 0,m = 0; 
    while (text[n] != '\0') {
        n++; }
    while (pattern[m] != '\0') {
        m++;}
    
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
    
    }
    
int main() {
        char text[100], pattern[100];
        printf("Enter the text: ");
        scanf("%s", text);
        
        printf("Enter the pattern: ");
        scanf("%s", pattern);
        
        patternMatching(text, pattern);
        
        return 0;
    }
