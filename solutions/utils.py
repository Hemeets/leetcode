'''
Author: QDX
Date: 2022-12-01 10:16:50
Description: 
'''

from typing import List, Optional
from pprint import pprint
from functools import wraps
import math


class ToDictMixin:
    def to_dict(self):
        return self._traverse_dict(self.__dict__)

    def _traverse_dict(self, instance_dict):
        output = {}
        for key, value in instance_dict.items():
            output[key] = self._traverse(key, value)
        return output

    def _traverse(self, key, value):
        if isinstance(value, ToDictMixin):
            return value.to_dict()
        elif isinstance(value, dict):
            return self._traverse_dict(value)
        elif isinstance(value, list):
            return [self._traverse(key, i) for i in value]
        elif hasattr(value, '__dict__'):
            return self._traverse_dict(value.__dict__)
        else:
            return value


def trace(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        print(f'{func.__name__}({args!r}, {kwargs!r}) '
              f'-> {result!r}')
        return result
    return wrapper


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def l2ln(List):
    Fnode = ListNode(0)
    node = Fnode
    for a in List:
        node.next = ListNode(a)
        node = node.next
    return Fnode.next


def ln2l(Node):
    List = list()
    node = Node
    while node:
        List.append(node.val)
        node = node.next
    return List


class TreeNode(ToDictMixin):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def l2tn(tn_val_list: List):
    ''' 完全二叉树按层从左到右枚举list --> 数结构 '''
    if not tn_val_list:
        return None
    node_n = len(tn_val_list)
    h = math.log2(node_n + 1)
    # assert int(h) == h, "input list len must be (2^h - 1), h is height of tree"
    if int(h) != h:
        pad_n = 2**(int(h) + 1) - 1 - node_n
        tn_val_list += [None] * pad_n

    tn_list = [TreeNode(v) for v in tn_val_list]
    for idx, cur_n in enumerate(tn_list):
        cur_left_idx = idx * 2 + 1
        cur_right_idx = idx * 2 + 2
        if cur_left_idx >= node_n:
            break
        if tn_val_list[cur_left_idx] is not None:
            cur_n.left = tn_list[cur_left_idx]
        if tn_val_list[cur_right_idx] is not None:
            cur_n.right = tn_list[cur_right_idx]
    return tn_list[0]


if __name__ == "__main__":
    # tn0 = TreeNode(0)
    # tn2 = TreeNode(2)
    # tn4 = TreeNode(4)
    # tn3 = TreeNode(3, tn2, tn4)
    # tn_bst = TreeNode(1, tn0, tn3)
    # tn_nbst = TreeNode(1, tn3, tn0)
    # pprint(tn_bst.to_dict())

    tn_val_list = [5, 4, 6, None, None, 3, 7]
    tn = l2tn(tn_val_list)
    pprint(tn.to_dict())
