class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return [[]]

        if len(strs) == 1:
            return [[strs[0]]]

        ga_pairs = {}
        key = [0] * 26

        for i in range(len(strs)):
            for j in range(len(strs[i])):
                idx = ord(strs[i][j]) - 97
                print(idx)
                key[idx]+=1

            hash_key = tuple(key.copy())
            if hash_key in ga_pairs.keys():
                ga_pairs[hash_key].append(strs[i])
            else:
                ga_pairs[hash_key] = [strs[i]]

            key = [0] * 26

        return list(ga_pairs.values())