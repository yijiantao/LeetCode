#-*- UTF-8 -*-

class Solution:
    @classmethod
    def countCharacters(self, words, chars):
        from collections import Counter
        res = 0
        chars_dict = Counter(chars)
        for word in words:
            word_dict = Counter(word)
            for c in word_dict:
                if chars_dict[c] < word_dict[c]:
                    break
            else:
                # 如果 if chars_dict[c] < word_dict[c] 条件成立，则 break 跳出for循环
                res += len(word)
        return res

if __name__ == "__main__":
    print (Solution.countCharacters(words = ["cat","bt","hat","tree"], chars = "atach"))