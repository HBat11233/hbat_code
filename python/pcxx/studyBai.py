# -*- coding: utf-8 -*-
import scrapy


class StudybaiSpider(scrapy.Spider):
    name = 'studyBai'
    allowed_domains = ['baike.baidu.com']
    start_urls = ['http://baike.baidu.com/']

    def parse(self, response):
        pass
