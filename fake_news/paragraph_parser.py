# imports #
import bs4, requests, re, newspaper
# import nltk.corpus, nltk.tokenize, nltk.stem
from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize, sent_tokenize
from bs4 import BeautifulSoup
from nltk.corpus import stopwords
from nltk.cluster.util import cosine_distance
import numpy as np
import networkx as nx
#

def lowercase_paragraph(paragraph):
    paragraph = paragraph.lower()

def sentence_similarity(sentence1, sentence2, stopwords=None):
    if stopwords is None:
        stopwords = []
    sent1 = [w.lower() for w in sentence1]
    sent2 = [w.lower() for w in sentence2]
    all_words = list(set(sent1+sent2))
    vec1 = [0] * len(all_words)
    vec2 = [0] * len(all_words)
    
    for w in sent1:
        if w in stopwords:
            continue
        vec1[all_words.index(w)] += 1
    
    for w in sent2:
        if w in stopwords:
            continue
        vec2[all_words.index(w)] += 1
    
    return 1 - cosine_distance(vec1,vec2)

def build_similarity_matrix(paragraphs, stop_words):
    sim_matrix = np.zeros((len(paragraphs), len(paragraphs)))
    for index1 in range(len(paragraphs)):
        for index2 in range(len(paragraphs)):
            if index1 == index2:
                continue
    sim_matrix[index1][index2] = sentence_similarity(paragraphs[index1], paragraphs[index2], stop_words)
    return sim_matrix

def generate_summary(paragraphs, top_n = 5):
    stop_words = stopwords.words('english')
    summarize_text = []
    #step 1 is read file, but we are passing in the text #
    #step 2 gen sim matrix across sentences #
    sen_sim_matrix = build_similarity_matrix(paragraphs,stop_words)
    #step 3 #
    sen_sim_graph = nx.from_numpy_array(sen_sim_matrix)
    scores = nx.pagerank(sen_sim_graph)
    #step 4#
    ranked_sen = sorted(((scores[i],s) for i,s in enumerate(paragraphs)), reverse=True)
    print("Sentences in ranked order are: ")
    for i in range(top_n):
        summarize_text.append(" ".join(ranked_sen[i][1]))
    print("Summarized Text: \n", ". ".join(summarize_text))
    

def get_article(url_link):
    request_art = requests.get(url_link)
    return request_art


def paragraph_parse(request_art):
    content_req = request_art.content
    content_soup = BeautifulSoup(content_req, features="lxml")
    paragraph_breakdown = content_soup.find_all("p", attrs={'class' : re.compile('css')})
    title = content_soup.find("title")
    print(title.text + '\n')
    article_by_paragraphs = []
    counter = 0
    input_string = ""
    print('-----------')
    for paragraphs in paragraph_breakdown:
        if counter <= 5:
            input_string += paragraphs.text
            counter += 1
        else:
            article_by_paragraphs.append(input_string)
            counter = 0
            input_string = ""
    generate_summary(article_by_paragraphs,2)
def main():
    ## for NYT, use beautifulSoup##
    ## for WAPO, use article ##
    test_url = "https://www.nytimes.com/2019/04/03/us/usc-admissions-scandal-students.html"
    parsed = get_article(test_url)
    paragraph_parse(parsed)

if __name__ == "__main__":
    main()