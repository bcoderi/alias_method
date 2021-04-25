#!/usr/bin/env python
# coding: utf-8

import matplotlib as mpl
mpl.use('tkagg')
import matplotlib.pyplot as plt
import numpy as np

#数据文件解析
f  = open('alias_method_time_100_times.txt','r')

scores_list = []
subjects_list = []
for line in f:
    line = list(line.strip().split(','))
    scores_list.append(int(line[1]))
    subjects_list.append(line[0])

scores = np.array(scores_list)
subjects = np.array(subjects_list)

font_size = 8 # 字体大小
fig_size = (8, 6) # 图表大小

# 更新字体大小
mpl.rcParams['font.size'] = font_size
mpl.rcParams['font.sans-serif'] = ['SimHei']
# 更新图表大小
mpl.rcParams['figure.figsize'] = fig_size

# 图表标题
plt.title(u'Alias method 效率验证')
plt.ylabel('耗时：单位/ms',fontsize=14)
plt.xlabel('运行次数：单位/次',fontsize=14)

rect_temp = plt.plot(subjects, scores)

plt.show()
