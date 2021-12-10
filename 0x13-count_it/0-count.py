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
        first_hot = requests.get(
            "https://reddit.com/r/{}/hot.json?limit=100".format(subreddit),
            headers={'User-agent': 'test'})
        if 'data' not in first_hot:
            return None
        children = first_hot.json().get("data").get("children")
        if (count_dict is None):
            count_dict = dict.fromkeys(word_list, 0)
        for child in children:
            for word in child['data']['title'].split():
                for key_word in word_list:
                    if key_word.lower() == word.lower():
                        if key_word.lower() in count_dict.keys():
                            count_dict[key_word.lower()] += 1
                        else:
                            count_dict[key_word.lower()] = 1
        after = first_hot.json().get("data").get("after")
        count_words(subreddit, word_list, after, count_dict)
    else:
        next_hot = requests.get(
            "https://reddit.com/r/{}/hot.json?after={}".format(
                subreddit, after),
            headers={'User-agent': 'test'})
        children = next_hot.json().get("data").get("children")
        for child in children:
            for word in child['data']['title'].split():
                for key_word in word_list:
                    if key_word.lower() == word.lower():
                        if key_word.lower() in count_dict.keys():
                            count_dict[key_word.lower()] += 1
                        else:
                            count_dict[key_word.lower()] = 1
        after = next_hot.json().get("data").get("after")
        if after is not None:
            return count_words(subreddit, word_list, after, count_dict)
        for key in sorted(count_dict, key=lambda x: (-count_dict[x], x)):
            if count_dict[key] > 0:
                print('{}: {}'.format(key, count_dict[key]))
        return (count_dict)
