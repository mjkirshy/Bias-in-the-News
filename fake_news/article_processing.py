import os, nltk, re, io
from nltk.corpus.reader.plaintext import PlaintextCorpusReader
from nltk.corpus import stopwords
from collections import Counter
from nltk.tokenize import RegexpTokenizer
from nltk.probability import FreqDist
from nltk.collocations import *

nltk.download("stopwords")

## KEEP ##
def remove_stop_words(word_list):
    stop_words = set(stopwords.words('english'))
    new_word_list = []
    #word_list = word_list.lower()
    #word_list.replace('\"','')
    for w in word_list:
        if w not in stop_words and len(w) > 3 and w.lower() != ('said' or 'would' or 'like'):
            new_word_list.append(w)
    return new_word_list
## PROBABLY GET RID OF -- REPLACE WITH TOKENIZER ##
def remove_everything_but_letters(word_list):
    regex = re.compile('[^a-zA-Z0-9]')
    new_word_list = []
    for w in word_list:
        regex.sub('', w)
        if w != '':
            new_word_list.append(w)
    return new_word_list
## PROBABLY GET RID OF -- REPLACE WITH FREQDIST (NLKT PROBABILITY) ##
def word_count(word_list):
    word_count_dict = dict()
    for w in word_list:
        if w not in word_count_dict:
            word_count_dict[w] = 1
        else:
            word_count_dict[w] += 1
    return word_count_dict

BiasedCorpusDir = "C:\\Users\\matthew.kirshy\\Desktop\\CSE-442-Fake-News-Web-Application\\article_db\\biased"
UnbiasedCorpusDir = "C:\\Users\\matthew.kirshy\\Desktop\\CSE-442-Fake-News-Web-Application\\article_db\\unbiased"
print("...Creating corpi...")
BiasedCorpus = PlaintextCorpusReader(BiasedCorpusDir, '.*')
UnbiasedCorpus = PlaintextCorpusReader(UnbiasedCorpusDir, '.*')

# print("...Pulling words...")
# BiasedWords = BiasedCorpus.words()
# UnbiasedWords = UnbiasedCorpus.words()
# pre_len_biased = len(BiasedWords)
# pre_len_unbiased = len(UnbiasedWords)
# print("...Removing stop words...")
# BiasedWords = remove_stop_words(BiasedWords)
# UnbiasedWords = remove_stop_words(UnbiasedWords)
# print("...Removing everything thats not a letter or number...")
# BiasedWords = remove_everything_but_letters(BiasedWords)
# UnbiasedWords = remove_everything_but_letters(UnbiasedWords)
# print("...Done...")
# print("Previous length of BiasedWords: " + str(pre_len_biased))
# print("Length after stop words removed: " + str(len(BiasedWords)))
# x = pre_len_biased - len(BiasedWords)
# print("Stop words removed: " + str(x))
# print("Previous length of UniasedWords: " + str(pre_len_unbiased))
# print("Length after stop words removed: " + str(len(UnbiasedWords)))
# x = pre_len_unbiased - len(UnbiasedWords)
# print("Stop words removed: " + str(x))
# print("...Creating word count...")
# BiasedWordCount = word_count(BiasedWords)
# UnbiasedWordCount = word_count(UnbiasedWords) ## valueerror got 3 values, expected 2

print("...Pulling strings...")
BiasedString = BiasedCorpus.raw()
UnbiasedString = UnbiasedCorpus.raw()
print("...Removing non-alphanumeric characters...")
tokenizer = RegexpTokenizer('\w+')
BiasedWords = tokenizer.tokenize(BiasedString)
UnbiasedWords = tokenizer.tokenize(UnbiasedString)

print("...Removing stop words...")
BiasedWords = remove_stop_words(BiasedWords)
UnbiasedWords = remove_stop_words(UnbiasedWords)
print("...Generating Bigrams...")
bigram_measures = nltk.collocations.BigramAssocMeasures()
finder = BigramCollocationFinder.from_words(BiasedWords)
finder.apply_freq_filter(4)
print(finder.nbest(bigram_measures.pmi, 50))
finder = BigramCollocationFinder.from_words(UnbiasedWords)
finder.apply_freq_filter(4)
print("--------------------------------------------------------------------------------------------")
print(finder.nbest(bigram_measures.pmi, 50))
print("...Creating word count...")
BiasedFreq = FreqDist(BiasedWords)
UnbiasedFreq = FreqDist(UnbiasedWords)
print(BiasedFreq.most_common(25))
print(UnbiasedFreq.most_common(25))
diff_list = []
for x in BiasedWords:
    if x not in UnbiasedWords:
        diff_list.append(x)
diff_word_count = FreqDist(diff_list)
f = io.open('C:\\Users\\matthew.kirshy\\Desktop\\CSE-442-Fake-News-Web-Application\\article_db\\diff.txt','w+')
f.write(str(diff_word_count)) ## iterate over list o write each one with count
f.close()
#print(diff_word_count.most_common(5000))
print("...Done...")