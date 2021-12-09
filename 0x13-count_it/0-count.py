#!/usr/bin/python3
"""
returns a list containing the titles of all hot articles for a given subreddit
"""
import json
import requests
import sys


def count_words(subreddit, word_list=[], after=None, count_dict=None):
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
            children = first_hot.json().get("data").get("children")
            for child in children:
                title = first_hot.json().get("data").get(
                    "children")[0].get("data").get("title")
                if (count_dict is None):
                    count_dict = dict.fromkeys(word_list, 0)
                for word in word_list:
                    count = title.lower().count(word.lower())
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
            title = next_hot.json().get("data").get(
                "children")[0].get("data").get("title")
            for word in word_list:
                count = title.lower().count(word)
                count_dict[word] += count
        after = next_hot.json().get("data").get("after")
        if after is not None:
            return count_words(subreddit, word_list, after, count_dict)
        for key, value in sorted(count_dict.items()):
            if (value > 0):
                print("{}: {}".format(key, value))
        return (count_dict)
