#!/usr/bin/python3
"""
returns a list containing the titles of all hot articles for a given subreddit
"""
import json
import requests
import sys


def count_words(subreddit, word_list=[], after=None, count_dict = None):
    """ returns a list containing the titles of
    all hot articles for a given subreddit """
    if after is None:
        subreddit_exists = requests.get(
            "https://reddit.com/r/{}".format(subreddit),
            headers={'User-agent': 'test'})
        if subreddit_exists.status_code == 200:
            first_hot = requests.get(
                "https://reddit.com/r/{}/hot.json".format(subreddit),
                headers={'User-agent': 'test'})
            # for post in first_hot.json().get("data").get("children"):
            #     word_list.append(post.get("data").get("title"))
            # after = first_hot.json().get("data").get("after")
            # count_words(subreddit, word_list, after, count + 1)
            children = first_hot.json().get("data").get("children")
            for child in children:
                title = first_hot.json().get("data").get("children")[0].get("data").get("title")
                if (count_dict is None):
                    count_dict = dict.fromkeys(word_list, 0)
                for word in word_list:
                    count = title.lower().count(word)
                    # print(title.lower())
                    # print(word + ":" + str(count))
                    # print(count)
                    count_dict[word] += count
            after = first_hot.json().get("data").get("after")
            count_words(subreddit, word_list, after, count_dict)
        else:
            return (None)
    else:
        next_hot = requests.get(
            "https://reddit.com/r/{}/hot.json?after={}".format(
                subreddit, after),
            headers={'User-agent': 'test'})
        children = next_hot.json().get("data").get("children")
        for child in children:
            title = next_hot.json().get("data").get("children")[0].get("data").get("title")
            for word in word_list:
                count = title.lower().count(word)
                # print(title.lower())
                # print(word + ":" + str(count))
                # print(count)
                count_dict[word] += count
        after = next_hot.json().get("data").get("after")
        if after is not None:
            return count_words(subreddit, word_list, after, count_dict)
        for key, value in count_dict.items():
            print("{}: {}".format(key, value))
        return (count_dict)
