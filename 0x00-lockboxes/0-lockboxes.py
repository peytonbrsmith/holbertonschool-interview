#!/usr/bin/python3
""" Determins if ALL boxes are unlockable """


def canUnlockAll(boxes):
    """ Determins if ALL boxes are unlockable """
    box_num = 0
    keys_avail = []
    locked_boxes = boxes.copy()
    for box in boxes:
        if box_num == 0:
            for key in box:
                if key not in keys_avail:
                    keys_avail.append(key)
            locked_boxes.remove(box)
        else:
            if box_num in keys_avail:
                for key in box:
                    if key not in keys_avail:
                        keys_avail.append(key)
                for lbox in locked_boxes:
                    if box_num in keys_avail:
                        for key in box:
                            if key not in keys_avail:
                                keys_avail.append(key)
                        locked_boxes.remove(lbox)
        box_num += 1
    if locked_boxes == [] and len(keys_avail) == len(boxes) - 1:
        return True
    else:
        return False
