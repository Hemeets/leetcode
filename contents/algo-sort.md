<!--
 * @Author: QDX
 * @Date: 2022-12-26 08:56:53
 * @Description: 
-->
# 排序算法

题目
| 题号 | 标题 | 难度 | cpp |
| --- | --- | --- | --- |
| 0021 | [合并两个有序链表](../solutions/0021_%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8.ipynb) | E | [cpp](../cpp_solutions/0021.cpp) |
| 0023 | [合并K个排序链表](../solutions/0023_%E5%90%88%E5%B9%B6K%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.ipynb) | H |
| 0088 | [合并两个有序数组](../solutions/0088_%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.ipynb) | E |
| 0148 | [排序链表](../solutions/0148_%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.ipynb) | M |
| 0215 | [数组中的第K个最大元](../solutions/0215_%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83.ipynb) | M |
| 0 | []() |  |
| 0 | []() |  |
| 0 | []() |  |


其他排序
| 题号 | 标题 | 难度 | 
| --- | --- | --- |
| 0056 | [合并区间](../solutions/0056_%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4.ipynb) | M |
| 0057 | [插入区间](../solutions/0057_%E6%8F%92%E5%85%A5%E5%8C%BA%E9%97%B4.ipynb) | M |
| 0 | []() |  |
| 0 | []() |  |



## 基本排序算法
```py
class MySort:
    ''' 写一下常用排序算法(原地排序) '''

    def __init__(self) -> None:
        pass

    # @trace
    def merge_sort(self, nums, p, r):
        """ 归并，需要额外n空间存放临时数组。闭区间[p, r] """
        if p >= r:
            return
        q = (p + r) // 2
        self.merge_sort(nums, p, q)
        self.merge_sort(nums, q+1, r)
        self.merge(nums, p, q, r)

    @staticmethod
    def merge(nums, p, q, r):
        """ p <=q < r，闭区间[p, r]，假设nums[p:q], nums[q+1:r+1] 已排好序 """
        tmp1 = nums[p:q+1]  # 临时数组
        tmp2 = nums[q+1:r+1]
        l1, l2 = q - p + 1, r - q
        i, j, k = 0, 0, 0
        while i < l1 and j < l2:
            if tmp1[i] <= tmp2[j]:
                nums[k] = tmp1[i]
                i += 1
            else:
                nums[k] = tmp2[j]
                j += 1
            k += 1
        nums[p+k: r+1] = tmp1[i:] if j == l2 else tmp2[j:]
    
    def quick_sort(self, nums, l, r):
        """ 快排 """
        if l >= r:
            return
        p = self._partition(nums, l, r)
        self.quick_sort(nums, l, p - 1)
        self.quick_sort(nums, p + 1, r)

    @staticmethod
    def _partition(nums, l, r):
        """ 慢指针j, 快指针i。闭区间[l, r] """
        j = l
        for i in range(l + 1, r + 1):
            if nums[i] < nums[l]:  # 小于nums[l]的放在左边, 循环不变量: [l+1, j]上恒小于nums[l]
                j += 1
                nums[i], nums[j] = nums[j], nums[i]
        # [j+1, i+1]上恒>=nums[l], i --> r
        nums[l], nums[j] = nums[j], nums[l]
        return j  # j的范围[l, r]

    @staticmethod
    def select_sort(nums):
        """ 选择排序 """
        if not nums:
            return
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[j] < nums[i]:
                    nums[i], nums[j] = nums[j], nums[i]
              
                    
nums = [9,2,7,4,3,1,2,3,3,8]
# MySort().select_sort(nums)
# MySort().merge_sort(nums, 0, len(nums)-1)
MySort().quick_sort(nums, 0, len(nums)-1)
print(nums)
```