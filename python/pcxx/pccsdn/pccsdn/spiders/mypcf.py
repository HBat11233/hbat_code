# -*- coding: utf-8 -*-
import scrapy


class MypcfSpider(scrapy.Spider):
    name = 'mypcf'
    allowed_domains = ['www.csdn.net']
    start_urls = ['http://www.csdn.net/']

    def parse(self, response):
        selectorMypcf = response.selector
        da = selectorMypcf.xpath("//a/text()")
        with open("csdn.txt","wb") as fp:
            for st in da:
                print(st.extract())
                ste=st.extract().strip()
                if(len(ste)!=0):
                    fp.write(st.extract().strip().encode())
                    fp.write("\n".encode())