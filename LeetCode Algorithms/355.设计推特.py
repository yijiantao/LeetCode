# -*- coding: UTF-8 -*-

'''
    23 / 23 个通过测试用例
状态：通过
执行用时：6092 ms  (击败了 5%) 腊鸡！！！代码优化
内存消耗：18.9 MB  (击败了 100%)
'''

class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.userId_dict = {}
        self.all_tweets_set = []    # 所有tweet集合，有序，按发tweet时间存储，不能用set

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        if userId not in self.userId_dict.keys(): 
            self.userId_dict[userId] = {}
            self.userId_dict[userId]['tweetId_set'] = set()
            self.userId_dict[userId]['followeeId_set'] = set()
        
        if 'tweetId_set' not in self.userId_dict[userId].keys(): self.userId_dict[userId]['tweetId_set'] = set()
        self.userId_dict[userId]['tweetId_set'].add(tweetId)
        self.all_tweets_set = [tweetId] + self.all_tweets_set

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        res = []
        linked_tweetid = []
        if userId not in self.userId_dict.keys(): return res
        linked_tweetid = list(self.userId_dict[userId]['tweetId_set']) if 'tweetId_set' in self.userId_dict[userId].keys() else []
        # 找到关注人发的 tweetId
        for _followee_id in self.userId_dict[userId]['followeeId_set']:
            if _followee_id in self.userId_dict.keys() and 'tweetId_set' in self.userId_dict[_followee_id].keys() and \
              self.userId_dict[_followee_id]['tweetId_set']:
                linked_tweetid += list(self.userId_dict[_followee_id]['tweetId_set'])

        # 对比 self.all_tweets_set，按时间抽取，结果存在 res 中返回
        for _tweetId in self.all_tweets_set:
            if _tweetId in linked_tweetid: res.append(_tweetId)

        return res if len(res) <= 10 else res[:10]

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId not in self.userId_dict.keys(): 
            self.userId_dict[followerId] = {}
            self.userId_dict[followerId]['followeeId_set'] = set()
        
        if 'followeeId_set' not in self.userId_dict[followerId].keys(): self.userId_dict[followerId]['followeeId_set'] = set()
        self.userId_dict[followerId]['followeeId_set'].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId in self.userId_dict.keys() and 'followeeId_set' in self.userId_dict[followerId].keys() and followeeId in self.userId_dict[followerId]['followeeId_set']:
            self.userId_dict[followerId]['followeeId_set'].remove(followeeId)
