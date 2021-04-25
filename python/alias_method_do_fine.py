#!/usr/bin/env python
# coding: utf-8

import matplotlib as mpl
mpl.use('tkagg')
import matplotlib.pyplot as plt
import numpy as np

#数据文件解析
f  = open('alias_method_do_100_times.txt','r')

scores_list = []
s_list = []
subjects_list = []
i = 0
j = 0
for line in f:
    i = i + 1
    j = j + 1
    line = list(line.strip().split(','))
    s_list.append(int(line[1]))
    if i == 9:
        i = 0
        scores_list.append(s_list)
        s_list = []
    if j <= 9:
        subjects_list.append(line[0])

scores = np.array(scores_list)
subjects = np.array(subjects_list)

font_size = 15 # 字体大小
fig_size = (8, 6) # 图表大小

# 更新字体大小
mpl.rcParams['font.size'] = font_size
mpl.rcParams['font.sans-serif'] = ['SimHei']
# 更新图表大小
mpl.rcParams['figure.figsize'] = fig_size
# 设置柱形图宽度
bar_width = 0.185

index = np.arange(len(scores[0]))
# X轴标题
plt.xticks(index, subjects)
# 图表标题
plt.title(u'Alias method 结果分布归一性')
plt.ylabel('实际采样值：单位/次',fontsize=14)
plt.xlabel('采样对象名字',fontsize=14)

x = list(range(1, 10))
for score in scores:
    rect_temp = plt.scatter(subjects, score, 500, c = x, alpha=0.02, marker='8')

plt.show()
