#!/usr/bin/env python
# coding: utf-8

import matplotlib as mpl
mpl.use('tkagg')
import matplotlib.pyplot as plt
import numpy as np

#数据文件解析
f  = open('alias_method_time.txt','r')
scores_alias = []
subjects_alias = []
for line in f:
    line = list(line.strip().split(','))
    scores_alias.append(int(line[1]))
    subjects_alias.append(line[0])

scores_alias = np.array(scores_alias)
subjects_alias = np.array(subjects_alias)

#数据文件解析
f  = open('x5_time.txt','r')
scores_x5 = []
subjects_x5 = []
for line in f:
    line = list(line.strip().split(','))
    scores_x5.append(int(line[1]))
    subjects_x5.append(line[0])

scores_x5 = np.array(scores_x5)
subjects_x5 = np.array(subjects_x5)

font_size = 8 # 字体大小
fig_size = (8, 6) # 图表大小

# 更新字体大小
mpl.rcParams['font.size'] = font_size
mpl.rcParams['font.sans-serif'] = ['SimHei']
# 更新图表大小
mpl.rcParams['figure.figsize'] = fig_size

# 图表标题
plt.title(u'Alias method 效率验证')

plt.ylabel('时间：单位/ms',fontsize=14)
plt.xlabel('第几次执行：单位/次',fontsize=14)
plt.plot(subjects_alias, scores_alias, ls = "-", lw = 2, c = "b", label = "Alias Method")
plt.plot(subjects_x5, scores_x5, ls = "-", lw = 2, c = "c", label = "X5")

plt.yticks(range(0,28000,500))
plt.legend()

plt.show()
