# -*- coding: utf-8 -*-
"""
Created on Sat Sep 21 17:47:01 2024

@author: Lichen
"""

import re
import urllib.request
url = "http://www.baidu.com"
response = urllib.request.urlopen(url)
html_content = response.read()
urls = re.findall(r'href="(http[s]?://[^"]+)"', html_content.decode('utf-8'))
for url in urls:
    print(url);
