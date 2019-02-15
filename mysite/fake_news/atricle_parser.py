from newspaper import Article

def article_parser_fn(link):
    ##for all information regarding 'article' objects, please see newspaper3k documentation
    article = Article(link)
    ##creating an article object from the string link
    article.download()
    ##downloading the article object
    article.parse()
    return(article.text)
    ##'parsing' the article object
    #articleText = article.text
    ##assigning the variable article text to article.text (the text of the news source)