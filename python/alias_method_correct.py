#!/usr/bin/env python
# coding: utf-8

import matplotlib as mpl
mpl.use('tkagg')
import matplotlib.pyplot as plt
import numpy as np

#数据文件解析
f  = open('alias_method_do_5_times.txt','r')

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
print(scores)
subjects = np.array(subjects_list)

font_size = 6 # 字体大小
fig_size = (32, 24) # 图表大小

# 更新字体大小
mpl.rcParams['font.size'] = font_size
mpl.rcParams['font.sans-serif'] = ['SimHei']
# 更新图表大小
mpl.rcParams['figure.figsize'] = fig_size
# 设置柱形图宽度
bar_width = 0.185

index = np.arange(len(scores[0]))
plt.ylabel('实际采样值：单位/次',fontsize=14)
plt.xlabel('采样对象名字',fontsize=14)
# X轴标题
plt.xticks(index + bar_width, subjects)
# 图表标题
plt.title(u'Alias method 随机结果正确性分析', fontsize=14)

# 添加数据标签
def add_labels(rects):
    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x() + rect.get_width() / 2, height, height, ha='center', va='bottom')
        rect.set_edgecolor('white')

k = 0
for score in scores:
    if k % 2 == 0:
        rect_temp = plt.bar(index + (bar_width * k ), scores[k], bar_width, color='#0072BC')
    else:
        rect_temp = plt.bar(index + (bar_width * k ), scores[k], bar_width, color='#ED1C24')
    add_labels(rect_temp)
    k = k + 1

plt.show()