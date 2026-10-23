int hash[26] = {0};

for (char ch : s) {
    hash[ch - 'a']++;
}

// Frequency of character c:
cout << hash[c - 'a'];
