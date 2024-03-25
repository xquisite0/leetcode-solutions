// 3093. Longest Common Suffix Queries

class Solution {
public:
 
    // trie node
    struct TrieNode
    {
        struct TrieNode *children[26];

        // isEndOfWord is true if the node represents
        // end of a word
        bool isEndOfWord;
        int length = INT_MAX;
        int i = -1;
    };

    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    // If not present, inserts key into trie
    // If the key is prefix of trie node, just
    // marks leaf node
    void insert(struct TrieNode *root, string key, int id)
    {
        struct TrieNode *pCrawl = root;
        if (key.size() < pCrawl->length) {
            pCrawl->length = key.size();
            pCrawl->i = id;
        } else if (key.size() == pCrawl->length && id < pCrawl->i) {
            pCrawl->i = id;
        }
        string cur = "";
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
            // cur += key[i];
            // if (cur == "hg") {
            //     cout << "Before: ";
            //     cout << pCrawl->length << " " << pCrawl->i << endl;
            // }
            if (key.size() < pCrawl->length) {
                pCrawl->length = key.size();
                pCrawl->i = id;
            } else if (key.size() == pCrawl->length && id < pCrawl->i) {
                pCrawl->i = id;
            }
            // if (cur == "hg") {
            //     cout << "After: ";
            //     cout << pCrawl->length << " " << pCrawl->i << endl;
            // }
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    // Returns true if key presents in trie, else
    // false
    int search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        string cur = "";
        for (int i = 0; i < key.length(); i++)
        {
            
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) break;
            cur += key[i];

            pCrawl = pCrawl->children[index];
        }
        // if (cur == "hg") {
        //     cout << "search: ";
        //     cout << pCrawl->length << " " << pCrawl->i << endl;
        // }
        return pCrawl->i;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size(), m = wordsQuery.size();
        struct TrieNode *root = getNode();

        // Construct trie
        for (int i = 0; i < n; i++) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            insert(root, wordsContainer[i], i);
        }
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            ans.push_back(search(root, wordsQuery[i]));
            // cout << id << endl;
        }
        return ans;

    }

};
