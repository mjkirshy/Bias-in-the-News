# imports 
import nltk
#
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize 
from nltk.stem import PorterStemmer
#
# This file will remove stop words, stem and compare sentences to the article title (and summary)
# and use their value as comparison for the most comparable 
# and later use these sentences/paragraphs to query google / etc
#
test_title = 'Medicare for All and Beyond, Sanders Uses the Senate as His Launching Pad'
test_para = 'I ran for president; I got 13 million votes, going over 1,700 delegates to the Democratic convention, and got more young peoples votes than Clinton and Trump combined, Mr Sanders boasted in an interview in his Washington office. And I thought that those 13 million people deserved a voice in Democratic leadership. The Medicare for All Act unveiling  its fifth iteration  comes as Mr Sanderss $18 million fund-raising haul has made him an instant front-runner in a very crowded field.  But in many ways he is still the same old Bernie, as many of his colleagues like to say  a gruff and sometimes grating presence in a chamber that prides itself on civility.  He still knows how to rankle.  He ran as a Democrat for president in 2016, then shunned the entreaties of Democratic leaders and sought re-election last year as an independent.  His push for Medicare for All runs counter to the wishes of top Democrats like Senator Chuck Schumer, the minority leader, and Speaker Nancy Pelosi, who are trying to de-emphasize it. At the same time, Mr Sanders  who has long cast himself as an outsider  has joined party leadership, which gives him a voice in plotting strategy.  His post as chair of outreach  a job that did not exist until he and Mr Schumer created it after the 2016 presidential election  has also given him license and a small budget to travel the country doing what he likes best: rallying the progressive left to resist President Trump.'
#
def get_title(url):
    a=5
#
def remove_stop_words(text):
    stop_words = set(stopwords.words('english'))
    word_tokens = word_tokenize(text)
    altered_string = []
    for word in word_tokens:
        if word not in stop_words:
            altered_string.append(word)
    # print(altered_string)
    temp = stem_text(altered_string)
    return altered_string
#
def stem_text(tokenized_string):
    pstemmer = PorterStemmer()
    stemmed_string = []
    for word in tokenized_string:
        temp = pstemmer.stem(word)
        stemmed_string.append(pstemmer.stem(word))
    print(stemmed_string)
    return stemmed_string
#
def main():
    remove_stop_words(test_title)
    remove_stop_words(test_para)
#
if __name__ == "__main__":
    main()