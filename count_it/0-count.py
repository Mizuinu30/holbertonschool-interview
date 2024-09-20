#!/usr/bin/python3
"""
A recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted
count of given keywords (case-insensitive, delimited by
spaces.
Javascript should count as javascript, but java should not).
"""

import requests


def count_words(subreddit, word_list, kw_cont=None, after=None):
    if kw_cont is None:
        kw_cont = {}

    headers = {"User-Agent": "Mozilla/5.0"}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {"limit": 100, "after": after}

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    posts = data.get("children", [])

    for post in posts:
        title = post["data"]["title"].lower().split()
        for word in title:
            word = word.strip(".,!?_")
            if word in word_list:
                if word in kw_cont:
                    kw_cont[word] += 1
                else:
                    kw_cont[word] = 1

    after = data.get("after")
    if after:
        count_words(subreddit, word_list, kw_cont, after)
    else:
        sorted_kw = sorted(kw_cont.items(), key=lambda kv: (-kv[1], kv[0]))
        for word, count in sorted_kw:
            print(f"{word}: {count}")

# Example usage:
# count_words('learnpython', ['python', 'java', 'javascript'])
