int firstUniqChar(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        bool res = true; 
        for (int j = 0; j < strlen(s); j++) {
            if (i != j && s[i] == s[j]) {
                res = false;  
                break; 
            }
        }
        if (res == true) {
            return i;  
        }
    }
    return -1;  
}
