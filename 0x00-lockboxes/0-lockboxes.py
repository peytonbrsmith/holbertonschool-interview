#!/usr/bin/python3
# Determins if boxes are unlockable

def canUnlockAll(boxes):
    box_num = 0
    keys_avail = []
    locked_boxes = []
    for box in boxes:
        if box_num == 0:
            for key in box:
                keys_avail.append(key)
        else:
            if box_num in keys_avail:
                for key in box:
                    keys_avail.append(key)
                for lbox in locked_boxes:
                    if box_num in keys_avail:
                        for key in box:
                            keys_avail.append(key)
                        locked_boxes.remove(lbox)
            else:
                locked_boxes.append(box)
        box_num += 1
    if locked_boxes == []:
        return True
    else:
        return False

# boxes = [[1], [2], [3], [4], []]
# print(canUnlockAll(boxes))

# boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
# print(canUnlockAll(boxes))

# boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
# print(canUnlockAll(boxes))
