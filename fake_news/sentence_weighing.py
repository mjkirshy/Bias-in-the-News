# imports 
import nltk, requests, Levenshtein as lev, bs4, sklearn, jellyfish
#
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
from fuzzywuzzy import fuzz
from bs4 import BeautifulSoup
from operator import itemgetter
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize 
# from nltk.stem import PorterStemmer
#
# This file will remove stop words, stem and compare sentences to the article title (and summary)
# and use their value as comparison for the most comparable 
# and later use these sentences/paragraphs to query google / etc
#
# test_title = 'Medicare for All and Beyond, Sanders Uses the Senate as His Launching Pad'
test_para = 'I ran for president; I got 13 million votes, going over 1,700 delegates to the Democratic convention, and got more young peoples votes than Clinton and Trump combined, Mr Sanders boasted in an interview in his Washington office. And I thought that those 13 million people deserved a voice in Democratic leadership. The Medicare for All Act unveiling  its fifth iteration  comes as Mr Sanderss $18 million fund-raising haul has made him an instant front-runner in a very crowded field.  But in many ways he is still the same old Bernie, as many of his colleagues like to say  a gruff and sometimes grating presence in a chamber that prides itself on civility.  He still knows how to rankle.  He ran as a Democrat for president in 2016, then shunned the entreaties of Democratic leaders and sought re-election last year as an independent.  His push for Medicare for All runs counter to the wishes of top Democrats like Senator Chuck Schumer, the minority leader, and Speaker Nancy Pelosi, who are trying to de-emphasize it. At the same time, Mr Sanders  who has long cast himself as an outsider  has joined party leadership, which gives him a voice in plotting strategy.  His post as chair of outreach  a job that did not exist until he and Mr Schumer created it after the 2016 presidential election  has also given him license and a small budget to travel the country doing what he likes best: rallying the progressive left to resist President Trump.'
test_url = 'https://www.nytimes.com/2019/04/10/us/politics/bernie-sanders-medicare-for-all.html?action=click&module=Top%20Stories&pgtype=Homepage'
#
def remove_stop_words(text):
    stop_words = set(stopwords.words('english'))
    word_tokens = word_tokenize(text)
    altered_string = []
    for word in word_tokens:
        if word not in stop_words:
            altered_string.append(word)
    print(altered_string)
    # temp = stem_text(altered_string)
    return altered_string
#
# def stem_text(tokenized_string):
#     pstemmer = PorterStemmer()
#     stemmed_string = []
#     for word in tokenized_string:
#         temp = pstemmer.stem(word)
#         # stemmed_string.append(pstemmer.stem(word))
#     return stemmed_string
#
def sentence_parse(paragraph):
    list_of_sentences = []
    pos_start = 0
    pos_period = paragraph.find('.')
    while pos_period != -1:
        temp = paragraph[pos_start:pos_period+1]
        list_of_sentences.append(str(temp.strip()))
        pos_start = pos_period+1
        pos_period = paragraph.find('.',pos_start+1)
    # for s in list_of_sentences:
        # print(s)
    return list_of_sentences
#
def get_title(url):
    requester = requests.get(url)
    content = requester.content
    bs_content = BeautifulSoup(content, features='lxml')
    title_unparsed = bs_content.title.string
    pos = title_unparsed.find("- The New York Times")
    title = title_unparsed[0:pos]
    return title
#
def calc_jaro(title,sentence):
    value =  jellyfish.jaro_distance(title,sentence)
    return (sentence, value)
#
def calc_jaro_winkler(title,sentence):
    value = jellyfish.jaro_winkler(title,sentence)
    return (sentence, value)
def calc_cosine(title, paragraph):
    # this function does not break it down by sentences as the results for entire paragraph are better/higher #
    # simple for loop and different input changes this no problem #
    title = [title]
    title.append(paragraph)
    tfidf_vectorizer  = TfidfVectorizer()
    tfidf_matrix = tfidf_vectorizer.fit_transform(title)
    result_cos = cosine_similarity(tfidf_matrix[0:1], tfidf_matrix)
    value = round(result_cos[0][1],4)
    # value_rounded = round(value,4)
    # print('Complete: ' + str(value))
    # print('Complete: ' + str(value_rounded))
    return (paragraph,value)
#
def calc_fuzzy(title, sentence):
    fuzz_ratio = fuzz.ratio(title.lower(),sentence.lower())
    fuzz_partial_ratio = fuzz.partial_ratio(title.lower(),sentence.lower())
    fuzz_token_sort_ratio = fuzz.token_sort_ratio(title,sentence)
    fuzz_token_set_ratio = fuzz.partial_token_set_ratio(title,sentence)
    # tuple_all = (sentence, fuzz_ratio,fuzz_partial_ratio,fuzz_token_sort_ratio,fuzz_token_set_ratio) # unsure if separate is better than averaged results
    tuple_combined = sentence, ((fuzz_ratio+fuzz_partial_ratio+fuzz_token_sort_ratio+fuzz_token_set_ratio)/4) # averages the result from the four methods
    return tuple_combined
#
def calc_lev(title, sentence):
    ratio = lev.ratio(title.lower(),sentence.lower())
    temp_tuple = (sentence,ratio)
    return temp_tuple
#
def gather_results(title, paragraph):
    # do cosine sim for each paragraph, update that
    # add step to combine results and add to dictionary for return to front end
    cosine_result_list = []
    cosine_result_list.append(calc_cosine(title,paragraph))
    sentence_list = sentence_parse(paragraph)
    #
    lev_result_list =[]
    fuzzy_result_list = []
    jaro_result_list = []
    jarowinkler_result_list = []
    #
    for sentence in sentence_list:
        lev_result_list.append(calc_lev(title,sentence))
        fuzzy_result_list.append(calc_fuzzy(title,sentence))
        jaro_result_list.append(calc_jaro(title,sentence))
        jarowinkler_result_list.append(calc_jaro_winkler(title,sentence))
    #
    lev_result_list.sort(key=itemgetter(1), reverse=True)
    fuzzy_result_list.sort(key=itemgetter(1),reverse=True) # only one that is value between 0 and 100
    jaro_result_list.sort(key=itemgetter(1),reverse=True)
    jarowinkler_result_list.sort(key=itemgetter(1),reverse=True)
    string = "check here for debugging purposes"
#
def main():
    # sentence_parse(test_para)
    title = get_title(test_url)
    gather_results(title,test_para)
    # gather_results(get_title(test_url),test_para)
#
if __name__ == "__main__":
    main()