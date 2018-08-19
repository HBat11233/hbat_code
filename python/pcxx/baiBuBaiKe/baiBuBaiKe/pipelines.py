# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import time

class BaibubaikePipeline(object):
    def process_item(self, item, spider):
        now = time.strftime('%y-%m-%f',time.localtime())
        fileName = 'baidubaike'+now+'.txt'
        with open(fileName,'a') as fp:
            fp.write(item['titleName'][0].encode('utf8')+'\n\n')
        return item
