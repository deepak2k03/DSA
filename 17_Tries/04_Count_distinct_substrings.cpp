struct Node {
    Node* links[26]{};

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
};

class Solution {
public:
    int countSubs(string& s) {
        int c = 0;
        Node* root = new Node();

        for (int i = 0; i < s.size(); i++) {
            Node* node = root;

            for (int j = i; j < s.size(); j++) {
                if (!node->containsKey(s[j])) {
                    c++;
                    node->put(s[j], new Node());
                }

                node = node->get(s[j]);
            }
        }

        return c;
    }
};