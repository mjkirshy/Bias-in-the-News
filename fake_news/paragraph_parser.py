# imports #
import bs4, requests, re
from bs4 import BeautifulSoup
from gensim.summarization import summarize
#
def para_summarize(paragraph):
    print(paragraph)
    p = summarize(paragraph)
    print(p)

#
def lowercase_paragraph(paragraph):
    string_p = str(paragraph)
    para = ""
    for index, char in enumerate(string_p):
        char = char.lower()
        para+=char
    # print(para)
    return para
#
def get_article(url_link):
    article_request = requests.get(url_link)
    return article_request
#
def paragraph_parse(test_url):
    if "nytimes" not in test_url:
        print("Incorrect Article Type: Not NY Times.")
        return
    else:
        article_request = get_article(test_url) # gets JSON information
        content_req = article_request.content #begins beautiful soup process
        content_soup = BeautifulSoup(content_req, features="lxml")
        # parsed_article = content_soup.find_all("p")
        parsed_article = content_soup.find_all("p", attrs={'class' : re.compile('css')}) # parse JSON by p tags
        article_by_paragraphs = []
        counter = 1
        for paragraph in parsed_article:
            if counter > 1:
                article_by_paragraphs.append(paragraph.text)
            counter+=1
        # title = content_soup.find("title")  # save for equality/relevance comparisons later            
#
def main():
    # force NYT only for accurate testing #
    test_url = "https://www.nytimes.com/2019/04/10/us/politics/bernie-sanders-medicare-for-all.html?action=click&module=Top%20Stories&pgtype=Homepage"
    paragraph_parse(test_url)
#
if __name__ == "__main__":
    main()