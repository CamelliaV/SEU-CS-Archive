# # -*- coding = utf-8 -*-
# # @Time : 2021/11/1 18:59
# # @Author : 09020328 王亮
# # @File : Web spider.py
# # @Software: PyCharm

import time
import requests
import json
import pandas as pd
from pyecharts.charts import Timeline, Pie, Bar
from pyecharts import options as opts
from pyecharts.options import PieLabelLineOpts

city_name_set = [
    "北京",
    "天津",
    "河北",
    "山西",
    "内蒙古",
    "辽宁",
    "吉林",
    "黑龙江",
    "上海",
    "江苏",
    "浙江",
    "安徽",
    "福建",
    "江西",
    "山东",
    "河南",
    "湖北",
    "湖南",
    "广东",
    "广西",
    "海南",
    "重庆",
    "四川",
    "贵州",
    "云南",
    "西藏",
    "陕西",
    "甘肃",
    "青海",
    "宁夏",
    "新疆"]
year_set = [2021, 2020, 2019]

'''
爬虫，爬取近三年(2021-2019)上述所有(提供数据的)城市
录取分数与专业
注：官网中2021年多地并没有提供平均数数据，而中国教育在线
中甚至没有2021年的数据，在2020-2019年的数据比较中，数据
是一致的，但区别在于官方提供的平均分中有小数，中国教育在线
提供没有小数，如分数  官网：649.8  中国教育在线：649
因为从官网直接获取的数据，故以官网的为准，不进行清洗
'''
with open('test.json','w',encoding="utf-8") as fw:
    for year in year_set:
        for city in city_name_set:
            science_class = requests.get(
                f"https://admin.zhinengdayi.com/front/enroll/getMajorSelectChange?cityName={city}&sCode=NLGYFE&year={year}")
            '''
            爬取各城市各年度的科类条目
            (不同城市不同年度有：综合改革，理工/物理类 文史/历史类 理科 文科)
            '''
            science_class.encoding='utf-8'
            time.sleep(0.3) #设置爬取间隔
            for sc in science_class:

                sc_str = sc.decode(encoding='utf-8')
                '''
                提取科类条目内容，获得完整目标URL
                '''
                if "scienceList" in sc_str:
                    pattern = sc_str.split(",")[1].split('[')[1].split(']')[0]
                    if "理工/物理类" in sc_str.split(',')[2]:
                        pattern2 = "理工/物理类"
                    elif "理科" in sc_str.split(',')[2]:
                        pattern2 = "理科"
                    else:
                        pattern2 = ""
                else:
                    continue
                pattern = eval(pattern)
                '''
                爬取普通招生
                '''
                r = requests.get(
                    f"https://admin.zhinengdayi.com/front/enroll/findMajorScoreCompareList?sCode=NLGYFE&cityName={city}&year={year}&scienceClass={pattern}&type=普通招生&batch=")
                r.encoding = "utf-8"
                '''
                打印测试 & 保存至json
                '''
                print(r.json())
                for i in r.json()['list']:
                    fw.write("\n")
                    json.dump(i, fw, ensure_ascii=False)
                '''
                爬取国家专项
                '''
                r = requests.get(
                    f"https://admin.zhinengdayi.com/front/enroll/findMajorScoreCompareList?sCode=NLGYFE&cityName={city}&year={year}&scienceClass={pattern}&type=国家专项&batch=")
                r.encoding = "utf-8"
                print(r.json())
                if r.json()['list']:
                    for i in r.json()['list']:
                        fw.write("\n")
                        json.dump(i, fw, ensure_ascii=False)

                if pattern2 != "":
                    r = requests.get(
                        f"https://admin.zhinengdayi.com/front/enroll/findMajorScoreCompareList?sCode=NLGYFE&cityName={city}&year={year}&scienceClass={pattern2}&type=普通招生&batch=")
                    r.encoding = "utf-8"
                    for j in r.json()['list']:
                        fw.write("\n")
                        json.dump(j, fw, ensure_ascii=False)

                    r = requests.get(
                        f"https://admin.zhinengdayi.com/front/enroll/findMajorScoreCompareList?sCode=NLGYFE&cityName={city}&year={year}&scienceClass={pattern2}&type=国家专项&batch=")
                    r.encoding = "utf-8"
                    if r.json()['list']:
                        for j in r.json()['list']:
                            fw.write("\n")
                            json.dump(j, fw, ensure_ascii=False)

print("finished!!!")


'''
读取json数据
将NaN数据清洗为"暂无数据"
删去'majorCategory','sCode','cityId'等其他无效条目
即无数据条目或不需要的条目
'''
with open('test.json','r',encoding='utf-8') as f:
     df = pd.read_json(f,lines=True)
     df.avgScore = df.avgScore.fillna("暂无数据")
     df.drop('majorCategory',axis=1,inplace=True)
     df.drop('cityId',axis=1,inplace=True)
     df.drop('sCode',axis=1,inplace=True)
     # df.drop(index=[i for i in range(13,42)],axis=1,inplace=True)
     store_cols = df.columns.values[11:]
     df.drop(columns=[col for col in store_cols],axis=1,inplace=True)
     df.to_csv('test.csv')
print("finished!!!")


'''
按照城市名与年份筛选数据
输出相应城市 相应年份下 全部录取情况
'''
with open('test.json', 'r', encoding='utf-8') as f:
    df = pd.read_csv("test.csv")
    for year in year_set:
        for city in city_name_set:
            temp = df[(df.year == year) & (df.cityName == city)]
            temp.to_csv('MyDataSet/'+city + str(year) + '.csv')


'''
输出城市数目，
城市数31*年份3，
应为93份数据,
验证数据集完整性
'''
print(len(city_name_set))



for city in city_name_set:
    data_test = pd.read_csv(f'MyDataSet/{city}2021.csv')
    data_test2 = pd.read_csv(f'MyDataSet/{city}2020.csv')
    data_test3 = pd.read_csv(f'MyDataSet/{city}2019.csv')
    data_test_set = [data_test,data_test2,data_test3]
    timeline = Timeline(init_opts=opts.InitOpts(width="1680px", height='720px'))
    for i in [2021,2020,2019]:
        pie = (Pie(init_opts=opts.InitOpts(width="1680px", height='1080px'))
         .add("", [list(z) for z in zip(data_test_set[i-2019]['majorName'], data_test_set[i-2019]['enrollNum'])],
              center=['30%', '50%'],
              radius=['10%', '50%'],

              )
         .set_global_opts(
            title_opts=opts.TitleOpts(title=f"{city}{i}年度各专业录取人数饼状图"),
            legend_opts=opts.LegendOpts(type_='scroll', pos_left='70%', orient='vertical'),

        )
         .set_series_opts(label_opts=opts.LabelOpts(formatter='{b}:{c}')))
        timeline.add(pie,f'{i}年')
    timeline.render(f"MyVisualization/{city}录取.html")




for city in city_name_set:

    data_test = pd.read_csv(f'MyDataSet/{city}2021.csv')
    data_test2 = pd.read_csv(f'MyDataSet/{city}2020.csv')
    data_test3 = pd.read_csv(f'MyDataSet/{city}2019.csv')
    data_test_set = [data_test,data_test2,data_test3]

    for i in [2019,2020,2021]:
        bar = (Bar(init_opts=opts.InitOpts(width='1080px',height='720px'))
        .add_xaxis(list(data_test_set[i-2019]['majorName']))
        .add_yaxis('最低分',list(data_test_set[i-2019]['lowScore']),stack="stack1")
        .add_yaxis('最高分',list(data_test_set[i-2019]['hightScore']),stack="stack1")
        .set_global_opts(
            xaxis_opts=opts.AxisOpts(axislabel_opts=opts.LabelOpts(rotate=-15)),
            title_opts=opts.TitleOpts(title="Bar-旋转X轴标签", subtitle="解决标签名字过长的问题"),
            datazoom_opts=[opts.DataZoomOpts()],
            toolbox_opts=opts.ToolboxOpts(),
        )
        )
        bar.render(f"MyVisualization/Bar/{city}{year_set[i-2019]}.html")


