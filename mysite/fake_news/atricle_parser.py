from newspaper import Article
from smmryapi.smmryapi import SmmryAPI

def article_parser_fn(link):
    ##for all information regarding 'article' objects, please see newspaper3k documentation
    article = Article(link)
    ##creating an article object from the string link
    article.download()
    ##downloading the article object
    article.parse()
    ##'parsing' the article object
    return(article.text)

def article_smmry_fn(link):
    SMMRY_API_KEY = "93267E94CD"
    smmry = SmmryAPI(SMMRY_API_KEY)
    url = link
    s = smmry.summarize(url, sm_length=3, sm_keyword_count=5)
    return(s)