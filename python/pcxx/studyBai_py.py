# -*- coding: utf-8 -*-
import scrapy


class StudybaiPySpider(scrapy.Spider):
    name = 'studyBai.py'
    allowed_domains = ['baike.baidu.com']
    start_urls = ['http://baike.baidu.com/']

    def parse(self, response):
        pass
