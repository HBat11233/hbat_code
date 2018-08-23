# -*- coding: utf-8 -*-
import scrapy


class MypcfSpider(scrapy.Spider):
    name = 'mypcf'
    allowed_domains = ['www.csdn.net']
    start_urls = ['http://www.csdn.net/']

    def parse(self, response):
        selectorMypcf = response.selector
        da = selectorMypcf.xpath("//a/text()")
        items=[]
        for st in da:
            ste=st.extract().strip()
            if(len(ste)!=0):
                items.append({"text":ste.encode()})
                yield {"1":ste}
        yield items