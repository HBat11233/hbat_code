# -*- coding: utf-8 -*-
import scrapy
from baiBuBaiKe.items import BaibubaikeItem

class StudaypcSpider(scrapy.Spider):
    name = 'studaypc'
    allowed_domains = ['baike.baidu.com']
    start_urls = ['http://baike.baidu.com/']

    def parse(self, response):
        subSelector = response.xpath('//div[@class="card_cnt_tit"]')
        items=[]
        for sub in subSelector:
            item = BaibubaikeItem()
            item['titleName'] = sub.xpath('./a/text()').extract()
            items.append(item)
        return items
