# 
# @lc app=leetcode.cn id=460 lang=python3
# 
# [460] LFU缓存
# 
# @lc code=start
class LFUCache:

    def __init__(self, capacity: int):
        self.LFU_LENGTH = capacity
        self.lfu_dict = {}
        self.key_list = []    # 二维数组，其中某一维数组下标索引表示使用次数，该一维数组表示为最远 -> 最近排列的key的list序列

    def get(self, key: int) -> int:
        if key not in self.lfu_dict.keys(): return -1
        self.key_list[self.lfu_dict[key]["use_counts"]].remove(key)
        self.lfu_dict[key]["use_counts"] += 1
        if self.lfu_dict[key]["use_counts"] >= len(self.key_list): self.key_list.append([])
        self.key_list[self.lfu_dict[key]["use_counts"]].append(key)
        print ("get", key, self.lfu_dict, self.key_list)
        return self.lfu_dict[key]["value"]

    def put(self, key: int, value: int) -> None:
        cur_length = len(self.lfu_dict.keys())
        # 修改 key -value
        if key in self.lfu_dict.keys():
            self.lfu_dict[key]["value"] = value
            self.key_list[self.lfu_dict[key]["use_counts"]].remove(key)
            self.lfu_dict[key]["use_counts"] += 1
            if self.lfu_dict[key]["use_counts"] >= len(self.key_list): self.key_list.append([])
            if key in self.key_list[self.lfu_dict[key]["use_counts"]]: self.key_list[self.lfu_dict[key]["use_counts"]].remove(key)
            self.key_list[self.lfu_dict[key]["use_counts"]].append(key)

        else:
            # 新增 key -value
            if (cur_length < self.LFU_LENGTH):
                self.lfu_dict[key] = {}
                self.lfu_dict[key]["value"] = value
                self.lfu_dict[key]["use_counts"] = 0
                
                if self.lfu_dict[key]["use_counts"] >= len(self.key_list): self.key_list.append([])
                self.key_list[self.lfu_dict[key]["use_counts"]].append(key)
            else:
                for _index in range(len(self.key_list)):
                    if self.key_list[_index] and self.key_list[_index][0]:
                        del_key = self.key_list[_index].pop(0)
                        break
                else:
                    return None
                self.lfu_dict.pop(del_key)
                self.lfu_dict[key] = {}
                self.lfu_dict[key]["value"] = value
                self.lfu_dict[key]["use_counts"] = 0
                if self.lfu_dict[key]["use_counts"] >= len(self.key_list): self.key_list.append([])
                self.key_list[self.lfu_dict[key]["use_counts"]].append(key)

        print ("put", key,value, self.lfu_dict, self.key_list)


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

if __name__ == "__main__":
    cache= LFUCache(2)
    print (cache.put(1, 1));
    print (cache.put(2, 2));
    print (cache.get(1));       
    print (cache.put(3, 3));
    print (cache.get(2));
    print (cache.get(3));
    print (cache.put(4, 4));
    print (cache.get(1));
    print (cache.get(3));
    print (cache.get(4));

    # print (cache.get(2))
    # print (cache.put(2, 6));
    # print (cache.get(1))
    # print (cache.put(1, 5));
    # print (cache.put(1, 2));
    # print (cache.get(1))
    # print (cache.get(2))