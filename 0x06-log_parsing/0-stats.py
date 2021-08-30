#!/usr/bin/python3
"""Compute metrics based on weird input"""
import sys
import re

line_count = 0
status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}
pattern = re.compile("^(?:[0-9]{1,3}\.){3}[0-9]{1,3} - \[(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2}.\d*)] \"GET \/projects\/260 HTTP\/1.1\" [1-5][0-9][0-9] (\d*)")

file_size = 0
for line in sys.stdin:
    if (pattern.search(line)):
        line = line.split()
        for token in line:
            if token in status_codes:
                status_codes[token] += 1
                line_count += 1
                try:
                    if (line[8].isdigit()):
                        file_size += int(line[8])
                except IndexError:
                    break

    if (line_count % 10 == 0):
        print("File size: {}".format(file_size))
        for key, value in status_codes.items():
            print("{}: {}".format(key, value))